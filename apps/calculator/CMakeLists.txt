cmake_minimum_required(VERSION 2.8.7)
project(calculator C CXX)

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
# Code Generation
######################################################################
FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)

# Create target for the parser
ADD_CUSTOM_TARGET(ParserCodeGen echo "Creating parser.c")

SET(FLEX_OUTPUT_DIR "${MOD_SRC_DIR}/compile/parser/grammar/flex")
# Create custom command for flex/lex (note the outputs)
ADD_CUSTOM_COMMAND(
        COMMAND ${FLEX_EXECUTABLE}
                --outfile=${FLEX_OUTPUT_DIR}/calc.lex.cpp
                ${FLEX_OUTPUT_DIR}/calc.l
        TARGET ParserCodeGen
        OUTPUTS ${FLEX_OUTPUT_DIR}/calc.lex.cpp
        COMMENT "Generating calc.lex.cpp"
)

SET(BISON_OUTPUT_DIR "${MOD_SRC_DIR}/compile/parser/grammar/bison")
# Create custom command for bison/yacc (note the DEPENDS)
ADD_CUSTOM_COMMAND(
        COMMAND ${BISON_EXECUTABLE}
                --defines=${BISON_OUTPUT_DIR}/calc.tab.hpp
                --output=${BISON_OUTPUT_DIR}/calc.tab.cpp
#                -y
                ${BISON_OUTPUT_DIR}/calc.y
        TARGET ParserCodeGen
        DEPENDS ${FLEX_OUTPUT_DIR}/calc.lex.cpp
        OUTPUTS ${BISON_OUTPUT_DIR}/calc.tab.cpp
        COMMENT "Generating calc.tab.cpp / calc.tab.hpp"
)

# Add parser.c to the list of sources
SET(CORE_SOURCE_FILES
        ${CORE_SOURCE_FILES}
        ${FLEX_OUTPUT_DIR}/calc.lex.cpp
        ${BISON_OUTPUT_DIR}/calc.tab.cpp
        ${BISON_OUTPUT_DIR}/calc.tab.hpp
        )

# Since the following cpp/hpp do not exists yet when cmake is run, mark it as generated
SET_SOURCE_FILES_PROPERTIES(${BISON_OUTPUT_DIR}/calc.tab.cpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(${BISON_OUTPUT_DIR}/calc.tab.hpp GENERATED)
SET_SOURCE_FILES_PROPERTIES(${FLEX_OUTPUT_DIR}/calc.lex.cpp GENERATED)

# Include binary directory to include lexer.c in parser.c
#INCLUDE_DIRECTORIES(${Foo_BINARY_DIR}/src)
######################################################################
# Build Core
######################################################################
#TODO: Replace with a macro / function that automatically discover source files
set(CORE_SOURCE_FILES
        ${CORE_SOURCE_FILES}
        ${MOD_SRC_DIR}/cli/Console.cpp
        ${MOD_SRC_DIR}/compile/MathInterpretor.cpp
        ${MOD_SRC_DIR}/compile/eval/Analyzer.cpp
        ${MOD_SRC_DIR}/compile/eval/MathEvaluator.cpp
        ${MOD_SRC_DIR}/compile/parser/MathParser.cpp
        ${MOD_SRC_DIR}/compile/parser/grammar/GrammarLibs.cpp
        ${MOD_SRC_DIR}/compile/traverse/ast/ASTreeWalker.cpp
        )

set(CORE_SOURCE_FILES_WITH_MAIN
        ${CORE_SOURCE_FILES}
        ${MOD_SRC_DIR}/Main.cpp)

#TODO: More graceful way to handle include_directories from other targets
include_directories("${MOD_INC_DIR}")
include_directories("${PRJ_ROOT_DIR}/libs/shacat/include")
include_directories("${PRJ_ROOT_DIR}/libs/compiler/include")

add_executable(calculator ${CORE_SOURCE_FILES_WITH_MAIN} )

target_link_libraries (calculator shacat compiler)

add_dependencies(calculator ParserCodeGen)
#####################################################################
# Build Test
#####################################################################
enable_testing()

#TODO: Replace with a macro / function that automatically discover source files
set(TEST_SOURCE_FILES
        ${MOD_TEST_DIR}/compile/eval/Test_Analyzer.cpp
        ${MOD_TEST_DIR}/compile/eval/Test_MathEvaluator.cpp
        ${MOD_TEST_DIR}//compile/parser/Test_Parser.cpp
        ${MOD_TEST_DIR}/TestMain.cpp
        )

include_directories(${GTEST_INCLUDE_DIR})
include_directories(${GMOCK_INCLUDE_DIR})
add_executable(CalculatorTest ${TEST_SOURCE_FILES} ${CORE_SOURCE_FILES})

target_link_libraries (CalculatorTest shacat compiler ${GMOCK_LIBRARY_PATH} ${CMAKE_THREAD_LIBS_INIT})


add_dependencies(CalculatorTest shacat compiler ${GMOCK_LIBRARY} ${${GTEST_LIBRARY}} ParserCodeGen)

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

    add_custom_target(CalculatorDoc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${MOD_DOXY_CONF}
        WORKING_DIRECTORY ${MOD_DOC_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

#    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
endif()
add_dependencies(CalculatorDoc CalculatorTest)

