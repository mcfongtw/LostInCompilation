/*
 * NodeStack.h
 *
 *  Created on: Dec 25, 2014
 *      Author: Michael Fong
 */

#ifndef NODESTACK_H_
#define NODESTACK_H_

#include <vector>

#include "algorithm/tree/TreeNode.h"

/**
 * TreeNodeStack refers to the stack/list of TreeNodePtr being visited. If a TreeNodePtr has been visited, it will be popped out of stack.
 *
 * @since 0.1
 *
 */
typedef std::vector<TreeNodePtr> TreeNodeStack;



#endif /* NODESTACK_H_ */
