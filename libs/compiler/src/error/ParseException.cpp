/*
 * ParseException.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#include "error/SyntaxError.h"
#include "error/ParseException.h"
#include "common/Utils.h"

ParseException::ParseException(const std::string& msg, const bool includeStackTrace) : ParseException("ParseException", msg, includeStackTrace) {

}

ParseException::ParseException(const std::string& prefix, const std::string& msg, const bool includeStackTrace): Exception(prefix, msg, includeStackTrace)  {

}

ParseException::ParseException(const std::string& msg) : ParseException(msg, false) {

}


ParseException::~ParseException() throw () {

}

//////////////////////////////////////////////////////////////

void ParseExceptionTranslator::translate(const std::string& hint, const std::string& message) {
    if(util::Strings::contain(hint, "syntax error")) {
        throw SyntaxError(message);
    } else {
        throw ParseException(message);
    }
}