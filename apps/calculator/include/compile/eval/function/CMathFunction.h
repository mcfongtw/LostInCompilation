//
// Created by mcfong on 11/22/16.
//

#ifndef LOSTINCOMPILATION_CMATHFUNCTION_H
#define LOSTINCOMPILATION_CMATHFUNCTION_H

#include <math.h>
#include "compile/eval/function/Function.h"

/**
 * CMathFunction is a class that any function that can be implemented by CMath should inherit from
 *
 * @since 0.1
 */
class CMathFunction : public Function {
public:
    CMathFunction(std::string name) : Function(name, FUNCTION_BUILT_IN_CMATH) {

    }

    virtual ~CMathFunction() {

    }

};


/**
 * A built-in function that invokes CMath.sqrt(..)
 *
 * @since 0.1
 */
class CMathSqrtFunction : public CMathFunction {
public:
    CMathSqrtFunction() : CMathFunction("sqrt") {

    }

    virtual ~CMathSqrtFunction() {

    }


    virtual RuntimeData evaluate() {
        validateFunction();

        double arg1 = _args[0].get<double>();
        RuntimeData result = RuntimeData(sqrt(arg1));

        return result;
    }

    virtual void validateFunction() {
        util::Conditions::requireEqualsTo<int>(1, _args.size(), "Func [" + _name + "] required args");
    }
};

/**
 * A built-in function that invokes CMath.pow(..)
 *
 * @since 0.1
 */
class CMathPowFunction : public CMathFunction {
public:
    CMathPowFunction() : CMathFunction("pow") {

    }

    virtual ~CMathPowFunction() {

    }


    virtual RuntimeData evaluate() {
        validateFunction();

        double arg1 = _args[0].get<double>();
        double arg2 = _args[1].get<double>();
        RuntimeData  result = RuntimeData(pow(arg1, arg2));

        return result;
    }

    virtual void validateFunction() {
        util::Conditions::requireEqualsTo<int>(2, _args.size(), "Func [" + _name + "] required args");
    }
};



#endif //LOSTINCOMPILATION_CMATHFUNCTION_H
