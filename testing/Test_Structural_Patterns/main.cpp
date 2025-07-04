/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include <iostream>

#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}

TEST_CASE("Unit Test 4 checking C++ standard", "[cpp-std-no]")
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits." << std::endl;

    CHECK(__cplusplus == 201703L);
}
