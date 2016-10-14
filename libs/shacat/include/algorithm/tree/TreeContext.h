/*
 * TreeContext.h
 *
 *  Created on: Dec 26, 2014
 *      Author: Michael Fong
 */

#ifndef TREECONTEXT_H_
#define TREECONTEXT_H_


/**
 * Definition of tree-traversing strategy:
 * 1) IN_ORDER
 * 2) POST_ORDER
 * 3) PRE_ORDER
 * 4) DEPTH_FIRST
 * 5) BREADTH_FIRST
 * 6)
 *
 */
enum TraverseStrategy {
	IN_ORDER, POST_ORDER, PRE_ORDER, DEPTH_FIRST, BREADTH_FIRST
};

/**
 * Definition of node-visiting action:
 * 1) TRAVERSE_IN: it was visited for the first time when traversal begins
 * 2) TRAVERSE_OUT: it was re-visited when traversal ends
 * 3) TRAVERSE_SECOND: it was visited again by intention. Barely used.
 * 4) UNKNOWN : initial value
 */
enum TraverseAction {
	TRAVERSE_IN = 100, TRAVERSE_OUT = 101, TRAVERSE_SECOND = 102, NO_INTERNAL_ACTION = 199
};


#endif /* TREECONTEXT_H_ */
