#ifndef TD_TOWER_H
#define TD_TOWER_H

#include "TileExtension.h"

namespace td {

class Effect;

class Tower : public TileExtension {
    Q_OBJECT

public:
    /**
     * Gets the unique class index for this object type.
     *
     * @author Darryl Pogue
     * @return The class index.
     */
    static unsigned char clsIdx() {
        return td::clsidx::kTower;
    }

public:
    Tower(QObject* parent = 0);
    virtual ~Tower() {}
    virtual void initComponents();
    virtual void update();

    /**
     * Sets the tower type (arrow, cannon, tar, flame, or flak).
     *
     * @author Darryl Pogue
     * @param The type of tower.
     */
    void setType(int type) {
        type_ = type;
    }

private:
    int type_;
};

} // end of namespace td

#endif

