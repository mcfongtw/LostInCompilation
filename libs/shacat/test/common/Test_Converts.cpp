/*
 * TestUtility.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Michael Fong
 */

#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
#include "error/Exception.h"

//TODO: complete the testing code for <long> <float> <size_t> <uint64_t>

//Test std::string -> <type>

TEST(Converts, UNIT_STRING_TO_BOOL_Simple) {
	EXPECT_TRUE(util::Converts::stringToBool("true"));
	EXPECT_FALSE(util::Converts::stringToBool("false"));
}

TEST(Converts, UNIT_STRING_TO_BOOL_Exception) {
	EXPECT_THROW(util::Converts::stringToBool("1"), IllegalArgumentException);
	EXPECT_THROW(util::Converts::stringToBool("0"), IllegalArgumentException);
	EXPECT_THROW(util::Converts::stringToBool("-1"), IllegalArgumentException);
}

TEST(Converts, UNIT_STRING_TO_INT_Simple) {
	EXPECT_EQ(1, util::Converts::stringToNumber<int>("1"));
	EXPECT_EQ(0, util::Converts::stringToNumber<int>("0"));
	EXPECT_EQ(-1, util::Converts::stringToNumber<int>("-1"));
}

TEST(Converts, UNIT_STRING_TO_INT_Down_Cast) {
	EXPECT_EQ(1, util::Converts::stringToNumber<int>("1.1"));
	EXPECT_EQ(0, util::Converts::stringToNumber<int>("0.2"));
	EXPECT_EQ(-1, util::Converts::stringToNumber<int>("-1.3"));
}

TEST(Converts, UNIT_STRING_TO_DOUBLE_Simple) {
	EXPECT_EQ(1.1, util::Converts::stringToNumber<double>("1.1"));
	EXPECT_EQ(0.2, util::Converts::stringToNumber<double>("0.2"));
	EXPECT_EQ(-1.3, util::Converts::stringToNumber<double>("-1.3"));
}

TEST(Converts, UNIT_STRING_TO_DOUBLE_Up_Cast) {
	EXPECT_EQ(1.0, util::Converts::stringToNumber<double>("1"));
	EXPECT_EQ(0.0, util::Converts::stringToNumber<double>("0"));
	EXPECT_EQ(-1.0, util::Converts::stringToNumber<double>("-1"));
}

/*
 *                  | 32-bit | 64-bit
-------------------------------
int                 |    4   |    4
-------------------------------
long int            |    4   |    8
-------------------------------
signed long int     |    4   |    4
-------------------------------
ulong               |    4   |    8      (sys/types.h)
-------------------------------
long double         |    12  |    16
 */
//Test hex std::string -> <type>

//TODO: expect negative, but become unsigned
TEST(Converts, UNIT_HEX_STRING_TO_TYPE_Short_2_Bytes) {
	EXPECT_EQ(1, util::Converts::hexStringToNumber<short>("1"));

	EXPECT_EQ(1, util::Converts::hexStringToNumber<short>("0x1"));

	EXPECT_EQ(0, util::Converts::hexStringToNumber<short>("0x0000"));

	EXPECT_EQ(1, util::Converts::hexStringToNumber<short>("0x0001"));

//	EXPECT_EQ(-1, util::Converts::hexStringToNumber<short>("0xffff"));

	EXPECT_EQ(127, util::Converts::hexStringToNumber<short>("0x007f"));

//	EXPECT_EQ(-128, util::Converts::hexStringToNumber<short>("0xff80"));

	//max of signed short - 2 bytes
	EXPECT_EQ(32767, util::Converts::hexStringToNumber<short>("0x7fff"));

	//min of signed short - 2 bytes
//	EXPECT_EQ(-32768, util::Converts::hexStringToNumber<short>("0x8000"));
}

