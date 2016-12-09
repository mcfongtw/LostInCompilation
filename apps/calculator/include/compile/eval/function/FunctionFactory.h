//
// Created by mcfong on 11/23/16.
//

#ifndef LOSTINCOMPILATION_FUNCTIONFACTORY_H
#define LOSTINCOMPILATION_FUNCTIONFACTORY_H

#include "compile/eval/function/CMathFunction.h"
#include "compile/eval/function/InvalidFunctionException.h"

/**
 * A factory method that creates an associated Function object
 *
 * @since 0.1
 */
class FunctionFactory {
public:
    static FunctionPtr getFunction(std::string funcName);
};


#endif //LOSTINCOMPILATION_FUNCTIONFACTORY_H
