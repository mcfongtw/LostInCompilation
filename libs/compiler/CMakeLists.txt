cmake_minimum_required(VERSION 2.8.7)
project(compiler  C CXX)

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
#TODO: Replace with a macro / function that automatically discover header & source files
set(CORE_SOURCE_FILES
        ##################################################################
        # Header
        ##################################################################
        ${MOD_INC_DIR}/algorithm/event/InternalEvent.h
        ${MOD_INC_DIR}/algorithm/event/ComponentType.h
        ${MOD_INC_DIR}/algorithm/tree/ast/ASTNode.h
        ${MOD_INC_DIR}/algorithm/tree/ast/ASTUtils.h
        ${MOD_INC_DIR}/compile/Compilable.h
        ${MOD_INC_DIR}/compile/SourceCodePosition.h
        ${MOD_INC_DIR}/compile/binding/DataBindingUtils.h
        ${MOD_INC_DIR}/compile/binding/RuntimeData.h
        ${MOD_INC_DIR}/compile/binding/ValueHolder.h
        ${MOD_INC_DIR}/compile/eval/Evaluator.h
        ${MOD_INC_DIR}/compile/parser/Parser.h
        ${MOD_INC_DIR}/compile/symtab/RuntimeStack.h
        ${MOD_INC_DIR}/compile/symtab/Symbol.h
        ${MOD_INC_DIR}/compile/symtab/ScopedSymbolTable.h
        ${MOD_INC_DIR}/compile/symtab/SimpleSymbolTable.h
        ${MOD_INC_DIR}/compile/symtab/SymbolRepository.h
        ${MOD_INC_DIR}/compile/symtab/SymbolTableFactory.h
        ${MOD_INC_DIR}/compile/symtab/SymbolTableStack.h
        ${MOD_INC_DIR}/compile/symtab/visitor/SimpleSymbolTableVisitor.h
        ${MOD_INC_DIR}/compile/symtab/visitor/SymbolTableVisitor.h
        ${MOD_INC_DIR}/compile/symtab/visitor/VisitedSymbolTable.h
        ${MOD_INC_DIR}/compile/Interpretable.h
        ${MOD_INC_DIR}/error/ParseException.h
        ${MOD_INC_DIR}/error/SyntaxError.h
        ${MOD_INC_DIR}/error/ArithmeticException.h
        ${MOD_INC_DIR}/tool/DotTreePrinter.h
        ${MOD_INC_DIR}/tool/AsciiTreePrinter.h
        ${MOD_INC_DIR}/tool/Printer.h
        ${MOD_INC_DIR}/tool/Appender.h
        #################################################################
        # Source
        #################################################################
        ${MOD_SRC_DIR}/algorithm/event/InternalEvent.cpp
        ${MOD_SRC_DIR}/algorithm/tree/ast/ASTNode.cpp
        ${MOD_SRC_DIR}/algorithm/tree/ast/ASTUtils.cpp
        ${MOD_SRC_DIR}/compile/SourceCodePosition.cpp
        ${MOD_SRC_DIR}/compile/binding/DataBindingUtils.cpp
        ${MOD_SRC_DIR}/compile/binding/RuntimeData.cpp
        ${MOD_SRC_DIR}/compile/symtab/RuntimeStack.cpp
        ${MOD_SRC_DIR}/compile/symtab/Symbol.cpp
        ${MOD_SRC_DIR}/compile/symtab/SimpleSymbolTable.cpp
        ${MOD_SRC_DIR}/compile/symtab/SymbolTableFactory.cpp
        ${MOD_SRC_DIR}/compile/symtab/SymbolTableStack.cpp
        ${MOD_SRC_DIR}/compile/symtab/visitor/SimpleSymbolTableVisitor.cpp
        ${MOD_SRC_DIR}/error/ParseException.cpp
        ${MOD_SRC_DIR}/error/SyntaxError.cpp
        ${MOD_SRC_DIR}/error/ArithmeticException.cpp
        ${MOD_SRC_DIR}/tool/DotTreePrinter.cpp
        ${MOD_SRC_DIR}/tool/AsciiTreePrinter.cpp
        ${MOD_SRC_DIR}/tool/Appender.cpp
        ${MOD_SRC_DIR}/tool/Printer.cpp
        )

#TODO: More graceful way to handle include_directories from other targets
include_directories("${MOD_INC_DIR}")
include_directories("${PRJ_ROOT_DIR}/libs/shacat/include")

add_library(compiler SHARED ${CORE_SOURCE_FILES})

#####################################################################
# Build Test
#####################################################################
enable_testing()

#TODO: Replace with a macro / function that automatically discover source files
set(TEST_SOURCE_FILES
        ${MOD_TEST_DIR}/algorithm/event/Test_InternalEvent.cpp
        ${MOD_TEST_DIR}/algorithm/tree/ast/Test_AST.cpp
        ${MOD_TEST_DIR}/compile/Test_SourceCodePosition.cpp
        ${MOD_TEST_DIR}/compile/binding/Test_RuntimeData.cpp
        ${MOD_TEST_DIR}/compile/symtab/Test_RuntimeStack.cpp
        ${MOD_TEST_DIR}/compile/symtab/Test_SymbolTable.cpp
        ${MOD_TEST_DIR}/compile/symtab/Test_SymbolTableStack.cpp
        ${MOD_TEST_DIR}/error/Test_ParseException.cpp
        ${MOD_TEST_DIR}/tool/Test_DotTreePrinter.cpp
        ${MOD_TEST_DIR}/tool/Test_AsciiTreePrinter.cpp
        ${MOD_TEST_DIR}/TestMain.cpp
        )

include_directories(${GTEST_INCLUDE_DIR})
include_directories(${GMOCK_INCLUDE_DIR})
add_executable(CompilerTest ${TEST_SOURCE_FILES} ${CORE_SOURCE_FILES})

add_dependencies(CompilerTest shacat compiler ${GMOCK_LIBRARY} ${${GTEST_LIBRARY}} )

target_link_libraries (CompilerTest shacat ${GMOCK_LIBRARY_PATH} ${CMAKE_THREAD_LIBS_INIT})

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

    add_custom_target(CompilerDoc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${MOD_DOXY_CONF}
        WORKING_DIRECTORY ${MOD_DOC_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    add_dependencies(CompilerDoc CompilerTest)
#    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
endif()


