#ifndef UNIT_H
#define UNIT_H

#include <QVector2D>
#include <QPointF>

#include "GameObject.h"
#include "PhysicsComponent.h"
#include "InputComponent.h"
#include "../graphics/GraphicsComponent.h"

class Unit : public GameObject {

public:
    /**
     * Gets the unique class index for this object type.
     *
     * @author Darryl Pogue
     * @return The class index.
     */
    static unsigned char clsIdx() {
        return td::clsidx::kUnit;
    }

public:
    Unit();
    virtual ~Unit();

    virtual void networkRead(td::Stream* s);
    virtual void networkWrite(td::Stream* s);

    /**
     * Inheriting classes need to define a method of setting their parent (owner) object.
     * 
     * @author Tom Nightingale
     */
    QVector2D& getVelocity();

    /**
     * Inheriting classes need to define a method of setting their parent (owner) object.
     * 
     * @author Tom Nightingale
     */
    void setVelocity(QVector2D&);

    /**
     * Inheriting classes need to define a method of setting their parent (owner) object.
     * 
     * @author Tom Nightingale
     */
    QVector2D getForce() {
        //qDebug("Unit::getForce: (%d, %d)", force_.x(), force_.y());
        return force_;
    }
    
    /**
     * Inheriting classes need to define a method of setting their parent (owner) object.
     * 
     * @author Tom Nightingale
     */
    void setForce(QVector2D& force) {
        force_.setX(force.x());
        force_.setY(force.y());
        //qDebug("Force: %d, %d", (int) force.x(), (int) force.y());
    }

    int getOrientation() {
        return orientation_;
    }

    void setOrientation(int orient) {
        orientation_ = orient;
    }

    float getScale() {
        return scale_;
    }

    void setScale(float scale) {
        scale_ = scale;
    }

    /**
     * Gets the InputComponent for this game unit.
     *
     * @author Darryl Pogue
     * @return The object's InputComponent.
     */
    InputComponent* getInputComponent() const {
        return input_;
    }

    /**
     * Sets the InputComponent for this game unit.
     *
     * @author Darryl Pogue
     * @param input The InputComponent to assign.
     */
    void setInputComponent(InputComponent* input) {
        input_ = input;
        input_->setParent(this);
    }

    /**
     * Gets the PhysicsComponent for this game unit.
     *
     * @author Darryl Pogue
     * @return The object's PhysicsComponent.
     */
    PhysicsComponent* getPhysicsComponent() const {
        return physics_;
    }

    /**
     * Sets the PhysicsComponent for this game unit.
     *
     * @author Darryl Pogue
     * @param physics The PhysicsComponent to assign.
     */
    void setPhysicsComponent(PhysicsComponent* physics) {
        physics_ = physics;
    }

    /**
     * Gets the GraphicsComponent for this game unit.
     *
     * @author Darryl Pogue
     * @return The object's GraphicsComponent.
     */
    GraphicsComponent* getGraphicsComponent() const {
        return graphics_;
    }

    /**
     * Sets the GraphicsComponent for this game unit.
     *
     * @author Darryl Pogue
     * @param graphics The GraphicsComponent to assign.
     */
    void setGraphicsComponent(GraphicsComponent* graphics) {
        graphics_ = graphics;
    }

protected:
    QVector2D velocity_;
    QVector2D force_;
    int orientation_;
    float scale_;

    InputComponent* input_;
    PhysicsComponent* physics_;
    GraphicsComponent* graphics_;
};

#endif
