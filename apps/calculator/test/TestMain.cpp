/*
 * TesMain.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <string>
#include <exception>
#include "stdlib.h"

//third party include
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "log/Logger.h"
#include "error/StackTraceUtils.h"



int main(int argc, char **argv) {
	LOG_CONF("debug", Logger::file_on | Logger::screen_on, Logger::LEVEL_TRACE,
			Logger::LEVEL_INFO);
	LOG(Logger::LEVEL_INFO, "Logging starts");

	StackTraceUtils::setupStackTraceAgent();

	std::cout << "Running main()" << std::endl;

	testing::GTEST_FLAG(throw_on_failure) = true;
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
