/*!
 *  \file       maze_factory.cpp
 *  \brief      
 *  
 */


#include "maze_factory.hpp"

#if defined(DEBUG_WITH_LOG)
    #include <iostream>
#endif

#include "maze.hpp"
#include "map_site.hpp"
#include "spell.hpp"

MazeFactory::MazeFactory()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "MazeFactory::MazeFactory() constructor" << std::endl;
#endif
}

MazeFactory::~MazeFactory()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "MazeFactory::~MazeFactory() destructor" << std::endl;
#endif
}

Maze* MazeFactory::makeMaze() const
{
    return new Maze;
}

Wall* MazeFactory::makeWall() const
{
    return new Wall;
}

Room* MazeFactory::makeRoom(int no) const
{
    return new Room(no);
}

Door* MazeFactory::makeDoor(Room* r1, Room* r2) const
{
    return new Door(r1, r2);
}

EnchantedMazeFactory::EnchantedMazeFactory() : MazeFactory()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "EnchantedMazeFactory::EnchantedMazeFactory() constructor" << std::endl;
#endif
}

EnchantedMazeFactory::~EnchantedMazeFactory()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "EnchantedMazeFactory::~EnchantedMazeFactory() destructor" << std::endl;
#endif
}

Room* EnchantedMazeFactory::makeRoom(int no) const
{
    return new EnchantedRoom(no, castSpell());
}

Spell* EnchantedMazeFactory::castSpell() const
{
    return new Spell;
}

Door* EnchantedMazeFactory::makeDoor(Room* r1, Room* r2) const
{
    return new DoorNeedingSpell(r1, r2);
}

BombedMazeFactory::BombedMazeFactory() : MazeFactory()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "BombedMazeFactory::BombedMazeFactory() constructor" << std::endl;
#endif
}

BombedMazeFactory::~BombedMazeFactory()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "BombedMazeFactory::~BombedMazeFactory() destructor" << std::endl;
#endif
}

Wall* BombedMazeFactory::makeWall() const
{
    return new BombedWall;
}

Room* BombedMazeFactory::makeRoom(int no) const
{
    return new RoomWithABomb(no);
}