#include "manager.h"


namespace td {

AudioManager* AudioManager::instance_ = NULL;
QMutex AudioManager::mutex_;
bool AudioManager::capturePause_ = true;
bool AudioManager::captureStop_ = false;
float AudioManager::gainScale[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.55, 0.6, 0.65,
                                   0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0
                                  };

AudioManager::AudioManager()
{
    AudioManager::startup();
    //Should be User Defined as MAX values
    sfxGain_ = 9;
    musicGain_ = 5;
    notiGain_ = 12;
}

AudioManager::~AudioManager()
{
    AudioManager::shutdown();
}

void AudioManager::shutdown()
{
    if (inited_) {
        inited_ = false;
        alExit();
    }
}

void AudioManager::startup()
{
    alInit();
    inited_ = true;
    playing_ = 0;
}

void AudioManager::startCapture()
{
    QFuture<void> future =
	QtConcurrent::run(this, &AudioManager::captureMic);
}

void AudioManager::playSfx(QStringList files, SoundType type) {
    
    int rdNum;
    
    if(files.size() < 1) {
	qCritical("AudioManager::playSfx(): Empty Vector");
	return;
    }
    
    rdNum = rand() % files.size();
    playSfx(files[rdNum],type);
}

void AudioManager::playSfx(QString filename, SoundType type)
{
    int gain;

    if (type == sfx) {
        gain = sfxGain_ - (playing_ / 1);

        if (gain < 0) {
            gain = 0;
        }
    } else if (type == ntf) {
        gain = notiGain_;
    } else {
        return;
    }
    
    filename = SFXPATH + filename + SFXFILEEXTENSION;

    QFuture<void> future =
        QtConcurrent::run(this, &AudioManager::streamFile,
                          filename, gainScale[gain]);
    return;
}


void AudioManager::captureMic()
{
    ALCdevice* captureDevice;
    ALint samplesAvailable;
    ALchar buffer[BUFFERSIZE];
    ALint format, frequency;

    format = AL_FORMAT_MONO8;
    frequency = 22050;

    captureDevice = alcCaptureOpenDevice(NULL, frequency, format, frequency);

    if (captureDevice) {
	alcCaptureStart(captureDevice);

	while(!checkError()) {

	    alcGetIntegerv(captureDevice, ALC_CAPTURE_SAMPLES, 1
			   , &samplesAvailable);

	    while(capturePause_ == true && captureStop_ == false) {
		alSleep(0.1f);
	    }

	    if(captureStop_ == true) {
		break;
	    } else if (samplesAvailable > (BUFFERSIZE)) {

		alcCaptureSamples(captureDevice, buffer, (BUFFERSIZE));
//TODO: Send to the network here!
	    }
	}
    }

    alcCaptureCloseDevice(captureDevice);
}

QQueue<QString> AudioManager::musicDir(QString dir)
{
    int i;
    int iter;
    QDir mDir(dir);
    mDir.setFilter(QDir::Files);
    QList<QString> musicList = mDir.entryList();
    QQueue<QString> musicQueue;

    if (musicList.length() == 0) {
        qCritical("AudioManager::musicDir(): No Files or Directory");
        return musicQueue;
    }

    iter = rand() % musicList.length();

    for (i = 0; i < musicList.length(); i++) {
        if (++iter >= musicList.length()) {
            iter = 0;
        }

        musicQueue.enqueue(dir + musicList[iter]);
    }

    return musicQueue;
}

void AudioManager::playMusic(QQueue<QString> filenameQueue)
{
    QFuture<void> future =
        QtConcurrent::run(this, &AudioManager::playMusicQueue, filenameQueue);
    return;
}

bool AudioManager::checkError()
{
    ALuint error = alGetError();
    const ALchar* err = alGetString(error);

    if (inited_ == false) {
        return true;
    } else if (error != AL_NO_ERROR) {
        qCritical("AudioManager::checkError(): %d:%s", error, err);
        alExit();
	inited_=false;
        return true;
    }

    return false;
}

void AudioManager::playMusicQueue(QQueue<QString> filenameQueue)
{
    QString filename;
    int gain;
    gain = musicGain_ - (playing_ / 8);

    if (gain < 0) {
        gain = 0;
    }

    while (!filenameQueue.empty() && inited_) {
        filename = filenameQueue.dequeue();
        AudioManager::streamFile(filename, gainScale[gain]);
        /*Sleep for 0.3 sec so playback doesn't overlap*/
        alSleep(0.3f);

        if (errno != ENOENT) {
            filenameQueue.enqueue(filename);
        }

        errno = 0;
    }

}


void AudioManager::streamFile(QString filename, float gain)
{
    FILE* file;
    char array[BUFFERSIZE];
    int bitStream;
    int buffersAvailable = QUEUESIZE;
    long size = 0;
    long result = 0;
    ALuint buffer[QUEUESIZE];
    ALuint source;
    ALint queued = 0;
    ALint queue = 0;
    ALint play = AL_TRUE;
    ALint playing = AL_TRUE;
    ALenum format;
    ALsizei freq = 44100;
    OggVorbis_File oggFile;

    /* Created the source and Buffers */
    alGenBuffers(QUEUESIZE, buffer);
    alGenSources(1, &source);
    /*set the Gain for Music or Sfx*/
    alSourcef(source, AL_GAIN, gain);
    SAFE_OPERATION(playing_++);

    if ((file = fopen(filename.toAscii().constData(), "rb")) == NULL) {
        qCritical() << "AudioManager::streamFile(): Cannot open " 
		    << filename << " for reading...";
        return;
    }

    openOgg(file, &oggFile, &format, &freq);
 
    do {

	clearProcessedBuffers(&source, buffersAvailable, &playing, &play);

        if (buffersAvailable > 0) {
            size = 0;
            /* Read file to we reached a BUFFERSIZE chunk */
            while (size < BUFFERSIZE) {
                result = ov_read(&oggFile, array + size,
                                 BUFFERSIZE - size, 0, 2, 1, &bitStream);

                if (result == 0) {
                    break;
                }

                size += result;

                if (result < 0) {
                    qCritical() << "AudioManager::streamFile(): Ogg Read Failed "
				<< endl;
                    break;
                }
            }

            alBufferData(buffer[queue], format, array, size, freq);
            alSourceQueueBuffers(source, 1, &buffer[queue]);
            queue = (++queue == QUEUESIZE ? 0 : queue);
            buffersAvailable--;
            /**Check the amount of buffers queued to see if
            * we should be playing the track right now.
            * If play is false it means it's playing already
            */
            alGetSourcei(source, AL_BUFFERS_QUEUED, &queued);

            if ((queued > 2 || result == 0) && play) {
                alSourcePlay(source);
                play = AL_FALSE;
            }
        } else {
            alSleep(0.1f);
        }

        /* result == 0 when file is completely read */
    } while (result > 0 && !checkError());

    ov_clear(&oggFile);
    
    cleanUp(&source, buffer);
    SAFE_OPERATION(playing_--);
}

void AudioManager::cleanUp(ALuint *source, ALuint *buffer)
{
    ALint processed;
    ALuint tempBuffer;
    ALint playing;

    do {
        alGetSourcei(*source, AL_SOURCE_STATE, &playing);
        alSleep(0.1f);
    } while (playing != AL_STOPPED && !checkError());

    alGetSourcei(*source, AL_BUFFERS_PROCESSED, &processed);

    while (processed && !checkError()) {
        alSourceUnqueueBuffers(*source, 1, &tempBuffer);
        processed--;
    }

    alDeleteSources(1, source);
    alDeleteBuffers(QUEUESIZE, buffer);
}

void AudioManager::clearProcessedBuffers
(ALuint *source, int &buffersAvailable, ALint *playing, ALint* play)
{
    ALint processed;
    ALuint tempBuffer;

    alGetSourcei(*source, AL_BUFFERS_PROCESSED, &processed);

    while (processed) {
	alSourceUnqueueBuffers(*source, 1, &tempBuffer);
	processed--;

/* ensures buffers don't get larger than QUEUESIZE */
	if (buffersAvailable < QUEUESIZE - 1) {
	    buffersAvailable++;
	}

/* Restarts playing if buffer emptied too quickly */
	alGetSourcei(*source, AL_SOURCE_STATE, playing);

	if (*playing == AL_STOPPED) {
	    *play = AL_TRUE;
	}
    }
}

void AudioManager::openOgg(FILE *file, OggVorbis_File *oggFile, 
			   ALenum *format, ALsizei *freq)
{

    vorbis_info* vorbisInfo;
    if (ov_open(file, oggFile, NULL, 0) != 0) {
        qCritical() << "AudioManager::openOgg(): Error opening file for decoding...";
        return;
    }

    vorbisInfo = ov_info(oggFile, -1);

    if(vorbisInfo->channels == 1) {
        *format = AL_FORMAT_MONO16;
    }
    else {
        *format = AL_FORMAT_STEREO16;
    }

    *freq = vorbisInfo->rate;
}

} /* End namespace td */
