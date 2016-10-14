/*
 * Test_Tree_Traverse.cpp
 *
 *  Created on: Dec 28, 2014
 *      Author: Michael Fong
 */


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

#include "algorithm/tree/TreeBuilder.h"
#include "algorithm/tree/traditional/LIFO/TreeTraverse.h"

static int staticNodeID = 0;

class TestTreeTraverseNode: public TreeNode {

public:
	TestTreeTraverseNode() :
			TreeNode() {
		this->_id = staticNodeID++;
		LOG(Logger::LEVEL_TRACE,
				"Creating <<" + util::Converts::numberToString(this)
						+ ">> TestTreeTraverseNode@["
						+ util::Converts::numberToString(this->_depth) + "]");
	}

	virtual ~TestTreeTraverseNode() {
		LOG(Logger::LEVEL_TRACE,
				"Deleting <<" + util::Converts::numberToString(this)
						+ ">> TestTreeTraverseNode@["
						+ util::Converts::numberToString(this->_depth) + "]");
	}

	virtual std::string toString() {
		return "id : " + util::Converts::numberToString<int>(this->_id) + "\t"
				+ TreeNode::toString();
	}

	int _id;
};

//Test Fixtures
class TREE_TRAVERSE: public ::testing::Test {
protected:
	TREE_TRAVERSE() {
	}

	virtual ~TREE_TRAVERSE() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).

		for (size_t i = 0; i < 7; i++) {
			TreeBuilder<TestTreeTraverseNode, TreeNodePtr> builder;
			this->_builders.push_back(builder);
		}

		for (size_t i = 0; i < 7 / 2; i++) {
			TreeBuilder<TestTreeTraverseNode, TreeNodePtr> builder1 =
					this->_builders[i];
			TreeBuilder<TestTreeTraverseNode, TreeNodePtr> builder2 =
					this->_builders[i * 2 + 1];
			TreeBuilder<TestTreeTraverseNode, TreeNodePtr> builder3 =
					this->_builders[i * 2 + 2];
			builder1.addChild(builder2.toTree()).addChild(builder3.toTree());
		}
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).

		staticNodeID = 0;
	}

	// Objects declared here can be used by all tests in the test case
	std::vector<TreeBuilder<TestTreeTraverseNode, TreeNodePtr>> _builders;
};

std::vector<int> collect(TreeNodeStack& stack) {
	std::vector<int> result;
	for(size_t i = 0; i < stack.size(); i++) {
		std::shared_ptr<TestTreeTraverseNode> current = std::dynamic_pointer_cast<TestTreeTraverseNode>(stack[i]);
		result.push_back(current->_id);
	}

	return result;
}

TEST_F(TREE_TRAVERSE, In_Order_Traversal) {
	TreeNodePtr root = _builders[0].toTree();

	TreeTraverse traverse;

	traverse.apply(root, IN_ORDER);

//	std::cout << "root " << root->toString() << std::endl;

	TreeNodeStack stack = traverse.getNodeStack();

	std::vector<int> result = collect(stack);

	const size_t expected[] = { 3, 1, 4, 0, 5, 2, 6 };
	ASSERT_THAT(result, testing::ElementsAreArray(expected));
}

TEST_F(TREE_TRAVERSE, Pre_Order_Traversal) {
	TreeNodePtr root = _builders[0].toTree();

	TreeTraverse traverse;

	traverse.apply(root, PRE_ORDER);

	//	std::cout << "root " << root->toString() << std::endl;

	TreeNodeStack stack = traverse.getNodeStack();

	std::vector<int> result = collect(stack);

	const size_t expected[] = { 0, 1, 3, 4, 2, 5, 6 };
	ASSERT_THAT(result, testing::ElementsAreArray(expected));
}

TEST_F(TREE_TRAVERSE, Post_Order_Traversal) {
	TreeNodePtr root = _builders[0].toTree();

	TreeTraverse traverse;

	traverse.apply(root, POST_ORDER);

	//	std::cout << "root " << root->toString() << std::endl;

	TreeNodeStack stack = traverse.getNodeStack();

	std::vector<int> result = collect(stack);

	const size_t expected[] = { 3, 4, 1, 5, 6, 2, 0 };
	ASSERT_THAT(result, testing::ElementsAreArray(expected));
}

TEST_F(TREE_TRAVERSE, Depth_First_Traversal) {
	TreeNodePtr root = _builders[0].toTree();

	TreeTraverse traverse;

	traverse.apply(root, DEPTH_FIRST);

//	std::cout << "root " << root->toString() << std::endl;

	TreeNodeStack stack = traverse.getNodeStack();

	std::vector<int> result = collect(stack);

	const size_t expected[] = { 0, 1, 3, 3, 4, 4, 1, 2, 5, 5, 6, 6, 2, 0 };
	ASSERT_THAT(result, testing::ElementsAreArray(expected));
}

TEST_F(TREE_TRAVERSE, Breadt_First_Traversal) {
	TreeNodePtr root = _builders[0].toTree();

	TreeTraverse traverse;

	traverse.apply(root, BREADTH_FIRST);

//	std::cout << "root " << root->toString() << std::endl;

	TreeNodeStack stack = traverse.getNodeStack();

	std::vector<int> result = collect(stack);

	const size_t expected[] = {0, 1, 2, 3, 4, 5, 6 };
	ASSERT_THAT(result, testing::ElementsAreArray(expected));
}
