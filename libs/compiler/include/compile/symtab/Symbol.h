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
};


typedef std::shared_ptr<Symbol> SymbolPtr;
#endif /* SYMBOL_H_ */
