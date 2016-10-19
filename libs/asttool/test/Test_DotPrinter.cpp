//
// Created by michael.fong on 10/18/16.
//

#include "algorithm/tree/ast/ASTNode.h"
#include "compile/tool/DotPrinter.h"
#include "gtest/gtest.h"

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

bool compareFiles(const std::string& p1, const std::string& p2) {
    std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        std::cerr << "Either f1 or f2 has IO error " << std::endl;
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        std::cerr << "f1 size (" << f1.tellg() << ") != f2 size (" << ")" << std::endl;
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    bool result = std::equal(std::istreambuf_iterator<char>(f1.rdbuf()), \
                    std::istreambuf_iterator<char>(), \
                    std::istreambuf_iterator<char>(f2.rdbuf()));

    if(!result) {
        //show diff result
        std::cerr << "File content mismatch!" << std::endl;
    }

    return result;
}

TEST(DOTPRINTER, Simple) {
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

    root->insertChild(left);
    root->insertChild(right);

    std::shared_ptr<DotPrinter> printerPtr = std::make_shared<DotPrinter>("test.txt");

    root->apply(printerPtr, DEPTH_FIRST);

    EXPECT_TRUE(compareFiles("test.txt", "verify/DOTPRINTER_Simple.dot"));
}