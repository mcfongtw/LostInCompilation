/*
 * Logger.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#include "log/Logger.h"

#include <iostream>
#include <sstream>
#include <new>
#include <cstdlib>

#include "common/Utils.h"
#include "error/Exception.h"

Logger* Logger::INSTANCE = nullptr;

Logger::Logger() :
		_isConfigured(false) {
	gettimeofday(&this->_initTime, NULL);
}

Logger::~Logger() {
	if (this->_configOption & file_on) {
		this->_out.close();
	}

	delete INSTANCE;
}

Logger* Logger::getInstance() {
	if (INSTANCE == 0) {
		INSTANCE = new Logger();
	}

	return INSTANCE;
}

void Logger::configure(const std::string& outputFileNamePrefix,
		Logger::LogConfigOption option, Logger::LogLevel fileVerbosityLevel,
		Logger::LogLevel screenVerbosityLevel) {
	this->_fileVerbosityLevel = fileVerbosityLevel;
	this->_screenVerbosityLevel = screenVerbosityLevel;

	// Close the old stream, if needed
	if (this->_configOption & file_on) {
		this->_out.close();
	}

	// Compute a new file name, if needed
	if (outputFileNamePrefix != this->_logFileName) {
		std::ostringstream oss;
		time_t currentTime;
		time(&currentTime);
		struct tm *currTm = localtime(&currentTime);
		oss << outputFileNamePrefix << "_" << (currTm->tm_mon + 1) << "_"
				<< (currTm->tm_mday) << "_" << (1900 + currTm->tm_year)
				<< ".log";
		this->_logFileName = oss.str().c_str();
	}

	// Open a new stream, if needed
	if (option & file_on) {

		if (option & file_append) {
			this->_out.open(this->_logFileName.c_str(), std::ios::app);
		} else {
			this->_out.open(this->_logFileName.c_str());
		}

	}
	this->_configOption = option;
	this->_isConfigured = true;
}

void Logger::print(Logger::LogLevel verbosityLevel, const char* fileName,
		const int codeLineNum, const std::string& message) {
	if (this->_isConfigured == false) {
		std::cerr << "ERROR: Logger not configured!" << std::endl;
		return;
	}
	time_t currentTime;
	time(&currentTime);
	struct tm *currTm = localtime(&currentTime);

	std::stringstream ss;
	std::string errorMsg;

	ss << "LOG [";
	switch (verbosityLevel) {
	case _LEVEL_ERROR:
		ss << "ERROR";
		break;
	case _LEVEL_WARN:
		ss << "WARN ";
		break;
	case _LEVEL_INFO:
		ss << "INFO ";
		break;
	case _LEVEL_DEBUG:
		ss << "DEBUG";
		break;
	case _LEVEL_TRACE:
		ss << "TRACE";
		break;
	case _LEVEL_ALL:
	case _LEVEL_OFF:
		//ALL & OFF
		errorMsg = "Logging error : verbosity label : ALL | OFF";
		ss << errorMsg;
		break;
	default:
		errorMsg = "Logging error : unknown verbosity : ("
				+ util::Converts::numberToString(verbosityLevel) + ")";
		ss << errorMsg;
		break;
	}
	ss << "]";

	ss << "<" << currTm->tm_hour << ":" << currTm->tm_min << ":"
			<< currTm->tm_sec << ">";
	ss << "{" << fileName << " : " << codeLineNum << "}";
	ss << " - " << message;

	if ((this->_configOption & file_on)
			&& (verbosityLevel >= this->_fileVerbosityLevel)) {
		this->_out << ss.str() << std::endl;
	}

	if ((this->_configOption & screen_on)
			&& (verbosityLevel >= this->_screenVerbosityLevel)) {
		std::cout << ss.str() << std::endl;
	}

	if (errorMsg.empty() == false) {
		throw IllegalStateException(errorMsg);
	}
}
