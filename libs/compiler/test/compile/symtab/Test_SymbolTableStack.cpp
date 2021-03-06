//
// Created by Michael Fong on 2016/11/6.
//

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

TEST(Symbol_Table_Stack, FUNCTIONAL_Simple) {
SymbolTableStack stack(ST_Simple);

//Open Global Scope

stack.openScope(SCOPE_GLOBAL);
double d = 1.234;
RuntimeData value1(d);
stack.add(SymbolPtr(new Symbol("x", value1)));
EXPECT_EQ(stack.size(), 1);
EXPECT_EQ(SCOPE_GLOBAL, stack.getScope());
EXPECT_FALSE(stack.isEmpty());

SymbolPtr answer = stack.lookup("x");
EXPECT_EQ(answer->getName(), "x");
EXPECT_EQ(answer->getValue().get<double>(), 1.234);

//Open Functional Scope

stack.openScope(SCOPE_FUNCTIONAL);
int i = 123;
RuntimeData value2(i);
stack.add(SymbolPtr(new Symbol("x", value2)));
EXPECT_EQ(stack.size(), 2);
EXPECT_EQ(SCOPE_FUNCTIONAL, stack.getScope());
EXPECT_FALSE(stack.isEmpty());

answer = stack.lookup("x");
EXPECT_EQ(answer->getValue().get<int>(), 123);

//Open Local Scope

stack.openScope(SCOPE_LOCAL);
short s = 99;
RuntimeData value3(s);
stack.add(SymbolPtr(new Symbol("x", value3)));
EXPECT_EQ(stack.size(), 3);
EXPECT_EQ(SCOPE_LOCAL, stack.getScope());
EXPECT_FALSE(stack.isEmpty());

answer = stack.lookup("x");
EXPECT_EQ(answer->getValue().get<short>(), 99);

//Close Local Scope

stack.closeScope();
EXPECT_EQ(stack.size(), 2);
EXPECT_EQ(SCOPE_FUNCTIONAL, stack.getScope());
EXPECT_FALSE(stack.isEmpty());

//Close Functional Scope

stack.closeScope();
EXPECT_EQ(stack.size(), 1);
EXPECT_EQ(SCOPE_GLOBAL, stack.getScope());
EXPECT_FALSE(stack.isEmpty());

//Close Global Scope

stack.closeScope();
EXPECT_TRUE(stack.isEmpty());
}