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
    static FunctionPtr getFunction(std::string funcName) {
        if(util::Strings::equalsIgnoreCase(funcName, "sqrt")) {
            return std::make_shared<CMathSqrtFunction>();
        } else if(util::Strings::equalsIgnoreCase(funcName, "pow")) {
            return std::make_shared<CMathPowFunction>();
        } else {
            throw InvalidFunctionException(funcName + " is not supported!");
        }
    }
};


#endif //LOSTINCOMPILATION_FUNCTIONFACTORY_H
