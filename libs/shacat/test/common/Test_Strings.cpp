/*
 * Test_Utility_Strings.cpp
 *
 *  Created on: May 4, 2014
 *      Author: Michael Fong
 */

#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

TEST(Strings, UNIT_To_Lower_Case) {
	std::string str = "AbC";
	util::Strings::toLowerCase(str);

	EXPECT_STREQ("abc", str.c_str());
}

TEST(Strings, UNIT_To_Upper_Case) {
	std::string str = "AbC";
	util::Strings::toUpperCase(str);

	EXPECT_STREQ("ABC", str.c_str());
}

TEST(Strings, UNIT_Equals_Ignore_Case) {
	EXPECT_TRUE(util::Strings::equalsIgnoreCase("ABC", "abc"));
	EXPECT_FALSE(util::Strings::equalsIgnoreCase("ABC", "bac"));
}

TEST(Strings, UNIT_End_With) {
	EXPECT_TRUE(util::Strings::endWith("abcdefg", "fg"));
	EXPECT_FALSE(util::Strings::endWith("abcdefg", "ef"));
}

TEST(Strings, UNIT_Begin_With) {
	EXPECT_TRUE(util::Strings::beginWith("abcdefg", "abc"));
	EXPECT_FALSE(util::Strings::beginWith("abcdefg", "bc"));
}

TEST(Strings, UNIT_Contain) {
	EXPECT_TRUE(util::Strings::contain("abcdefg", "bcd"));
	EXPECT_FALSE(util::Strings::contain("abcdefg", "bcx"));
}
