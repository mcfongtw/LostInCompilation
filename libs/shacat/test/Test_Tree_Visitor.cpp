/*
 * Test_Tree_Visitor.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: Michael Fong
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

#include "algorithm/tree/TreeBuilder.h"
#include "algorithm/tree/visitor/VisitedTreeNode.h"

static int staticNodeID = 0;
static std::vector<int> staticNodeIDSequence;

class TestVisitedTreeNode: public VisitedTreeNode {

public:
	TestVisitedTreeNode() :
			VisitedTreeNode() {
		this->_id = staticNodeID++;
		LOG(Logger::LEVEL_TRACE,
				"Creating <<" + util::Converts::numberToString(this)
						+ ">> TestTreeNode@["
						+ util::Converts::numberToString(this->_depth) + "]");
	}

	virtual ~TestVisitedTreeNode() {
		LOG(Logger::LEVEL_TRACE,
				"Deleting <<" + util::Converts::numberToString(this)
						+ ">> TestTreeNode@["
						+ util::Converts::numberToString(this->_depth) + "]");
	}

	virtual std::string toString() {
		return "id : " + util::Converts::numberToString<int>(this->_id) + "\t"
				+ VisitedTreeNode::toString();
	}

	virtual int apply(TreeWalker* walker, TraverseAction action) {
		staticNodeIDSequence.push_back(this->_id);
		return 1;
	}

	int _id;
};

class TestTreeWalker: public TreeWalker {

public:

	TestTreeWalker() :TreeWalker() {

	}

	virtual ~TestTreeWalker() {

	}

	virtual int walk(VisitedTreeNodePtr ptr) {
		std::shared_ptr<TestVisitedTreeNode> current = std::dynamic_pointer_cast<TestVisitedTreeNode>(ptr);
		staticNodeIDSequence.push_back(current->_id);
		return 1;
	}

protected:
	virtual int startWalking() {
		return 1;
	}

	virtual int stopWalking() {
		return 1;
	}
};

//Test Fixtures
class TREE_VISITOR: public ::testing::Test {
protected:
	TREE_VISITOR() {
	}

	virtual ~TREE_VISITOR() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).

		for (size_t i = 0; i < 7; i++) {
			TreeBuilder<TestVisitedTreeNode, VisitedTreeNodePtr> builder;
			this->_builders.push_back(builder);
		}

		for (size_t i = 0; i < 7 / 2; i++) {
			TreeBuilder<TestVisitedTreeNode, VisitedTreeNodePtr> builder1 =
					this->_builders[i];
			TreeBuilder<TestVisitedTreeNode, VisitedTreeNodePtr> builder2 =
					this->_builders[i * 2 + 1];
			TreeBuilder<TestVisitedTreeNode, VisitedTreeNodePtr> builder3 =
					this->_builders[i * 2 + 2];
			builder1.addChild(builder2.toTree()).addChild(builder3.toTree());
		}
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).

		staticNodeID = 0;
		staticNodeIDSequence.clear();
	}

	// Objects declared here can be used by all tests in the test case
	std::vector<TreeBuilder<TestVisitedTreeNode, VisitedTreeNodePtr>> _builders;
};

TEST_F(TREE_VISITOR, In_Order_Traversal) {
	VisitedTreeNodePtr root = _builders[0].toTree();

	TreeWalkerPtr walker = std::make_shared<TestTreeWalker>();

//	std::cout << "root " << root->toString() << std::endl;

	root->apply(walker, IN_ORDER);

	const size_t expected[] = { 3, 1, 4, 0, 5, 2, 6 };
	ASSERT_THAT(staticNodeIDSequence, testing::ElementsAreArray(expected));
}

TEST_F(TREE_VISITOR, Pre_Order_Traversal) {
	VisitedTreeNodePtr root = _builders[0].toTree();

	TreeWalkerPtr walker = std::make_shared<TestTreeWalker>();

//	std::cout << "root " << root->toString() << std::endl;

	root->apply(walker, PRE_ORDER);

	const size_t expected[] = { 0, 1, 3, 4, 2, 5, 6 };
	ASSERT_THAT(staticNodeIDSequence, testing::ElementsAreArray(expected));
}

TEST_F(TREE_VISITOR, Post_Order_Traversal) {
	VisitedTreeNodePtr root = _builders[0].toTree();

	TreeWalkerPtr walker = std::make_shared<TestTreeWalker>();

//	std::cout << "root " << root->toString() << std::endl;

	root->apply(walker, POST_ORDER);

	const size_t expected[] = { 3, 4, 1, 5, 6, 2, 0 };
	ASSERT_THAT(staticNodeIDSequence, testing::ElementsAreArray(expected));
}

TEST_F(TREE_VISITOR, Depth_First_Traversal) {
	VisitedTreeNodePtr root = _builders[0].toTree();

	TreeWalkerPtr walker = std::make_shared<TestTreeWalker>();

//	std::cout << "root " << root->toString() << std::endl;

	root->apply(walker, DEPTH_FIRST);

	const size_t expected[] = { 0, 1, 3, 3, 4, 4, 1, 2, 5, 5, 6, 6, 2, 0 };
	ASSERT_THAT(staticNodeIDSequence, testing::ElementsAreArray(expected));
}

TEST_F(TREE_VISITOR, Breadt_First_Traversal) {
	VisitedTreeNodePtr root = _builders[0].toTree();

	TreeWalkerPtr walker = std::make_shared<TestTreeWalker>();

//	std::cout << "root " << root->toString() << std::endl;

	root->apply(walker, BREADTH_FIRST);

	const size_t expected[] = {0, 1, 2, 3, 4, 5, 6 };
	ASSERT_THAT(staticNodeIDSequence, testing::ElementsAreArray(expected));
}

