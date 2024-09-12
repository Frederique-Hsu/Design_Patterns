/*!
 *  \file       maze_builder.hpp
 *  \brief      
 *  
 */


#pragma once


class Maze;
class Room;

enum class Direction;

class MazeBuilder
{
public:
    virtual void buildMaze();
    virtual void buildRoom(int room_no);
    virtual void buildDoor(int from_room_no, int to_room_no);
    
    virtual Maze* getMaze();
    
protected:
    MazeBuilder();
};

class StandardMazeBuilder : public MazeBuilder
{
public:
    StandardMazeBuilder();
    
private:
    Maze* m_current_maze;
    
public:
    virtual void buildMaze() override;
    virtual void buildRoom(int room_no) override;
    virtual void buildDoor(int from_room_no, int to_room_no) override;
    
    virtual Maze* getMaze() override;
    
private:
    Direction commonWall(Room*, Room*);
};

class CountingMazeBuilder : public MazeBuilder
{
public:
    CountingMazeBuilder();
    
private:
    int m_doors;
    int m_rooms;
    
public:
    virtual void buildMaze() override;
    virtual void buildRoom(int) override;
    virtual void buildDoor(int, int) override;
    
    void getCounts(int& rooms_count, int& doors_count) const;
};