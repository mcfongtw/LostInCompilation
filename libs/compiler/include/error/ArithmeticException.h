//
// Created by Michael Fong on 2016/11/6.
//

#ifndef MAINPROJECT_ARITHMETICEXCEPTION_H
#define MAINPROJECT_ARITHMETICEXCEPTION_H

#include "error/Exception.h"

/**
 * Thrown when an exceptional arithmetic condition has occurred. For example, an integer "divide by zero" throws an instance of this class
 *
 * @since 0.1
 */
class ArithmeticException: public Exception {
public:
    ArithmeticException(const std::string& msg);

    virtual ~ArithmeticException() throw ();
};


#endif //MAINPROJECT_ARITHMETICEXCEPTION_H
