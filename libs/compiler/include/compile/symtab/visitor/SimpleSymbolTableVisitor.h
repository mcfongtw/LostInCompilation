//
// Created by mcfong on 10/21/16.
//

#ifndef MAINPROJECT_SIMPLESYMBOLTABLEVISITOR_H
#define MAINPROJECT_SIMPLESYMBOLTABLEVISITOR_H

#include "compile/symtab/visitor/SymbolTableVisitor.h"


class SimpleSymbolTableVisitor: public SymbolTableVisitor {
public:
    SimpleSymbolTableVisitor();

    virtual ~SimpleSymbolTableVisitor();

    virtual SymbolPtr lookup(const std::string& name);

    virtual int visit(SymbolTablePtr);

protected:

    virtual int startVisit();

    virtual int stopVisit();
};

typedef std::shared_ptr<SimpleSymbolTableVisitor> SimpleSTVisitorPtr;


#endif //MAINPROJECT_SIMPLESYMBOLTABLEVISITOR_H
