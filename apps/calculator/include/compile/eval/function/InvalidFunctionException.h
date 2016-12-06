//
// Created by mcfong on 11/22/16.
//

#ifndef LOSTINCOMPILATION_INVALIDFUNCTIONEXCEPTION_H
#define LOSTINCOMPILATION_INVALIDFUNCTIONEXCEPTION_H


#include "error/Exception.h"

/**
 * A generic exception to be thrown when any function related error occurs
 *
 * @since 0.1
 */
class InvalidFunctionException : public Exception {
public:
    InvalidFunctionException(const std::string& msg) : Exception(msg) {

    }
};


#endif //LOSTINCOMPILATION_INVALIDFUNCTIONEXCEPTION_H
