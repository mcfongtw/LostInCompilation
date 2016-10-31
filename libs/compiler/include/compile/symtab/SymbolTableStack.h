//
// Created by Michael Fong on 2016/10/25.
//

#ifndef MAINPROJECT_SYMBOLTABLESTACK_H
#define MAINPROJECT_SYMBOLTABLESTACK_H

#include <vector>

#include "compile/symtab/ScopedSymbolTable.h"
#include "algorithm/visitor/VisitedObject.h"
#include "SymbolTableFactory.h"

/*
 * Proxy based, Stack backed Symbol Table data structure
 */
class SymbolTableStack : public VisitedObject, public SymbolRepository {
public:
    SymbolTableStack(SymbolTableStrategy strategy);

    virtual ~SymbolTableStack();

    virtual void add(SymbolPtr ptr);

    virtual void remove(const std::string& name);

    virtual void remove(SymbolPtr ptr);

    virtual SymbolPtr lookup(const std::string& name);

    virtual std::string toString();

    virtual bool isEmpty();

    virtual void accept(VisitorPtr);

    virtual void openScope(SymbolScope scope);

    virtual void closeScope();

    virtual int size();

    virtual SymbolScope getScope();
private :
    void openScope();

    std::vector<SymbolTablePtr> _stack;

    SymbolTablePtr _current;

    SymbolTableStrategy _strategy;
};


#endif //MAINPROJECT_SYMBOLTABLESTACK_H
