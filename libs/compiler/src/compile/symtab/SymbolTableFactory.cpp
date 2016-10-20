//
// Created by Michael Fong on 2016/10/19.
//

#include "compile/symtab/SymbolTableFactory.h"

#include "compile/symtab/SimpleSymbolTable.h"
#include "compile/symtab/SymbolTableTreeNode.h"

SymbolTablePtr SymbolTableFactory::getSymbolTable(SymbolTableStrategy choice) {
    if(choice == ST_Simple) {
        return std::make_shared<SimpleSymbolTable>();
    } else if(choice == ST_Tree) {
        return std::make_shared<SymbolTableTreeNode>();
    } else {
        return nullptr;
    }
}

SymbolTablePtr SymbolTableFactory::getSymbolTable(SymbolTableStrategy choice, SymbolScope scope) {
    if(choice == ST_Simple) {
        return std::make_shared<SimpleSymbolTable>(scope);
    } else if(choice == ST_Tree) {
        return std::make_shared<SymbolTableTreeNode>(scope);
    } else {
        return nullptr;
    }
}