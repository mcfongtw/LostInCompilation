//
// Created by Michael Fong on 2016/10/19.
//

#ifndef MAINPROJECT_SIMPLE_SYMBOLTABLE_H
#define MAINPROJECT_SIMPLE_SYMBOLTABLE_H

#include "compile/symtab/Symbol.h"
#include "compile/symtab/visitor/VisitedSymbolTable.h"


//case-Sensitive symbol table
class SimpleSymbolTable : public VisitedSymbolTable {
public:
    SimpleSymbolTable();

    SimpleSymbolTable(SymbolScope lvl);

    virtual ~SimpleSymbolTable();

    virtual void add(SymbolPtr ptr);

    virtual void remove(const std::string& name);

    virtual void remove(SymbolPtr ptr);

    virtual SymbolPtr lookup(const std::string& name);

    virtual std::string toString();

    virtual bool isEmpty();

    virtual void accept(VisitorPtr);

protected:
    std::map<std::string, SymbolPtr> symbol_map;
};

typedef std::shared_ptr<SimpleSymbolTable> SimpleSymbolTablePtr;

#endif //MAINPROJECT_SIMPLE_SYMBOLTABLE_H
