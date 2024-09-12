/*!
 *  \file       door.hpp
 *  \brief      
 *  
 */


#pragma once

#include "map_site.hpp"


class Room;

class Door : public MapSite
{
public:
    Door(Room* r1 = nullptr, Room* r2 = nullptr);
    Door(const Door& rhs);
    virtual ~Door();
    
private:
    Room* m_room1;
    Room* m_room2;
    
public:
    virtual Door* clone() const;
    virtual void enter() override;
};