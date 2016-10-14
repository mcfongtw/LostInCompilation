/*
 * Test_Basics.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: shannaracat
 */

#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
#include "error/Exception.h"

/*
                    | 32-bit | 64-bit
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

/*

	ILP32	LP64	LLP64	ILP64
char	8	8	8	8
short	16	16	16	16
int	32	32	32	64
long	32	64	32	64
long long	64	64	64	64
size_t	32	64	64	64
pointer	32	64	64	64
 */
TEST(GCC_BASIC, Data_Type_Size) {
	EXPECT_EQ(1, sizeof(bool));

	EXPECT_EQ(1, sizeof(char));
	EXPECT_EQ(2, sizeof(short));
	EXPECT_EQ(2, sizeof(unsigned short));
	EXPECT_EQ(4, sizeof(int));
	EXPECT_EQ(4, sizeof(unsigned int));
	EXPECT_EQ(8, sizeof(long));
	EXPECT_EQ(8, sizeof(unsigned long));
	EXPECT_EQ(8, sizeof(long long));
	EXPECT_EQ(8, sizeof(unsigned long long));

	EXPECT_EQ(4, sizeof(float));
	EXPECT_EQ(8, sizeof(double));
	EXPECT_EQ(16, sizeof(long double));

	EXPECT_EQ(4, sizeof(wchar_t));

	EXPECT_EQ(2, sizeof(uint16_t));
	EXPECT_EQ(4, sizeof(uint32_t));
	EXPECT_EQ(8, sizeof(uint64_t));

	//Unsigned integer type. Data of this bype is returned by the sizeof() operator.
	EXPECT_EQ(8, sizeof(size_t));

	//Integer types capable to keep pointer value.
	EXPECT_EQ(8, sizeof(intptr_t));
	EXPECT_EQ(8, sizeof(uintptr_t));

	EXPECT_EQ(8, sizeof(time_t));
}


