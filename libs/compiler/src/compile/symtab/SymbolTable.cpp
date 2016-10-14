/*
 * SymbolTable.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#include <compile/symtab/SymbolTable.h>
#include <iostream>

#include "common/Utils.h"

SymbolTable::SymbolTable() {
	this->_level = ST_GLOBAL;
}

SymbolTable::SymbolTable(SymbolTableLevel lvl) {
	this->_level = lvl;
}

SymbolTable::~SymbolTable() {
//	std::map<std::string, SymbolPtr>::iterator it;
//
//	for(it = this->symbol_map.begin(); it != this->symbol_map.end(); it++) {
//		SymbolPtr symbol = (*it).second;
////		delete symbol;
//	}

	this->symbol_map.clear();
}

void SymbolTable::add(SymbolPtr ptr) {
	util::Conditions::requireNotNull(ptr, "Symbol added into symbol table");

//	this->symbol_map.insert(std::make_pair(ptr.get()->getName(), std::move(ptr)));
	this->symbol_map[ptr.get()->getName()] = ptr;
}

void SymbolTable::remove(const std::string& name) {
	util::Conditions::requireNotEmpty(name, "symbol name");

	SymbolPtr ptr = this->lookup(name);

	if(ptr != nullptr) {
		this->symbol_map.erase(name);
	}

//	delete symbol;
}

SymbolPtr SymbolTable::lookup(const std::string& name) {
	util::Conditions::requireNotEmpty(name, "symbol name");

	std::map<std::string, SymbolPtr>::iterator it;

	it = this->symbol_map.find(name);

	if(it == this->symbol_map.end()) {
		return nullptr;
	} else {
		return it->second;
	}
}

std::string SymbolTable::toString() {
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

bool SymbolTable::isEmpty() {
	return this->symbol_map.empty();
}

void SymbolTable::setLevel(SymbolTableLevel lvl) {
	this->_level = lvl;
}

SymbolTableLevel SymbolTable::getLevel() {
	return this->_level;
}
