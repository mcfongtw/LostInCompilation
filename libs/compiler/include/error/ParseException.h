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
	ParseException(const std::string& msg);

	virtual ~ParseException() throw ();
};

#endif /* PARSEEXCEPTION_H_ */
