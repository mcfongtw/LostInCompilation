//
// Created by Michael Fong on 2016/11/6.
//
#include <string>
#include <error/ArithmeticException.h>
#include "compile/parser/MathParser.h"
#include "compile/eval/MathEvaluator.h"
#include "compile/eval/function/InvalidFunctionException.h"

#include "gtest/gtest.h"

class MATH_EVALUATOR : public ::testing::Test {
public:
    // Per-test-case set-up.
    // Called before the first test in this test case.
    // Can be omitted if not needed.
    static void SetUpTestCase() {
        MATH_EVALUATOR::stStack =  std::make_shared<SymbolTableStack>(ST_Simple);
        MATH_EVALUATOR::evaluator = new MathEvaluator(MATH_EVALUATOR::stStack);
    }

    // Per-test-case tear-down.
    // Called after the last test in this test case.
    // Can be omitted if not needed.
    static void TearDownTestCase() {
        delete evaluator;
        evaluator = NULL;
    }

    virtual void SetUp() {
        evaluator->startEval();
    }

    virtual void TearDown() {
        evaluator->stopEval();
    }

    static RuntimeData evaluate(const std::string& line) {
        RuntimeData result = nullptr;

        ASTNodePtr root = nullptr;
        MathParser parser;
        parser.parse(root, line);
        MATH_EVALUATOR::evaluator->doEval(std::shared_ptr<ASTNode>(root));
        result = MATH_EVALUATOR::evaluator->getLastAnswer();

        return result;
    }

    static SymTabStackPtr stStack;
    // Some expensive resource shared by all tests.
    static MathEvaluator* evaluator;
};


MathEvaluator* MATH_EVALUATOR::evaluator = nullptr;
SymTabStackPtr MATH_EVALUATOR::stStack;


TEST_F(MATH_EVALUATOR, INTEGRATION_Start_and_Stop) {

}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Constant_Primitive_Expr) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("123");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(123, obj.get<double>());
}

/*
 * *********************
 * Arithmetic Operation
 * *********************
 */

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Negation_Expr_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("-2");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(-2, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Addition_Expr_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("1 + 2");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(3, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Addition_Expr_2) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("-1 + 2");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(1, obj.get<double>());
}


TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Subtraction_Expr_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("2 - 1");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(1, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Subtraction_Expr_2) {
    RuntimeData obj = MATH_EVALUATOR::evaluate( "1 - 2");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(-1, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Multiplication_Expr_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("2 * 3");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(6, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Multiplication_Expr_2) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("2 * 3 * -1");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(-6, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Division_Expr_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("4 / 2");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(2, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Division_Expr_2) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("4 / -2");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(-2, obj.get<double>());
}

//Compiler-28
TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Division_Expr_Divide_By_Zero) {
    EXPECT_THROW(MATH_EVALUATOR::evaluate("4 / 0"), ArithmeticException);
}

//TODO: Support modular expression
//TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Modular_Expr_1) {
//    RuntimeData obj = MATH_EVALUATOR::evaluate("4 % 3");
//
//    EXPECT_STREQ("d", obj.getType().name());
//    EXPECT_THROW(obj.get<int>(), TypeCastException);
//    EXPECT_EQ(sizeof(double), obj.getSizeof());
//    EXPECT_EQ(1, obj.get<double>());
//}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Complex_Expr_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("1 + 2 * 3");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(7, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Complex_Expr_2) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("3 - 9 / 3");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(0, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Complex_Expr_3) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("(1 + 2) * 3");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(9, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Primitive_Complex_Expr_4) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("(3 - 9) / 3");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(-2, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Assign_Symbol_Expr_1) {
    MATH_EVALUATOR::evaluate("x=3");
    RuntimeData obj = MATH_EVALUATOR::evaluate("x * x + x - 1");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(11, obj.get<double>());

}

//Since COMPILER-37
TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Assign_Symbol_Expr_2) {
    MATH_EVALUATOR::evaluate("x=3");
    MATH_EVALUATOR::evaluate("y = x + 1");
    RuntimeData obj = MATH_EVALUATOR::evaluate("y * y + 1");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(17, obj.get<double>());

}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Undefined_Function) {
    EXPECT_THROW(MATH_EVALUATOR::evaluate("undefine()"), InvalidFunctionException);
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Built_In_Sqrt_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("sqrt(4)");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(2, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Built_In_Sqrt_2) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("sqrt(1+3)");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(2, obj.get<double>());
}

TEST_F(MATH_EVALUATOR, INTEGRATION_Evaluate_Built_In_Pow_1) {
    RuntimeData obj = MATH_EVALUATOR::evaluate("pow(2, 3)");

    EXPECT_STREQ("d", obj.getType().name());
    EXPECT_THROW(obj.get<int>(), TypeCastException);
    EXPECT_EQ(sizeof(double), obj.getSizeof());
    EXPECT_EQ(8, obj.get<double>());
}
