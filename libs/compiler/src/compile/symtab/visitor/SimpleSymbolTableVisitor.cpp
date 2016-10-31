//
// Created by Michael Fong on 10/21/16.
//

#include "compile/symtab/visitor/SimpleSymbolTableVisitor.h"

SimpleSymbolTableVisitor::SimpleSymbolTableVisitor() {

}

SimpleSymbolTableVisitor::~SimpleSymbolTableVisitor() {

}

SymbolPtr SimpleSymbolTableVisitor::lookup(const std::string &name) {
    return this->_current->lookup(name);
}

int SimpleSymbolTableVisitor::visit(SymbolTablePtr ptr) {
    this->_current = ptr;

    this->startVisit();

    this->stopVisit();
}

int SimpleSymbolTableVisitor::startVisit() {
    return 1;
}

int SimpleSymbolTableVisitor::stopVisit() {
    return 1;
}