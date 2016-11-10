//
// Created by Michael Fong on 2016/11/6.
//

#ifndef MAINPROJECT_ARITHMETICEXCEPTION_H
#define MAINPROJECT_ARITHMETICEXCEPTION_H

#include "error/Exception.h"


class ArithmeticException: public Exception {
public:
    ArithmeticException(const std::string& msg);

    virtual ~ArithmeticException() throw ();
};


#endif //MAINPROJECT_ARITHMETICEXCEPTION_H
