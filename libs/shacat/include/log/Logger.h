/*
 * Logger.h
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <ostream>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <string.h>

#include "error/Exception.h"

/*
 * Define a macro __FILE_NAME__ that intends to extract file name only from __FILE__
 */
#define __FILE_NAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/**
 * 	LOG_CONF("outputfile", Logger::file_on|Logger::screen_on, DBG_DEBUG, DBG_ERROR);
 */
#define LOG_CONF(outputFile, \
		configuration, \
		fileVerbosityLevel, \
		screenVerbosityLevel) { \
			Logger::getInstance()->configure(outputFile, \
						configuration, \
						fileVerbosityLevel, \
						screenVerbosityLevel); \
		}

/**
 *	    LOG(DBG_DEBUG, "hello " << "world");
 */
#define LOG(log_level, msg) { \
			std::ostringstream __debug_stream__; \
			__debug_stream__ << msg; \
			Logger::getInstance()->print(log_level, __FILE_NAME__, __LINE__, \
					__debug_stream__.str()); \
		}

#define LOG_ERROR(error_msg) { \
			LOG(Logger::LEVEL_ERROR, error_msg); \
		}
/**
 * A simple Logger implementation that provides
 * 1) Output the logging message on screen and/or on a file
 * 2) Predefined prioritized logging level for filtering.
 */
class Logger {
private:
	enum _LogLevel {
		_LEVEL_OFF = 10000,
		_LEVEL_ERROR = 8000,
		_LEVEL_WARN = 7000,
		_LEVEL_INFO = 5000,
		_LEVEL_DEBUG = 3000,
		_LEVEL_TRACE = 2000,
		_LEVEL_ALL = 0
	};

	enum _LogConfigOption {
		_file_on = 1 << 0,
		_file_off = 1 << 1,
		_screen_on = 1 << 2,
		_screen_off = 1 << 3,
		_file_append = 1 << 4
	};
public:
	typedef _LogLevel LogLevel;

	static const LogLevel LEVEL_OFF = _LEVEL_OFF;

	static const LogLevel LEVEL_ERROR = _LEVEL_ERROR;

	static const LogLevel LEVEL_WARN = _LEVEL_WARN;

	static const LogLevel LEVEL_INFO = _LEVEL_INFO;

	static const LogLevel LEVEL_DEBUG = _LEVEL_DEBUG;

	static const LogLevel LEVEL_TRACE = _LEVEL_TRACE;

	static const LogLevel LEVEL_ALL = _LEVEL_ALL;

	typedef _LogConfigOption LogConfigOption;

	static const LogConfigOption file_on = _file_on;

	static const LogConfigOption file_off = _file_off;

	static const LogConfigOption screen_on = _screen_on;

	static const LogConfigOption screen_off = _screen_off;

	static const LogConfigOption file_append = _file_append;

	static Logger* getInstance();

	virtual ~Logger();

	void configure(const std::string& outputFile, LogConfigOption option,
			LogLevel fileVerbosityLevel, LogLevel screenVerbosityLevel);

	void print(LogLevel verbosityLevel, const char* fileName,
			const int codeLineNum, const std::string& message);

private:
	Logger();

	static Logger* INSTANCE;

	bool _isConfigured;

	std::string _logFileName;

	LogConfigOption _configOption;

	std::ofstream _out;

	struct timeval _initTime;

	size_t _fileVerbosityLevel;

	size_t _screenVerbosityLevel;

};

inline Logger::LogConfigOption operator|(Logger::LogConfigOption opt1,
		Logger::LogConfigOption opt2) {
	return Logger::LogConfigOption(
			static_cast<int>(opt1) | static_cast<int>(opt2));
}

inline Logger::LogConfigOption operator&(Logger::LogConfigOption opt1,
		Logger::LogConfigOption opt2) {
	return Logger::LogConfigOption(
			static_cast<int>(opt1) & static_cast<int>(opt2));
}

#endif /* LOGGER_H_ */
