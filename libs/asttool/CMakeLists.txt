cmake_minimum_required(VERSION 2.8.7)
project(asttool C CXX)

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
######################################################################
# Build Core
######################################################################
#TODO: Replace with a macro / function that automatically discover source files
set(CORE_SOURCE_FILES
        ${MOD_SRC_DIR}/compile/tool/ASTPrinter.cpp
        ${MOD_SRC_DIR}/compile/tool/DotPrinter.cpp
        ${MOD_SRC_DIR}/compile/tool/ParseTreePrinter.cpp
        )
#TODO: More graceful way to handle include_directories from other targets
include_directories("${MOD_INC_DIR}")
include_directories("${PRJ_ROOT_DIR}/libs/shacat/include")
include_directories("${PRJ_ROOT_DIR}/libs/compiler/include")

add_library(ASTTool SHARED ${CORE_SOURCE_FILES})
target_link_libraries (ASTTool shacat compiler ${GMOCK_LIBRARY_PATH} ${CMAKE_THREAD_LIBS_INIT})

#####################################################################
# Build Test
#####################################################################
enable_testing()

# Variable to store verify files
file(MAKE_DIRECTORY ${PRJ_BIN_DIR}/verify)
file(GLOB MOD_VERIFY_FILES "${MOD_TEST_DIR}/verify/*")
file(COPY ${MOD_VERIFY_FILES} DESTINATION ${PRJ_BIN_DIR}/verify)

#TODO: Replace with a macro / function that automatically discover source files
set(TEST_SOURCE_FILES
        ${MOD_TEST_DIR}/compile/tool/Test_DotPrinter.cpp
        ${MOD_TEST_DIR}/TestMain.cpp
        )

include_directories(${GTEST_INCLUDE_DIR})
include_directories(${GMOCK_INCLUDE_DIR})
add_executable(AstToolTest ${TEST_SOURCE_FILES} ${CORE_SOURCE_FILES})

target_link_libraries (AstToolTest shacat compiler ${GMOCK_LIBRARY_PATH} ${CMAKE_THREAD_LIBS_INIT})


add_dependencies(AstToolTest shacat compiler ${GMOCK_LIBRARY} ${${GTEST_LIBRARY}})