/*!
 *  \file       maze_factory.hpp
 *  \brief      
 *  
 */


#pragma once

class Maze;
class Wall;
class Room;
class Door;
class Spell;

class MazeFactory
{
public:
    MazeFactory();
    virtual ~MazeFactory();
    
public:
    virtual Maze* makeMaze() const;
    virtual Wall* makeWall() const;
    virtual Room* makeRoom(int no) const;
    virtual Door* makeDoor(Room* r1, Room* r2) const;
};

class EnchantedMazeFactory : public MazeFactory
{
public:
    EnchantedMazeFactory();
    virtual ~EnchantedMazeFactory();
    
public:
    virtual Room* makeRoom(int no) const override;
    virtual Door* makeDoor(Room* r1, Room* r2) const override;
    
protected:
    Spell* castSpell() const;
};

class BombedMazeFactory : public MazeFactory
{
public:
    BombedMazeFactory();
    virtual ~BombedMazeFactory();
    
public:
    virtual Wall* makeWall() const override;
    virtual Room* makeRoom(int no) const override;
};