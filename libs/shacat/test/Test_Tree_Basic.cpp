/*
 * Test_Tree_Basic.cpp
 *
 *  Created on: Nov 28, 2014
 *      Author: Michael Fong
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

#include "algorithm/tree/TreeBuilder.h"
#include "algorithm/tree/TreeNode.h"


//Test Fixtures
class TREE_BASIC: public ::testing::Test {
protected:
	TREE_BASIC() {
	}

	virtual ~TREE_BASIC() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).

		for (size_t i = 0; i < 7; i++) {
			TreeBuilder<TreeNode, TreeNodePtr> builder;
			this->_builders.push_back(builder);
		}

		for (size_t i = 0; i < 7 / 2; i++) {
			TreeBuilder<TreeNode, TreeNodePtr> builder1 =
					this->_builders[i];
			TreeBuilder<TreeNode, TreeNodePtr> builder2 =
					this->_builders[i * 2 + 1];
			TreeBuilder<TreeNode, TreeNodePtr> builder3 =
					this->_builders[i * 2 + 2];
			builder1.addChild(builder2.toTree()).addChild(builder3.toTree());
		}
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case
	std::vector<TreeBuilder<TreeNode, TreeNodePtr>> _builders;
};

TEST_F(TREE_BASIC, Simple) {
	TreeNodePtr root = _builders[0].toTree();

//	std::cout << root->toString() << std::endl;

	TreeNodePtr son = root->getChildAt(0);
	TreeNodePtr grandson1 = son->getChildAt(0);
	TreeNodePtr grandson2 = son->getChildAt(0);
	TreeNodePtr daughter = root->getChildAt(1);
	TreeNodePtr granddaughter1 = daughter->getChildAt(1);
	TreeNodePtr granddaughter2 = daughter->getChildAt(1);

	EXPECT_EQ(2, root->getNumOfChildren());
	EXPECT_EQ(0, root->getDepth());
	EXPECT_TRUE(root->isRoot());
	EXPECT_EQ(root->getParent(), nullptr);

	EXPECT_EQ(2, son->getNumOfChildren());
	EXPECT_EQ(1, son->getDepth());
	EXPECT_FALSE(son->isRoot());
	EXPECT_FALSE(son->isLeaf());
	EXPECT_EQ(son->getParent(), root.get());

	EXPECT_EQ(0, grandson1->getNumOfChildren());
	EXPECT_EQ(2, grandson1->getDepth());
	EXPECT_TRUE(grandson1->isLeaf());
	EXPECT_EQ(grandson1->getParent(), son.get());

	EXPECT_EQ(0, grandson2->getNumOfChildren());
	EXPECT_EQ(2, grandson2->getDepth());
	EXPECT_TRUE(grandson2->isLeaf());
	EXPECT_EQ(grandson2->getParent(), son.get());

	EXPECT_EQ(2, daughter->getNumOfChildren());
	EXPECT_EQ(1, daughter->getDepth());
	EXPECT_FALSE(daughter->isRoot());
	EXPECT_FALSE(daughter->isLeaf());
	EXPECT_EQ(daughter->getParent(), root.get());

	EXPECT_EQ(0, granddaughter1->getNumOfChildren());
	EXPECT_EQ(2, granddaughter1->getDepth());
	EXPECT_TRUE(granddaughter1->isLeaf());
	EXPECT_EQ(granddaughter1->getParent(), daughter.get());

	EXPECT_EQ(0, granddaughter2->getNumOfChildren());
	EXPECT_EQ(2, granddaughter2->getDepth());
	EXPECT_TRUE(granddaughter2->isLeaf());
	EXPECT_EQ(granddaughter2->getParent(), daughter.get());
}

TEST_F(TREE_BASIC, ReplaceRoot) {
	TreeNodePtr root = _builders[0].toTree();
	TreeNodePtr son = root->getChildAt(0);

	TreeBuilder<TreeNode, TreeNodePtr> builder;
	TreeNodePtr newRoot = builder.toTree();

//	std::cout << "Before : " << root->toString() << std::endl;
	root->replace(newRoot);
//	root = newRoot;
//	std::cout << "After : " << root->toString() << std::endl;

	EXPECT_EQ(son->getParent(), newRoot.get());
}

TEST_F(TREE_BASIC, ReplaceIntermediate) {
	TreeNodePtr root = _builders[0].toTree();
	TreeNodePtr son = root->getChildAt(0);

	TreeBuilder<TreeNode, TreeNodePtr> builder;
	TreeNodePtr newSon = builder.toTree();

//	std::cout << "Before : " << root->toString() << std::endl;
	son->replace(newSon);
//	std::cout << "After : " << root->toString() << std::endl;
	EXPECT_EQ(root->getChildAt(0), newSon);
}

TEST_F(TREE_BASIC, ReplaceLeaf) {
	TreeNodePtr root = _builders[0].toTree();

	TreeBuilder<TreeNode, TreeNodePtr> builder;
	TreeNodePtr newGrandson = builder.toTree();

	TreeNodePtr son = root->getChildAt(0);
	TreeNodePtr grandson = son->getChildAt(0);

//	std::cout << "Before : " << root->toString() << std::endl;
	grandson->replace(newGrandson);
//	std::cout << "After : " << root->toString() << std::endl;

	EXPECT_EQ(son->getChildAt(0), newGrandson);
}
