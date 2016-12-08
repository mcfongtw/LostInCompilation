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
 * -# Leaf node : no children node.
 * -# Intermediate node : more than 1 children nodes.
 *
 * Each TreeNode also has a link that points to its parent node, indicating if it is a root node
 *
 * One of the other implementation of Visitor pattern to visit (accept) current node and recursively visit
 * the children nodes if there are any (depth-first way)
 *
 * @since 0.1
 */
//TODO: making it template
class TreeNode : public std::enable_shared_from_this<TreeNode>{
public:
    /// Default Constructor
	TreeNode();

    /// Copy Constructor with raw pointer
	TreeNode(TreeNode* const);

    /// Copy Constructor with shared_ptr
	TreeNode(TreeNodePtr that);

    /// Default Destructor
	virtual ~TreeNode();

    /**
     * add TreeNodePtr as child and set ParentNodePtr as the parent of child node
     *
     * @param childPtr child node pointer
     * @param parentPtr parent node pointer
     *
     */
	virtual void insertChild(TreeNodePtr childPtr, ParentNodePtr parentPtr);

    /**
     * add childPtr as child node and set the current node as the parent of child node
     *
     * @param childPtr child node pointer
     *
     */
	virtual void insertChild(TreeNodePtr childPtr);

    /**
     * add childrenPtr as list of child nodes and set the current node as the parent of those child nodes
     *
     * @param childrenPtr a list / vector of child node pointers
     *
     */
	virtual void insertChildren(std::vector<TreeNodePtr>& childrenPtr);

    /**
     * Retrieve # of children (nodes)
     * @return A positive integer that represents the number of children.
     */
	virtual size_t getNumOfChildren();

    /**
     * Retrieve the index of desginated child node
     *
     * @param ptr A pointer to one of the child TreeNode
     * @return A positive number indicating the index of the given child node; -1, otherwise.
     */
	virtual size_t getChildIndexOf(TreeNodePtr ptr);

    /**
     * Check whether there are more than certain number of children.
     *
     * @return true if child exists at certain index; false, otherwise.
     */
	virtual bool isChildAt(size_t i);

    /**
     * Retrieve the pointer of child TreeNode given a index
     *
     * @param index A positive number representing the index of the child TreeNode
     * @throw IllegalStateException, if index is larger than size of children list
     * @return the pointer of child TreeNode at index
     */
	virtual TreeNodePtr getChildAt(size_t index);

    virtual void removeChildAt(size_t);

	virtual void replaceChildAt(size_t, TreeNodePtr);

	virtual void removeAllChildren();

	virtual ParentNodePtr getParent();

	virtual bool isRoot();

	virtual bool isLeaf();

	virtual size_t getDepth();

	virtual void setState(TraverseAction action);

    /**
     * Retrieve the visiting state
     *
     * @return a TraverseAction representing the state of tree traversal algorithm
     */
	virtual TraverseAction getState();

	virtual void setParent(ParentNodePtr ptr);

	/**
	 * Replace everything in this with that, including parentPtr, and children pointers
	 *
	 * @param that
	 */
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
