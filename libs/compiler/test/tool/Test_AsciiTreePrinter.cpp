//
// Created by Michael Fong on 2016/12/3.
//

#include "algorithm/tree/ast/ASTNode.h"
#include "tool/AsciiTreePrinter.h"
#include "tool/Appender.h"
#include "gtest/gtest.h"

#include <memory>

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

TEST(TOOL_ASCII_PRINTER, Simple_Ascii_Printer_1) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

    root->insertChild(left);
    root->insertChild(right);

    std::shared_ptr<AsciiTreePrinter> printer = std::make_shared<AsciiTreePrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

    std::cout << stringAppender->toString() << std::endl;

    std::string expected =
            "(1,+)\n"
            "|----(2,1)\n"
            "`----(2,2)\n";

    ASSERT_EQ(expected, stringAppender->toString());
}

TEST(TOOL_ASCII_PRINTER, Simple_Ascii_Printer_2) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr grandson = std::make_shared<ASTNode>("2", 3);

    root->insertChild(left);
    left->insertChild(grandson);

    std::shared_ptr<AsciiTreePrinter> printer = std::make_shared<AsciiTreePrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

    std::cout << stringAppender->toString() << std::endl;

    std::string expected =
            "(1,+)\n"
            "`----(2,1)\n"
            "     `----(3,2)\n";

    ASSERT_EQ(expected, stringAppender->toString());
}

TEST(TOOL_ASCII_PRINTER, Simple_Ascii_Printer_3) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);
    VisitedTreeNodePtr grandson1 = std::make_shared<ASTNode>("x", 3);
    VisitedTreeNodePtr grandson2 = std::make_shared<ASTNode>("y", 4);
    VisitedTreeNodePtr grandson3 = std::make_shared<ASTNode>("z", 5);

    root->insertChild(left);
    root->insertChild(right);
    left->insertChild(grandson1);
    right->insertChild(grandson2);
    right->insertChild(grandson3);


    std::shared_ptr<AsciiTreePrinter> printer = std::make_shared<AsciiTreePrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

    std::cout << stringAppender->toString() << std::endl;

    std::string expected =
            "(1,+)\n"
            "|----(2,1)\n"
            "|    `----(3,x)\n"
            "`----(2,2)\n"
            "     |----(4,y)\n"
            "     `----(5,z)\n";

    ASSERT_EQ(expected, stringAppender->toString());
}

TEST(TOOL_ASCII_PRINTER, Simple_Ascii_Printer_4) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr grandson = std::make_shared<ASTNode>("2", 3);
    VisitedTreeNodePtr grandgrandson = std::make_shared<ASTNode>("3", 4);

    root->insertChild(left);
    left->insertChild(grandson);
    grandson->insertChild(grandgrandson);

    std::shared_ptr<AsciiTreePrinter> printer = std::make_shared<AsciiTreePrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

    std::cout << stringAppender->toString() << std::endl;

    std::string expected =
            "(1,+)\n"
                    "`----(2,1)\n"
                    "     `----(3,2)\n"
                    "          `----(4,3)\n";

    ASSERT_EQ(expected, stringAppender->toString());
}