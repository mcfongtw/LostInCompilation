/*
 * Test_Exception.cpp
 *
 *  Created on: May 8, 2014
 *      Author: Michael Fong
 */
#include "gtest/gtest.h"

#include "error/ParseException.h"

void throwParseException() {
	throw ParseException("parse error!");
}

TEST(EXCEPTION, Parse_Exception) {
	EXPECT_THROW(throwParseException(), ParseException);
}
