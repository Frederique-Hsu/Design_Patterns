/*!
 *  \file       room.cpp
 *  \brief      
 *  
 */


#include "room.hpp"

#include "user_exception.hpp"
#include "spell.hpp"

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

RoomWithABomb::RoomWithABomb(int no, bool bombed) : Room(no), m_has_bomb{bombed}
{
}

RoomWithABomb::~RoomWithABomb()
{
}

bool RoomWithABomb::hasBomb() const
{
    return m_has_bomb;
}

EnchantedRoom::EnchantedRoom(int room_no, Spell* magic_stick) : Room{room_no}, m_spell{magic_stick}
{
}

EnchantedRoom::~EnchantedRoom()
{
}