/*
 * TestUtility_Exception.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Michael Fong
 */
#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
#include "error/Exception.h"

void throwNullPointerException() {
	throw NullPointerException("npe!");
}

void throwIllegalStateException() {
	throw IllegalStateException("not a good state!");
}

void throwIllegalArgumentException() {
	throw IllegalArgumentException("not a good arg!");
}

void throwOutOfMemoryException() {
	throw OutOfMemoryException("oom!");
}

void throwUndefinedSymbolException() {
	throw UndefinedSymbolException("undefined!");
}

void throwTypeCastException() {
	throw TypeCastException("wrong type!");
}

void* throwExeption() {
	throw Exception("error!");

	return (void*) 1;
}

TEST(Exception, UNIT_Null_Pointer_Exception) {
	EXPECT_THROW(throwNullPointerException(), NullPointerException);
}

TEST(Exception, UNIT_Illegal_State_Exception) {
	EXPECT_THROW(throwIllegalStateException(), IllegalStateException);
}

TEST(Exception, UNIT_Illegal_Argument_Exception) {
	EXPECT_THROW(throwIllegalArgumentException(), IllegalArgumentException);
}

TEST(Exception, UNIT_Out_Of_Memory_Exception) {
	EXPECT_THROW(throwOutOfMemoryException(), OutOfMemoryException);
}

TEST(Exception, UNIT_Undefined_Symbol_Exception) {
	EXPECT_THROW(throwUndefinedSymbolException(), UndefinedSymbolException);
}

TEST(Exception, UNIT_Type_Cast_Exception) {
	EXPECT_THROW(throwTypeCastException(), TypeCastException);
}

TEST(Exception, UNIT_Genric_Exception) {
	EXPECT_THROW(throwExeption(), Exception);
}

