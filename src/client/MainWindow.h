#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include "../engine/GraphicsComponent.h"

namespace td {

class MainWindow : public QMainWindow {
    Q_OBJECT

private:

    /**
     * The graphics scene which contains all the objects
     */
    QGraphicsScene* scene_;

    /**
     * The view which displays the graphics scene.
     */
    QGraphicsView* view_;

public:
    MainWindow();
    virtual ~MainWindow();
    QGraphicsScene* getScene() { return scene_; }
    
protected:
    virtual bool event(QEvent*);
    
    /**
     * Deals with keyboard presses. Arrow keys are handled elsewhere.
     *
     * @author Dean Morin
     * @param event The key press event.
     */
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent *);

public slots:
    /**
     * Creates a graphical representation of a game object.
     * This creates a QGraphicsPixmapItem to be rendered, adds it to the
     * graphics scene, and stores it back in the graphics component of the
     * game object.
     *
     * @author Darryl Pogue
     * @param gc The GraphicsComponent of the game object.
     */
    void createGraphicRepr(GraphicsComponent* gc);

    /**
     * Draws the graphical representation of the game object.
     *
     * @author Darryl Pogue
     * @param gc The GraphicsComponent of the game object.
     */
    void drawItem(QPointF pos, GraphicsComponent* gc);
    
signals:
    void signalKeyPressed(int);
    void signalKeyReleased(int);
    void signalNumberPressed(int);
    void signalSpacebarPressed();
};

} /* end namespace td */

#endif
