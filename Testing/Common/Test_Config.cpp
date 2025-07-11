/*!
 *	\file		Test_Config.cpp
 *	\brief		Make the unit test for Common::Config class
 *	
 */


#include "Test_Config.hpp"


void TestConfig::SetUp()
{
}

void TestConfig::TearDown()
{
}

TEST_F(TestConfig, CheckFunction_readFromFilePathToString)
{
	std::cout << "Current config.xml is " << CONFIGURATION_XML_FILE << std::endl;

	std::string xml_content = Common::Config::readFromFilePathToString(CONFIGURATION_XML_FILE);
	EXPECT_NE(xml_content.size(), 0);
}

TEST_F(TestConfig, CheckFunction_isContainKey)
{
	std::string xml_content = Common::Config::readFromFilePathToString(CONFIGURATION_XML_FILE);

	bool is_success = configurator.readFromXmlString(xml_content.c_str());
	EXPECT_EQ(is_success, true);

	bool is_contain = configurator.isContainKey("host");
	EXPECT_EQ(is_contain, true);

	is_contain = configurator.isContainKey("check");
	EXPECT_EQ(is_contain, false);
}