//TODO: expect negative, but become unsigned
TEST(Converts, UNIT_HEX_STRING_TO_TYPE_Integer_4_Bytes) {
	EXPECT_EQ(1, util::Converts::hexStringToNumber<int>("1"));

	EXPECT_EQ(1, util::Converts::hexStringToNumber<int>("0x1"));

	EXPECT_EQ(0, util::Converts::hexStringToNumber<int>("0x0000"));

	EXPECT_EQ(1, util::Converts::hexStringToNumber<int>("0x0001"));

//	EXPECT_EQ(-1, util::Converts::hexStringToNumber<int>("0xffff"));

	EXPECT_EQ(127, util::Converts::hexStringToNumber<int>("0x007f"));

//	EXPECT_EQ(-128, util::Converts::hexStringToNumber<int>("0xff80"));

	EXPECT_EQ(32767, util::Converts::hexStringToNumber<int>("0x7fff"));

//	EXPECT_EQ(-32768, util::Converts::hexStringToNumber<int>("0x8000"));

	//max of signed int - 4 bytes
	EXPECT_EQ(2147483647, util::Converts::hexStringToNumber<int>("0x7fffffff"));

	//min of signed int - 4 bytes
//	EXPECT_EQ(-2147483647, util::Converts::hexStringToNumber<int>("0x80000001"));
}

//TODO: expect negative, but become unsigned
TEST(Converts, UNIT_HEX_STRING_TO_TYPE_Long_8_Bytes) {
	EXPECT_EQ(1, util::Converts::hexStringToNumber<long>("1"));

	EXPECT_EQ(1, util::Converts::hexStringToNumber<long>("0x1"));

	EXPECT_EQ(0, util::Converts::hexStringToNumber<long>("0x0000"));

	EXPECT_EQ(1, util::Converts::hexStringToNumber<long>("0x0001"));

//	EXPECT_EQ(-1, util::Converts::hexStringToNumber<long>("0xffff"));

	EXPECT_EQ(127, util::Converts::hexStringToNumber<long>("0x007f"));

//	EXPECT_EQ(-128, util::Converts::hexStringToNumber<long>("0xff80"));

	EXPECT_EQ(32767, util::Converts::hexStringToNumber<long>("0x7fff"));

//	EXPECT_EQ(-32768, util::Converts::hexStringToNumber<long>("0x8000"));

	EXPECT_EQ(2147483647, util::Converts::hexStringToNumber<long>("0x7fffffff"));

//	EXPECT_EQ(-2147483647, util::Converts::hexStringToNumber<long>("0x80000001"));

	//max of signed long - 8 bytes
	EXPECT_EQ(9223372036854775807, util::Converts::hexStringToNumber<long>("0x7fffffffffffffff"));

	//min of signed long - 8 bytes
//	EXPECT_EQ(-9223372036854775807, util::Converts::hexStringToNumber<long>("0x8000000000000001"));


}
//Test <type> -> std::string

TEST(Converts, UNIT_BOOL_TO_STRING_Simple) {
	EXPECT_STREQ("true", util::Converts::boolToString(true).c_str());
	EXPECT_STREQ("false", util::Converts::boolToString(false).c_str());
}

TEST(Converts, UNIT_INT_TO_STRING_Simple) {
	EXPECT_STREQ("1", util::Converts::numberToString<int>(1).c_str());
	EXPECT_STREQ("0", util::Converts::numberToString<int>(0).c_str());
	EXPECT_STREQ("-1", util::Converts::numberToString<int>(-1).c_str());
}

TEST(Converts, UNIT_INT_TO_STRING_Down_Cast) {
	EXPECT_STREQ("1", util::Converts::numberToString<int>(1.1).c_str());
	EXPECT_STREQ("0", util::Converts::numberToString<int>(0.2).c_str());
	EXPECT_STREQ("-1", util::Converts::numberToString<int>(-1.3).c_str());
}

TEST(Converts, UNIT_DOUBLE_TO_STRING_Simple) {
	EXPECT_STREQ("1.1", util::Converts::numberToString<double>(1.1).c_str());
	EXPECT_STREQ("0.2", util::Converts::numberToString<double>(0.2).c_str());
	EXPECT_STREQ("-1.3", util::Converts::numberToString<double>(-1.3).c_str());
}

TEST(Converts, UNIT_DOUBLE_TO_STRING_Up_Cast) {
	EXPECT_STREQ("1", util::Converts::numberToString<double>(1.0).c_str());
	EXPECT_STREQ("0", util::Converts::numberToString<double>(0.0).c_str());
	EXPECT_STREQ("-1", util::Converts::numberToString<double>(-1.0).c_str());
}

/*
 *                  | 32-bit | 64-bit
-------------------------------
int                 |    4   |    4
-------------------------------
long int            |    4   |    8
-------------------------------
signed long int     |    4   |    4
-------------------------------
ulong               |    4   |    8      (sys/types.h)
-------------------------------
long double         |    12  |    16
 */

