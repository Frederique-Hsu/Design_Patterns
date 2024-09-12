/*!
 *  \file       maze.cpp
 *  \brief      
 *  
 */


#include "maze.hpp"

#include "room.hpp"

Maze::Maze() : m_rooms(new std::vector<Room*>)
{
}

Maze::~Maze()
{
    if (m_rooms != nullptr)
    {
        delete m_rooms;
    }
}

Room* Maze::roomNo(int no) const
{
    for (auto citer = m_rooms->cbegin(); citer != m_rooms->cend(); ++citer)
    {
        if ((*citer)->getRoomNumber() == no)
        {
            return *citer;
        }
    }
    return nullptr;
}

void Maze::addRoom(Room* room)
{
    m_rooms->push_back(room);
}

Maze* Maze::clone() const
{
    return new Maze(*this);
}