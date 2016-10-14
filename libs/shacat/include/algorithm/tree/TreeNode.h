/*
 * TreeNode.h
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#ifndef TREENODE_H_
#define TREENODE_H_

//for size_t
#include "stdlib.h"
#include <vector>
#include <memory>
#include <string>

#include "algorithm/tree/TreeContext.h"

class TreeNode;

typedef std::shared_ptr<TreeNode> TreeNodePtr;
typedef TreeNode* ParentNodePtr;

/**
 * A generic implementation of a tree data structure, where each TreeNode contains
 * 1) no children node - Leaf
 * 2) more than 1 children nodes - intermediate node.
 *
 * Each TreeNode also has a link that points to its parent node, indicating if it is a root node
 *
 * One of the other implementation of Visitor pattern to visit (accept) current node and recursively visit
 * the children nodes if there are any (depth-first way)
 */

//TODO: making it template
class TreeNode : public std::enable_shared_from_this<TreeNode>{
public:
	TreeNode();

	TreeNode(TreeNode* const);

	TreeNode(TreeNodePtr that);

	virtual ~TreeNode();

	virtual void insertChild(TreeNodePtr, ParentNodePtr);

	virtual void insertChild(TreeNodePtr);

	virtual void insertChildren(std::vector<TreeNodePtr>&);

	virtual size_t getNumOfChildren();

	virtual size_t getChildIndexOf(TreeNodePtr);

	virtual bool isChildAt(size_t i);

	virtual TreeNodePtr getChildAt(size_t i);

	virtual void replaceChildAt(size_t, TreeNodePtr);

	virtual void removeAllChildren();

	virtual ParentNodePtr getParent();

	virtual bool isRoot();

	virtual bool isLeaf();

	virtual size_t getDepth();

	virtual void setState(TraverseAction action);

	virtual TraverseAction getState();

	virtual void setParent(ParentNodePtr ptr);

	virtual void replace(TreeNodePtr that);

	virtual std::string toString();

protected:

	virtual TreeNodePtr getThisPtr();

	std::vector<TreeNodePtr> _children;

	bool _isRoot;

	size_t _depth;

	/*
	 * Since smart pointer (shared_ptr) is deleted automatically through class destructors, thus, would cause cyclic referencing (free twice)
	 * Therefore, use raw (manual) pointer to keep track of parent node.
	 *
	 */
	ParentNodePtr _parent;

	TraverseAction _state;

private:
	TreeNodePtr searchParent(TreeNodePtr target);

};

#endif /* TREENODE_H_ */
