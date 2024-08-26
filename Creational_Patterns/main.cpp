/*!
 *  \file       main.cpp
 *  \brief      Make the in-depth research on the Creational design patterns, this file is common file,
 *              which implements the main() portal for all sub-projects.
 *  \author     Frederique Hsu  (frederique.hsu@outlook.com)
 *  \date       Tue.    27 Aug. 2024
 *  \copyright  2024    All rights reserved.
 *  
 */


#define BOOST_TEST_MODULE   "Unit testing for Creational Patterns"
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

int main(int argc, char* argv[])
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    
    return boost::unit_test::unit_test_main(init_unit_test, argc, argv);
}

BOOST_AUTO_TEST_CASE(UTest4CreationalPatterns)
{
    BOOST_CHECK(true);
}