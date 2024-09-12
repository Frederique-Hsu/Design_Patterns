/*!
 *  \file       room.cpp
 *  \brief      
 *  
 */


#include "room.hpp"

#include "user_exception.hpp"

Room::Room(int no) : MapSite(), m_room_no{no}, m_sides{nullptr, nullptr, nullptr, nullptr}
{
}

Room::~Room()
{
    for (auto index = 0U; index < sizeof(m_sides)/sizeof(MapSite*); ++index)
    {
        if (m_sides[index] != nullptr)
        {
            delete m_sides[index];
        }
    }
}

void Room::setSide(Direction direction, MapSite* ms)
{
    m_sides[static_cast<int>(direction)] = ms;
}

int Room::getRoomNumber()
{
    return m_room_no;
}

Room* Room::clone() const
{
    return new Room(*this);
}

void Room::enter()
{
    /*! \todo   implement this method later */
    throw UnimplementedException(std::string(__FUNCTION__));
}