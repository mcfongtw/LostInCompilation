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


enum SymbolScope {
	SCOPE_GLOBAL = 1,
	SCOPE_FUNCTIONAL,
	SCOPE_FUNCTIONAL_ANONYMOUS,
	SCOPE_LOCAL
};

/*
 * Pure abstract SymbolTable class
 *
 */
class SymbolTable {
public:
	SymbolTable() {

    };

	SymbolTable(SymbolScope lvl){

    };

	virtual ~SymbolTable() {

    };

	virtual void add(SymbolPtr ptr) = 0;

	virtual void remove(const std::string& name) = 0;

	virtual SymbolPtr lookup(const std::string& name) = 0;

	virtual std::string toString() = 0;

	virtual bool isEmpty() = 0;

	virtual void setScope(SymbolScope lvl) = 0;

	virtual SymbolScope getScope() = 0;
};


typedef std::shared_ptr<SymbolTable> SymbolTablePtr;

#endif /* SYMBOLTABLE_H_ */
