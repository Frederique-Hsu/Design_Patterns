/*!
 *  \file       room.hpp
 *  \brief      
 *  
 */

#pragma once

#include "map_site.hpp"

class Room : public MapSite
{
public:
    Room(int no = 0);
    virtual ~Room();

private:
    int m_room_no;
    MapSite* m_sides[4];
    
public:
    void setSide(Direction direction, MapSite* ms);
    int getRoomNumber();
    
    virtual Room* clone() const;
    virtual void enter() override;
};