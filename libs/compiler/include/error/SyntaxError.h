/*
 * ParseException.h
 *
 *  Created on: 2/5/17
 *      Author: Michael Fong
 */

#ifndef LOSTINCOMPILATION_SYNTACTICEXCEPTION_H
#define LOSTINCOMPILATION_SYNTACTICEXCEPTION_H

#include "error/ParseException.h"

/**
 * An exception dedicated for syntactic error
 *
 * @since 0.1
 */
class SyntaxError : public ParseException {
public:
    SyntaxError(const std::string &msg);

};


#endif //LOSTINCOMPILATION_SYNTACTICEXCEPTION_H
