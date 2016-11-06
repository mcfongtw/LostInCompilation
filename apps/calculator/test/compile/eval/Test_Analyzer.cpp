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

TEST(ANALYZER, Functional_Const_Expr) {
	MathParser parser;
	ASTNodePtr root;
	SymTabStackPtr stStack = std::make_shared<SymbolTableStack>(ST_Simple);
    stStack->openScope();
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>(stStack);

	std::string expr = "777";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
//	std::cout << root->toString() << std::endl;

	RuntimeStack rtStack = analyzer->getRunTimeStack();
	ObjectValue answer = rtStack.top();
	EXPECT_EQ(777, answer.get<double>());
	rtStack.pop();
	EXPECT_TRUE(rtStack.isEmpty());

    EXPECT_EQ(1, stStack->size());
    stStack->closeScope();
    EXPECT_TRUE(stStack->isEmpty());
}

TEST(ANALYZER, Functional_Simple_Expr) {
	MathParser parser;
	ASTNodePtr root;
	SymTabStackPtr stStack = std::make_shared<SymbolTableStack>(ST_Simple);
    stStack->openScope();
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>(stStack);

	std::string expr = "1 * 3";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
//	std::cout << root->toString() << std::endl;

	RuntimeStack rtStack = analyzer->getRunTimeStack();
	ObjectValue answer = rtStack.top();
	EXPECT_EQ(3, answer.get<double>());
	rtStack.pop();
	EXPECT_TRUE(rtStack.isEmpty());

    EXPECT_EQ(1, stStack->size());
    stStack->closeScope();
    EXPECT_TRUE(stStack->isEmpty());
}

TEST(ANALYZER, Functional_Advanced_Expr) {
	MathParser parser;
	ASTNodePtr root;
	SymTabStackPtr stStack = std::make_shared<SymbolTableStack>(ST_Simple);
    stStack->openScope();
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>(stStack);

	std::string expr = "1 + 2 * 3.33";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	RuntimeStack rtStack = analyzer->getRunTimeStack();
	ObjectValue answer = rtStack.top();

	EXPECT_EQ(7.66, answer.get<double>());
	rtStack.pop();
	EXPECT_TRUE(rtStack.isEmpty());

    EXPECT_EQ(1, stStack->size());
    stStack->closeScope();
    EXPECT_TRUE(stStack->isEmpty());
}

TEST(ANALYZER, Functional_Simple_Symbol_Expr) {
	MathParser parser;
	ASTNodePtr root;
	SymTabStackPtr stStack = std::make_shared<SymbolTableStack>(ST_Simple);
    stStack->openScope();
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>(stStack);

	std::string expr = "x = 2";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	expr = "x * 3";
	parser.parse(root, expr);
	root->apply(analyzer, DEPTH_FIRST);
	//	std::cout << root->toString() << std::endl;

	RuntimeStack rtStack = analyzer->getRunTimeStack();
	ObjectValue answer = rtStack.top();

	EXPECT_EQ(6, answer.get<double>());
	rtStack.pop();
	EXPECT_TRUE(rtStack.isEmpty());


	EXPECT_TRUE(stStack.get()->lookup("x") != nullptr);
	EXPECT_STREQ("x", stStack.get()->lookup("x")->getName().c_str());
	EXPECT_EQ(2, stStack.get()->lookup("x")->getValue().get<double>());

    EXPECT_EQ(1, stStack->size());
    stStack->closeScope();
    EXPECT_TRUE(stStack->isEmpty());
}

TEST(ANALYZER, Functional_Multiple_Symbol_Expr) {
	MathParser parser;
	ASTNodePtr root;
	SymTabStackPtr stStack = std::make_shared<SymbolTableStack>(ST_Simple);
    stStack->openScope();
	std::shared_ptr<Analyzer> analyzer = std::make_shared<Analyzer>(stStack);

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
	SymTabStackPtr stSTack = analyzer->getSymbolTableStack();
	ObjectValue answer = stack.top();

	EXPECT_EQ(35, answer.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());

	EXPECT_TRUE(stSTack.get()->lookup("x") != nullptr);
	EXPECT_STREQ("x", stSTack.get()->lookup("x")->getName().c_str());
	EXPECT_EQ(2, stSTack.get()->lookup("x")->getValue().get<double>());

	EXPECT_TRUE(stSTack.get()->lookup("y") != nullptr);
	EXPECT_STREQ("y", stSTack.get()->lookup("y")->getName().c_str());
	EXPECT_EQ(3.3, stSTack.get()->lookup("y")->getValue().get<double>());

    EXPECT_EQ(1, stStack->size());
    stStack->closeScope();
    EXPECT_TRUE(stStack->isEmpty());
}
