/*!
 *  \file       main.cpp
 *  \brief      Make the in-depth research on the Structural design patterns, this file is common file,
 *              which implements the main() portal for all sub-projects.
 *  \author     Frederique Hsu  (frederique.hsu@outlook.com)
 *  \date       Tue.    27 Aug. 2024
 *  \copyright  2024    All rights reserved.
 *  
 */


#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>

int main(int argc, char* argv[])
{    
    return Catch::Session().run(argc, argv);
}

TEST_CASE("Unit testing for Structural Patterns", "[Structural_Patterns]")
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    CHECK(true);
}