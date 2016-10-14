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

TEST(EXCEPTION, Null_Pointer_Exception) {
	EXPECT_THROW(throwNullPointerException(), NullPointerException);
}

TEST(EXCEPTION, Illegal_State_Exception) {
	EXPECT_THROW(throwIllegalStateException(), IllegalStateException);
}

TEST(EXCEPTION, Illegal_Argument_Exception) {
	EXPECT_THROW(throwIllegalArgumentException(), IllegalArgumentException);
}

TEST(EXCEPTION, Out_Of_Memory_Exception) {
	EXPECT_THROW(throwOutOfMemoryException(), OutOfMemoryException);
}

TEST(EXCEPTION, Undefined_Symbol_Exception) {
	EXPECT_THROW(throwUndefinedSymbolException(), UndefinedSymbolException);
}

TEST(EXCEPTION, Type_Cast_Exception) {
	EXPECT_THROW(throwTypeCastException(), TypeCastException);
}

TEST(EXCEPTION, Exception) {
	EXPECT_THROW(throwExeption(), Exception);
}

