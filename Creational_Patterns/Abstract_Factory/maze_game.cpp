/*!
 *  \file       maze_game.cpp
 *  \brief      
 *  
 */


#include "maze_game.hpp"

#if defined(DEBUG_WITH_LOG)
    #include <iostream>
#endif

#include "maze.hpp"
#include "map_site.hpp"
#include "maze_factory.hpp"

MazeGame::MazeGame()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "MazeGame::MazeGame() constructor" << std::endl;
#endif
}

MazeGame::~MazeGame()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "MazeGame::~MazeGame() destructor" << std::endl;
#endif
}

Maze* MazeGame::createMaze(MazeFactory& factory)
{
    Maze* maze = factory.makeMaze();
    
    Room* r1 = factory.makeRoom(1);
    Room* r2 = factory.makeRoom(2);
    
    Door* door = factory.makeDoor(r1, r2);
    
    maze->addRoom(r1);
    maze->addRoom(r2);
    
    r1->setSide(Direction::kNorth, factory.makeWall());
    r1->setSide(Direction::kEast, door);
    r1->setSide(Direction::kSouth, factory.makeWall());
    r1->setSide(Direction::kWest, factory.makeWall());
    
    r2->setSide(Direction::kNorth, factory.makeWall());
    r2->setSide(Direction::kEast, factory.makeWall());
    r2->setSide(Direction::kSouth, factory.makeWall());
    r2->setSide(Direction::kWest, door);
    
    return maze;
}