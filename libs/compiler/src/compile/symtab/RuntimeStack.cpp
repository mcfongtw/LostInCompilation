/*
 * RuntimeStack.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#include "compile/symtab/RuntimeStack.h"
#include "common/Utils.h"

RuntimeStack::RuntimeStack() {

}

RuntimeStack::~RuntimeStack() {

}

void RuntimeStack::pop() {
	if(this->_stack.empty() == false) {
		this->_stack.pop_back();
	}
}

RuntimeData& RuntimeStack::top() {
	return this->_stack.back();
}

void RuntimeStack::push(RuntimeData& value) {
	this->_stack.push_back(value);
}

bool RuntimeStack::isEmpty() {
	return this->_stack.empty();
}

size_t RuntimeStack::size() {
	return this->_stack.size();
}

RuntimeData& RuntimeStack::operator[](size_t index) {
	util::Conditions::requireBetween<int>(index, 0, this->_stack.size() - 1,
			"runtime stack size");

	return this->_stack[index];
}

std::string RuntimeStack::toString() {
	std::string result = "";
	result += "\t" + util::Converts::numberToString(this->_stack.size()) + " elements: \n";

	if(this->_stack.empty()) {
		return result;
	}

	result += "Top\n";
	for(int i = this->_stack.size() - 1; i >= 0; i--) {
		result += "[" + util::Converts::numberToString(i) + "] " + this->_stack[i].toString() + "\n";
	}

	return result;
}
