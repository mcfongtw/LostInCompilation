/*
 * Test_SymbolTable.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */

#include "compile/binding/RuntimeData.h"
#include "compile/symtab/Symbol.h"
#include "compile/symtab/SimpleSymbolTable.h"
#include "compile/symtab/SymbolTableFactory.h"
#include "compile/symtab/SymbolTableStack.h"

#include "gtest/gtest.h"

#include <typeinfo>
#include "compile/symtab/visitor/SimpleSymbolTableVisitor.h"
#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"


TEST(SYMBOL_TABLE, UNIT_Simple_Symbol) {
	double d = 1.234;
	RuntimeData value(d);

	Symbol symbol("x", value);

	EXPECT_STREQ("x", symbol.getName().c_str());
	EXPECT_EQ(1.234, symbol.getValue().get<double>());
}

TEST(SYMBOL_TABLE, UNIT_Simple_Symbol_Table) {
	double d = 1.234;
	RuntimeData value1(d);
	SymbolPtr symbPtr1 = SymbolPtr(new Symbol("x", value1));

	int i = 1;
	RuntimeData value2(i);
	SymbolPtr symbPtr2 = SymbolPtr(new Symbol("y", value2));

    SimpleSymbolTable table;
	table.add(symbPtr1);
	table.add(symbPtr2);

	EXPECT_TRUE(table.lookup("x") != nullptr);
	EXPECT_STREQ("x", table.lookup("x")->getName().c_str());
	EXPECT_EQ(1.234, table.lookup("x")->getValue().get<double>());
	EXPECT_TRUE(table.lookup("y") != nullptr);
	EXPECT_STREQ("y", table.lookup("y")->getName().c_str());
	EXPECT_EQ(1, table.lookup("y")->getValue().get<int>());

}

TEST(SYMBOL_TABLE, UNIT_Simple_Remove_From_Symbol_Table) {
	double d = 1.234;
	RuntimeData value1(d);
	SymbolPtr symbPtr1 = SymbolPtr(new Symbol("x", value1));

	SimpleSymbolTable table;
	table.add(symbPtr1);
    table.remove(symbPtr1);

    EXPECT_TRUE(table.lookup("x") == nullptr);
    EXPECT_TRUE(table.isEmpty());
}

TEST(SYMBOL_TABLE, UNIT_Symbol_Table_Boundary_Condition) {
    SimpleSymbolTable table;

	EXPECT_FALSE(table.lookup("z") != nullptr);
}

TEST(SYMBOL_TABLE, UNIT_Advanced_Symbol_Table_Change_Value) {
	double d = 1.234;
	RuntimeData oldVal(d);
	SymbolPtr ptr = SymbolPtr(new Symbol("x", oldVal));

    SimpleSymbolTable table;
	table.add(ptr);

	EXPECT_EQ(1.234, table.lookup("x").get()->getValue().get<double>());

	double d2 = 9.999;
	RuntimeData newVal(d2);
	ptr->setValue(newVal);

	EXPECT_EQ(9.999, table.lookup("x").get()->getValue().get<double>());
}

TEST(SYMBOL_TABLE, UNIT_Advanced_Symbol_Table_Change_Type) {
	double d = 1.234;
	RuntimeData oldVal(d);
	SymbolPtr ptr = SymbolPtr(new Symbol("x", oldVal));

    SimpleSymbolTable table;
	table.add(ptr);

	EXPECT_EQ(typeid(double), table.lookup("x").get()->getValue().getType());
	EXPECT_EQ(1.234, table.lookup("x").get()->getValue().get<double>());

	int i2 = 100;
	RuntimeData newVal(i2);
	ptr->setValue(newVal);

	EXPECT_EQ(typeid(int), table.lookup("x").get()->getValue().getType());
	EXPECT_EQ(100, table.lookup("x").get()->getValue().get<int>());
}

TEST(SYMBOL_TABLE_FACTORY, UNIT_Simple) {
    SymbolTablePtr ptr = nullptr;

    ptr = SymbolTableFactory::getSymbolTable(ST_Simple);
    EXPECT_EQ(ptr->getScope(), SCOPE_GLOBAL);
    EXPECT_TRUE(dynamic_cast<SimpleSymbolTable*>(ptr.get()));

    ptr = SymbolTableFactory::getSymbolTable(ST_Simple, SCOPE_FUNCTIONAL);
    EXPECT_EQ(ptr->getScope(), SCOPE_FUNCTIONAL);
    EXPECT_TRUE(dynamic_cast<SimpleSymbolTable*>(ptr.get()));
}

TEST(Symbol_Table_Visitor, FUNCTIONAL_Simple) {
    SymbolTablePtr table = SymbolTableFactory::getSymbolTable(ST_Simple);
    double d = 1.234;
    RuntimeData oldVal(d);
    SymbolPtr symbol = SymbolPtr(new Symbol("x", oldVal));
    table->add(symbol);

    SimpleSTVisitorPtr visitor = std::make_shared<SimpleSymbolTableVisitor>();
    visitor->visit(table);
    SymbolPtr answer = visitor->lookup("x");

    EXPECT_EQ(answer->getName(), "x");
    EXPECT_EQ(answer->getValue().get<double>(), 1.234);
}

