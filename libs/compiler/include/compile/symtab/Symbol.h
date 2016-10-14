/*
 * Symbol.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <compile/symtab/ObjectValue.h>
#include <string>


class Symbol {
public:
	Symbol(std::string name);

	Symbol(std::string name, ObjectValue val);

	virtual ~Symbol();

	virtual std::string& getName();

	virtual ObjectValue& getValue();

	virtual void setValue(ObjectValue val);

	virtual std::string toString();

protected:
	std::string _name;

	ObjectValue _value;
};

#endif /* SYMBOL_H_ */
