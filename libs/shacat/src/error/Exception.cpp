/*
 * Exception.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Michael Fong
 */
#include "error/Exception.h"
#include "error/StackTraceUtils.h"

Exception::Exception() {
	this->_message = "<No Message>";
}

Exception::Exception(const std::string& prefix) {
	this->_message = prefix + StackTraceUtils::getStackTraceMessage();
}

Exception::Exception(const std::string& prefix, const std::string& msg) {
//	this->_message = new char[msg.size() + 1];
//	strcpy(this->_message, msg.c_str());
//	this->_message[msg.size()] = '\0';
	this->_message = prefix + msg + StackTraceUtils::getStackTraceMessage();
}

Exception::~Exception() throw (){
//	delete [] (char*) this->_message;
}

const char* Exception::what() const throw (){
    return this->_message.c_str();
 }
//////////////////////////////////////////////////////////////////////

NullPointerException::NullPointerException(const std::string& msg) : Exception("NullPointerException : ", msg) {

}

NullPointerException::~NullPointerException() throw () {

}

////////////////////////////////////////////////////////////////////////

OutOfMemoryException::OutOfMemoryException(const std::string& msg) : Exception("OutOfMemoryException : ", msg)  {
}

OutOfMemoryException::~OutOfMemoryException() throw () {

}

////////////////////////////////////////////////////////////////////////

UndefinedSymbolException::UndefinedSymbolException(const std::string& msg) : Exception("UndefinedSymbolException : ", msg)  {
}

UndefinedSymbolException::~UndefinedSymbolException() throw () {

}

////////////////////////////////////////////////////////////////////////

IllegalStateException::IllegalStateException(const std::string& msg) : Exception("IllegalStateException : ", msg)  {
}

IllegalStateException::~IllegalStateException() throw () {

}

////////////////////////////////////////////////////////////////////////

IllegalArgumentException::IllegalArgumentException(const std::string& msg) : Exception("IllegalArgumentException : ", msg)  {

}

IllegalArgumentException::~IllegalArgumentException() throw () {

}
////////////////////////////////////////////////////////////////////////
TypeCastException::TypeCastException(const std::string& msg) : Exception("TypeCastException : ", msg)  {

}

TypeCastException::~TypeCastException() throw () {

}
