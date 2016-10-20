//
// Created by shannaracat on 2016/10/19.
//

#ifndef MAINPROJECT_SYMBOLTABLEFACTORY_H
#define MAINPROJECT_SYMBOLTABLEFACTORY_H

#include "compile/symtab/SymbolTable.h"

enum SymbolTableStrategy {
    ST_Simple,
    ST_Tree,
    ST_Hash_Table
};

class SymbolTableFactory {
public:
    SymbolTablePtr getSymbolTable(SymbolTableStrategy);

};


#endif //MAINPROJECT_SYMBOLTABLEFACTORY_H
