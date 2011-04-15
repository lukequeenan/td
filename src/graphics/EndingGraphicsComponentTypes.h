#ifndef ENDINGGRAPHICSCOMPONENTTYPES_H
#define ENDINGGRAPHICSCOMPONENTTYPES_H

#include "EndingGraphicsComponent.h"

namespace td {

// cannon
class CannonEndingGraphicsComponent : public EndingGraphicsComponent {
    Q_OBJECT

public:
    /**
      Construct the CannonEndingGraphicsComponent based on a position.
      Creates and starts a timer for the animation.

      @param pos Position to draw the animation at.
      @author Nick Huber
      */
    CannonEndingGraphicsComponent(const QPointF& pos)
        : EndingGraphicsComponent(pos) {
        emit created(this);
        redraw(55, LAYER_FLYNPC);
    }

    /**
      Destructor.
      @author Nick Huber
      */
    virtual ~CannonEndingGraphicsComponent() { }

    /**
      Initilize the pixmaps for this object.
      @author Nick Huber
      */
    virtual void initPixmaps();

    /**
      Get the pixmaps for this animation.

      @return Pointer to the pixmap images
      @author Nick Huber
      */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

protected:
    /**
      Timer event where the animation is done.

      @author Nick Huber
      */
    void timerEvent(QTimerEvent*);

private:
    /**
      Set the non-static data members for the pixmaps.

      @author Nick Huber
      */
    virtual void setNonStaticValues();

private:
    static QPixmap* pixmapImgs_; /**< static pixmaps for this ending. */
};


// arrow
class ArrowEndingGraphicsComponent : public EndingGraphicsComponent {
    Q_OBJECT

public:
    /**
      Construct the ArrowEndingGraphicsComponent based on a position.
      Creates and starts a timer for the animation.

      @param pos Position to draw the animation at.
      @author Nick Huber
      */
    ArrowEndingGraphicsComponent(const QPointF& pos)
        : EndingGraphicsComponent(pos) {
        emit created(this);
        redraw(55, LAYER_FLYNPC);
    }

    /**
      Destructor.
      @author Nick Huber
      */
    virtual ~ArrowEndingGraphicsComponent() { }

    /**
      Initilize the pixmaps for this object.
      @author Nick Huber
      */
    virtual void initPixmaps();

    /**
      Get the pixmaps for this animation.

      @return Pointer to the pixmap images
      @author Nick Huber
      */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

protected:
    /**
      Timer event where the animation is done.

      @author Nick Huber
      */
    void timerEvent(QTimerEvent*);

private:
    /**
      Set the non-static data members for the pixmaps.

      @author Nick Huber
      */
    virtual void setNonStaticValues();

private:
    static QPixmap* pixmapImgs_; /**< static pixmaps for this ending. */
};

// tar
class TarEndingGraphicsComponent : public EndingGraphicsComponent {
    Q_OBJECT

public:
    /**
      Construct the TarEndingGraphicsComponent based on a position.
      Creates and starts a timer for the animation.

      @param pos Position to draw the animation at.
      @author Nick Huber
      */
    TarEndingGraphicsComponent(const QPointF& pos)
        : EndingGraphicsComponent(pos) {
        emit created(this);
        redraw(55, LAYER_FLYNPC);
    }

    /**
      Destructor.
      @author Nick Huber
      */
    virtual ~TarEndingGraphicsComponent() { }

    /**
      Initilize the pixmaps for this object.
      @author Nick Huber
      */
    virtual void initPixmaps();

    /**
      Get the pixmaps for this animation.

      @return Pointer to the pixmap images
      @author Nick Huber
      */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

protected:
    /**
      Timer event where the animation is done.

      @author Nick Huber
      */
    void timerEvent(QTimerEvent*);

private:
    /**
      Set the non-static data members for the pixmaps.

      @author Nick Huber
      */
    virtual void setNonStaticValues();

private:
    static QPixmap* pixmapImgs_; /**< static pixmaps for this ending. */
};

// flying death
class FlyingEndingGraphicsComponent : public EndingGraphicsComponent {
    Q_OBJECT

public:
    /**
      Construct the FlyingEndingGraphicsComponent based on a position.
      Creates and starts a timer for the animation.

      @param pos Position to draw the animation at.
      @author Nick Huber
      */
    FlyingEndingGraphicsComponent(const QPointF& pos)
        : EndingGraphicsComponent(pos) {
        emit created(this);
        redraw(1000, LAYER_DEFAULT);
    }

    /**
      Destructor.
      @author Nick Huber
      */
    virtual ~FlyingEndingGraphicsComponent() { }

    /**
      Initilize the pixmaps for this object.
      @author Nick Huber
      */
    virtual void initPixmaps();

    /**
      Get the pixmaps for this animation.

      @return Pointer to the pixmap images
      @author Nick Huber
      */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

protected:
    /**
      Timer event where the animation is done.

      @author Nick Huber
      */
    void timerEvent(QTimerEvent*);

private:
    /**
      Set the non-static data members for the pixmaps.

      @author Nick Huber
      */
    virtual void setNonStaticValues();

private:
    static QPixmap* pixmapImgs_; /**< static pixmaps for this ending. */
};

class GenericNPCEndingGraphicsComponent : public EndingGraphicsComponent {
    Q_OBJECT

public:
    /**
      Construct the GenericNPCEndingGraphicsComponent based on a position.
      Creates and starts a timer for the animation.

      @param pos Position to draw the animation at.
      @author Nick Huber
      */
    GenericNPCEndingGraphicsComponent(const QPointF& pos)
        : EndingGraphicsComponent(pos) {
        emit created(this);
        redraw(1000, LAYER_DEFAULT);
    }

    /**
      Destructor.
      @author Nick Huber
      */
    virtual ~GenericNPCEndingGraphicsComponent() { }

    /**
      Initilize the pixmaps for this object.
      @author Nick Huber
      */
    virtual void initPixmaps();

    /**
      Get the pixmaps for this animation.

      @return Pointer to the pixmap images
      @author Nick Huber
      */
    virtual QPixmap* getPixmapArray() {
        return pixmapImgs_;
    }

protected:
    /**
      Timer event where the animation is done.

      @author Nick Huber
      */
    void timerEvent(QTimerEvent*);

private:
    /**
      Set the non-static data members for the pixmaps.

      @author Nick Huber
      */
    virtual void setNonStaticValues();

private:
    static QPixmap* pixmapImgs_; /**< static pixmaps for this ending. */
};


}

#endif
