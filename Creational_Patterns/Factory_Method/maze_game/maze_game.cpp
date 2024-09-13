/*!
 *  \file       maze_game.cpp
 *  \brief      
 *  
 */


#include "maze_game.hpp"

#include "../../Builder/maze.hpp"
#include "../../Builder/room.hpp"
#include "../../Builder/wall.hpp"
#include "../../Builder/door.hpp"
#include "../../Builder/spell.hpp"


Maze* MazeGame::makeMaze() const
{
    return new Maze;
}

Room* MazeGame::makeRoom(int room_no) const
{
    return new Room(room_no);
}

Wall* MazeGame::makeWall() const
{
    return new Wall;
}

Door* MazeGame::makeDoor(Room* r1, Room* r2) const
{
    return new Door(r1, r2);
}

Maze* MazeGame::createMaze()
{
    Maze* maze = makeMaze();
    
    Room* r1 = makeRoom(1);
    Room* r2 = makeRoom(2);
    Door* door = makeDoor(r1, r2);
    
    maze->addRoom(r1);
    maze->addRoom(r2);
    
    r1->setSide(Direction::kNorth, makeWall());
    r1->setSide(Direction::kEast, door);
    r1->setSide(Direction::kSouth, makeWall());
    r1->setSide(Direction::kWest, makeWall());
    
    r2->setSide(Direction::kNorth, makeWall());
    r2->setSide(Direction::kEast, makeWall());
    r2->setSide(Direction::kSouth, makeWall());
    r2->setSide(Direction::kWest, door);
    
    return maze;
}

BombedMazeGame::BombedMazeGame() : MazeGame()
{
}

Wall* BombedMazeGame::makeWall() const
{
    return new BombedWall;
}

Room* BombedMazeGame::makeRoom(int room_no) const
{
    return new RoomWithABomb;
}

EnchantedMazeGame::EnchantedMazeGame() : MazeGame()
{
}

Room* EnchantedMazeGame::makeRoom(int room_no) const
{
    return new EnchantedRoom(room_no, castSpell());
}

Spell* EnchantedMazeGame::castSpell() const
{
    return new Spell;
}

Door* EnchantedMazeGame::makeDoor(Room* r1, Room* r2) const
{
    return new DoorNeedingSpell(r1, r1);
}