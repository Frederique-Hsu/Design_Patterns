/*!
 *	\file		Test_Logger.cpp
 *	\brief		
 *	
 */


#include <gtest/gtest.h>

#include "Common/Logger.h"


class UTester4Logger : public ::testing::Test
{
public:
	void SetUp() override
	{

	}
	void TearDown() override
	{
		logger.clearLogs();
		logger.setLogLevel(Common::Logger::HZLogLevel::LL_INFO);

	}

protected:
	Common::Logger& logger = Common::Logger::inst();
};

TEST_F(UTester4Logger, CheckFunctions_setLogLevel_getLogLevel)
{
	logger.setLogLevel(Common::Logger::HZLogLevel::LL_DEBUG);

	Common::Logger::HZLogLevel log_level = logger.getLogLevel();

	EXPECT_EQ(log_level, Common::Logger::HZLogLevel::LL_DEBUG);

	logger.setLogLevel(Common::Logger::HZLogLevel::LL_ERROR);
	EXPECT_EQ(logger.getLogLevel(), Common::Logger::HZLogLevel::LL_ERROR);
}

TEST_F(UTester4Logger, CheckFunction_getLogs)
{
	using namespace Common;

	logger.debug("This is a debug log message");
	logger.info("This is a normal information message");
	logger.warn("Your compilation has a warning");
	logger.error("An error occurred during running");

	std::vector<Common::Logger::LogEntry> logs = logger.getLogs();
	EXPECT_EQ(logs.size(), 4);

	EXPECT_EQ(logs[0].level, Logger::HZLogLevel::LL_DEBUG);
	EXPECT_EQ(logs[1].level, Logger::HZLogLevel::LL_INFO);
	EXPECT_EQ(logs[2].level, Logger::HZLogLevel::LL_WARN);
	EXPECT_EQ(logs[3].level, Logger::HZLogLevel::LL_ERROR);

	std::printf("File name: %s, Function name: %s", __FILE__, __FUNCTION__);

	logger.fatal("Encountering a fatal error at: %s %s", __FILE__, __FUNCTION__);
	EXPECT_EQ(logs.size(), 5);
	/*
	EXPECT_EQ(logs[4].level, Logger::HZLogLevel::LL_FATAL);
	std::cout << "The fatal error message is: " << logs[4].message << std::endl;
	 */
}

TEST_F(UTester4Logger, CheckFunction_getLogs_AllLogLevel)
{

}

TEST_F(UTester4Logger, CheckFunction_getLastLog)
{
	using namespace Common;

	logger.debug("This is a debug log message");
	logger.info("This is a normal information message");

	std::string latest_log = logger.getLastLog();
	EXPECT_STREQ(latest_log.c_str(), "This is a normal information message");

	/*
	logger.fatal("Program occurs a fatal error.");
	EXPECT_EQ(logger.getLogs().size(), 3);
	EXPECT_STREQ(logger.getLastLog().c_str(), "Program occurs a fatal error.");
	 */
}

TEST_F(UTester4Logger, CheckFunction_clearLogs)
{
	using namespace Common;

	logger.debug("This is a debug log message");
	logger.info("This is a normal information message");
	logger.warn("Your compilation has a warning");

	EXPECT_EQ(logger.getLogs().size(), 3);

	logger.clearLogs();
	EXPECT_EQ(logger.getLogs().size(), 0);
}