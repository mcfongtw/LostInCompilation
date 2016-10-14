/*
 * Test_Utility_Logger.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */
#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
#include "error/Exception.h"


/*
 * TODO: Think of a way to test Logger
 * i.e. Logging some messages into a file and compare contents by string-match.
 */
TEST(LOGGER, Simple_Logging) {
	LOG(Logger::LEVEL_TRACE, "This is a TRACE message");
	LOG(Logger::LEVEL_DEBUG, "This is a DEBUG message");
	LOG(Logger::LEVEL_INFO, "This is a INFO message");
	LOG(Logger::LEVEL_WARN, "This is a WARN message");
	LOG(Logger::LEVEL_ERROR, "This is a ERROR message");
}

void throwExceptionPleaseCatch() {
	throw IllegalStateException("Test");
}

TEST(LOGGER, Exception_Logging) {
	try {
		throwExceptionPleaseCatch();
	} catch(Exception& e) {
		LOG_ERROR(e.what());
	}
}
