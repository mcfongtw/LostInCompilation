//
// Created by mcfong on 11/22/16.
//

#ifndef LOSTINCOMPILATION_CMATHFUNCTION_H
#define LOSTINCOMPILATION_CMATHFUNCTION_H

#include <math.h>
#include "compile/eval/function/Function.h"
#include "log/Logger.h"

/**
 * CMathFunction is a class that any function that can be implemented by CMath should inherit from
 *
 * @since 0.1
 */
class CMathFunction : public Function {
public:
    CMathFunction(std::string name);

    virtual ~CMathFunction();

};

/**
 * CMathMonoArgFunction is a class that any function with single argument should inherit from
 *
 * @since 0.1
 */
class CMathMonoArgFunction : public CMathFunction {
public:
    CMathMonoArgFunction(std::string name);

    virtual ~CMathMonoArgFunction();


    virtual RuntimeData evaluate();

    virtual void validateFunction();

protected:
    virtual double compute(double arg1) = 0;
};

/**
 * CMathDuoArgsFunction is a class that any function with two arguments should inherit from
 *
 * @since 0.1
 */
class CMathDuoArgsFunction : public CMathFunction {
public:
    CMathDuoArgsFunction(std::string name);

    virtual ~CMathDuoArgsFunction();

    virtual RuntimeData evaluate();

    virtual void validateFunction();

protected:
    virtual double compute(double arg1, double arg2) = 0;
};


/**
 * A built-in function that invokes CMath.sqrt(..)
 *
 * @since 0.1
 */
class CMathSqrtFunction : public CMathMonoArgFunction {
public:
    CMathSqrtFunction();

    virtual ~CMathSqrtFunction();

protected:
    virtual double compute(double arg1);
};

////////////////////////////////
//Power functions
////////////////////////////////

/**
 * A built-in function that invokes CMath.pow(..)
 *
 * @since 0.1
 */
class CMathPowFunction : public CMathDuoArgsFunction {
public:
    CMathPowFunction();

    virtual ~CMathPowFunction();

protected:
    virtual double compute(double arg1, double arg2);
};


/**
 * A built-in function that invokes CMath.cbrt(..)
 *
 * @since 0.1
 */
class CMathCbrtFunction : public CMathMonoArgFunction {
public:
    CMathCbrtFunction();

    virtual ~CMathCbrtFunction();

protected:
    virtual double compute(double arg1);
};

///////////////////////////////////
//Rounding and remainder functions
///////////////////////////////////

/**
 * A built-in function that invokes CMath.ceil(..)
 *
 * @since 0.1
 */
class CMathCeilFunction : public CMathMonoArgFunction {
public:
    CMathCeilFunction();

    virtual ~CMathCeilFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.floor(..)
 *
 * @since 0.1
 */
class CMathFloorFunction : public CMathMonoArgFunction {
public:
    CMathFloorFunction();

    virtual ~CMathFloorFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.fabs(..)
 *
 * @since 0.1
 */
class CMathAbsFunction : public CMathMonoArgFunction {
public:
    CMathAbsFunction();

    virtual ~CMathAbsFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.round(..)
 *
 * @since 0.1
 */
class CMathRoundFunction : public CMathMonoArgFunction {
public:
    CMathRoundFunction();

    virtual ~CMathRoundFunction();

protected:
    virtual double compute(double arg1);
};

//////////////////////////////////////////
//Exponential and logarithmic functions
//////////////////////////////////////////

/**
 * A built-in function that invokes CMath.exp(..)
 *
 * @since 0.1
 */
class CMathExpFunction : public CMathMonoArgFunction {
public:
    CMathExpFunction();

    virtual ~CMathExpFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.log(..)
 *
 * @since 0.1
 */
class CMathLogFunction : public CMathMonoArgFunction {
public:
    CMathLogFunction();

    virtual ~CMathLogFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.log10(..)
 *
 * @since 0.1
 */
class CMathLog10Function : public CMathMonoArgFunction {
public:
    CMathLog10Function();

    virtual ~CMathLog10Function();

protected:
    virtual double compute(double arg1);
};

/////////////////////////
//Trigonometric functions
/////////////////////////

/**
 * A built-in function that invokes CMath.sin(..)
 *
 * @since 0.1
 */
class CMathSinFunction : public CMathMonoArgFunction {
public:
    CMathSinFunction();

    virtual ~CMathSinFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.cos(..)
 *
 * @since 0.1
 */
class CMathCosFunction : public CMathMonoArgFunction {
public:
    CMathCosFunction();

    virtual ~CMathCosFunction();

protected:
    virtual double compute(double arg1);
};

/**
 * A built-in function that invokes CMath.tan(..)
 *
 * @since 0.1
 */
class CMathTanFunction : public CMathMonoArgFunction {
public:
    CMathTanFunction();

    virtual ~CMathTanFunction();

protected:
    virtual double compute(double arg1);
};

#endif //LOSTINCOMPILATION_CMATHFUNCTION_H
