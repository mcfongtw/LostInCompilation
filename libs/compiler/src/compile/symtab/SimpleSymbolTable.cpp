/*
 * SymbolTable.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <algorithm>

#include "compile/symtab/SimpleSymbolTable.h"
#include "common/Utils.h"
#include "error/Exception.h"

SimpleSymbolTable::SimpleSymbolTable() : VisitedSymbolTable() {
	this->_level = SCOPE_GLOBAL;
}

SimpleSymbolTable::SimpleSymbolTable(SymbolScope lvl) : VisitedSymbolTable(lvl) {
	this->_level = lvl;
}

SimpleSymbolTable::~SimpleSymbolTable() {
//	std::map<std::string, SymbolPtr>::iterator it;
//
//	for(it = this->symbol_map.begin(); it != this->symbol_map.end(); it++) {
//		SymbolPtr symbol = (*it).second;
////		delete symbol;
//	}

	this->symbol_map.clear();
}

void SimpleSymbolTable::add(SymbolPtr ptr) {
	util::Conditions::requireNotNull(ptr, "Symbol added into symbol table");

//	this->symbol_map.insert(std::make_pair(ptr.get()->getName(), std::move(ptr)));
	this->symbol_map[ptr.get()->getName()] = ptr;
}

void SimpleSymbolTable::remove(const std::string& name) {
	util::Conditions::requireNotEmpty(name, "symbol name");

	SymbolPtr ptr = this->lookup(name);

	if(ptr != nullptr) {
		this->symbol_map.erase(name);
	}

//	delete symbol;
}

void SimpleSymbolTable::remove(SymbolPtr ptr) {
    throw Exception("Not Yet Implemented");
    //TODO: Add bool operator() (const Object& lhs, const Object& rhs) const { .. } for the stored symbol objects
//    util::Conditions::requireNotNull(ptr, "Symbol Ptr of interest");
//
//    std::find_if(this->symbol_map.begin(), this->symbol_map.end(), ptr);
}

SymbolPtr SimpleSymbolTable::lookup(const std::string& name) {
	util::Conditions::requireNotEmpty(name, "symbol name");

	std::map<std::string, SymbolPtr>::iterator it;

	it = this->symbol_map.find(name);

	if(it == this->symbol_map.end()) {
		return nullptr;
	} else {
		return it->second;
	}
}

std::string SimpleSymbolTable::toString() {
	if(this->isEmpty()) {
		return "..NO SYMBOL..";
	}

	std::map<std::string, SymbolPtr>::iterator it;
	int index = 1;
	std::string result = "\n";

	for(it = this->symbol_map.begin(); it != this->symbol_map.end(); it++) {
		Symbol* ptr = (*it).second.get();
		result += util::Converts::numberToString(index) + ")" + ptr->toString();
		index++;
	}

	return result;
}

bool SimpleSymbolTable::isEmpty() {
	return this->symbol_map.empty();
}

void SimpleSymbolTable::setScope(SymbolScope lvl) {
	this->_level = lvl;
}

SymbolScope SimpleSymbolTable::getScope() {
	return this->_level;
}

void SimpleSymbolTable::accept(VisitorPtr) {

}