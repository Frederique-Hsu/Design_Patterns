/*!
 *  \file       test_abstract_factory.cc
 *  \brief      
 *  
 */


#include "test_abstract_factory_pattern.hh"

#include "maze_game.hpp"
#include "maze_factory.hpp"
#include "maze.hpp"

BOOST_AUTO_TEST_SUITE(UTest4AbstractFactoryPattern)

    BOOST_AUTO_TEST_CASE(CreateBombMazeGameOverMazeFactory)
    {
        MazeGame game;
        BombedMazeFactory bomb_factory;
        
        Maze* maze = game.createMaze(bomb_factory);
        delete maze;
    }
    
    BOOST_AUTO_TEST_CASE(CreateEnchantedMazeGameOverMazeFactory)
    {
        MazeGame game;
        EnchantedMazeFactory enchanted_factory;
        
        game.createMaze(enchanted_factory);
    }
    
BOOST_AUTO_TEST_SUITE_END()