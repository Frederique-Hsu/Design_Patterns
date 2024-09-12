/*!
 *  \file       test_builder_pattern.c++
 *  \brief      
 *  
 */


#include <boost/test/unit_test.hpp>

#include "maze_builder.hpp"
#include "maze_game.hpp"
#include "maze.hpp"

BOOST_AUTO_TEST_SUITE(UTest4BuilderPattern)

    BOOST_AUTO_TEST_CASE(BuildMazeGameOverStandardMazeBuilder)
    {
        MazeGame game;
        StandardMazeBuilder builder;
        
        game.createMaze(builder);
        Maze* maze = builder.getMaze();
        
        BOOST_CHECK(maze->roomNo(1) != nullptr);
        
        delete maze;
    }
    
    BOOST_AUTO_TEST_CASE(BuildeMazeGameOverCountingMazeBuilder)
    {
        MazeGame game;
        CountingMazeBuilder builder;
        
        int rooms_count{0}, doors_count{0};
        game.createMaze(builder);
        builder.getCounts(rooms_count, doors_count);
        
        std::cout << "The maze has " << rooms_count << " rooms, and "
                  << doors_count << " doors." << std::endl;
        BOOST_CHECK_EQUAL(rooms_count, 3);
        BOOST_CHECK_EQUAL(doors_count, 1);
    }

BOOST_AUTO_TEST_SUITE_END()