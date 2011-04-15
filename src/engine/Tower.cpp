#include "Tower.h"
#ifndef SERVER
#include "CDriver.h"
#endif
#include "Effect.h"
#include "../graphics/TowerGraphicsComponentTypes.h"
#include "../physics/TowerPhysicsComponentTypes.h"
#include "../util/defines.h"

namespace td {

Tower::Tower(QObject* parent) : TileExtension(parent) { }

void Tower::update() {
    if (physics_ != NULL) {
        physics_->update(this);
    }

    if (isDirty()) {
        getDriver()->update(this);
    }

    if (graphics_ != NULL) {
        graphics_->update(this);
    }
}

void Tower::networkRead(Stream* s) {
    TileExtension::networkRead(s);
    
    if (dirty_ & kType) {
        type_ = s->readInt();
    }
}

void Tower::networkWrite(Stream* s) {
    TileExtension::networkWrite(s);

    if (dirty_ & kType) {
        s->writeInt(type_);
    }
}

void Tower::initComponents() {
    switch (type_) {
        case TOWER_ARROW:
            setPhysicsComponent(new ArrowTowerPhysicsComponent(this));
#ifndef SERVER
            setGraphicsComponent(new ArrowTowerGraphicsComponent());
#endif
            break;
        case TOWER_CANNON:
            setPhysicsComponent(new CannonTowerPhysicsComponent(this));
#ifndef SERVER
            setGraphicsComponent(new CannonTowerGraphicsComponent());
#endif
            break;
        case TOWER_FLAME:
            setPhysicsComponent(new FlameTowerPhysicsComponent(this));
#ifndef SERVER
            setGraphicsComponent(new FlameTowerGraphicsComponent());
#endif
            break;
        case TOWER_TAR:
            setPhysicsComponent(new TarTowerPhysicsComponent(this));
#ifndef SERVER
            setGraphicsComponent(new TarTowerGraphicsComponent());
#endif
            break;
        case TOWER_FLAK:
            setPhysicsComponent(new FlakTowerPhysicsComponent(this));
#ifndef SERVER
            setGraphicsComponent(new FlakTowerGraphicsComponent());
#endif
            break;
    }
#ifndef SERVER
    connect(CDriver::instance()->getMainWindow(), SIGNAL(signalAltHeld(bool)),
                getGraphicsComponent(), SLOT(setVisibleRange(bool)));
#endif
}

} // end of namespace td

