/*!
 *  \file       door.cpp
 *  \brief      
 *  
 */


#include "door.hpp"

#include "room.hpp"
#include "user_exception.hpp"

Door::Door(Room* r1, Room* r2) : m_room1(r1), m_room2(r2)
{
}

Door::Door(const Door& rhs) : m_room1{rhs.m_room1}, m_room2{rhs.m_room2}
{
}

Door::~Door()
{
    if (m_room1 != nullptr)
    {
        delete m_room1;
    }
    if (m_room2 != nullptr)
    {
        delete m_room2;
    }
}

Door* Door::clone() const
{
    return new Door(*this);
}

void Door::enter()
{
    /*! \todo   implement this method later */
    throw UnimplementedException(std::string(__FUNCTION__));
}

DoorNeedingSpell::DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2)
{
}

DoorNeedingSpell::~DoorNeedingSpell()
{
}

DoorNeedingSpell* DoorNeedingSpell::clone() const
{
    return new DoorNeedingSpell(*this);
}