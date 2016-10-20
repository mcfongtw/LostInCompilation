/*
 * Test_SymbolTable.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */

#include "compile/symtab/ObjectValue.h"
#include "compile/symtab/Symbol.h"
#include "compile/symtab/SimpleSymbolTable.h"
#include "compile/symtab/SymbolTableTreeNode.h"
#include "compile/symtab/SymbolTableFactory.h"

#include "gtest/gtest.h"

#include <typeinfo>


TEST(SYMBOL_TABLE, UNIT_Simple_Symbol) {
	double d = 1.234;
	ObjectValue value(d);

	Symbol symbol("x", value);

	EXPECT_STREQ("x", symbol.getName().c_str());
	EXPECT_EQ(1.234, symbol.getValue().get<double>());
}

TEST(SYMBOL_TABLE, UNIT_Simple_Symbol_Table) {
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

TEST(SYMBOL_TABLE, UNIT_Symbol_Table_Boundary_Condition) {
    SimpleSymbolTable table;

	EXPECT_FALSE(table.lookup("z") != nullptr);
}

TEST(SYMBOL_TABLE, UNIT_Advanced_Symbol_Table_Change_Value) {
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

TEST(SYMBOL_TABLE, UNIT_Advanced_Symbol_Table_Change_Type) {
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

TEST(SYMBOL_TABLE_FACTORY, UNIT_Simple) {
    SymbolTablePtr ptr = nullptr;

    ptr = SymbolTableFactory::getSymbolTable(ST_Simple);
    EXPECT_EQ(ptr->getScope(), SCOPE_GLOBAL);
    EXPECT_TRUE(dynamic_cast<SimpleSymbolTable*>(ptr.get()));

    ptr = SymbolTableFactory::getSymbolTable(ST_Simple, SCOPE_FUNCTIONAL);
    EXPECT_EQ(ptr->getScope(), SCOPE_FUNCTIONAL);
    EXPECT_TRUE(dynamic_cast<SimpleSymbolTable*>(ptr.get()));
}

TEST(SYMBOL_TABLE_FACTORY, UNIT_Hierarchical) {
    SymbolTablePtr ptr = nullptr;

    ptr = SymbolTableFactory::getSymbolTable(ST_Tree);
    EXPECT_EQ(ptr->getScope(), SCOPE_GLOBAL);
    EXPECT_TRUE(dynamic_cast<SymbolTableTreeNode*>(ptr.get()));

    ptr = SymbolTableFactory::getSymbolTable(ST_Tree, SCOPE_LOCAL);
    EXPECT_EQ(ptr->getScope(), SCOPE_LOCAL);
    EXPECT_TRUE(dynamic_cast<SymbolTableTreeNode*>(ptr.get()));
}

TEST(SYMBOL_TABLE, UNIT_Hierarchical_Symbol_Table) {
    HierarchicalSymbolTablePtr root = std::make_shared<SymbolTableTreeNode>(SCOPE_GLOBAL);
    HierarchicalSymbolTablePtr child = std::make_shared<SymbolTableTreeNode>(SCOPE_FUNCTIONAL);
    HierarchicalSymbolTablePtr grandchild = std::make_shared<SymbolTableTreeNode>(SCOPE_LOCAL);
    root->insertChild(child);
    child->insertChild(grandchild);

    HierarchicalSymbolTablePtr tmp = nullptr;

    EXPECT_EQ(1, root->getNumOfChildren());
    EXPECT_EQ(0, root->getChildIndexOf(child));
    tmp = std::dynamic_pointer_cast<SymbolTableTreeNode>(root->getChildAt(0));
    EXPECT_EQ(SCOPE_FUNCTIONAL, tmp->getScope());

    EXPECT_EQ(1, child->getNumOfChildren());
    EXPECT_EQ(0, child->getChildIndexOf(grandchild));
    EXPECT_EQ(root.get(), child->getParent());
    tmp = std::dynamic_pointer_cast<SymbolTableTreeNode>(child->getChildAt(0));
    EXPECT_EQ(SCOPE_LOCAL, tmp->getScope());

    EXPECT_EQ(0, grandchild->getNumOfChildren());
    EXPECT_EQ(child.get(), grandchild->getParent());
}
