cmake_minimum_required(VERSION 2.8.7)
project(LostInCompilation)

######################################################################
#Global Variables
######################################################################

# Global Var : The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   1   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

#Set the default CMAKE_BUILD_TYPE if it has not been set.
if( NOT CMAKE_BUILD_TYPE )
    SET(CMAKE_BUILD_TYPE Debug CACHE STRING
            "Choose the type of build, options are: None Debug Release RelWithDebInfo
MinSizeRel."
            FORCE )
ENDIF()
message("================================================")
message("CMAKE_BUILD_TYPE : ${CMAKE_BUILD_TYPE}")
message("================================================")

# Global Var : binary directory
set(PRJ_BIN_DIR "${CMAKE_BINARY_DIR}/bin")
file(MAKE_DIRECTORY ${PRJ_BIN_DIR})
message("================================================")
message("PRJ_BIN_DIR : ${PRJ_BIN_DIR}")
message("================================================")

# Global Var : source directory
set(PRJ_ROOT_DIR "${CMAKE_SOURCE_DIR}")
message("================================================")
message("PRJ_ROOT_DIR : ${PRJ_ROOT_DIR}")
message("================================================")

# Global var : doc directory
IF(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RELEASE")
    SET(PRJ_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/doxygen")
ELSE()
    set(PRJ_DOC_DIR "${CMAKE_BINARY_DIR}/docs")
ENDIF()
file(MAKE_DIRECTORY ${PRJ_DOC_DIR})
message("================================================")
message("PRJ_DOC_DIR : ${PRJ_DOC_DIR}")
message("================================================")

# Global var : doxygen conf
set(PRJ_DOXY_CONF ${PRJ_ROOT_DIR}/Doxyfile.conf)
message("================================================")
message("PRJ_DOXY_CONF : ${PRJ_DOXY_CONF}")
message("================================================")

# CMake internal : G++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CMake internal : compilation output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PRJ_BIN_DIR})
SET(EXECUTABLE_OUTPUT_PATH ${PRJ_BIN_DIR})
######################################################################
# Init pthread
######################################################################
find_package (Threads)

INCLUDE(ExternalProject)
FIND_PACKAGE(Git REQUIRED)

######################################################################
# Setup Google Test Suite
######################################################################
ExternalProject_ADD(
        #--External-project-name------
        googletestsuite
        #--Core-directories-----------
        PREFIX             ${CMAKE_BINARY_DIR}/externals/googletestsuite
        #--Download step--------------
        GIT_REPOSITORY     https://github.com/google/googletest.git
        #  GIT_TAG            release-1.7.0
        TIMEOUT            10
        LOG_DOWNLOAD       ON
        #--Update/Patch step----------
        UPDATE_COMMAND     ""
        #--Configure step-------------
        # CONFIGURE_COMMAND ${CMAKE_COMMAND} .
        CMAKE_ARGS ${CMAKE_ARGS} -DBUILD_GTEST=ON -DBUILD_GMOCK=ON
        #--Build step-----------------
        #BUILD_COMMAND ${CMAKE_MAKE_PROGRAM}
        #BUILD_IN_SOURCE 1
        #--Install step---------------
        INSTALL_COMMAND    ""
        #--Logging step---------------
        LOG_CONFIGURE ON
        LOG_BUILD ON
)

ExternalProject_Get_Property(googletestsuite source_dir)
set(GTEST_INCLUDE_DIR ${source_dir}/googletest/include)
set(GMOCK_INCLUDE_DIR ${source_dir}/googlemock/include)

ExternalProject_Get_Property(googletestsuite binary_dir)
set(GTEST_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GTEST_LIBRARY gtest)
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GTEST_LIBRARY} PROPERTIES
        IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}
        IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(${GTEST_LIBRARY} googletest)

set(GTEST_MAIN_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main.a)
set(GTEST_MAIN_LIBRARY gtest_main)
add_library(${GTEST_MAIN_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GTEST_MAIN_LIBRARY} PROPERTIES
        IMPORTED_LOCATION ${GTEST_MAIN_LIBRARY_PATH}
        IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(${GTEST_MAIN_LIBRARY} googletest)

set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
set(GMOCK_LIBRARY gmock)
add_library(${GMOCK_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GMOCK_LIBRARY} PROPERTIES
        IMPORTED_LOCATION ${GMOCK_LIBRARY_PATH}
        IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(${GMOCK_LIBRARY} googletest)

set(GMOCK_MAIN_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock_main.a)
set(GMOCK_MAIN_LIBRARY gmock_main)
add_library(${GMOCK_MAIN_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GMOCK_MAIN_LIBRARY} PROPERTIES
        IMPORTED_LOCATION ${GMOCK_MAIN_LIBRARY_PATH}
        IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(${GMOCK_MAIN_LIBRARY} ${GTEST_LIBRARY})

######################################################################
# Start to build sub-modules
######################################################################
add_subdirectory(libs/shacat)
add_subdirectory(libs/compiler)
add_subdirectory(apps/calculator)


