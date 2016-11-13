/*
 * Evaluator.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <math.h>

#include "compile/binding/RuntimeData.h"
#include "compile/traverse/ast/ASTreeWalker.h"
#include "compile/symtab/RuntimeStack.h"
#include "compile/symtab/SymbolTableStack.h"
#include "common/Utils.h"
#include "log/Logger.h"

/**
 * Function pointer to MathOperation::function<type>(...)
 *
 * @param first RuntimeData operand
 * @param second RuntimeData operand
 *
 * @return answer RuntimeData
 */
typedef RuntimeData (*MathOperation)( RuntimeData&, RuntimeData& );

/**
 * Analyzer is a implementation of a visitor (out of visitor pattern) that walks through the AST
 * and perform specific task at each AST node. Such tasks involves with symbol resolving and call stack
 * operations.
 */
class Analyzer: public ASTreeWalker {
public:
	Analyzer(SymTabStackPtr stack);

	virtual ~Analyzer();

	RuntimeStack& getRunTimeStack();

	SymTabStackPtr getSymbolTableStack();

protected:
	virtual int startWalking();

	virtual int stopWalking();

	virtual int walk_MATH(ASTNodePtr ptr);

	virtual int walk_ASSIGN(ASTNodePtr ptr);

	virtual int walk_FUNC(ASTNodePtr ptr);

	virtual int walk_INTEGER(ASTNodePtr ptr);

	virtual int walk_NUMBER(ASTNodePtr ptr);

	virtual int walk_LITERAL(ASTNodePtr ptr);

	virtual int walk_ID(ASTNodePtr ptr);

private:
	RuntimeData getNextRuntimeData(TreeNodePtr ptr);

	bool isMathOperator(ASTNodePtr ptr);

	RuntimeStack _runtimeStack;

	SymTabStackPtr _symtabStack;
};

class MathOperationHandle {
public:
	template<typename T>
	static RuntimeData add(RuntimeData& data1, RuntimeData& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 + operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " + "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		RuntimeData result(answer);

		return result;
	}

	template<typename T>
	static RuntimeData sub(RuntimeData& data1, RuntimeData& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 - operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " - "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		RuntimeData result(answer);

		return result;
	}

	template<typename T>
	static RuntimeData mul(RuntimeData& data1, RuntimeData& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 * operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " * "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		RuntimeData result(answer);

		return result;
	}

	template<typename T>
	static RuntimeData div(RuntimeData& data1, RuntimeData& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 / operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " / "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		RuntimeData result(answer);

		return result;
	}

//	template<typename T>
//	static RuntimeData pow(RuntimeData& data1, RuntimeData& data2) {
//		T operand1 = data1.get<T>();
//		T operand2 = data2.get<T>();
//		T answer = pow(operand1, operand2);
//
//		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " ^ "
//				+ util::Converts::numberToString<T>(operand2) + " = "
//				+ util::Converts::numberToString<T>(answer));
//
//		RuntimeData result(answer);
//
//		return result;
//	}

	template<typename T>
	static RuntimeData mod(RuntimeData& data1, RuntimeData& data2);
};

#endif /* ANALYZER_H_ */
