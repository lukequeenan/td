#ifndef TOWERPHYSICSCOMPONENT_H
#define TOWERPHYSICSCOMPONENT_H

#include "PhysicsComponent.h"
#include "../engine/NPC.h"
#include "../engine/Map.h"
#include "../engine/Driver.h"
#include <QLineF>
#include <QPointF>
#include <QSet>
#include <QtDebug>

namespace td {

class Tower;

/** Movement Physics for basic Tower */
class TowerPhysicsComponent: public PhysicsComponent {
    Q_OBJECT

public:
    TowerPhysicsComponent(Tower* tower, size_t fireInterval, int radius,
            int projType);
    virtual ~TowerPhysicsComponent();

    /**
     * Applies a direction to the position.
     * This function uses velocity to find angle, pos
     *
     * @author Joel Stewart
     * @param Tower, pointer to the Tower object
     */
    void applyDirection(GameObject* tower);

    /**
     * This updates the physics properties of Tower.
     */
    virtual void update(GameObject* tower);

    /**
     * Finds the next target. Once a target is aquired, it remains the target
     * until it gets out of range. At that point, the new target will be the 
     * first in the enemies_ set.
     *
     * @author Joel Stewart, Dean Morin
     */
    void findTarget();

    /**
     * Checks to see if the tower can fire, and creates a projectile if it can.
     *
     * @author Dean Morin
     */
    virtual void fire();

    /**
     * returns current enemies in sight.
     *
     * @author Joel Stewart
     */
    QSet<Unit*> getEnemies() {
        return enemies_;
    }

    /**
     * Set current Target
     *
     * @author Joel Stewart
     * @param Unit, pointer to target your setting
     */
    void setTarget(Unit* target) {
        target_ = target;
    }

    /**
     * gets current target.
     *
     * @author Joel Stewart
     * @return current target
     */
    Unit* getTarget() {
        return target_;
    }

    /**
     * Sets radius value of tower.
     *
     * @author Joel Stewart
     * @param radius sets radius_
     */
    void setRadius(int radius) {
        radius_ = radius;
    }

    /**
     * returns radius value of the tower
     *
     * @author Joel Stewart
     * @return radius value
     */
    int getRadius() {
        return radius_;
    }

    /**
     * Sets fire interval value of tower.
     *
     * @author Marcel Vangrootheest
     * @param fireInterval sets fireInterval_
     */
    void setFireInterval(size_t fireInterval) {
        fireInterval_ = fireInterval;
    }

    /**
     * returns fireInterval value of the tower
     *
     * @author Marcel Vangrootheest
     * @return fire interval value
     */
    int getFireInterval() {
        return fireInterval_;
    }

    /**
     * Sets the projectile type the tower will fire.
     *
     * @author Marcel Vangrootheest
     * @param projType sets projType_
     */
    void setProjType(int projType) {
        projType_ = projType;
    }

    /**
     * Returns the projetile type the tower will fire.
     *
     * @author Marcel Vangrootheest
     * @return projectile type
     */
    int getProjType() {
        return projType_;
    }

    virtual bool isValidTarget(Unit*) = 0;

protected:
    /** The line between the tower and its current target. */
    QLineF projectilePath_;
    
    /** All enemies that are potentially in range of the tower. */
    QSet<Unit*> enemies_;

    /** The tower that this component defines. */
    Tower* tower_;

    /** The enemy that's currently being tracked by the tower. */
    Unit* target_;

    /** The number of ticks beween each shot. */
    size_t fireInterval_;

    /** The range of the tower. */
    int radius_;

    /** The projectile type that the tower will fire. */
    int projType_;
    
    /** Number of game timer ticks before this tower can fire a projectile. */
    size_t fireCountdown_;

signals:
    /**
     * Connected to the createProjectile() slot in CDriver.
     *
     * @author Dean Morin
     * @param source The position of the tower firing the projectile.
     * @param target The current position of the enemy that the tower has 
     * tageted.
     */
    void fireProjectile(int projType, QPointF source, QPointF target,
            Unit* enemy);

public slots:
    /**
     * Sets the target_ member to null if the NPC dies.
     *
     * Connected to signalNPCDied() in the NPC class.
     *
     * @author Dean Morin
     */
    void targetDied();
};

} /* end namespace td */

#endif
