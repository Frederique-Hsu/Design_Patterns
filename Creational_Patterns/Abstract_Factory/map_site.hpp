/*!
 *  \file       map_site.hpp
 *  \brief      Create a maze game, define the interface MapSite.
 *  
 */


#pragma once


class MapSite
{
public:
    MapSite();
    virtual ~MapSite();
public:
    virtual void enter() = 0;
};

enum class Direction
{
    kNorth,
    kSouth,
    kEast,
    kWest
};

class Room : public MapSite
{
public:
    Room(int room_no);
    virtual ~Room();
private:
    MapSite* m_sides[4];
    int m_room_number;
public:
    MapSite* getSide(Direction) const;
    void setSide(Direction, MapSite*);
    int getRoomNo() const;
    
    virtual void enter() override;
};

class Wall : public MapSite
{
public:
    Wall();
    virtual ~Wall();
public:
    virtual void enter() override;
};

class Door : public MapSite
{
public:
    Door(Room* = nullptr, Room* = nullptr);
    virtual ~Door();
private:
    Room* m_room1;
    Room* m_room2;
    bool m_is_open;
public:
    Room* otherSideFrom(Room*);
    
    virtual void enter() override;
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

class DoorNeedingSpell : public Door
{
public:
    DoorNeedingSpell(Room* r1, Room* r2);
    virtual ~DoorNeedingSpell();
};

class BombedWall : public Wall
{
public:
    BombedWall();
    virtual ~BombedWall();
private:
    bool m_has_bomb;
public:
    bool hasBomb() const;
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