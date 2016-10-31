//
// Created by Michael Fong on 2016/10/19.
//

#ifndef MAINPROJECT_SYMBOLTABLEFACTORY_H
#define MAINPROJECT_SYMBOLTABLEFACTORY_H

#include "compile/symtab/ScopedSymbolTable.h"

enum SymbolTableStrategy {
    ST_Simple,
    ST_Tree,
    ST_Hash_Table
};

class SymbolTableFactory {
public:
    static SymbolTablePtr getSymbolTable(SymbolTableStrategy);

    static SymbolTablePtr getSymbolTable(SymbolTableStrategy, SymbolScope);

};


#endif //MAINPROJECT_SYMBOLTABLEFACTORY_H