//Test <type> -> hex std::string
TEST(Converts, UNIT_TYPE_TO_HEX_STRING_Short_2_Bytes) {
	EXPECT_STREQ("0x0000", util::Converts::numberToHexString<short>(0).c_str());

	EXPECT_STREQ("0x0001", util::Converts::numberToHexString<short>(1).c_str());

	EXPECT_STREQ("0xffff", util::Converts::numberToHexString<short>(-1).c_str());

	EXPECT_STREQ("0x007f", util::Converts::numberToHexString<short>(127).c_str());

	EXPECT_STREQ("0xff80", util::Converts::numberToHexString<short>(-128).c_str());

	//max of signed short - 2 bytes
	EXPECT_STREQ("0x7fff", util::Converts::numberToHexString<short>(32767).c_str());

	//min of signed short - 2 bytes
	EXPECT_STREQ("0x8000", util::Converts::numberToHexString<short>(-32768).c_str());

	//overflow
	EXPECT_STREQ("0x8000", util::Converts::numberToHexString<short>(32768).c_str());

	//overflow
	EXPECT_STREQ("0x7fff", util::Converts::numberToHexString<short>(-32769).c_str());

}

TEST(Converts, UNIT_TYPE_TO_HEX_STRING_Integer_4_Bytes) {
	EXPECT_STREQ("0x00000000", util::Converts::numberToHexString<int>(0).c_str());

	EXPECT_STREQ("0x00000001", util::Converts::numberToHexString<int>(1).c_str());

	EXPECT_STREQ("0xffffffff", util::Converts::numberToHexString<int>(-1).c_str());

	EXPECT_STREQ("0x0000007f", util::Converts::numberToHexString<int>(127).c_str());

	EXPECT_STREQ("0xffffff80", util::Converts::numberToHexString<int>(-128).c_str());

	EXPECT_STREQ("0x00007fff", util::Converts::numberToHexString<int>(32767).c_str());

	EXPECT_STREQ("0xffff8000", util::Converts::numberToHexString<int>(-32768).c_str());

	//max of signed integer - 4 bytes
	EXPECT_STREQ("0x7fffffff", util::Converts::numberToHexString<int>(2147483647).c_str());

	//min of signed integer - 4 bytes
	EXPECT_STREQ("0x80000001", util::Converts::numberToHexString<int>(-2147483647).c_str());

	//overflow
	EXPECT_STREQ("0x0000000080000000", util::Converts::numberToHexString<long>(2147483648).c_str());

	//overflow
	EXPECT_STREQ("0xffffffff80000000", util::Converts::numberToHexString<long>(-2147483648).c_str());

}

TEST(Converts, UNIT_TYPE_TO_HEX_STRING_Long_8_Byte) {
	EXPECT_STREQ("0x0000000000000000", util::Converts::numberToHexString<long>(0).c_str());

	EXPECT_STREQ("0x0000000000000001", util::Converts::numberToHexString<long>(1).c_str());

	EXPECT_STREQ("0xffffffffffffffff", util::Converts::numberToHexString<long>(-1).c_str());

	EXPECT_STREQ("0x000000000000007f", util::Converts::numberToHexString<long>(127).c_str());

	EXPECT_STREQ("0xffffffffffffff80", util::Converts::numberToHexString<long>(-128).c_str());

	EXPECT_STREQ("0x0000000000007fff", util::Converts::numberToHexString<long>(32767).c_str());

	EXPECT_STREQ("0xffffffffffff8000", util::Converts::numberToHexString<long>(-32768).c_str());

	EXPECT_STREQ("0x000000007fffffff", util::Converts::numberToHexString<long>(2147483647).c_str());

	EXPECT_STREQ("0xffffffff80000001", util::Converts::numberToHexString<long>(-2147483647).c_str());

	//max of signed long - 8 bytes
	EXPECT_STREQ("0x7fffffffffffffff", util::Converts::numberToHexString<long>(9223372036854775807).c_str());

	//min of signed long - 8 bytes
	EXPECT_STREQ("0x8000000000000001", util::Converts::numberToHexString<long>(-9223372036854775807).c_str());

	//overflow
	EXPECT_STREQ("0x8000000000000000", util::Converts::numberToHexString<signed long long>(9223372036854775808).c_str());

	//overflow
	EXPECT_STREQ("0x7fffffffffffffff", util::Converts::numberToHexString<signed long long>(-9223372036854775809).c_str());

}
