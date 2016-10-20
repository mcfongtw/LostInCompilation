//
// Created by Michael Fong on 2016/10/19.
//

#ifndef MAINPROJECT_SIMPLE_SYMBOLTABLE_H
#define MAINPROJECT_SIMPLE_SYMBOLTABLE_H

#include "compile/symtab/Symbol.h"
#include "compile/symtab/SymbolTable.h"

//case-Sensitive symbol table
class SimpleSymbolTable : public SymbolTable {
public:
    SimpleSymbolTable();

    SimpleSymbolTable(SymbolScope lvl);

    virtual ~SimpleSymbolTable();

    virtual void add(SymbolPtr ptr);

    virtual void remove(const std::string& name);

    virtual SymbolPtr lookup(const std::string& name);

    virtual std::string toString();

    virtual bool isEmpty();

    virtual void setScope(SymbolScope lvl);

    virtual SymbolScope getScope();

protected:
    std::map<std::string, SymbolPtr> symbol_map;

    SymbolScope _level;

};

#endif //MAINPROJECT_SIMPLE_SYMBOLTABLE_H
