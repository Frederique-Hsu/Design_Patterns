/*!
 *	\file		main.cpp
 *	\brief		
 *	
 */


#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}


TEST_CASE("Make the unit test for C++ standard", "[check_cpp_std_no]")
{
	std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
	std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

	CHECK(__cplusplus == 201703L);
}