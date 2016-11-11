/*
 * Test_RuntimeStack.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */

#include <compile/binding/RuntimeData.h>
#include <compile/symtab/RuntimeStack.h>
#include "gtest/gtest.h"

#include <typeinfo>


TEST(RUN_TIME_STACK, UNIT_Simple) {
	RuntimeStack stack;

	EXPECT_TRUE(stack.isEmpty());
	RuntimeData obj(1.111);
	stack.push(obj);

	RuntimeData result = stack.top();
	EXPECT_EQ((size_t)1, stack.size());
	EXPECT_EQ(typeid(double), result.getType());
	EXPECT_EQ(1.111, result.get<double>());
	stack.pop();
	EXPECT_TRUE(stack.isEmpty());

}
