/*
 * Symbol.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#include <compile/symtab/Symbol.h>
#include "common/Utils.h"

Symbol::Symbol(std::string name) :
		_value() {
	this->_name = name;
}

Symbol::Symbol(std::string name, RuntimeData val) :
		_value(val) {
	this->_name = name;
	this->_value = val;
}

Symbol::~Symbol() {

}

std::string& Symbol::getName() {
	return this->_name;
}

RuntimeData& Symbol::getValue() {
	return this->_value;
}

void Symbol::setValue(RuntimeData val) {
	this->_value = val;
}

std::string Symbol::toString() {
	std::string result = "";

	result += "[Name: " + this->_name + ", ";

	result += this->_value.toString();

	result += "]\n";

	return result;
}
