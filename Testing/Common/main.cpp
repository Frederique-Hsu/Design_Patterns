/*!
 *	\file		main.cpp
 *	\brief		Main entry point for the application.
 *	\author		Frederique Hsu
 *	\date		Mon.	07 Jul. 2025
 *	\copyright	Copyright (c) 2025	Hozone Automation Co.
 *	
 */



#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(UTester4CppStanadrd, CheckCppStandardNo)
{
	std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
	std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

	EXPECT_EQ(__cplusplus, 201703L);
}