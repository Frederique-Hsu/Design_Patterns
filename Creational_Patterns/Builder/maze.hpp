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
    virtual ~Maze();
private:
    std::vector<Room*>* m_rooms;

public:
    Room* roomNo(int no) const;
    void addRoom(Room* room);
    
    virtual Maze* clone() const;
};