//
// Created by mcfong on 11/23/16.
//

#include "compile/eval/function/FunctionFactory.h"

FunctionPtr FunctionFactory::getFunction(std::string funcName) {
    FunctionPtr result = nullptr;
    if(util::Strings::equalsIgnoreCase(funcName, "sqrt")) {
        result = std::make_shared<CMathSqrtFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "cbrt")) {
        result = std::make_shared<CMathCbrtFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "pow")) {
        result = std::make_shared<CMathPowFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "ceil")) {
        result = std::make_shared<CMathCeilFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "floor")) {
        result = std::make_shared<CMathFloorFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "abs")) {
        result = std::make_shared<CMathAbsFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "round")) {
        result = std::make_shared<CMathRoundFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "exp")) {
        result = std::make_shared<CMathExpFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "log")) {
        result = std::make_shared<CMathLogFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "log10")) {
        result = std::make_shared<CMathLog10Function>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "sin")) {
        result = std::make_shared<CMathSinFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "cos")) {
        result = std::make_shared<CMathCosFunction>();
    } else if(util::Strings::equalsIgnoreCase(funcName, "tan")) {
        result = std::make_shared<CMathTanFunction>();
    } else {
        throw InvalidFunctionException(funcName + " is not supported!");
    }

    return result;
}