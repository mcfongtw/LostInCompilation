//
// Created by Michael Fong on 2016/10/22.
//

#ifndef MAINPROJECT_VISITEDSYMBOLTABLE_H
#define MAINPROJECT_VISITEDSYMBOLTABLE_H

#include "compile/symtab/ScopedSymbolTable.h"
#include "algorithm/visitor/VisitedObject.h"


/**
 * An implementation of ScopedSymbolTable and VisitedObject that represent a symbol table tree data structure.
 *
 * @since 0.1
 */
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
