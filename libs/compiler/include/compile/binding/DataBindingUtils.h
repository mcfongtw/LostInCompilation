//
// Created by Michael Fong on 2016/11/11.
//

#ifndef LOSTINCOMPILATION_DATABINDINGUTILS_H
#define LOSTINCOMPILATION_DATABINDINGUTILS_H

#include <cstring>
#include <string>
//for typeid()
#include <typeinfo>

#include "error/Exception.h"

/**
 * This class includes a set of utility functions for use of dynamic data binding.
 *
 * @since 0.1
 */
class DataBindingUtils {
public:

	static std::string toString(const std::type_info& type);
};


#endif //LOSTINCOMPILATION_DATABINDINGUTILS_H
