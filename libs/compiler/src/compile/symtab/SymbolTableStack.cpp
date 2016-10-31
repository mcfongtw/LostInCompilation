//
// Created by Michael Fong on 2016/10/25.
//


#include "compile/symtab/SymbolTableStack.h"
#include "compile/symtab/SymbolTableFactory.h"
#include "compile/symtab/SimpleSymbolTable.h"

SymbolTableStack::SymbolTableStack(SymbolTableStrategy strategy) : VisitedObject(), SymbolRepository() {
    this->_strategy = strategy;
}

SymbolTableStack::~SymbolTableStack() {

}

bool SymbolTableStack::isEmpty() {
    return this->_stack.size() == 0;
}

SymbolPtr SymbolTableStack::lookup(const std::string &name) {
    SymbolPtr result = nullptr;

    for(int i = this->_stack.size() - 1; i >= 0; i--) {
        result = this->_stack[i]->lookup(name);
        if(result != nullptr) {
            break;
        }
    }

    return result;
}

void SymbolTableStack::add(SymbolPtr ptr) {
    this->_current->add(ptr);
}

void SymbolTableStack::remove(const std::string &name) {
    this->_current->remove(name);
}

void SymbolTableStack::remove(SymbolPtr ptr) {
    //TODO: Add bool operator() (const Object& lhs, const Object& rhs) const { .. } for the stored symbol objects
//    util::Conditions::requireNotNull(ptr, "Symbol Ptr of interest");
//
//    std::find_if(this->symbol_map.begin(), this->symbol_map.end(), ptr);
}

void SymbolTableStack::accept(VisitorPtr) {

}


std::string SymbolTableStack::toString() {

}

void SymbolTableStack::openScope() {
    this->openScope(SCOPE_GLOBAL);
}

void SymbolTableStack::openScope(SymbolScope scope) {
    SymbolTablePtr newSTPtr = SymbolTableFactory::getSymbolTable(this->_strategy, scope);
    this->_stack.push_back(newSTPtr);
    this->_current = newSTPtr;
}

void SymbolTableStack::closeScope() {
    this->_stack.pop_back();
    if(this->_stack.empty()) {
        this->_current = nullptr;
    } else {
        this->_current = this->_stack.back();
    }
}

int SymbolTableStack::size() {
    return this->_stack.size();
}
SymbolScope SymbolTableStack::getScope() {
    return this->_current->getScope();
}