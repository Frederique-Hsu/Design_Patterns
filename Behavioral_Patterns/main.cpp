/*!
 *  \file       main.cpp
 *  \brief      Make the in-depth research on the Behavioral design patterns, this file is common file,
 *              which implements the main() portal for all sub-projects.
 *  \author     Frederique Hsu  (frederique.hsu@outlook.com)
 *  \date       Tue.    27 Aug. 2024
 *  \copyright  2024    All rights reserved.
 *  
 */


#include <gtest/gtest.h>

int main(int argc, char* argv[], char* envp[])
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}