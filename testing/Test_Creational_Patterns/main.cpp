/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include <iostream>

#include <CppUTest/CommandLineTestRunner.h>


int main(int argc, char* argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}


TEST_GROUP(UTester4CheckCppStandard)
{
};

TEST(UTester4CheckCppStandard, CheckCppStandardNo)
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits." << std::endl;

    CHECK(__cplusplus == 201703L);
}
