/*
 * ParseException.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#include "error/ParseException.h"

ParseException::ParseException(const std::string& msg) : Exception("ParseException : ", msg) {

}

ParseException::~ParseException() throw () {

}

