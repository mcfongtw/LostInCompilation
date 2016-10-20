//
// Created by shannaracat on 2016/10/19.
//

#include "compile/symtab/SymbolTableFactory.h"

#include "compile/symtab/SimpleSymbolTable.h"

SymbolTablePtr SymbolTableFactory::getSymbolTable(SymbolTableStrategy choice) {
    if(choice == ST_Simple) {
        return std::shared_ptr<SymbolTable>(new SimpleSymbolTable());
    }
}