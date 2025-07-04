/*!
 *  \file       check_scoped_enum.cpp
 *  \brief
 *
 */


#include "check_scoped_enum.hpp"

#include <gtest/gtest.h>

TEST(UTester7ScopedEnum, CheckScopedEnumDefinedInsideNamespace)
{
    details::EndiannessType endian{};

    EXPECT_EQ(sizeof(endian), 1);
    EXPECT_EQ(endian, details::EndiannessType::SEP_LITTLE_ENDIAN);
}
