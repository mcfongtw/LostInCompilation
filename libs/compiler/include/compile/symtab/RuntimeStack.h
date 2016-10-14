/*
 * RuntimeStack.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#ifndef RUNTIMESTACK_H_
#define RUNTIMESTACK_H_

#include <compile/symtab/ObjectValue.h>
#include <stack>
#include <vector>
#include <string>


/*
 * TODO:
 * typedef std::vector< ObjectValue > RuntimeStack;
 *
 * or
 *
 * typedef std::stack<ObjectValue> RuntimeStack;
 */

class RuntimeStack {
public:
	RuntimeStack();

	virtual ~RuntimeStack();

	void pop();

	ObjectValue& top();

	void push (ObjectValue& value);

	bool isEmpty();

	size_t size();

	ObjectValue& operator[](std::size_t index);

	std::string toString();

private:
	std::vector<ObjectValue> _stack;
};


#endif /* RUNTIMESTACK_H_ */
