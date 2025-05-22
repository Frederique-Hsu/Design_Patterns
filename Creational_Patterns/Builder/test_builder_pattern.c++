/*!
 *  \file       test_builder_pattern.c++
 *  \brief      
 *  
 */


#include "../select_test_framework.hpp"

#include "maze_builder.hpp"
#include "maze_game.hpp"
#include "maze.hpp"

#if (SELECT_TEST_FRAMEWORK == SELECT_BOOST_UNIT_TEST_FRAMEWORK)
    #include <boost/test/unit_test.hpp>

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
#elif (SELECT_TEST_FRAMEWORK == SELECT_CPPUTEST_FRAMEWORK)
    #include <CppUTest/TestHarness.h>

    TEST_GROUP(UTest4BuilderPattern)
    {
    };

    TEST(UTest4BuilderPattern, BuildMazeGameOverStandardMazeBuilder)
    {
        MazeGame game;
        StandardMazeBuilder builder;

        game.createMaze(builder);
        Maze* maze = builder.getMaze();

        CHECK(maze->roomNo(1) != nullptr);
        delete maze;
    }
#endif