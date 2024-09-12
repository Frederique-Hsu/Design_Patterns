/*!
 *  \file       maze_builder.cpp
 *  \brief      
 *  
 */


#include "maze_builder.hpp"

#include "maze.hpp"
#include "room.hpp"
#include "wall.hpp"
#include "door.hpp"

void MazeBuilder::buildMaze()
{
}

void MazeBuilder::buildRoom(int room_no)
{
    (void)room_no;
}

void MazeBuilder::buildDoor(int from_room_no, int to_room_no)
{
    (void)from_room_no;
    (void)to_room_no;
}

Maze* MazeBuilder::getMaze()
{
    return nullptr;
}

MazeBuilder::MazeBuilder()
{
}

StandardMazeBuilder::StandardMazeBuilder() : MazeBuilder(), m_current_maze{nullptr}
{
}

void StandardMazeBuilder::buildMaze()
{
    m_current_maze = new Maze;
}

void StandardMazeBuilder::buildRoom(int room_no)
{
    if (!m_current_maze->roomNo(room_no))
    {
        Room* room = new Room(room_no);
        m_current_maze->addRoom(room);
        
        room->setSide(Direction::kNorth, new Wall);
        room->setSide(Direction::kSouth, new Wall);
        room->setSide(Direction::kEast, new Wall);
        room->setSide(Direction::kWest, new Wall);
    }
}

void StandardMazeBuilder::buildDoor(int from_room_no, int to_room_no)
{
    Room* r1 = m_current_maze->roomNo(from_room_no);
    Room* r2 = m_current_maze->roomNo(to_room_no);
    
    Door* door = new Door(r1, r2);
    r1->setSide(commonWall(r1, r2), door);
    r2->setSide(commonWall(r2, r1), door);
}

Maze* StandardMazeBuilder::getMaze()
{
    return m_current_maze;
}

Direction StandardMazeBuilder::commonWall(Room* r1, Room* r2)
{
    if (r1->getRoomNumber() < r2->getRoomNumber())
    {
        return Direction::kEast;
    }
    else
    {
        return Direction::kWest;
    }
}

CountingMazeBuilder::CountingMazeBuilder() : m_doors{0}, m_rooms{0}
{
}

void CountingMazeBuilder::buildMaze()
{
}

void CountingMazeBuilder::buildRoom(int room_no)
{
    m_rooms += room_no;
}

void CountingMazeBuilder::buildDoor(int, int)
{
    m_doors++;
}

void CountingMazeBuilder::getCounts(int& rooms_count, int& doors_count) const
{
    rooms_count = m_rooms;
    doors_count = m_doors;
}