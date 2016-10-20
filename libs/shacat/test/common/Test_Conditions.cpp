/*
 * Test_Utility_Conditions.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Michael Fong
 */
#include <string>
#include <memory>

#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
#include "error/Exception.h"

TEST(Conditions, UNIT_Require_True) {
	util::Conditions::requireTrue(true, "Expect normal");
	EXPECT_THROW(util::Conditions::requireTrue(false, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Not_Null) {
	std::string* nul = 0;
	std::string* empty = new std::string();
	std::string ref;

	util::Conditions::requireNotNull(empty, "Expect normal");
	util::Conditions::requireNotNull(&ref, "Expect normal");
	EXPECT_THROW(util::Conditions::requireNotNull(nul, "Expect error"), NullPointerException);
}

TEST(Conditions, UNIT_Require_Not_Null_Shared_Ptr) {
	std::shared_ptr<std::string> nul;
	std::shared_ptr<std::string> empty = std::shared_ptr<std::string>(new std::string(""));

	util::Conditions::requireNotNull(empty, "Expect normal");
	EXPECT_THROW(util::Conditions::requireNotNull(nul, "Expect error"), NullPointerException);
}

//FIXME: Use of unique_ptr<?> does not work
//TEST(Conditions, UNIT_Require_Not_Null_Unique_Ptr) {
//	std::unique_ptr<std::string> nul;
//	std::unique_ptr<std::string> empty = std::unique_ptr<std::string>(new std::string(""));
//
//	util::Conditions::requireNotNull(empty, "Expect normal");
//	EXPECT_THROW(util::Conditions::requireNotNull(nul, "Expect error"), NullPointerException);
//}

TEST(Conditions, UNIT_Require_Greater_Than) {
	util::Conditions::requireGreaterThan(1, 0, "Expect normal");
	EXPECT_THROW(util::Conditions::requireGreaterThan(-1, 0, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Less_Than) {
	util::Conditions::requireLessThan(-1, 0, "Expect normal");
	EXPECT_THROW(util::Conditions::requireLessThan(1, 0, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Equals_To) {
	util::Conditions::requireEqualsTo(1, 1, "Expect normal");
	EXPECT_THROW(util::Conditions::requireEqualsTo(1, 0, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Between) {
	util::Conditions::requireBetween(1, 0, 2, "Expect normal");
	EXPECT_THROW(util::Conditions::requireBetween(-1, 0, 2, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Not_Empty_String) {
	std::string empty = "";
	std::string notEmpty = "1";

	util::Conditions::requireNotEmpty(notEmpty, "Expect normal");
	EXPECT_THROW(util::Conditions::requireNotEmpty(empty, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Not_Empty_Vector) {
	std::vector<int> empty;
	std::vector<int> notEmpty;
	notEmpty.push_back(1);

	util::Conditions::requireNotEmpty(notEmpty, "Expect normal");
	EXPECT_THROW(util::Conditions::requireNotEmpty(empty, "Expect error"), IllegalStateException);
}

TEST(Conditions, UNIT_Require_Not_Empty_Map) {
	std::map<int,  int> empty;
	std::map<int,  int> notEmpty;
	notEmpty[1] = 1;

	util::Conditions::requireNotEmpty(notEmpty, "Expect normal");
	EXPECT_THROW(util::Conditions::requireNotEmpty(empty, "Expect error"), IllegalStateException);
}
