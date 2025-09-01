/*!
 *  \file       main.cpp
 *  \brief      Make the in-depth research on the Structural design patterns, this file is the common file,
 *              which implements the main() portal for all sub-projects.
 *  \author     Frederique Hsu  (frederique.hsu@outlook.com)
 *  \date       Tue.    27 Aug. 2024
 *  \copyright  2024    All rights reserved.
 *  
 */


#include <iostream>

int main(int argc, char* argv[])
{    
    (void)argc;
    (void)argv;
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    return EXIT_SUCCESS;
}
