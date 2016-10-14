/*
 * StringUtils.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */
#include <sstream>

#include "common/Utils.h"

void util::Strings::toUpperCase(std::string& str) {
	std::string::iterator iterator = str.begin();

	while (iterator != str.end()) {
		*iterator = std::toupper((unsigned char) *iterator);
		iterator++;
	}
}

void util::Strings::toLowerCase(std::string& str) {
	std::string::iterator iterator = str.begin();

	while (iterator != str.end()) {
		*iterator = std::tolower((unsigned char) *iterator);
		iterator++;
	}
}

bool util::Strings::equalsIgnoreCase(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    for (size_t i = 0; i < str1.size(); i++) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}

bool util::Strings::endWith(const std::string& srcStr, const std::string& targetStr) {
    if (srcStr.length() >= targetStr.length()) {
        return (srcStr.compare(srcStr.length() - targetStr.length(), targetStr.length(), targetStr) == 0);
    } else {
        return false;
    }
}

bool util::Strings::beginWith(const std::string& srcStr, const std::string& targetStr) {
    if (srcStr.length() >= targetStr.length()) {
        return (srcStr.compare(0, targetStr.length(), targetStr) == 0);
    } else {
        return false;
    }
}

bool util::Strings::contain(const std::string& srcStr, const std::string& targetStr) {
    if (srcStr.length() >= targetStr.length()) {
        return (srcStr.find(targetStr) != std::string::npos);
    } else {
        return false;
    }
}
