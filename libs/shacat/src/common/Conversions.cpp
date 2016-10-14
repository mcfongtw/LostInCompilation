/*
 * NumberUtils.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */


#include "common/Utils.h"
#include "error/Exception.h"

std::string util::Converts::boolToString(bool b) {
	if (b) {
		return "true";
	} else {
		return "false";
	}
}

bool util::Converts::stringToBool(const std::string& str) {
	if(util::Strings::equalsIgnoreCase(str, "true")) {
		return true;
	} else if(util::Strings::equalsIgnoreCase(str, "false")) {
		return false;
	} else {
		throw IllegalArgumentException(str);
	}
}
