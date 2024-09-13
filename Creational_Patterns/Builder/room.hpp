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

class RoomWithABomb : public Room
{
public:
    RoomWithABomb(int no = 0, bool bombed = false);
    virtual ~RoomWithABomb();
private:
    bool m_has_bomb;
public:
    bool hasBomb() const;
};

class Spell;

class EnchantedRoom : public Room
{
public:
    EnchantedRoom(int room_no, Spell* magic_stick);
    virtual ~EnchantedRoom();
private:
    Spell* m_spell;
};