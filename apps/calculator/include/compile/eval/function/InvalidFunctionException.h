//
// Created by mcfong on 11/22/16.
//

#ifndef LOSTINCOMPILATION_INVALIDFUNCTIONEXCEPTION_H
#define LOSTINCOMPILATION_INVALIDFUNCTIONEXCEPTION_H


#include "error/Exception.h"

class InvalidFunctionException : public Exception {
public:
    InvalidFunctionException(const std::string& msg) : Exception(msg) {

    }
};


#endif //LOSTINCOMPILATION_INVALIDFUNCTIONEXCEPTION_H
