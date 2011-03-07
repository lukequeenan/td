#ifndef PLAYERGRAPHICSCOMPONENT_H
#define PLAYERGRAPHICSCOMPONENT_H

#include <QObject>
#include <QPainter>
#include <QPointF>
#include "GraphicsComponent.h"

namespace td {

class PlayerGraphicsComponent : public GraphicsComponent {
    Q_OBJECT

public:
    /**
     * Instantiates a PlayerGraphicsComponent component
     * @author Warren Voelkl
     */
    PlayerGraphicsComponent();
    //virtual ~PlayerGraphicsComponent();

    /**
     * Loads a structure from the item and game component class then sends
     * the structure to the generic draw slot in GraphicsComponent.
     *
     * @author Warren Voelkl
     */
    virtual void update(GameObject* obj);

    /**
     * Gets a pixmap for the object based on its current animation state.
     *
     * @author Warren Voelkl
     */
    virtual void initPixmaps();

    /**
     * The primary method used to determine the behaviours of animation
     *
     * @author Warren Voelkl
     */
    virtual void animate();

private:
    /**
     * Slows down how often the images animate from the timer.
     */
    int animateMod;

    /**
     * The number of times the timer has ticked.
     */
    int animateCount;
};

} /* end namespace td */

#endif

