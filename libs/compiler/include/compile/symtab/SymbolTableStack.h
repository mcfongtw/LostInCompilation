//
// Created by Michael Fong on 2016/10/25.
//

#ifndef MAINPROJECT_SYMBOLTABLESTACK_H
#define MAINPROJECT_SYMBOLTABLESTACK_H

#include <vector>

#include "compile/symtab/ScopedSymbolTable.h"
#include "algorithm/visitor/VisitedObject.h"
#include "SymbolTableFactory.h"

/**
 *
 * A implemented as an LIFO Stack that provides stack operations involving symbol table creation or deletion. A
 * SymbolTable is created when it enters a block scope, i.e., function scope, local scope, where new symbols can be
 * created associated to the new scope. Conversely, a SymbolTable will be destroyed when visitor leaves that scope.
 *
 * This stack is also a delegator to lookup a symbol from currently referenced symbol table.
 *
 * @since 0.1
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

    //TODO: Have a clearnScope(ST_GLOBAL)as a special condition check on closing all scops

    virtual void openScope();

    virtual void closeScope();

    virtual int size();

    virtual SymbolScope getScope();
private :
    std::vector<SymbolTablePtr> _stack;

    SymbolTablePtr _current;

    SymbolTableStrategy _strategy;
};

typedef std::shared_ptr<SymbolTableStack> SymTabStackPtr;


#endif //MAINPROJECT_SYMBOLTABLESTACK_H
