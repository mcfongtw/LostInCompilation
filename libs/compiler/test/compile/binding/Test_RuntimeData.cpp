/*
 * Test_DataBlock.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Michael Fong
 */

#include <string>
#include <typeinfo>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "error/Exception.h"
#include "compile/binding/RuntimeData.h"
#include "compile/symtab/RuntimeStack.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

TEST(RUNTIME_DATA, UNIT_Null_Object) {
    RuntimeData data1;
    EXPECT_TRUE(data1.isNull());
//TODO: Make the result of statement works
//    RuntimeData data2 = data1;
//    EXPECT_TRUE(data2.isNull());
//
//	RuntimeData data3 = nullptr;
//	EXPECT_TRUE(data3.isNull());
//
//	RuntimeData data4 = NULL;
//	EXPECT_TRUE(data4.isNull());
//
//    RuntimeData data5(nullptr);
//    EXPECT_TRUE(data5.isNull());
//
//    RuntimeData data6(0);
//    EXPECT_FALSE(data6.isNull());
}

TEST(RUNTIME_DATA, UNIT_Copy_Null_Object) {
    /////////////////////////////////////////////
    // nullptr vs nullptr
    ////////////////////////////////////////////
    RuntimeData hasValue(1);

    RuntimeData nullptrObj = nullptr;

    EXPECT_FALSE(hasValue == nullptrObj);
    EXPECT_FALSE(nullptrObj == hasValue);

    RuntimeData copyOfNullptrObj = nullptrObj;

    EXPECT_TRUE(copyOfNullptrObj == nullptrObj);
    EXPECT_TRUE(nullptrObj == copyOfNullptrObj);

	/////////////////////////////////////////////
    // NULL vs NULL
    ////////////////////////////////////////////

	RuntimeData nullObj = NULL;

	EXPECT_FALSE(hasValue == nullObj);
	EXPECT_FALSE(nullObj == hasValue);

	RuntimeData copyOfNullObj = nullObj;

	EXPECT_TRUE(copyOfNullObj == nullObj);
	EXPECT_TRUE(nullObj == copyOfNullObj);

	/////////////////////////////////////////////
    // nullptr vs NULL
    ////////////////////////////////////////////
	EXPECT_FALSE(copyOfNullObj == copyOfNullptrObj);
}

RuntimeData testPassByReference() {
    RuntimeData origin(1);

    return origin;
}

TEST(RUNTIME_DATA, UNIT_Copy_Object) {
	RuntimeData copy = testPassByReference();

	EXPECT_STREQ("i", copy.getType().name());
	EXPECT_THROW(copy.get<double>(), TypeCastException);
	EXPECT_EQ(sizeof(int), copy.getSizeof());
	EXPECT_EQ(1, copy.get<int>());
}

TEST(RUNTIME_DATA, UNIT_Primitive_Bool) {
	RuntimeData obj(true);
	EXPECT_STREQ("b", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(bool), obj.getSizeof());
	EXPECT_TRUE(obj.get<bool>());
}

TEST(RUNTIME_DATA, UNIT_Primitive_Int) {
	RuntimeData obj(1);
	EXPECT_STREQ("i", obj.getType().name());
	EXPECT_THROW(obj.get<double>(), TypeCastException);
	EXPECT_EQ(sizeof(int), obj.getSizeof());
	EXPECT_EQ(1, obj.get<int>());
}

TEST(RUNTIME_DATA, UNIT_Primitive_Double) {
	RuntimeData obj(1.234);
	EXPECT_STREQ("d", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(double), obj.getSizeof());
	EXPECT_EQ(1.234, obj.get<double>());
}

TEST(RUNTIME_DATA, UNIT_Primitive_String) {
	RuntimeData obj((std::string)"Hello World");
	EXPECT_STREQ("Ss", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(std::string), obj.getSizeof());
	EXPECT_STREQ("Hello World", obj.get<std::string>().c_str());
}

TEST(RUNTIME_DATA, UNIT_Primitive_Value_Change) {
	RuntimeData obj(1);
	EXPECT_EQ(1, obj.get<int>());

	obj = 1.234;
	EXPECT_EQ(1.234, obj.get<double>());

	obj = (std::string)"Hello World";
	EXPECT_STREQ("Hello World", obj.get<std::string>().c_str());
}

TEST(RUNTIME_DATA, UNIT_Equality) {
	RuntimeData obj(1);

	RuntimeData result = obj;
	EXPECT_TRUE(obj == result);
}

TEST(RUNTIME_DATA, UNIT_Vector_Bool) {
	std::vector<bool> list;
	list.push_back(true);
	list.push_back(false);

	RuntimeData obj((std::vector<bool>)list);
	EXPECT_STREQ("St6vectorIbSaIbEE", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		bool actual = obj.get<std::vector<bool>>()[i];
		bool expect = list[i];

		EXPECT_EQ(expect, actual);
	}
}

TEST(RUNTIME_DATA, UNIT_Vector_Int) {
	std::vector<int> list;
	list.push_back(1);
	list.push_back(0);
	list.push_back(-1);

	RuntimeData obj((std::vector<int>)list);
	EXPECT_STREQ("St6vectorIiSaIiEE", obj.getType().name());
	EXPECT_THROW(obj.get<bool>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		int actual = obj.get<std::vector<int>>()[i];
		int expect = list[i];

		EXPECT_EQ(expect, actual);
	}
}

TEST(RUNTIME_DATA, UNIT_Vector_Double) {
	std::vector<double> list;
	list.push_back(1.234);
	list.push_back(0.123);
	list.push_back(-1.234);

	RuntimeData obj((std::vector<double>)list);
	EXPECT_STREQ("St6vectorIdSaIdEE", obj.getType().name());
	EXPECT_THROW(obj.get<bool>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		double actual = obj.get<std::vector<double>>()[i];
		double expect = list[i];

		EXPECT_EQ(expect, actual);
	}
}

TEST(RUNTIME_DATA, UNIT_Vector_String) {
	std::vector<std::string> list;
	list.push_back("Hello");
	list.push_back("World");
	list.push_back("foo");

	//RuntimeData obj = (std::vector<int>)list;
	RuntimeData obj((std::vector<std::string>)list);
	EXPECT_STREQ("St6vectorISsSaISsEE", obj.getType().name());
	EXPECT_THROW(obj.get<bool>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		std::string actual = obj.get<std::vector<std::string>>()[i];
		std::string expect = list[i];

		EXPECT_STREQ(expect.c_str(), actual.c_str());
	}
}
