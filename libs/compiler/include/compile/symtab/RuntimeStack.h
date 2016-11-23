/*
 * RuntimeStack.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#ifndef RUNTIMESTACK_H_
#define RUNTIMESTACK_H_

#include "compile/binding/RuntimeData.h"
#include <stack>
#include <vector>
#include <string>


/**
 * TODO:
 * typedef std::vector< RuntimeData > RuntimeStack;
 *
 * or
 *
 * typedef std::stack<RuntimeData> RuntimeStack;
 *
 * A stack that stores the processed RuntimData during expression evaluation.
 *
 * @since 0.1
 */
class RuntimeStack {
public:
	RuntimeStack();

	virtual ~RuntimeStack();

	void pop();

	RuntimeData& top();

	void push (RuntimeData& value);

	bool isEmpty();

	size_t size();

	RuntimeData& operator[](std::size_t index);

	std::string toString();

private:
	std::vector<RuntimeData> _stack;
};


#endif /* RUNTIMESTACK_H_ */
