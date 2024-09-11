/*!
 *  \file       map_site.cpp
 *  \brief      
 *  
 */


#include "map_site.hpp"

#if defined(DEBUG_WITH_LOG)
    #include <iostream>
#endif

#include "spell.hpp"

MapSite::MapSite()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "MapSite::MapSite() constructor" << std::endl;
#endif
}

MapSite::~MapSite()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "MapSite::~MapSite() destructor" << std::endl;
#endif
}

Room::Room(int room_no) : MapSite(), m_room_number{room_no}
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Room::Room() constructor" << std::endl;
#endif
}

Room::~Room()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Room::~Room() destructor" << std::endl;
#endif
}

MapSite* Room::getSide(Direction direction) const
{
    return m_sides[static_cast<int>(direction)];
}

void Room::setSide(Direction direction, MapSite* side)
{
    m_sides[static_cast<int>(direction)] = side;
}

int Room::getRoomNo() const
{
    return m_room_number;
}

void Room::enter()
{
    /*! \todo   implement this method later */
}


Wall::Wall() : MapSite()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Wall::Wall() constructor" << std::endl;
#endif
}

Wall::~Wall()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Wall::~Wall() destructor" << std::endl;
#endif
}

void Wall::enter()
{
    /*! \todo   implement this method later */
}

Door::Door(Room* r1, Room* r2) : MapSite(), m_room1{r1}, m_room2{r2}, m_is_open(bool{})
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Door::Door() constructor" << std::endl;
#endif
}

Door::~Door()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "Door::~Door() destructor" << std::endl;
#endif
}

void Door::enter()
{
    /*! \todo   implement this method later */
}

EnchantedRoom::EnchantedRoom(int room_no, Spell* magic_stick) : Room{room_no}, m_spell{magic_stick}
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "EnchantedRoom::EnchantedRoom() constructor" << std::endl;
#endif
}

EnchantedRoom::~EnchantedRoom()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "EnchantedRoom::~EnchantedRoom() destructor" << std::endl;
#endif
}

DoorNeedingSpell::DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2)
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "DoorNeedingSpell::DoorNeedingSpell() constructor" << std::endl;
#endif
}

DoorNeedingSpell::~DoorNeedingSpell()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "DoorNeedingSpell::~DoorNeedingSpell() destructor" << std::endl;
#endif
}

BombedWall::BombedWall() : m_has_bomb(bool{})
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "BombedWall::BombedWall() constructor" << std::endl;
#endif
}

BombedWall::~BombedWall()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "BombedWall::~BombedWall() destructor" << std::endl;
#endif
}

bool BombedWall::hasBomb() const
{
    return m_has_bomb;
}

RoomWithABomb::RoomWithABomb(int no, bool bombed) : Room(no), m_has_bomb{bombed}
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "RoomWithABomb::RoomWithABomb() constructor" << std::endl;
#endif
}

RoomWithABomb::~RoomWithABomb()
{
#if defined(DEBUG_WITH_LOG)
    std::clog << "RoomWithABomb::~RoomWithABomb() destructor" << std::endl;
#endif
}

bool RoomWithABomb::hasBomb() const
{
    return m_has_bomb;
}