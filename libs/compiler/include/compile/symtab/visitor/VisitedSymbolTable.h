//
// Created by Michael Fong on 2016/10/22.
//

#ifndef MAINPROJECT_VISITEDSYMBOLTABLE_H
#define MAINPROJECT_VISITEDSYMBOLTABLE_H

#include "compile/symtab/ScopedSymbolTable.h"
#include "algorithm/visitor/VisitedObject.h"

class VisitedSymbolTable : public ScopedSymbolTable, public VisitedObject {
public:
    VisitedSymbolTable() : ScopedSymbolTable(), VisitedObject() {

    }

    VisitedSymbolTable(SymbolScope lvl) : ScopedSymbolTable(lvl), VisitedObject() {

    }

    virtual ~VisitedSymbolTable() {

    }
};
#endif //MAINPROJECT_VISITEDSYMBOLTABLE_H
