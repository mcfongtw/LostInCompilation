//
// Created by michael.fong on 10/18/16.
//

#include "algorithm/tree/ast/ASTNode.h"
#include "tool/DotPrinter.h"
#include "tool/Appender.h"
#include "gtest/gtest.h"

#include <memory>


TEST(TOOL_APPENDER, Simple_Console_Appender) {
    std::shared_ptr<ConsoleAppender> appender = std::make_shared<ConsoleAppender>();
    appender->write("Hello World");
    appender->close();
}

TEST(TOOL_APPENDER, Simple_File_Appender) {
    std::shared_ptr<FileAppender> appender = std::make_shared<FileAppender>("test.txt");
    appender->write("Hello World");
    appender->close();
}

TEST(TOOL_APPENDER, Simple_String_Appender) {
    std::shared_ptr<StringAppender> appender = std::make_shared<StringAppender>();
    appender->write("Hello World");
    appender->close();
    EXPECT_STREQ(appender->toString().c_str(), "Hello World");
}

TEST(TOOL_PRINTER, Simple_DotPrinter_Node_1) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("1", 1);

    std::shared_ptr<DotPrinter> printer = std::make_shared<DotPrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

//    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

//    std::cout << stringAppender->toString() << std::endl;

    std::string expected =
            "digraph G {\n"
            "\t node [style=rounded]\n"
            "\t node_1 [label = \"'1' token = 1\"]\n"
            "}";

    EXPECT_STREQ(expected.c_str(), stringAppender->toString().c_str());
}

TEST(TOOL_PRINTER, Simple_DotPrinter_Tree_1) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

    root->insertChild(left);
    root->insertChild(right);

    std::shared_ptr<DotPrinter> printer = std::make_shared<DotPrinter>();
    std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
    printer->addAppender(stringAppender);

//    printer->addAppender(std::make_shared<ConsoleAppender>());

    root->apply(printer, DEPTH_FIRST);

//    std::cout << stringAppender->toString() << std::endl;

    std::string expected =
            "digraph G {\n"
            "\t node [style=rounded]\n"
            "\t node_1 [label = \"'+' token = 1\"]\n"
            "\t node_1 -> node_2\n"
            "\t node_1 -> node_3\n"
            "\t node_2 [label = \"'1' token = 2\"]\n"
            "\t node_3 [label = \"'2' token = 2\"]\n"
            "}";
    EXPECT_STREQ(expected.c_str(), stringAppender->toString().c_str());
}