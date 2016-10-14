//
// Created by shannaracat on 2016/10/13.
//

#include <iostream>
#include <string>
#include <exception>
#include "stdlib.h"


#include "log/Logger.h"
#include "error/StackTraceUtils.h"



int main(int argc, char **argv) {
    LOG_CONF("debug", Logger::file_on | Logger::screen_on, Logger::LEVEL_TRACE,
             Logger::LEVEL_INFO);
    LOG(Logger::LEVEL_INFO, "Logging starts");

    StackTraceUtils::setupStackTraceAgent();
}