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

TEST(PARSER, Parser_Error) {
	std::string line = "1 + 2 + ";
	ASTNodePtr root;
	MathParser parser;

	EXPECT_THROW(parser.parse(root, line), ParseException);
}
