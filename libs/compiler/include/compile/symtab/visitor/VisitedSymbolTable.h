//
// Created by Michael Fong on 2016/10/22.
//

#ifndef MAINPROJECT_VISITEDSYMBOLTABLE_H
#define MAINPROJECT_VISITEDSYMBOLTABLE_H

#include "compile/symtab/SymbolTable.h"
#include "algorithm/visitor/VisitedObject.h"

class VisitedSymbolTable : public SymbolTable, public VisitedObject {
public:
    VisitedSymbolTable() : SymbolTable(), VisitedObject() {

    }

    VisitedSymbolTable(SymbolScope lvl) : SymbolTable(lvl), VisitedObject() {

    }

    virtual ~VisitedSymbolTable() {

    }
};
#endif //MAINPROJECT_VISITEDSYMBOLTABLE_H
