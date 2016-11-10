/*
 * Analyzer.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <memory>

#include "error/ArithmeticException.h"
#include "compile/eval/Analyzer.h"
#include "../../compile/parser/grammar/bison/calc.tab.hpp"


Analyzer::Analyzer(SymTabStackPtr stack) :
		ASTreeWalker() {
    this->_symtabStack = stack;
}

Analyzer::~Analyzer() {

}

int Analyzer::startWalking() {
	LOG(Logger::LEVEL_DEBUG,
		"Before walking, Runtime Call Stack has " + this->_runtimeStack.toString());
	LOG(Logger::LEVEL_DEBUG,
		"Before walking, Symbol Table Stack has " + this->_symtabStack->toString());
	return 1;
}

int Analyzer::stopWalking() {
	LOG(Logger::LEVEL_DEBUG,
			"After walking, Runtime Call Stack has " + this->_runtimeStack.toString());
	LOG(Logger::LEVEL_DEBUG,
			"After walking, Symbol Table Stack has " + this->_symtabStack->toString());
	return 1;
}

int Analyzer::walk_MATH(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode MATH");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {
		MathOperation operation;


		ObjectValue data2 = resolveOperand(ptr->getChildAt(1), true);
		ObjectValue data1 = resolveOperand(ptr->getChildAt(0), true);

		if (ptr->getToken() == TOKEN_OP_ADD) {
			operation = &MathOperationHandle::add<double>;
		} else if (ptr->getToken() == TOKEN_OP_SUB) {
			operation = &MathOperationHandle::sub<double>;
		} else if (ptr->getToken() == TOKEN_OP_MUL) {
			operation = &MathOperationHandle::mul<double>;
		} else if (ptr->getToken() == TOKEN_OP_DIV) {
			if(data2.get<double>() == 0) {
				throw ArithmeticException("Cannot divide by 0!");
			}
			operation = &MathOperationHandle::div<double>;
		} else if (ptr->getToken() == TOKEN_OP_MOD) {
			operation = &MathOperationHandle::mod<int>;
		} else if (ptr->getToken() == TOKEN_OP_POW) {
//			operation = &MathOperationHandle::pow<double>;
			throw UndefinedSymbolException(
					"math power function not implemented");
		} else {
			throw IllegalStateException(
					"Unknown math operation <"
							+ util::Converts::numberToString(
									ptr->getToken()) + ">");
		}

		ObjectValue answer = (operation)(data1, data2);
		this->_runtimeStack.push(answer);

		LOG(Logger::LEVEL_TRACE,
				"After walking [MATH], Stack has " + this->_runtimeStack.toString());
	}

	return 1;
}

int Analyzer::walk_ASSIGN(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode ASSIGN");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

		std::shared_ptr<ASTNode> leftChildPtr = std::dynamic_pointer_cast<ASTNode>(ptr->getChildAt(0));
		ObjectValue rhsValue = resolveOperand(ptr->getChildAt(1), false);

		SymbolPtr ptr = this->_symtabStack->lookup(leftChildPtr->getText());
		if (ptr != nullptr) {
			ptr.get()->setValue(rhsValue);
		} else {
			ptr = SymbolPtr(new Symbol(leftChildPtr->getText(), rhsValue));
			this->_symtabStack->add(ptr);
		}

		LOG(Logger::LEVEL_DEBUG,
				"[Variable] assign " + leftChildPtr->getImage() + " = "
						+ util::Converts::numberToString(
								rhsValue.get<double>()));
		LOG(Logger::LEVEL_TRACE,
				"After walking [ASSIGN], Stack has " + this->_runtimeStack.toString());
		LOG(Logger::LEVEL_TRACE,
				"After walking [ASSIGN], Table has " + this->_symtabStack->toString());
	}

	return 1;
}

//XXX: unimplemented
int Analyzer::walk_FUNC(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode FUNC");
	TraverseAction action = ptr->getState();


	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

	}
}

int Analyzer::walk_INTEGER(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode INTEGER");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

		std::string str = ptr->getText();
		//FIXME: int num = util::Converts::stringToNumber<int>(str);
		double num = util::Converts::stringToNumber<double>(str);

		ObjectValue data = ObjectValue(num);
		this->_runtimeStack.push(data);

		LOG(Logger::LEVEL_TRACE,
				"After walking [INTEGER], Stack has " + this->_runtimeStack.toString());
	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

int Analyzer::walk_NUMBER(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode NUMBER");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

		std::string str = ptr->getText();
		double num = util::Converts::stringToNumber<double>(str);

		ObjectValue data = ObjectValue(num);
		this->_runtimeStack.push(data);

		LOG(Logger::LEVEL_TRACE,
				"After walking [NUMBER], Stack has " + this->_runtimeStack.toString());
	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

//XXX: unimplemented
int Analyzer::walk_LITERAL(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode LITERAL");
	TraverseAction action = ptr->getState();


	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

int Analyzer::walk_ID(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode ID");
	TraverseAction action = ptr->getState();


	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

ObjectValue Analyzer::resolveOperand(TreeNodePtr ptr, bool walkingMath) {
	ASTNodePtr astPtr = std::dynamic_pointer_cast<ASTNode>(ptr);
	ObjectValue result;

	int tokenType = astPtr->getToken();

	if (tokenType == TOKEN_NUMBER) {
		result = this->_runtimeStack.top();
		this->_runtimeStack.pop();
	} else if (tokenType == TOKEN_INTEGER) {
		result = this->_runtimeStack.top();
		this->_runtimeStack.pop();
	} else if (tokenType == TOKEN_ID) {
		SymbolPtr ptr = this->_symtabStack->lookup(astPtr->getImage());
		if (ptr != nullptr) {
			result = ptr.get()->getValue();

			LOG(Logger::LEVEL_DEBUG,
					"VARIABLE [" + astPtr->getImage() + "] resolved as ["
							+ util::Converts::numberToString(
									result.get<double>()) + "]");
		} else {
			LOG(Logger::LEVEL_WARN,
					"VARIABLE [" + astPtr->getImage() + "] UNresolvable!");
		}
	} else if (walkingMath) {
		result = this->_runtimeStack.top();
		this->_runtimeStack.pop();
	} else {
		throw IllegalStateException("Unable to resolve operand token [" + astPtr->getImage() + "]");
	}

	return result;
}

RuntimeStack& Analyzer::getRunTimeStack() {
	return this->_runtimeStack;
}

SymTabStackPtr Analyzer::getSymbolTableStack() {
	return this->_symtabStack;
}


template<typename T>
ObjectValue MathOperationHandle::mod(ObjectValue& data1, ObjectValue& data2) {
	T operand1 = data1.get<T>();
	T operand2 = data2.get<T>();
	T answer = operand1 % operand2;

	LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " % "
			+ util::Converts::numberToString<T>(operand2) + " = "
			+ util::Converts::numberToString<T>(answer));

	ObjectValue result(answer);

	return result;
}
template ObjectValue MathOperationHandle::mod<int>(ObjectValue& data1,
		ObjectValue& data2);
