/*
 * Exception.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Michael Fong
 */
#include "error/Exception.h"
#include "error/StackTraceUtils.h"

Exception::Exception() {
	this->_cause = "<No Message>";
}

Exception::Exception(const std::string& prefix): Exception(prefix, "") {

}

Exception::Exception(const std::string& prefix, const std::string& msg) : Exception(prefix, msg, true) {
}

Exception::Exception(const std::string& prefix, const std::string& msg, const bool includeStackTrace) {
	this->_cause = prefix + msg;
    this->_trace = StackTraceUtils::getStackTraceMessage();
    this->_message = includeStackTrace ? this->_cause + this->_trace : this->_cause;
}

Exception::~Exception() throw (){

}

const char* Exception::what() const throw (){
    return this->_message.c_str();
}

std::string Exception::getTrace() {
    return this->_trace;
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
