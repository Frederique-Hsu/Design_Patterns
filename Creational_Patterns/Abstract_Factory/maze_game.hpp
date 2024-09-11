/*!
 *  \file       maze_game.hpp
 *  \brief      
 *  
 */


#pragma once

class Maze;
class MazeFactory;

class MazeGame
{
public:
    MazeGame();
    ~MazeGame();
public:
    Maze* createMaze(MazeFactory& factory);
};