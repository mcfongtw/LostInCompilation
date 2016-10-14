/*
 * TreeBuilder.h
 *
 *  Created on: Nov 24, 2014
 *      Author: Michael Fong
 */

#ifndef TREEBUILDER_H_
#define TREEBUILDER_H_

#include <memory>
#include <vector>

#include "algorithm/tree/TreeNode.h"
#include "algorithm/tree/visitor/VisitedTreeNode.h"

template <typename NodeType, typename NodePtrType>
class TreeBuilder {
public:
	TreeBuilder() {
		this->_current = std::shared_ptr<NodeType>(new NodeType());
	}

	TreeBuilder(NodePtrType that) {
		this->_current = std::shared_ptr<NodeType>(new NodeType(that));
	}

	virtual ~TreeBuilder() {

	}

	virtual TreeBuilder& addChild(NodePtrType child){
		this->_current->insertChild(child);

		return *this;
	}

	virtual TreeBuilder& addChildren(std::vector<NodePtrType> children){
		for(size_t i = 0; i < children.size(); i++) {
			NodePtrType child = children[i];
			this->_current->insertChild(child);
		}

		return *this;
	}

	virtual NodePtrType toTree(){
		return this->_current;
	}

private:
	NodePtrType _current;
};



#endif /* TREEBUILDER_H_ */
