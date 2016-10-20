/*
 * Test_SymbolTable.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */

#include <compile/symtab/ObjectValue.h>
#include <compile/symtab/Symbol.h>
#include <compile/symtab/SimpleSymbolTable.h>
#include "gtest/gtest.h"

#include <typeinfo>


TEST(SYMBOL_TABLE, Simple_Symbol) {
	double d = 1.234;
	ObjectValue value(d);

	Symbol symbol("x", value);

	EXPECT_STREQ("x", symbol.getName().c_str());
	EXPECT_EQ(1.234, symbol.getValue().get<double>());
}

TEST(SYMBOL_TABLE, Simple_Symbol_Table) {
	double d = 1.234;
	ObjectValue value1(d);
	SymbolPtr symbPtr1 = SymbolPtr(new Symbol("x", value1));

	int i = 1;
	ObjectValue value2(i);
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

TEST(SYMBOL_TABLE, Symbol_Table_Boundary_Condition) {
    SimpleSymbolTable table;

	EXPECT_FALSE(table.lookup("z") != nullptr);
}

TEST(SYMBOL_TABLE, Advanced_Symbol_Table_Change_Value) {
	double d = 1.234;
	ObjectValue oldVal(d);
	SymbolPtr ptr = SymbolPtr(new Symbol("x", oldVal));

    SimpleSymbolTable table;
	table.add(ptr);

	EXPECT_EQ(1.234, table.lookup("x").get()->getValue().get<double>());

	double d2 = 9.999;
	ObjectValue newVal(d2);
	ptr->setValue(newVal);

	EXPECT_EQ(9.999, table.lookup("x").get()->getValue().get<double>());
}

TEST(SYMBOL_TABLE, Advanced_Symbol_Table_Change_Type) {
	double d = 1.234;
	ObjectValue oldVal(d);
	SymbolPtr ptr = SymbolPtr(new Symbol("x", oldVal));

    SimpleSymbolTable table;
	table.add(ptr);

	EXPECT_EQ(typeid(double), table.lookup("x").get()->getValue().getType());
	EXPECT_EQ(1.234, table.lookup("x").get()->getValue().get<double>());

	int i2 = 100;
	ObjectValue newVal(i2);
	ptr->setValue(newVal);

	EXPECT_EQ(typeid(int), table.lookup("x").get()->getValue().getType());
	EXPECT_EQ(100, table.lookup("x").get()->getValue().get<int>());
}
