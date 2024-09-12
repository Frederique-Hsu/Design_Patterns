/*!
 *  \file       maze_game.cpp
 *  \brief      
 *  
 */


#include "maze_game.hpp"

#include "maze.hpp"
#include "maze_builder.hpp"

Maze* MazeGame::createMaze(MazeBuilder& builder)
{
    builder.buildMaze();
    builder.buildRoom(1);
    builder.buildRoom(2);
    builder.buildDoor(1, 2);
    
    return builder.getMaze();
}

Maze* MazeGame::createComplexMaze(MazeBuilder& builder)
{
    builder.buildRoom(1);
    // .... build more rooms
    builder.buildRoom(100);
    
    return builder.getMaze();
}