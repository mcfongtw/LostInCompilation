/*
 * Test_Hack.cpp
 *
 *  Created on: Jun 13, 2014
 *      Author: Michael Fong
 */

#include "gtest/gtest.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"
#include "hack/AccessPrivate.h"

class PoorGuy {
private:
	const char* getName() { return "John";}

	bool isMale() {return true;}

	int getAge() { return 20;}

	int plusOne(int i) { return i + 1;}

	double money = 1.23;
};

struct PoorGuyPrivate_getName { typedef const char*(PoorGuy::*type)(); };
template class HackPrivate<PoorGuyPrivate_getName, &PoorGuy::getName>;

struct PoorGuyPrivate_isMale { typedef bool(PoorGuy::*type)(); };
template class HackPrivate<PoorGuyPrivate_isMale, &PoorGuy::isMale>;

struct PoorGuyPrivate_getAge { typedef int(PoorGuy::*type)(); };
template class HackPrivate<PoorGuyPrivate_getAge, &PoorGuy::getAge>;

struct PoorGuyPrivate_plusOne { typedef int(PoorGuy::*type)(int i); };
template class HackPrivate<PoorGuyPrivate_plusOne, &PoorGuy::plusOne>;

TEST(HACK, Access_Private_Member) {
	PoorGuy who;
	EXPECT_STREQ((who.*HackProxy<PoorGuyPrivate_getName>::privateFuncPtr)(), "John");
	EXPECT_TRUE((who.*HackProxy<PoorGuyPrivate_isMale>::privateFuncPtr)());
	EXPECT_EQ((who.*HackProxy<PoorGuyPrivate_getAge>::privateFuncPtr)(), 20);

	EXPECT_EQ((who.*HackProxy<PoorGuyPrivate_plusOne>::privateFuncPtr)(20), 21);
}
