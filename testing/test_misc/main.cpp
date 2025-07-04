/*!
 *  \file       main.cpp
 *  \brief      Make some unit testing about user's misc. code snippets
 *
 */


#include <gtest/gtest.h>


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(UTester4CheckCppStandard, CheckCppStandardNo)
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits." << std::endl;

    EXPECT_EQ(__cplusplus, 201703L);
}
