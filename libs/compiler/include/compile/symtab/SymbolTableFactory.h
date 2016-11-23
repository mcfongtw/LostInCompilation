//
// Created by Michael Fong on 2016/10/19.
//

#ifndef MAINPROJECT_SYMBOLTABLEFACTORY_H
#define MAINPROJECT_SYMBOLTABLEFACTORY_H

#include "compile/symtab/ScopedSymbolTable.h"

/**
 * Describes which type of symbol table data strcuture is being used.
 *
 * @since 0.1
 */
enum SymbolTableStrategy {
    ST_Simple,
    ST_Tree,
    ST_Hash_Table
};

/**
 * A Factory method to retrieve which type of SymbolTable given SymbolTableStrategy
 *
 * @since 0.1
 */
class SymbolTableFactory {
public:
    static SymbolTablePtr getSymbolTable(SymbolTableStrategy);

    static SymbolTablePtr getSymbolTable(SymbolTableStrategy, SymbolScope);

};


#endif //MAINPROJECT_SYMBOLTABLEFACTORY_H
