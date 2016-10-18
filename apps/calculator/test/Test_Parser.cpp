/*
 * Test_Parser.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */
#include <string>
#include <iostream>
#include <exception>

#include "gtest/gtest.h"

#include "error/Exception.h"
#include "error/ParseException.h"
#include "compile/parser/MathParser.h"
#include "algorithm/tree/ast/ASTNode.h"

TEST(PARSER, First_Test) {
	std::string line = "1";
	ASTNodePtr root = 0;
	MathParser parser;

	parser.parse(root, line);

	EXPECT_EQ((size_t )0, root->getNumOfChildren());
	EXPECT_TRUE(root->isRoot());
	EXPECT_TRUE(root->isLeaf());
}

TEST(PARSER, Simple) {
	std::string line = "1 + 2";
	ASTNodePtr root = 0;
	MathParser parser;

	parser.parse(root, line);
	TreeNodePtr left = root->getChildAt(0);
	TreeNodePtr right = root->getChildAt(1);

	EXPECT_EQ((size_t )2, root->getNumOfChildren());
	EXPECT_TRUE(root->isRoot());
	EXPECT_FALSE(root->isLeaf());

	EXPECT_EQ((size_t ) 0, left->getNumOfChildren());
	EXPECT_FALSE(left->isRoot());
	EXPECT_TRUE(left->isLeaf());
	EXPECT_EQ(root.get(), left->getParent());

	EXPECT_EQ((size_t ) 0, right->getNumOfChildren());
	EXPECT_FALSE(right->isRoot());
	EXPECT_TRUE(right->isLeaf());
	EXPECT_EQ(root.get(), right->getParent());
}

TEST(PARSER, Moderate) {
    std::string line = "1 + 2 * 3";
    /*   +
     *  / \
     * 1   *
     *     / \
     *    2  3
     */
    ASTNodePtr root = 0;
    MathParser parser;

    parser.parse(root, line);
    TreeNodePtr left = root->getChildAt(0);
    TreeNodePtr right = root->getChildAt(1);

    EXPECT_EQ((size_t )2, root->getNumOfChildren());
    EXPECT_TRUE(root->isRoot());
    EXPECT_FALSE(root->isLeaf());

    EXPECT_EQ((size_t ) 0, left->getNumOfChildren());
    EXPECT_FALSE(left->isRoot());
    EXPECT_TRUE(left->isLeaf());
    EXPECT_EQ(root.get(), left->getParent());

    EXPECT_EQ((size_t ) 2, right->getNumOfChildren());
    EXPECT_FALSE(right->isRoot());
    EXPECT_FALSE(right->isLeaf());
    EXPECT_EQ(root.get(), right->getParent());

    TreeNodePtr leftGrandChild = right->getChildAt(0);
    TreeNodePtr rightGrandChild = right->getChildAt(1);

    EXPECT_EQ((size_t ) 0, leftGrandChild->getNumOfChildren());
    EXPECT_FALSE(leftGrandChild->isRoot());
    EXPECT_TRUE(leftGrandChild->isLeaf());
    EXPECT_EQ(right.get(), leftGrandChild->getParent());

    EXPECT_EQ((size_t ) 0, rightGrandChild->getNumOfChildren());
    EXPECT_FALSE(rightGrandChild->isRoot());
    EXPECT_TRUE(rightGrandChild->isLeaf());
    EXPECT_EQ(right.get(), rightGrandChild->getParent());
}

TEST(PARSER, Parser_Error) {
	std::string line = "1 + 2 + ";
	ASTNodePtr root;
	MathParser parser;

	EXPECT_THROW(parser.parse(root, line), ParseException);
}
