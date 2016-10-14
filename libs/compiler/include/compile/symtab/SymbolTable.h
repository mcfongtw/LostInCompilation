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


enum SymbolTableLevel {
	ST_GLOBAL = 1,
	ST_FUNCTIONAL,
	ST_FUNCTIONAL_ANONYMOUS,
	ST_LOCAL
};


typedef std::shared_ptr<Symbol> SymbolPtr;

//case-Sensitive symbol table
class SymbolTable {
public:
	SymbolTable();

	SymbolTable(SymbolTableLevel lvl);

	virtual ~SymbolTable();

	virtual void add(SymbolPtr ptr);

	virtual void remove(const std::string& name);

	virtual SymbolPtr lookup(const std::string& name);

	virtual std::string toString();

	virtual bool isEmpty();

	virtual void setLevel(SymbolTableLevel lvl);

	virtual SymbolTableLevel getLevel();

private:
	std::map<std::string, SymbolPtr> symbol_map;

	SymbolTableLevel _level;
};

#endif /* SYMBOLTABLE_H_ */
