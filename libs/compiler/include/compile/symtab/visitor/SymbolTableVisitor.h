//
// Created by Michael Fong on 10/21/16.
//

#ifndef MAINPROJECT_SYMBOLTABLEVISITOR_H
#define MAINPROJECT_SYMBOLTABLEVISITOR_H

#include "compile/symtab/ScopedSymbolTable.h"
#include "algorithm/visitor/Visitor.h"

class SymbolTableVisitor : public Visitor {
public:
    SymbolTableVisitor() {

    };

    virtual ~SymbolTableVisitor() {

    };

    virtual SymbolPtr lookup(const std::string& name) = 0;

    virtual int visit(SymbolTablePtr) = 0;

protected:
    //Hide intentionally, as we only expose visit(SymbolTablePtr) to outside
    virtual int visit(VisitedObjectPtr ptr) {
        SymbolTablePtr stPtr = std::dynamic_pointer_cast<ScopedSymbolTable>(ptr);
        this->visit(stPtr);
    }

    virtual int startVisit() = 0;

    virtual int stopVisit() = 0;
};

typedef std::shared_ptr<SymbolTableVisitor> SymbolTableVisitorPtr;


#endif //MAINPROJECT_SYMBOLTABLEVISITOR_H
