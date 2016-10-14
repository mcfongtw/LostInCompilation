/*
 * Object.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: shannaracat
 */

#include "lang/Object.h"

#include <memory>
#include <algorithm>
#include <iostream>
#include <functional>
#include <string>

#include "common/Utils.h"
#include "log/Logger.h"

#include <iostream>
#include <string.h>

Object::Object() {
	std::string fileName = std::string(CLASS_NAME);
	this->_className = fileName.substr(0, fileName.find_last_of('.'));
	this->_addr = (uintptr_t) this;

	LOG(Logger::LEVEL_TRACE,
			"OBJ_CREATE " + this->_className + "<<"
					+ util::Converts::numberToHexString(this->_addr) + ">>");
}

Object::Object(const Object& that) {
	std::string fileName = std::string(CLASS_NAME);
	this->_className = fileName.substr(0, fileName.find_last_of('.'));
	this->_addr = (uintptr_t) this;

	LOG(Logger::LEVEL_TRACE,
			"OBJ_COPY <<" + this->_className + "<<"
					+ util::Converts::numberToHexString(this->_addr) + ">>");
}

Object::~Object() {
	LOG(Logger::LEVEL_TRACE,
			"OBJ_DELETE <<" + this->_className + "<<"
					+ util::Converts::numberToHexString(this->_addr) + ">>");
}

Object& Object::operator=(Object that) {
	swap(that);

	LOG(Logger::LEVEL_TRACE,
			"OBJ_ASSIGN <<" + this->_className + "<<"
					+ util::Converts::numberToHexString(this->_addr) + ">>");
	return *this;
}

std::string Object::toString() {
	return this->_className + "@"
			+ util::Converts::numberToHexString(this->hashCode());
}

size_t Object::hashCode() {
	size_t h1 = std::hash<std::string>()(this->_className);
	size_t h2 = std::hash<uintptr_t>()(this->_addr);

	size_t result = h1 ^ (h2 << 1);

	return result;
}

void Object::swap(Object& that) {
	//nothing to swap
}
