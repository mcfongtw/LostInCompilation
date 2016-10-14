/*
 * Test_DataBlock.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Michael Fong
 */
#include <compile/symtab/ObjectValue.h>
#include <compile/symtab/RuntimeStack.h>
#include <string>
#include <typeinfo>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "error/Exception.h"

TEST(DYNAMIC_OBJ_VAL, Bool) {
	ObjectValue obj(true);
	EXPECT_STREQ("b", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(bool), obj.getSizeof());
	EXPECT_TRUE(obj.get<bool>());
}

TEST(DYNAMIC_OBJ_VAL, Int) {
	ObjectValue obj(1);
	EXPECT_STREQ("i", obj.getType().name());
	EXPECT_THROW(obj.get<double>(), TypeCastException);
	EXPECT_EQ(sizeof(int), obj.getSizeof());
	EXPECT_EQ(1, obj.get<int>());
}

TEST(DYNAMIC_OBJ_VAL, Double) {
	ObjectValue obj(1.234);
	EXPECT_STREQ("d", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(double), obj.getSizeof());
	EXPECT_EQ(1.234, obj.get<double>());
}

TEST(DYNAMIC_OBJ_VAL, String) {
	ObjectValue obj((std::string)"Hello World");
	EXPECT_STREQ("Ss", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(std::string), obj.getSizeof());
	EXPECT_STREQ("Hello World", obj.get<std::string>().c_str());
}

TEST(DYNAMIC_OBJ_VAL, Value_Change) {
	ObjectValue obj(1);
	EXPECT_EQ(1, obj.get<int>());

	obj = 1.234;
	EXPECT_EQ(1.234, obj.get<double>());

	obj = (std::string)"Hello World";
	EXPECT_STREQ("Hello World", obj.get<std::string>().c_str());
}

TEST(DYNAMIC_OBJ_VAL, Equality) {
	ObjectValue obj(1);

	ObjectValue result = obj;
	EXPECT_TRUE(obj == result);
}

TEST(DYNAMIC_OBJ_VAL, Vector_Bool) {
	std::vector<bool> list;
	list.push_back(true);
	list.push_back(false);

	ObjectValue obj((std::vector<bool>)list);
//	EXPECT_STREQ("Ss", obj.getType().name());
	EXPECT_THROW(obj.get<int>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		bool actual = obj.get<std::vector<bool>>()[i];
		bool expect = list[i];

		EXPECT_EQ(expect, actual);
	}
}

TEST(DYNAMIC_OBJ_VAL, Vector_Int) {
	std::vector<int> list;
	list.push_back(1);
	list.push_back(0);
	list.push_back(-1);

	ObjectValue obj((std::vector<int>)list);
//	EXPECT_STREQ("Ss", obj.getType().name());
	EXPECT_THROW(obj.get<bool>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		int actual = obj.get<std::vector<int>>()[i];
		int expect = list[i];

		EXPECT_EQ(expect, actual);
	}
}

TEST(DYNAMIC_OBJ_VAL, Vector_Double) {
	std::vector<double> list;
	list.push_back(1.234);
	list.push_back(0.123);
	list.push_back(-1.234);

	ObjectValue obj((std::vector<double>)list);
//	EXPECT_STREQ("Ss", obj.getType().name());
	EXPECT_THROW(obj.get<bool>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		double actual = obj.get<std::vector<double>>()[i];
		double expect = list[i];

		EXPECT_EQ(expect, actual);
	}
}

TEST(DYNAMIC_OBJ_VAL, Vector_String) {
	std::vector<std::string> list;
	list.push_back("Hello");
	list.push_back("World");
	list.push_back("foo");

	//ObjectValue obj = (std::vector<int>)list;
	ObjectValue obj((std::vector<std::string>)list);
//	EXPECT_STREQ("Ss", obj.getType().name());
	EXPECT_THROW(obj.get<bool>(), TypeCastException);
	EXPECT_EQ(sizeof(list), obj.getSizeof());
	for(size_t i = 0; i < list.size(); i++) {
		std::string actual = obj.get<std::vector<std::string>>()[i];
		std::string expect = list[i];

		EXPECT_STREQ(expect.c_str(), actual.c_str());
	}
}
