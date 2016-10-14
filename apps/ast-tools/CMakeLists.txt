cmake_minimum_required(VERSION 3.2.2)
project(ast-tools C CXX)

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

######################################################################
# Build Core
######################################################################
#TODO: Replace with a macro / function that automatically discover source files
set(CORE_SOURCE_FILES
        ${MOD_SRC_DIR}/ASTPrinter.cpp
        ${MOD_SRC_DIR}/DotPrinter.cpp
        ${MOD_SRC_DIR}/ParseTreePrinter.cpp
        ${MOD_SRC_DIR}/Main.cpp
        )
#TODO: More graceful way to handle include_directories from other targets
include_directories("${MOD_INC_DIR}")
include_directories("${PRJ_ROOT_DIR}/libs/shacat/include")
include_directories("${PRJ_ROOT_DIR}/libs/compiler/include")

add_executable(ASTTool ${CORE_SOURCE_FILES})
target_link_libraries (ASTTool shacat compiler ${GMOCK_LIBRARY_PATH} ${CMAKE_THREAD_LIBS_INIT})