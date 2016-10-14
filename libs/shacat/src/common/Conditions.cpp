/*
 * ConditionUtils.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */
#include "common/Utils.h"

void util::Conditions::requireTrue(bool value, const std::string& hint) {
	if(value == false) {
		throw IllegalStateException(hint + " is false!");
	}
}

void util::Conditions::requireNotNull(const void* obj,
		const std::string& hint) {
	if (obj == nullptr) {
		throw NullPointerException(hint + std::string(" is null!"));
	}
}

