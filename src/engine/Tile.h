#ifndef TILE_H
#define TILE_H

// System includes
#include <QObject>
#include <set>

// Custom includes
#include "Unit.h"

enum blockingType {OPEN = 0, CLOSED = 1, NORTH_WEST = 2, NORTH_EAST = 3,
                   SOUTH_WEST = 4, SOUTH_EAST = 5};

class Tile : public QObject {
    Q_OBJECT

public:
    /**
     * Gets the unique class index for this object type.
     *
     * @author Darryl Pogue
     * @return The class index.
     */
    static unsigned char clsIdx() {
        return td::clsidx::kTile;
    }

public:
    Tile(int column, int row, blockingType type);
    virtual ~Tile() { }

    int getColumn();
    int getRow();
    void addUnit(Unit *unitToAdd);
    void removeUnit(Unit *unitToRemove);
    blockingType getType();

private:
    int tileID_;
    blockingType type_;
    std::set<Unit*> currentUnits_;
};

#endif
