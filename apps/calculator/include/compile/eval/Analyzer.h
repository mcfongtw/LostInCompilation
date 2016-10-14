/*
 * Evaluator.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <math.h>

#include "compile/symtab/ObjectValue.h"
#include "compile/traverse/ast/ASTreeWalker.h"
#include "compile/symtab/RuntimeStack.h"
#include "compile/symtab/SymbolTable.h"
#include "common/Utils.h"
#include "log/Logger.h"

/**
 * Function pointer to MathOperation::function<type>(...)
 *
 * @param first ObjectValue operand
 * @param second ObjectValue operand
 *
 * @return answer ObjectValue
 */
typedef ObjectValue (*MathOperation)( ObjectValue&, ObjectValue& );

/**
 * Analyzer is a implementation of a visitor (out of visitor pattern) that walks through the AST
 * and perform specific task at each AST node. Such tasks involves with symbol resolving and call stack
 * operations.
 */
class Analyzer: public ASTreeWalker {
public:
	Analyzer();

	virtual ~Analyzer();

	RuntimeStack& getRunTimeStack();

	SymbolTable& getSymbolTable();

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
	ObjectValue resolveOperand(TreeNodePtr ptr, bool walkingMath);

	RuntimeStack _stack;

	SymbolTable _table;
};

class MathOperationHandle {
public:
	template<typename T>
	static ObjectValue add(ObjectValue& data1, ObjectValue& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 + operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " + "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		ObjectValue result(answer);

		return result;
	}

	template<typename T>
	static ObjectValue sub(ObjectValue& data1, ObjectValue& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 - operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " - "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		ObjectValue result(answer);

		return result;
	}

	template<typename T>
	static ObjectValue mul(ObjectValue& data1, ObjectValue& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 * operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " * "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		ObjectValue result(answer);

		return result;
	}

	template<typename T>
	static ObjectValue div(ObjectValue& data1, ObjectValue& data2) {
		T operand1 = data1.get<T>();
		T operand2 = data2.get<T>();
		T answer = operand1 / operand2;

		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " / "
				+ util::Converts::numberToString<T>(operand2) + " = "
				+ util::Converts::numberToString<T>(answer));

		ObjectValue result(answer);

		return result;
	}

//	template<typename T>
//	static ObjectValue pow(ObjectValue& data1, ObjectValue& data2) {
//		T operand1 = data1.get<T>();
//		T operand2 = data2.get<T>();
//		T answer = pow(operand1, operand2);
//
//		LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " ^ "
//				+ util::Converts::numberToString<T>(operand2) + " = "
//				+ util::Converts::numberToString<T>(answer));
//
//		ObjectValue result(answer);
//
//		return result;
//	}

	template<typename T>
	static ObjectValue mod(ObjectValue& data1, ObjectValue& data2);
};

#endif /* ANALYZER_H_ */
