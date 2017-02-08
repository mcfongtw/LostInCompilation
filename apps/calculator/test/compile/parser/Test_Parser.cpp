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

#include "compile/parser/grammar/GrammarLibs.h"
#include "error/SyntaxError.h"
#include "compile/parser/MathParser.h"

#include "log/Logger.h"
#include "hack/DebugLib.h"

TEST(PARSER, First_Test) {
	std::string line = "1";
	ASTNodePtr root = 0;
	MathParser parser;

	parser.parse(root, line);

	EXPECT_EQ((size_t )0, root->getNumOfChildren());
	EXPECT_TRUE(root->isRoot());
	EXPECT_TRUE(root->isLeaf());
    EXPECT_EQ(1, root->getPosition().getRow());
    EXPECT_EQ(1, root->getPosition().getCol());
}

TEST(PARSER, Simple) {
	std::string line = "1 + 2";
	ASTNodePtr root = 0;
	MathParser parser;

	parser.parse(root, line);
    ASTNodePtr left = std::dynamic_pointer_cast<ASTNode>(root->getChildAt(0));
    ASTNodePtr right = std::dynamic_pointer_cast<ASTNode>(root->getChildAt(1));

	EXPECT_EQ((size_t )2, root->getNumOfChildren());
	EXPECT_TRUE(root->isRoot());
	EXPECT_FALSE(root->isLeaf());
    EXPECT_EQ(1, root->getPosition().getRow());
    EXPECT_EQ(3, root->getPosition().getCol());


	EXPECT_EQ((size_t ) 0, left->getNumOfChildren());
	EXPECT_FALSE(left->isRoot());
	EXPECT_TRUE(left->isLeaf());
	EXPECT_EQ(root.get(), left->getParent());
    EXPECT_EQ(1, left->getPosition().getRow());
    EXPECT_EQ(1, left->getPosition().getCol());

	EXPECT_EQ((size_t ) 0, right->getNumOfChildren());
	EXPECT_FALSE(right->isRoot());
	EXPECT_TRUE(right->isLeaf());
	EXPECT_EQ(root.get(), right->getParent());
    EXPECT_EQ(1, right->getPosition().getRow());
    EXPECT_EQ(5, right->getPosition().getCol());
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
    ASTNodePtr leftChild =  std::dynamic_pointer_cast<ASTNode>(root->getChildAt(0));
    ASTNodePtr rightChild =  std::dynamic_pointer_cast<ASTNode>(root->getChildAt(1));

    EXPECT_EQ((size_t )2, root->getNumOfChildren());
    EXPECT_TRUE(root->isRoot());
    EXPECT_FALSE(root->isLeaf());
    EXPECT_EQ(1, root->getPosition().getRow());
    EXPECT_EQ(3, root->getPosition().getCol());


    EXPECT_EQ((size_t ) 0, leftChild->getNumOfChildren());
    EXPECT_FALSE(leftChild->isRoot());
    EXPECT_TRUE(leftChild->isLeaf());
    EXPECT_EQ(root.get(), leftChild->getParent());
    EXPECT_EQ(1, leftChild->getPosition().getRow());
    EXPECT_EQ(1, leftChild->getPosition().getCol());

    EXPECT_EQ((size_t ) 2, rightChild->getNumOfChildren());
    EXPECT_FALSE(rightChild->isRoot());
    EXPECT_FALSE(rightChild->isLeaf());
    EXPECT_EQ(root.get(), rightChild->getParent());
    EXPECT_EQ(1, rightChild->getPosition().getRow());
    EXPECT_EQ(7, rightChild->getPosition().getCol());

    ASTNodePtr leftGrandChild =  std::dynamic_pointer_cast<ASTNode>(rightChild->getChildAt(0));
    ASTNodePtr rightGrandChild =  std::dynamic_pointer_cast<ASTNode>(rightChild->getChildAt(1));

    EXPECT_EQ((size_t ) 0, leftGrandChild->getNumOfChildren());
    EXPECT_FALSE(leftGrandChild->isRoot());
    EXPECT_TRUE(leftGrandChild->isLeaf());
    EXPECT_EQ(rightChild.get(), leftGrandChild->getParent());
    EXPECT_EQ(1, leftGrandChild->getPosition().getRow());
    EXPECT_EQ(5, leftGrandChild->getPosition().getCol());

    EXPECT_EQ((size_t ) 0, rightGrandChild->getNumOfChildren());
    EXPECT_FALSE(rightGrandChild->isRoot());
    EXPECT_TRUE(rightGrandChild->isLeaf());
    EXPECT_EQ(rightChild.get(), rightGrandChild->getParent());
    EXPECT_EQ(1, rightGrandChild->getPosition().getRow());
    EXPECT_EQ(9, rightGrandChild->getPosition().getCol());
}

TEST(PARSE_ERROR, Parser_Error_1) {
	std::string line = "1 + 2 + ";
	ASTNodePtr root;
	MathParser parser;

	EXPECT_THROW(parser.parse(root, line), ParseException);
    EXPECT_EQ(8, yy_custom_col);
}

TEST(PARSE_ERROR, Parser_Error_2) {
    std::string line = "1 + 2 + ";
    ASTNodePtr root;
    MathParser parser;

    try {
        parser.parse(root, line);
    } catch(ParseException e) {
        std::cout << e.what() << std::endl;
    }
    EXPECT_EQ(8, yy_custom_col);
}

TEST(PARSE_ERROR, ParseExceptionTranslator_1) {
    EXPECT_THROW(ParseExceptionTranslator::translate("syntax error", "error message"), SyntaxError);
}

TEST(PARSE_ERROR, ParseExceptionTranslator_2) {
    EXPECT_THROW(ParseExceptionTranslator::translate("other error", "error message"), ParseException);
}