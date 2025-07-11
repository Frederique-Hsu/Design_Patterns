/*!
 *	\file		Test_Config.hpp
 *	\brief		Define the unit test class TestConfig
 *	
 */


#pragma once

#include <gtest/gtest.h>

#include "Common/Config.h"

class TestConfig : public ::testing::Test
{
public:
	void SetUp() override;
	void TearDown() override;

protected:
	Common::Config& configurator = Common::Config::inst();
};