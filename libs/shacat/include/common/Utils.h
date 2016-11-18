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


#include "error/Exception.h"

class Strings;

namespace util {


/**
 * A utility class that provides static functions for string manipulation
 *
 * @since 0.1
 */
class Strings {
public:
    /**
     * Update the given string in-place to all upper case
     *
     * @param str the string to be updated
     */
	static void toUpperCase(std::string& str);

    /**
     * Update the given string in-place to all lower case
     *
     * @param str the string to be updated
     */
	static void toLowerCase(std::string& str);

    /**
     * Compare two strings about their equality.
     *
     * @param str1 string 1
     * @param str2 string 2
     * @return true, if two strings are equal (char-to-char); false, otherwise.
     */
	static bool equalsIgnoreCase(const std::string& str1,
			const std::string& str2);

    /**
     * Check if given string ends with the other given string
     *
     * @param srcStr the source string to check against
     * @param patternStr the string that expects srcStr to ends with
     * @return true, if srcStr ends with patternStr; false, otherwise.
     */
	static bool endWith(const std::string& srcStr, const std::string& patternStr);

    /**
     * Check if given string begins with the other given string
     *
     * @param srcStr the source string to check against
     * @param patternStr the string that expects srcStr to begins with
     * @return true, if srcStr begins with patternStr; false, otherwise.
     */
	static bool beginWith(const std::string& srcStr, const std::string& patternStr);

    /**
     * Check if given string contains the other given string
     *
     * @param srcStr the source string to check against
     * @param patternStr the string that contains srcStr to ends with
     * @return true, if srcStr contains patternStr; false, otherwise.
     */
	static bool contain(const std::string& srcStr, const std::string& patternStr);
};


/**
 * A utility class that provides static functions for data type conversions
 *
 * @since 0.1
 */
class Converts {
public:
    /**
     * Convert given boolean to value in string form
     * @param b boolean value to convert from
     * @return 'true' or 'false'
     */
	static std::string boolToString(bool b);

    /**
     * Convert given (templated) numeric value in string form
     * @param num numeric value to convert from
     * @return numeric value in string form
     */
    //TODO: Strict tempalted type to be numeric
	template<typename T>
	static std::string numberToString(T num) {
		std::stringstream ss;
		ss << num;
		return ss.str();
	}

    /**
     * Convert given (templated) numeric value in hexidecimal string form
     * @param num numeric value to convert from
     * @return numeric value in hexidecimal string form
     */
    //TODO: Strict tempalted type to be numeric
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

    /**
     * Convert given string to boolean value
     * @param str string to convert from, either 'true' or 'false'
     * @return true or false
     * @throw IllegalArgumentException, if given string is not 'true' nor 'false'
     */
	static bool stringToBool(const std::string& str);

    /**
     * Convert given string to numeric value
     * @param str literal value to convert from
     * @return numeric value
     */
    //TODO: Strict tempalted type to be numeric
	template<typename T>
	static T stringToNumber(const std::string& str) {
		std::stringstream ss(str);
		T result;
		return ss >> result ? result : 0;
	}

    /**
     * Convert given hexidecimal string to numeric value
     * @param str hexidecimal string to convert from
     * @return numeric value
     */
    //TODO: Strict tempalted type to be numeric
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
 *
 * @since 0.1
 */
//TODO: make template to accept <unsigned type> or <size_t>
class Conditions {
public:
    /**
     * Check if given bool value is true
     *
     * @param value bool value to be put to test
     * @param hint helper message
     * @throw IllegalStateException, if given bool value is false
     */
	static void requireTrue(bool value, const std::string& hint);

    /**
     * Check if given raw pointer is NULL
     *
     * @param obj raw pointer to be put to test
     * @param hint helper message
     * @throw NullPointerException, if given pointer is NULL
     */
	static void requireNotNull(const void* obj, const std::string& hint);

    /**
     * Check if given shared pointer is nullptr
     *
     * @param ptr shared pointer to be put to test
     * @param hint helper message
     * @throw NullPointerException, if shared_ptr is nullptr
     */
	template<typename T>
	static void requireNotNull(std::shared_ptr<T> ptr, const std::string& hint) {
		if (ptr == nullptr) {
			throw NullPointerException(hint + std::string(" is null!"));
		}
	}

    /**
     * Check if given unique pionter is nullptr
     *
     * @param ptr unique pointer to be put to test
     * @param hint helper message
     * @throw IllegalStateException, if the test failed
     */
	template<typename T>
	static void requireNotNull(std::unique_ptr<T> ptr, const std::string& hint) {
		if (ptr == nullptr) {
			throw NullPointerException(hint + std::string(" is null!"));
		}
	}

    /**
     * Check if given numeric value is greater than lower bound
     *
     * @param val numeric value to be put to test
     * @param low lower bound to test against
     * @param hint helper message
     * @throw IllegalStateException, if the test failed
     */
    //TODO: Strict tempalted type to be numeric
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

	/**
	 * Check if given numeric value is less than upper bound
	 *
	 * @param val numeric value to be put to test
	 * @param high upper bound to test against
	 * @param hint helper message
	 * @throw IllegalStateException, if the test failed
	 */
    //TODO: Strict tempalted type to be numeric
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

	/**
     * Check if given numeric value is equal to given threshold
	 *
	 * @param val numeric value to be put to test
	 * @param threshold nemric value to be equal to
	 * @param hint helper message
	 * @throw IllegalStateException, if the test failed
	 */
    //TODO: Strict tempalted type to be numeric
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

	/**
	 * Check if given numeric value is within range (lower, upper)
	 *
	 * @param val numeric value to be put to test
	 * @param low lower bound to test against
	 * @param high upper bound to test against
	 * @param hint helper message
	 * @throw IllegalStateException, if the test failed
	 */
    //TODO: Strict tempalted type to be numeric
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
	/**
	 * Check if the given container object not empty
	 *
	 * @param obj contain object
	 * @param hint helper message
	 * @throw IllegalStateException, if the test failed
	 */
    //TODO: Strict tempalted type to be container based
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
