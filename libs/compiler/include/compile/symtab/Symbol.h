/*
 * Symbol.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>

#include "compile/binding/RuntimeData.h"

/**
 * A wrapper class that describes a symbol with
 * - a name in literal form
 * - a typeless data (RuntimeData)
 *
 * @since 0.1
 */
class Symbol {
public:
	Symbol(std::string name);

	Symbol(std::string name, RuntimeData val);

	virtual ~Symbol();

	virtual std::string& getName();

	virtual RuntimeData& getValue();

	virtual void setValue(RuntimeData val);

	virtual std::string toString();

protected:
	std::string _name;

	RuntimeData _value;

	//TODO: additional info, type or living scope
};


typedef std::shared_ptr<Symbol> SymbolPtr;
#endif /* SYMBOL_H_ */
