/*
 * Test_AST.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */
#include "algorithm/tree/ast/ASTNode.h"
#include "algorithm/tree/ast/ASTUtils.h"
#include "gtest/gtest.h"

#include "error/Exception.h"

TEST(AST, Simple_Node) {
	VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);

	EXPECT_STREQ("+", std::dynamic_pointer_cast<ASTNode>(root)->getText());
	EXPECT_EQ(1, std::dynamic_pointer_cast<ASTNode>(root)->getToken());
	EXPECT_EQ(nullptr, root->getParent());
	EXPECT_EQ((size_t) 0, root->getNumOfChildren());
	EXPECT_THROW(root->getChildAt(0), IllegalStateException);
	EXPECT_TRUE(root->isLeaf());
	EXPECT_TRUE(root->isRoot());
}

TEST(AST, Simple_Abstract_Syntax_Tree) {
	VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
	VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

	root->insertChild(left);
	root->insertChild(right);

//	std::cout << root->toString() << std::endl;

	EXPECT_EQ((size_t)2, root->getNumOfChildren());
	EXPECT_TRUE(root->isRoot());
	EXPECT_FALSE(root->isLeaf());
	EXPECT_EQ((size_t) 0, root->getChildIndexOf(left));
	EXPECT_EQ((size_t) 1, root->getChildIndexOf(right));
	EXPECT_EQ(nullptr, root->getParent());

	EXPECT_EQ((size_t) 0, left->getNumOfChildren());
	EXPECT_FALSE(left->isRoot());
	EXPECT_TRUE(left->isLeaf());
	EXPECT_EQ(root.get(), left->getParent());

	EXPECT_EQ((size_t) 0, right->getNumOfChildren());
	EXPECT_FALSE(right->isRoot());
	EXPECT_TRUE(right->isLeaf());
	EXPECT_EQ(root.get(), right->getParent());
}

TEST(AST, Abstract_Syntax_Tree_Replace) {
	VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
	VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

	root->insertChild(left);
	root->insertChild(right);

	//	std::cout << root->toString() << std::endl

	TreeNodePtr newRoot = std::make_shared<ASTNode>("3", 2);

	root->replace(newRoot);

	EXPECT_STREQ("3", std::dynamic_pointer_cast<ASTNode>(newRoot)->getText());
	EXPECT_EQ(2, std::dynamic_pointer_cast<ASTNode>(newRoot)->getToken());
	EXPECT_EQ((size_t) 2, newRoot->getNumOfChildren());
	EXPECT_EQ(left, newRoot->getChildAt(0));
	EXPECT_EQ(right, std::dynamic_pointer_cast<ASTNode>(newRoot)->getChildAt(1));
	EXPECT_FALSE(newRoot->isLeaf());
	EXPECT_TRUE(newRoot->isRoot());

	EXPECT_EQ(newRoot.get(), left->getParent());
	EXPECT_EQ(newRoot.get(), right->getParent());
}

TEST(AST, AST_Utils_Reduce_1) {
	VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);
	VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

	root->insertChild(left);
	root->insertChild(right);

	VisitedTreeNodePtr result =  std::make_shared<ASTNode>("3", 2);

	ASTUtils::reduceTree(std::dynamic_pointer_cast<VisitedTreeNode>(root), result);

	EXPECT_STREQ("3", std::dynamic_pointer_cast<ASTNode>(result)->getText());
	EXPECT_EQ(2, std::dynamic_pointer_cast<ASTNode>(result)->getToken());
	EXPECT_EQ(nullptr, result->getParent());
	EXPECT_EQ((size_t) 0, result->getNumOfChildren());
	EXPECT_THROW(result->getChildAt(0), IllegalStateException);
	EXPECT_TRUE(result->isLeaf());
	EXPECT_TRUE(result->isRoot());
}
