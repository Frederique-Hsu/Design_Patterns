/*!
 *  \file       maze_game.hpp
 *  \brief      
 *  
 */


#pragma once

class Maze;
class MazeBuilder;

class MazeGame
{
public:
    Maze* createMaze(MazeBuilder& builder);
    Maze* createComplexMaze(MazeBuilder& builder);
};