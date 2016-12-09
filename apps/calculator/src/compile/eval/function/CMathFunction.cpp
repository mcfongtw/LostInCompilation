//
// Created by mcfong on 11/22/16.
//

#include "compile/eval/function/CMathFunction.h"


CMathFunction::CMathFunction(std::string name) : Function(name, FUNCTION_BUILT_IN_CMATH) {

}

CMathFunction::~CMathFunction() {

}


CMathMonoArgFunction::CMathMonoArgFunction(std::string name) : CMathFunction(name) {

}

CMathMonoArgFunction::~CMathMonoArgFunction() {

}


RuntimeData CMathMonoArgFunction::evaluate() {
    validateFunction();

    double arg1 = _args[0].get<double>();

    double temp = compute(arg1);

    RuntimeData result = RuntimeData(compute(arg1));

    return result;
}

void CMathMonoArgFunction::validateFunction() {
    util::Conditions::requireEqualsTo<int>(1, _args.size(), "Func [" + _name + "] required args");
}

////////////


CMathDuoArgsFunction::CMathDuoArgsFunction(std::string name) : CMathFunction(name) {

}

CMathDuoArgsFunction::~CMathDuoArgsFunction() {

}

RuntimeData CMathDuoArgsFunction::evaluate() {
    validateFunction();

    double arg1 = _args[0].get<double>();
    double arg2 = _args[1].get<double>();
    RuntimeData  result = RuntimeData(compute(arg1, arg2));

    return result;
}

void CMathDuoArgsFunction::validateFunction() {
    util::Conditions::requireEqualsTo<int>(2, _args.size(), "Func [" + _name + "] required args");
}

//////////////////


CMathSqrtFunction::CMathSqrtFunction() : CMathMonoArgFunction("sqrt") {

}

CMathSqrtFunction::~CMathSqrtFunction() {

}

double CMathSqrtFunction::compute(double arg1) {
    return sqrt(arg1);
}

////////////////////////////////
//Power functions
////////////////////////////////

CMathPowFunction::CMathPowFunction() : CMathDuoArgsFunction("pow") {

}

CMathPowFunction::~CMathPowFunction() {

}

double CMathPowFunction::compute(double arg1, double arg2) {
    return pow(arg1, arg2);
}

CMathCbrtFunction::CMathCbrtFunction() : CMathMonoArgFunction("cbrt") {

}

CMathCbrtFunction::~CMathCbrtFunction() {

}

double CMathCbrtFunction::compute(double arg1) {
    return cbrt(arg1);
}

///////////////////////////////////
//Rounding and remainder functions
///////////////////////////////////

CMathCeilFunction::CMathCeilFunction() : CMathMonoArgFunction("ceil") {

}

CMathCeilFunction::~CMathCeilFunction() {

}


double CMathCeilFunction::compute(double arg1) {
    return ceil(arg1);
}



CMathFloorFunction::CMathFloorFunction() : CMathMonoArgFunction("floor") {

}

CMathFloorFunction::~CMathFloorFunction() {

}

double CMathFloorFunction::compute(double arg1) {
    return floor(arg1);
}



CMathAbsFunction::CMathAbsFunction() : CMathMonoArgFunction("abs") {

}

CMathAbsFunction::~CMathAbsFunction() {

}

double CMathAbsFunction::compute(double arg1) {
    return fabs(arg1);
}


CMathRoundFunction::CMathRoundFunction() : CMathMonoArgFunction("round") {

}

CMathRoundFunction::~CMathRoundFunction() {

}

double CMathRoundFunction::compute(double arg1) {
    return round(arg1);
}


//////////////////////////////////////////
//Exponential and logarithmic functions
//////////////////////////////////////////


CMathExpFunction::CMathExpFunction() : CMathMonoArgFunction("exp") {

}

CMathExpFunction::~CMathExpFunction() {

}

double CMathExpFunction::compute(double arg1) {
    return exp(arg1);
}

CMathLogFunction::CMathLogFunction() : CMathMonoArgFunction("log") {

}

CMathLogFunction::~CMathLogFunction() {

}

double CMathLogFunction::compute(double arg1) {
    return log(arg1);
}

CMathLog10Function::CMathLog10Function() : CMathMonoArgFunction("log10") {

}

CMathLog10Function::~CMathLog10Function() {

}

double CMathLog10Function::compute(double arg1) {
    return log10(arg1);
}

/////////////////////////
//Trigonometric functions
/////////////////////////

CMathSinFunction::CMathSinFunction() : CMathMonoArgFunction("sin") {

}

CMathSinFunction::~CMathSinFunction() {

}

double CMathSinFunction::compute(double arg1) {
    return sin(arg1);
}


CMathCosFunction::CMathCosFunction() : CMathMonoArgFunction("cos") {

}

CMathCosFunction::~CMathCosFunction() {

}


double CMathCosFunction::compute(double arg1) {
    return cos(arg1);
}

CMathTanFunction::CMathTanFunction() : CMathMonoArgFunction("tan") {

}

CMathTanFunction::~CMathTanFunction() {

}

double CMathTanFunction::compute(double arg1) {
    return tan(arg1);
}
