//
// Created by Michael Fong on 2016/12/3.
//

#include "algorithm/tree/ast/ASTNode.h"
#include "tool/AsciiPrinter.h"
#include "tool/Appender.h"
#include "gtest/gtest.h"

#include <memory>

TEST(TOOL_ASCII_PRINTER, Simple_Ascii_Printer_1) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

    root->insertChild(left);
    root->insertChild(right);

    std::shared_ptr<AsciiPrinter> printer = std::make_shared<AsciiPrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

    std::cout << stringAppender->toString() << std::endl;
}