/*
 * Analyzer.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <memory>
#include <algorithm>
#include <compile/eval/function/FunctionFactory.h>

#include "algorithm/tree/ast/ASTUtils.h"
#include "error/ArithmeticException.h"
#include "compile/eval/Analyzer.h"
#include "../../compile/parser/grammar/bison/calc.tab.hpp"
#include "compile/eval/function/FunctionFactory.h"

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

/**
 *     MATH
 *      |
 * ------------
 * |          |
 * expr       expr
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_MATH(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode MATH");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {
		MathOperation operation;


		RuntimeData data2 = getNextRuntimeData(ptr->getChildAt(1));
		RuntimeData data1 = getNextRuntimeData(ptr->getChildAt(0));

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

		RuntimeData answer = (operation)(data1, data2);
		this->_runtimeStack.push(answer);

		LOG(Logger::LEVEL_TRACE,
				"After walking [MATH], Stack has " + this->_runtimeStack.toString());
	}

	return 1;
}

/**
 *     ASSIGN
 *       |
 * ---------------
 * |             |
 * identifier    expr
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_ASSIGN(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode ASSIGN");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

		std::shared_ptr<ASTNode> leftChildPtr = std::dynamic_pointer_cast<ASTNode>(ptr->getChildAt(0));
		RuntimeData rhsValue = getNextRuntimeData(ptr->getChildAt(1));

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

/**
 *      CALL
 *       |
 * ---------------
 * |             |
 * identifier    ARGS
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_CALL(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode CALL");
	TraverseAction action = ptr->getState();


	if (action == TRAVERSE_IN) {
        //init for collecting number of arguments
        _numOfArgs = 0;
	} else if (action == TRAVERSE_OUT) {
		std::shared_ptr<ASTNode> funcIdentifierPtr = std::dynamic_pointer_cast<ASTNode>(ptr->getChildAt(0));
        std::vector<RuntimeData> arguments;

		if(ptr->isChildAt(1)) {
			//With arguments

            for(int i = 0; i < _numOfArgs; i++) {
                RuntimeData topData = this->_runtimeStack.top();
                this->_runtimeStack.pop();
                arguments.push_back(topData);
                LOG(Logger::LEVEL_TRACE,
                    "[ARGS] Collecting [" + util::Converts::numberToString(topData.get<double>()) + "]");
            }

            //reverse arguments
            std::reverse(arguments.begin(), arguments.end());
		} else {
			//No arguments

		}

        FunctionPtr func = FunctionFactory::getFunction(funcIdentifierPtr->getImage());
        func->setArguments(arguments);

        LOG(Logger::LEVEL_TRACE, "[CALL] Invoke function [" + func->toString() + "]");

        RuntimeData result = func->evaluate();

        this->_runtimeStack.push(result);
	}
}

/**
 *      ARGS
 *       |
 * ---------------
 * |             |
 * expr         ARGS
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_ARGS(ASTNodePtr ptr) {
    util::Conditions::requireNotNull(ptr, "node to walk ASTNode ARGS");
    TraverseAction action = ptr->getState();

    if (action == TRAVERSE_IN) {
        std::shared_ptr<ASTNode> numberPtr = std::dynamic_pointer_cast<ASTNode>(ptr->getChildAt(0));

        LOG(Logger::LEVEL_TRACE, "Observe [" + numberPtr->getImage() + "]");
        _numOfArgs++;
    } else if (action == TRAVERSE_OUT) {
        if(ptr->isChildAt(1)) {
            //TODO: Enhancement, ASTUtils::Reduce on another argument
        }
    }
}


/**
 *     <integer>
 *       |
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_INTEGER(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode INTEGER");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

		std::string str = ptr->getText();
		//FIXME: int num = util::Converts::stringToNumber<int>(str);
		double num = util::Converts::stringToNumber<double>(str);

		RuntimeData data = RuntimeData(num);
		this->_runtimeStack.push(data);

		LOG(Logger::LEVEL_TRACE,
				"After walking [INTEGER], Stack has " + this->_runtimeStack.toString());
	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

/**
 *    <number>
 *       |
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_NUMBER(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode NUMBER");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {

		std::string str = ptr->getText();
		double num = util::Converts::stringToNumber<double>(str);

		RuntimeData data = RuntimeData(num);
		this->_runtimeStack.push(data);

		LOG(Logger::LEVEL_TRACE,
				"After walking [NUMBER], Stack has " + this->_runtimeStack.toString());
	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

//XXX: unimplemented

/**
 *    <literal>
 *       |
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */
int Analyzer::walk_LITERAL(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode LITERAL");
	TraverseAction action = ptr->getState();


	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

/**
 *   <identifier>
 *       |
 *
 *
 * @param ptr ASTNodePtr for current node
 *
 * @return result of traversing this node. 1 for success, and 0 for failure.
 */

int Analyzer::walk_ID(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "node to walk ASTNode ID");
	TraverseAction action = ptr->getState();


	if (action == TRAVERSE_IN) {

	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}

RuntimeData Analyzer::getNextRuntimeData(TreeNodePtr ptr) {
	ASTNodePtr astPtr = std::dynamic_pointer_cast<ASTNode>(ptr);
	RuntimeData result;

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
	} else if (isMathOperator(astPtr)) {
		result = this->_runtimeStack.top();
		this->_runtimeStack.pop();
	} else {
		throw IllegalStateException("Unable to resolve operand token [" + astPtr->getImage() + "]");
	}

	return result;
}

//NOTE: since COMPILER-37
bool Analyzer::isMathOperator(ASTNodePtr ptr) {
	bool result = false;
	switch(ptr->getToken()) {
		case TOKEN_OP_ADD:
		case TOKEN_OP_SUB:
		case TOKEN_OP_MUL:
		case TOKEN_OP_DIV:
			result = true;
			break;
		default:
			break;
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
RuntimeData MathOperationHandle::mod(RuntimeData& data1, RuntimeData& data2) {
	T operand1 = data1.get<T>();
	T operand2 = data2.get<T>();
	T answer = operand1 % operand2;

	LOG(Logger::LEVEL_TRACE, util::Converts::numberToString<T>(operand1) + " % "
			+ util::Converts::numberToString<T>(operand2) + " = "
			+ util::Converts::numberToString<T>(answer));

	RuntimeData result(answer);

	return result;
}
template RuntimeData MathOperationHandle::mod<int>(RuntimeData& data1,
		RuntimeData& data2);
