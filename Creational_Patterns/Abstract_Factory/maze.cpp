/*!
 *  \file       maze.hpp
 *  \brief      
 *  
 */


#include "maze.hpp"

#if defined(DEBUG_WITH_LOG)
    #include <iostream>
#endif

#include "map_site.hpp"

Maze::Maze() : m_rooms(new std::vector<Room*>(0))
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Maze::Maze() constructor" << std::endl;
#endif
}

Maze::~Maze()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Maze::~Maze() destructor" << std::endl;
#endif
}

void Maze::addRoom(Room* room)
{
    m_rooms->push_back(room);
}

Room* Maze::roomNo(int no) const
{
    for (auto iter = m_rooms->begin(); iter != m_rooms->end(); ++iter)
    {
        if (no == (*iter)->getRoomNo())
        {
            return (*iter);
        }
    }
    return nullptr;
}