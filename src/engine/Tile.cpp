#include "Tile.h"
#include "Unit.h"

// Temp defines pending a map object
#define MAP_ROWS 99
#define MAP_COLS 99
#define TILE_HEIGHT 10
#define TILE_WIDTH 10

/**
  * The constructor for the tile class
  *
  * The tile class contains a tile's blocking property, its position in
  * the tile array (located in the map), and a set of units currently on
  * the tile.
  *
  * @author Luke Queenan
  *
  */
Tile::Tile(int column, int row, blockingType type)
{
    tileID_ = column * MAP_ROWS + row;
    type_ = type;
}

/**
  * Returns the tile's column position in the array
  *
  * @author Luke Queenan
  * @return The tile's column position in the array
  */
int Tile::getColumn()
{
    return tileID_ / MAP_ROWS;
}

/**
  * Returns the tile's row position in the array
  *
  * @author Luke Queenan
  * @return The tile's row position in the array
  */
int Tile::getRow()
{
    return tileID_ % MAP_COLS;
}

/**
  * Returns the tile's blocking type
  *
  * @author Luke Queenan
  * @return The tile's blocking type
  */
blockingType Tile::getType()
{
    return type_;
}

/**
  * Adds a pointer to a unit to this tile's list of units.
  *
  * @author Luke Queenan
  * @return void
  */
void Tile::addUnit(Unit *unitToAdd)
{
    currentUnits_.insert(unitToAdd);
}

/**
  * Removes a pointer to a unit from this tile's list of units.
  *
  * @author Luke Queenan
  * @return void
  */
void Tile::removeUnit(Unit *unitToRemove)
{
    currentUnits_.erase(unitToRemove);
}