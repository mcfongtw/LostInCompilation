/*
 * Test_Evaluator.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */

#include <string>

#include "gtest/gtest.h"
#include "compile/parser/MathParser.h"
#include "compile/eval/Analyzer.h"

TEST(ANALYZER, First_Expr) {
	MathParser parser;
	ASTNodePtr root;
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>();

	std::string expr = "777";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
//	std::cout << root->toString() << std::endl;

	RuntimeStack stack = analyzer->getRunTimeStack();
	ObjectValue answer = stack.top();
	EXPECT_EQ(777, answer.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());
}

TEST(ANALYZER, Simple_Expr) {
	MathParser parser;
	ASTNodePtr root;
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>();

	std::string expr = "1 * 3";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
//	std::cout << root->toString() << std::endl;

	RuntimeStack stack = analyzer->getRunTimeStack();
	ObjectValue answer = stack.top();
	EXPECT_EQ(3, answer.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());
}

TEST(ANALYZER, Advanced_Expr) {
	MathParser parser;
	ASTNodePtr root;
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>();

	std::string expr = "1 + 2 * 3.33";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	RuntimeStack stack = analyzer->getRunTimeStack();
	ObjectValue answer = stack.top();

	EXPECT_EQ(7.66, answer.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());
}

TEST(ANALYZER, Simple_Symbol_Expr) {
	MathParser parser;
	ASTNodePtr root;
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>();

	std::string expr = "x = 2";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	expr = "x * 3";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	RuntimeStack stack = analyzer->getRunTimeStack();
    SymbolTablePtr table = analyzer->getSymbolTable();
	ObjectValue answer = stack.top();

	EXPECT_EQ(6, answer.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());

	EXPECT_TRUE(table.get()->lookup("x") != nullptr);
	EXPECT_STREQ("x", table.get()->lookup("x")->getName().c_str());
	EXPECT_EQ(2, table.get()->lookup("x")->getValue().get<double>());
}

TEST(ANALYZER, More_Symbol_Expr) {
	MathParser parser;
	ASTNodePtr root;
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>();

	std::string expr = "x = 2";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	expr = "y = 3.3";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	expr = "x + y * 10";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	RuntimeStack stack = analyzer->getRunTimeStack();
    SymbolTablePtr table = analyzer->getSymbolTable();
	ObjectValue answer = stack.top();

	EXPECT_EQ(35, answer.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());

	EXPECT_TRUE(table.get()->lookup("x") != nullptr);
	EXPECT_STREQ("x", table.get()->lookup("x")->getName().c_str());
	EXPECT_EQ(2, table.get()->lookup("x")->getValue().get<double>());

	EXPECT_TRUE(table.get()->lookup("y") != nullptr);
	EXPECT_STREQ("y", table.get()->lookup("y")->getName().c_str());
	EXPECT_EQ(3.3, table.get()->lookup("y")->getValue().get<double>());
}
