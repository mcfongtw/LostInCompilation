//
// Created by Michael Fong on 2016/10/31.
//

#ifndef MAINPROJECT_SCOPEDSYMBOLTABLE_H
#define MAINPROJECT_SCOPEDSYMBOLTABLE_H

#include "compile/symtab/SymbolRepository.h"

enum SymbolScope {
    SCOPE_GLOBAL = 1,
    SCOPE_FUNCTIONAL,
    SCOPE_FUNCTIONAL_ANONYMOUS,
    SCOPE_LOCAL
};

/*
 * Abstract Class
 * Scoped based <Key:Pointer> paired Symbol Table
 */
class ScopedSymbolTable : public SymbolRepository {
public :
    ScopedSymbolTable() : SymbolRepository() {
        this->_scope = SCOPE_GLOBAL;
    }

    ScopedSymbolTable(SymbolScope scope) : SymbolRepository() {
        this->_scope = scope;
    }

    virtual void remove(const std::string& name) = 0;

    virtual SymbolPtr lookup(const std::string& name) = 0;

    virtual void setScope(SymbolScope scope) {
        this->_scope = scope;
    }

    virtual SymbolScope getScope()  {
        return this->_scope;
    }

protected:
    SymbolScope _scope;
};


typedef std::shared_ptr<ScopedSymbolTable> SymbolTablePtr;

#endif //MAINPROJECT_SCOPEDSYMBOLTABLE_H
