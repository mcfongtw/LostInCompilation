//
// Created by Michael Fong on 2016/11/6.
//

#include "error/ArithmeticException.h"

ArithmeticException::ArithmeticException(const std::string& msg) : Exception("ArithmeticException : ", msg) {

}

ArithmeticException::~ArithmeticException() throw ()  {

}