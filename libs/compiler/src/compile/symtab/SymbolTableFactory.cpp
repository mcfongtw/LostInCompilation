//
// Created by Michael Fong on 2016/10/19.
//

#include "compile/symtab/SymbolTableFactory.h"

#include "compile/symtab/SimpleSymbolTable.h"
#include "compile/symtab/VisitedSymbolTableTreeNode.h"

SymbolTablePtr SymbolTableFactory::getSymbolTable(SymbolTableStrategy choice) {
    if(choice == ST_Simple) {
        return std::make_shared<SimpleSymbolTable>();
    } else {
        return nullptr;
    }
}

SymbolTablePtr SymbolTableFactory::getSymbolTable(SymbolTableStrategy choice, SymbolScope scope) {
    if(choice == ST_Simple) {
        return std::make_shared<SimpleSymbolTable>(scope);
    } else {
        return nullptr;
    }
}