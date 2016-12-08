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

TEST(AST, UNIT_Simple_Node) {
	VisitedTreeNodePtr root = std::make_shared<ASTNode>("+", 1);

	EXPECT_STREQ("+", std::dynamic_pointer_cast<ASTNode>(root)->getText());
	EXPECT_EQ(1, std::dynamic_pointer_cast<ASTNode>(root)->getToken());
	EXPECT_EQ(nullptr, root->getParent());
	EXPECT_EQ((size_t) 0, root->getNumOfChildren());
	EXPECT_THROW(root->getChildAt(0), IllegalStateException);
	EXPECT_TRUE(root->isLeaf());
	EXPECT_TRUE(root->isRoot());
}

TEST(AST, UNIT_Simple_Abstract_Syntax_Tree) {
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

TEST(AST, UNIT_Abstract_Syntax_Tree_Replace_1) {
	VisitedTreeNodePtr oldRoot = std::make_shared<ASTNode>("+", 1);
	VisitedTreeNodePtr left = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr right = std::make_shared<ASTNode>("2", 2);

	oldRoot->insertChild(left);
	oldRoot->insertChild(right);

	//	std::cout << oldRoot->toString() << std::endl

	TreeNodePtr newRoot = std::make_shared<ASTNode>("-", 3);

	oldRoot->replace(newRoot);

    ASTNodePtr testRoot = std::dynamic_pointer_cast<ASTNode>(newRoot);

	EXPECT_STREQ("-", testRoot->getText());
	EXPECT_EQ(3, testRoot->getToken());
	EXPECT_EQ((size_t) 2, testRoot->getNumOfChildren());
	EXPECT_EQ(left, testRoot->getChildAt(0));
	EXPECT_EQ(right, testRoot->getChildAt(1));
	EXPECT_FALSE(testRoot->isLeaf());
	EXPECT_TRUE(testRoot->isRoot());

	EXPECT_EQ(testRoot.get(), left->getParent());
	EXPECT_EQ(testRoot.get(), right->getParent());
}


TEST(AST, UNIT_AST_Utils_Reduce_1) {
    /*
     *    R
     *    |
     *    +
     *   / \
     *  1   2
     *
     */
	VisitedTreeNodePtr root = std::make_shared<ASTNode>("R", 99);
	VisitedTreeNodePtr opPlus = std::make_shared<ASTNode>("+", 1);
	VisitedTreeNodePtr operand1 = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr operand2 = std::make_shared<ASTNode>("2", 2);

	root->insertChild(opPlus);

	opPlus->insertChild(operand1);
	opPlus->insertChild(operand2);

	VisitedTreeNodePtr answer =  std::make_shared<ASTNode>("3", 2);

    /*
     *   R
     *   |
     *   3
     */
    ASTUtils::reduceTreeWithoutChildren(std::dynamic_pointer_cast<VisitedTreeNode>(opPlus), answer);

    ASTNodePtr testChild = std::dynamic_pointer_cast<ASTNode>(root->getChildAt(0));

	EXPECT_STREQ("3", testChild->getText());
	EXPECT_EQ(2, testChild->getToken());
	EXPECT_EQ(root.get(), testChild->getParent());
	EXPECT_EQ((size_t) 0, testChild->getNumOfChildren());
	EXPECT_THROW(testChild->getChildAt(0), IllegalStateException);
	EXPECT_TRUE(testChild->isLeaf());
	EXPECT_FALSE(testChild->isRoot());
	EXPECT_EQ(root->getChildAt(0), testChild);
}


TEST(AST, UNIT_AST_Utils_Reduce_2) {
    /*
     *    R
     *    |
     *    +
     *   / \
     *  1   2
     *
     */
    VisitedTreeNodePtr root = std::make_shared<ASTNode>("R", 99);
    VisitedTreeNodePtr opPlus = std::make_shared<ASTNode>("+", 1);
    VisitedTreeNodePtr operand1 = std::make_shared<ASTNode>("1", 2);
    VisitedTreeNodePtr operand2 = std::make_shared<ASTNode>("2", 2);

    root->insertChild(opPlus);

    opPlus->insertChild(operand1);
    opPlus->insertChild(operand2);

	/*
     *    *
     *   / \
     *  2   3
     *
     */
    VisitedTreeNodePtr opMultiply =  std::make_shared<ASTNode>("*", 1);
    VisitedTreeNodePtr operand11 = std::make_shared<ASTNode>("2", 2);
    VisitedTreeNodePtr operand22 = std::make_shared<ASTNode>("3", 2);
    opPlus->insertChild(operand11);
    opPlus->insertChild(operand22);

	/*
     *      R
     *      |
     *      *
     *   / \  \  \
     *  1  2  2  3
     *
     */
    ASTUtils::reduceTree(std::dynamic_pointer_cast<VisitedTreeNode>(opPlus), opMultiply);

    ASTNodePtr testNode = std::dynamic_pointer_cast<ASTNode>(root->getChildAt(0));

    EXPECT_STREQ("*", testNode->getText());
    EXPECT_EQ(1, testNode->getToken());
    EXPECT_EQ(root.get(), testNode->getParent());
    EXPECT_EQ((size_t) 4, testNode->getNumOfChildren());
    EXPECT_EQ(testNode->getChildAt(0), operand1);
    EXPECT_EQ(testNode->getChildAt(1), operand2);
    EXPECT_EQ(testNode->getChildAt(2), operand11);
    EXPECT_EQ(testNode->getChildAt(3), operand22);
    EXPECT_FALSE(testNode->isLeaf());
    EXPECT_FALSE(testNode->isRoot());
    EXPECT_EQ(root->getChildAt(0), testNode);
}


#include "tool/DotPrinter.h"
#include "tool/Appender.h"
#include "hack/DebugLib.h"
#include <string>


TEST(AST, UNIT_Abstract_Syntax_Tree_Replace_With_Direct_Hierarchy_1) {
	VisitedTreeNodePtr oldRoot = std::make_shared<ASTNode>("R", 1);
	VisitedTreeNodePtr arg02 = std::make_shared<ASTNode>("ARGS", 199);
	VisitedTreeNodePtr arg11 = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr arg12 = std::make_shared<ASTNode>("ARGS", 299);
	VisitedTreeNodePtr arg21 = std::make_shared<ASTNode>("2", 2);

	oldRoot->insertChild(arg02);
	arg02->insertChild(arg11);
	arg02->insertChild(arg12);
	arg12->insertChild(arg21);

	/*
	 *     R
	 *     |
	 *    ARGS    --> that  (arg02)
	 *   /   \
	 * 1    ARGS  --> this  (arg12)
	 *        |
	 *        2
	 *
	 */
	ASTUtils::reduceTree(arg12, arg02);
	/*
	 *     R
	 *     |
	 *    ARGS    --> that  (arg02)
	 *   /   \
	 *  1     2
	 *
	 */

	std::shared_ptr<DotPrinter> printer = std::make_shared<DotPrinter>();
	std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
	printer->addAppender(stringAppender);

	oldRoot->apply(printer, DEPTH_FIRST);
	std::cout << stringAppender->toString() << std::endl;

	ASTNodePtr testNode = std::dynamic_pointer_cast<ASTNode>(oldRoot->getChildAt(0));


	EXPECT_EQ((size_t) 2, testNode->getNumOfChildren());
	EXPECT_EQ(199, testNode->getToken());
    EXPECT_EQ(arg11, testNode->getChildAt(0));
    EXPECT_EQ(arg21, testNode->getChildAt(1));
    EXPECT_EQ(arg11->getParent(), testNode.get());
    EXPECT_EQ(arg21->getParent(), testNode.get());

}


TEST(AST, UNIT_Abstract_Syntax_Tree_Replace_With_Direct_Hierarchy_2) {
	VisitedTreeNodePtr oldRoot = std::make_shared<ASTNode>("R", 1);
	VisitedTreeNodePtr arg02 = std::make_shared<ASTNode>("ARGS", 199);
	VisitedTreeNodePtr arg11 = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr arg12 = std::make_shared<ASTNode>("ARGS", 299);
	VisitedTreeNodePtr arg21 = std::make_shared<ASTNode>("2", 2);

	oldRoot->insertChild(arg02);
	arg02->insertChild(arg11);
	arg02->insertChild(arg12);
	arg12->insertChild(arg21);

	/*
	 *     R
	 *     |
	 *    ARGS    --> this  (arg02)
	 *   /   \
	 * 1    ARGS  --> that  (arg12)
	 *        |
	 *        2
	 *
	 */
	ASTUtils::reduceTree(arg02, arg12);
	/*
	 *     R
	 *     |
	 *    ARGS    --> that  (arg12)
	 *   /   \
	 *  2     1
	 *
	 */

	std::shared_ptr<DotPrinter> printer = std::make_shared<DotPrinter>();
	std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
	printer->addAppender(stringAppender);

	oldRoot->apply(printer, DEPTH_FIRST);
	std::cout << stringAppender->toString() << std::endl;

	ASTNodePtr testNode = std::dynamic_pointer_cast<ASTNode>(oldRoot->getChildAt(0));

	EXPECT_EQ((size_t) 2, testNode->getNumOfChildren());
	EXPECT_EQ(299, testNode->getToken());
	EXPECT_EQ(arg21, testNode->getChildAt(0));
	EXPECT_EQ(arg11, testNode->getChildAt(1));
	EXPECT_EQ(arg11->getParent(), testNode.get());
	EXPECT_EQ(arg21->getParent(), testNode.get());
}

TEST(AST, UNIT_Abstract_Syntax_Tree_Replace_With_Direct_Hierarchy_3) {
	VisitedTreeNodePtr oldRoot = std::make_shared<ASTNode>("R", 1);
	VisitedTreeNodePtr arg02 = std::make_shared<ASTNode>("ARGS", 199);
	VisitedTreeNodePtr arg11 = std::make_shared<ASTNode>("1", 2);
	VisitedTreeNodePtr arg12 = std::make_shared<ASTNode>("ARGS", 299);
	VisitedTreeNodePtr arg21 = std::make_shared<ASTNode>("2", 2);
	VisitedTreeNodePtr arg22 = std::make_shared<ASTNode>("ARGS", 399);
	VisitedTreeNodePtr arg31 = std::make_shared<ASTNode>("3", 2);

	oldRoot->insertChild(arg02);
	arg02->insertChild(arg11);
	arg02->insertChild(arg12);
	arg12->insertChild(arg21);
	arg12->insertChild(arg22);
	arg22->insertChild(arg31);

	/*
	 *     R
	 *     |
	 *    ARGS
	 *   /   \
	 * 1    ARGS    --> that  (arg12)
	 *      /  \
	 *     2  ARGS  --> this  (arg22)
	 *          \
	 *          3
	 */
	ASTUtils::reduceTree(arg22, arg12);
	/*
	 *     R
	 *     |
	 *    ARGS
	 *   /   \
	 * 1    ARGS    --> that  (arg12)
	 *      /  \
	 *     2   3
	 */

	/*
	 *     R
	 *     |
	 *    ARGS      --> that  (arg02)
	 *   /   \
	 * 1    ARGS    --> this  (arg12)
	 *      /  \
	 *     2   3
	 */
	ASTUtils::reduceTree(arg12, arg02);
	/*
	 *     R
	 *     |
	 *    ARGS      --> that  (arg02)
	 *   / |  \
	 * 1   2  3
	 */

	std::shared_ptr<DotPrinter> printer = std::make_shared<DotPrinter>();
	std::shared_ptr<StringAppender> stringAppender = std::make_shared<StringAppender>();
	printer->addAppender(stringAppender);

	oldRoot->apply(printer, DEPTH_FIRST);
	std::cout << stringAppender->toString() << std::endl;

	ASTNodePtr testNode = std::dynamic_pointer_cast<ASTNode>(oldRoot->getChildAt(0));


	EXPECT_EQ((size_t) 3, testNode->getNumOfChildren());
	EXPECT_EQ(199, testNode->getToken());
	EXPECT_EQ(arg11, testNode->getChildAt(0));
	EXPECT_EQ(arg21, testNode->getChildAt(1));
	EXPECT_EQ(arg31, testNode->getChildAt(2));
	EXPECT_EQ(arg11->getParent(), testNode.get());
	EXPECT_EQ(arg21->getParent(), testNode.get());
	EXPECT_EQ(arg31->getParent(), testNode.get());
}
