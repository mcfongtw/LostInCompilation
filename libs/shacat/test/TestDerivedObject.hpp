/*
 * TestDerivedObject.hpp
 *
 *  Created on: Jan 18, 2015
 *      Author: shannaracat
 */

#ifndef TESTDERIVEDOBJECT_HPP_
#define TESTDERIVEDOBJECT_HPP_

#include "common/Utils.h"
#include "log/Logger.h"

#include "lang/Object.h"

class TestDerivedObject: public Object {
public:
	TestDerivedObject() :
			Object() {
		std::string fileName = std::string(CLASS_NAME);
		this->_className = fileName.substr(0, fileName.find_last_of('.'));

		LOG(Logger::LEVEL_TRACE,
				"OBJ_CREATE " + this->_className + "<<"
						+ util::Converts::numberToHexString(this->_addr) + ">>");
	}

	TestDerivedObject(const TestDerivedObject& that) :
			Object(that) {
		std::string fileName = std::string(CLASS_NAME);
		this->_className = fileName.substr(0, fileName.find_last_of('.'));

		LOG(Logger::LEVEL_TRACE,
				"OBJ_COPY " + this->_className + "<<"
						+ util::Converts::numberToHexString(this->_addr) + ">>");
	}

	virtual ~TestDerivedObject() {
		LOG(Logger::LEVEL_TRACE,
				"OBJ_DELETE <<" + this->_className + "<<"
						+ util::Converts::numberToHexString(this->_addr) + ">>");
	}

	TestDerivedObject& operator=(TestDerivedObject that) {
		Object::operator =(that);

		LOG(Logger::LEVEL_TRACE,
				"OBJ_ASSIGN " + this->_className + "<<"
						+ util::Converts::numberToHexString(this->_addr) + ">>");
		return *this;
	}

//	virtual TestDerivedObject* clone() {
//		return new TestDerivedObject(*this);
//	}
	;
};

#endif /* TESTDERIVEDOBJECT_HPP_ */
