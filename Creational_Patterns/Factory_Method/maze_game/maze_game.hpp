/*!
 *  \file       maze_game.hpp
 *  \brief      
 *  
 */


#pragma once


class Maze;
class Room;
class Wall;
class Door;

class MazeGame
{
public:
    virtual ~MazeGame() = default;
public:
    Maze* createMaze();
    
    // Factory methods
    virtual Maze* makeMaze() const;
    virtual Room* makeRoom(int room_no) const;
    virtual Wall* makeWall() const;
    virtual Door* makeDoor(Room* r1, Room* r2) const;
};

class BombedMazeGame : public MazeGame
{
public:
    BombedMazeGame();
    
public:
    virtual Wall* makeWall() const override;
    virtual Room* makeRoom(int room_no) const override;
};


class Spell;

class EnchantedMazeGame : public MazeGame
{
public:
    EnchantedMazeGame();

public:
    virtual Room* makeRoom(int room_no) const override;
    virtual Door* makeDoor(Room* r1, Room* r2) const override;

protected:
    Spell* castSpell() const;
};