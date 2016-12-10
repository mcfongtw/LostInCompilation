//
// Created by Michael Fong on 2016/11/12.
//
#include <vector>
#include <string>
#include "compile/MathCompiler.h"

#include "gtest/gtest.h"

#include "tool/AsciiPrinter.h"
#include "tool/DotPrinter.h"
#include "tool/Appender.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
TEST(MATH_COMPILER, UNIT_compile_empty_input) {
    MathCompiler compiler;

    std::vector<std::string> content;

    compiler.compile(content);
}

TEST(MATH_COMPILER, UNIT_compile_from_input_1) {
    MathCompiler compiler;

    std::vector<std::string> content;
    content.push_back(std::string("x=3"));
    content.push_back(std::string("x*x+x"));


    compiler.compile(content);
}

TEST(MATH_COMPILER, UNIT_compile_from_input_2) {
    MathCompiler compiler;

    std::vector<std::string> content;
    content.push_back(std::string("x=3"));
    content.push_back(std::string("y=4"));
    content.push_back(std::string("x * y + 5"));

    compiler.compile(content);
}