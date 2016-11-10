cmake_minimum_required(VERSION 2.8.7)
project(shacat C CXX)

######################################################################
#Module Variables
######################################################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MOD_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
message("================================================")
message("MOD_SRC_DIR : ${MOD_SRC_DIR}")
message("================================================")

set(MOD_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
message("================================================")
message("MOD_INC_DIR : ${MOD_INC_DIR}")
message("================================================")

set(MOD_TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
message("================================================")
message("MOD_TEST_DIR : ${MOD_TEST_DIR}")
message("================================================")

set(MOD_DOC_DIR "${PRJ_DOC_DIR}/${PROJECT_NAME}")
file(MAKE_DIRECTORY ${MOD_DOC_DIR})
message("================================================")
message("MOD_DOC_DIR : ${MOD_DOC_DIR}")
message("================================================")

######################################################################
# Build Core
######################################################################
#TODO: Replace with a macro / function that automatically discover source files
set(CORE_SOURCE_FILES
        ${MOD_SRC_DIR}/algorithm/tree/traditional/LIFO/TreeTraverse.cpp
        ${MOD_SRC_DIR}/algorithm/tree/visitor/VisitedTreeNode.cpp
        ${MOD_SRC_DIR}/algorithm/tree/TreeBuilder.cpp
        ${MOD_SRC_DIR}/algorithm/tree/TreeNode.cpp
        ${MOD_SRC_DIR}/common/Conditions.cpp
        ${MOD_SRC_DIR}/common/Conversions.cpp
        ${MOD_SRC_DIR}/common/Strings.cpp
        ${MOD_SRC_DIR}/error/Exception.cpp
        ${MOD_SRC_DIR}/error/StackTraceUtils.cpp
        ${MOD_SRC_DIR}/lang/Object.cpp
        ${MOD_SRC_DIR}/log/Logger.cpp
        )
include_directories("${MOD_INC_DIR}")
add_library(shacat SHARED ${CORE_SOURCE_FILES})

#####################################################################
# Build Test
#####################################################################
enable_testing()
#TODO: Replace with a macro / function that automatically discover source files
set(TEST_SOURCE_FILES
        ${MOD_TEST_DIR}/algorithm/tree/Test_Tree_Basic.cpp
        ${MOD_TEST_DIR}/algorithm/tree/traditional/Test_Tree_Traverse.cpp
        ${MOD_TEST_DIR}/algorithm/tree/visitor/Test_Tree_Visitor.cpp
        ${MOD_TEST_DIR}/algorithm/visitor/Test_Visitor.cpp
        ${MOD_TEST_DIR}/algorithm/visitor/CountVisitor.h
        ${MOD_TEST_DIR}/algorithm/visitor/BlueAndRedVisitedObject.h
        ${MOD_TEST_DIR}/common/Test_Conditions.cpp
        ${MOD_TEST_DIR}/common/Test_Converts.cpp
        ${MOD_TEST_DIR}/common/Test_Strings.cpp
        ${MOD_TEST_DIR}/error/Test_Exception.cpp
        ${MOD_TEST_DIR}/hack/Test_Hack.cpp
        ${MOD_TEST_DIR}/lang/Test_Object.cpp
        ${MOD_TEST_DIR}/lang/TestDerivedObject.hpp
        ${MOD_TEST_DIR}/log/Test_Logger.cpp
        ${MOD_TEST_DIR}/Test_Basics.cpp
        ${MOD_TEST_DIR}/TestMain.cpp
        )

include_directories(${GTEST_INCLUDE_DIR})
include_directories(${GMOCK_INCLUDE_DIR})
add_executable(ShacatTest ${TEST_SOURCE_FILES} ${CORE_SOURCE_FILES})

add_dependencies(ShacatTest shacat ${GMOCK_LIBRARY} ${${GTEST_LIBRARY}})

target_link_libraries (ShacatTest ${GMOCK_LIBRARY_PATH} ${CMAKE_THREAD_LIBS_INIT})

######################################################################
# Build Documentation
######################################################################

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(MOD_DOXY_CONF ${MOD_DOC_DIR}/Doxyfile.conf)

    configure_file(${PRJ_DOXY_CONF} ${MOD_DOXY_CONF})

    add_custom_target(ShacatDoc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${MOD_DOXY_CONF}
        WORKING_DIRECTORY ${MOD_DOC_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

#    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
endif()
add_dependencies(ShacatDoc ShacatTest)
