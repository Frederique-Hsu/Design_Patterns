/*!
 *  \file       maze.hpp
 *  \brief      
 *  
 */


#pragma once

#include <vector>

class Room;

class Maze
{
public:
    Maze();
    ~Maze();
private:
    std::vector<Room*>* m_rooms;
public:
    void addRoom(Room*);
    Room* roomNo(int) const;
};