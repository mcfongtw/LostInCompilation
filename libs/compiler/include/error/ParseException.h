/*
 * ParseException.h
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#ifndef PARSEEXCEPTION_H_
#define PARSEEXCEPTION_H_

#include "error/Exception.h"

/**
 * An exception dedicated for parsing error
 *
 * @since 0.1
 */
class ParseException: public Exception {
public:
	ParseException(const std::string& prefix, const std::string& msg, const bool includeStackTrace);

    ParseException(const std::string& msg, const bool includeStackTrace);

	ParseException(const std::string& msg);

	virtual ~ParseException() throw ();
};


/**
 * A utility function to throw coresponding exception depending on the context.
 *
 * @since 0.1
 */
class ParseExceptionTranslator {
public:
	static void translate(const std::string& hint, const std::string& message);
};

#endif /* PARSEEXCEPTION_H_ */
