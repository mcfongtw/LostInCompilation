/*
 * Utils.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Michael Fong
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <sstream>
//uint64_t
//#include "stdint.h"
//for size_t
#include "stdlib.h"
//int tolower(int)
#include "ctype.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
//for std::setfill & std::setw
#include <iomanip>
//for std::numeric_limits::digits
#include <limits>
//#include <iostream>


#include "error/Exception.h"

class Strings;

namespace util {


/**
 * A utility class that provides static functions for string manipulation
 */
class Strings {
public:
	static void toUpperCase(std::string& str);

	static void toLowerCase(std::string& str);

	static bool equalsIgnoreCase(const std::string& str1,
			const std::string& str2);

	static bool endWith(const std::string& srcStr, const std::string& endStr);

	static bool beginWith(const std::string& srcStr, const std::string& beginStr);

	static bool contain(const std::string& srcStr, const std::string& targetStr);
};


/**
 * A utility class that provides static functions for data type conversions
 */
class Converts {
public:
	static std::string boolToString(bool b);

	template<typename T>
	static std::string numberToString(T num) {
		std::stringstream ss;
		ss << num;
		return ss.str();
	}

	template<typename T>
	static std::string numberToHexString(T num) {
		std::stringstream ss;

		ss << "0x"
		//set the accurate # of digits
		<< std::setw(sizeof(T) * 2)
		//XXX: wrong
//		<< std::numeric_limits<T>::digits / 4
		//padding w/ 0s
		<< std::setfill('0')
		//set to hex mode
		<< std::hex
		<< num;

		return ss.str();
	}

	static bool stringToBool(const std::string& str);

	template<typename T>
	static T stringToNumber(const std::string& str) {
		std::stringstream ss(str);
		T result;
		return ss >> result ? result : 0;
	}

	template<typename T>
	static T hexStringToNumber(const std::string& str) {
		T result;
		std::stringstream ss;

		std::string temp = str;

		if(util::Strings::beginWith(str, "0x")) {
			std::size_t pos = str.find("0x");
			temp = str.substr(pos + 2);
		}
		ss << std::hex << temp;
		ss >> result;

		return result;
	}
};

/**
 * A utility class that provides static functions for checking conditions and throw exceptions if fail.
 */
//TODO: make template to accept <unsigned type> or <size_t>
class Conditions {
public:
	static void requireTrue(bool value, const std::string& hint);

	static void requireNotNull(const void* obj, const std::string& hint);

	template<typename T>
	static void requireNotNull(std::shared_ptr<T> ptr, const std::string& hint) {
		if (ptr == nullptr) {
			throw NullPointerException(hint + std::string(" is null!"));
		}
	}

	template<typename T>
	static void requireNotNull(std::unique_ptr<T> ptr, const std::string& hint) {
		if (ptr == nullptr) {
			throw NullPointerException(hint + std::string(" is null!"));
		}
	}

	template<typename T>
	static void requireGreaterThan(const T& val, const T& low,
			const std::string& hint) {
		if (val <= low) {
			throw IllegalStateException(
					hint + util::Converts::numberToString<T>(val)
							+ std::string(" <= ")
							+ util::Converts::numberToString<T>(low));
		}
	}

	template<typename T>
	static void requireLessThan(const T& val, const T& high,
			const std::string& hint) {
		if (val >= high) {
			throw IllegalStateException(
					hint + util::Converts::numberToString<T>(val)
							+ std::string(" >= ")
							+ util::Converts::numberToString<T>(high));
		}
	}

	template<typename T>
	static void requireEqualsTo(const T& val, const T& threshold,
			const std::string& hint) {
		if (val != threshold) {
			throw IllegalStateException(
					hint + util::Converts::numberToString<T>(val)
							+ std::string(" != ")
							+ util::Converts::numberToString<T>(threshold));
		}
	}

	template<typename T>
	static void requireBetween(const T& val, const T& low, const T& high,
			const std::string& hint) {
		if (val < low) {
			throw IllegalStateException(
					hint + util::Converts::numberToString<T>(val)
							+ std::string(" < ")
							+ util::Converts::numberToString<T>(low));
		} else if (val > high) {
			throw IllegalStateException(
					hint + util::Converts::numberToString<T>(val)
							+ std::string(" > ")
							+ util::Converts::numberToString<T>(high));
		}
	}

	//	template<template<typename, typename > class ContainerT, typename ValueT>
	//	static void requireNotEmpty(const ContainerT<ValueT, std::allocator<ValueT>>& obj, const std::string& hint) {
	//		typedef ContainerT<ValueT, std::allocator<ValueT>> type;
	template<class Container>
	static void requireNotEmpty(const Container& obj, const std::string& hint) {
		if (obj.empty()) {
			throw IllegalStateException(hint + " vector is empty!");
		}
	}
};

//class Memory {
//public:
//	template<typename T>
//	static void smartDelete(T* &ptr) {
//		delete ptr;
//		ptr = NULL;
//	}
//};

}

#endif /* UTILS_H_ */
