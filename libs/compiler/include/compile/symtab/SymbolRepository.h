/*
 * SymbolTable.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <compile/symtab/Symbol.h>
#include <string>
#include <memory>
#include <map>

/*
 * Symbol Repository Interface
 *
 */
class SymbolRepository {
public:
	SymbolRepository() {

    };

	virtual ~SymbolRepository() {

    };

	virtual void add(SymbolPtr ptr) = 0;

	virtual void remove(SymbolPtr ptr) = 0;

	virtual bool isEmpty() = 0;

    virtual std::string toString() = 0;
};

#endif /* SYMBOLTABLE_H_ */
