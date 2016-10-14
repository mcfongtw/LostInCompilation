//
// Created by shannaracat on 2016/8/12.
//

//third party include
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "log/Logger.h"


int main(int argc, char **argv)
{
    LOG_CONF("debug", Logger::file_on | Logger::screen_on, Logger::LEVEL_TRACE,
             Logger::LEVEL_INFO);
    LOG(Logger::LEVEL_INFO, "Logging starts");


    std::cout << "Running main()" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}