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
 * -# IN_ORDER
 * -# POST_ORDER
 * -# PRE_ORDER
 * -# DEPTH_FIRST
 * -# BREADTH_FIRST
 *
 * @since 0.1
 */
enum TraverseStrategy {
	IN_ORDER, POST_ORDER, PRE_ORDER, DEPTH_FIRST, BREADTH_FIRST
};

/**
 * Definition of node-visiting action:
 * -# TRAVERSE_IN: it was visited for the first time when traversal begins
 * -# TRAVERSE_OUT: it was re-visited when traversal ends
 * -# TRAVERSE_SECOND: it was visited again by intention. Barely used.
 * -# UNKNOWN : initial value
 *
 * @since 0.1
 */
enum TraverseAction {
	TRAVERSE_IN = 100, TRAVERSE_OUT = 101, TRAVERSE_SECOND = 102, NO_INTERNAL_ACTION = 199
};


#endif /* TREECONTEXT_H_ */
