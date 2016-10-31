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
 * Scoped based <Key:Pointer> paired Symbol Table
 */
class ScopedSymbolTable : public SymbolRepository {
public :
    ScopedSymbolTable() : SymbolRepository() {

    }

    ScopedSymbolTable(SymbolScope scope) : SymbolRepository() {
        this->_level = scope;
    }

    virtual void remove(const std::string& name) = 0;

    virtual SymbolPtr lookup(const std::string& name) = 0;

    virtual void setScope(SymbolScope lvl) {
        this->_level = lvl;
    }

    virtual SymbolScope getScope()  {
        return this->_level;
    }

protected:
    std::map<std::string, SymbolPtr> symbol_map;

    SymbolScope _level;
};


typedef std::shared_ptr<ScopedSymbolTable> SymbolTablePtr;

#endif //MAINPROJECT_SCOPEDSYMBOLTABLE_H
