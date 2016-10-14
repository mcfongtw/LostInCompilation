/*
 * Object.h
 *
 *  Created on: Jan 18, 2015
 *      Author: shannaracat
 */

#ifndef ALGORITHM_OBJECT_H_
#define ALGORITHM_OBJECT_H_

#include <memory>
#include <algorithm>
#include <iostream>
#include <functional>
#include <string>

#include "common/Utils.h"
#include "log/Logger.h"

#include <iostream>
#include <string.h>

#define CLASS_NAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

//TODO: Look for the appropriate way to write copy constructor & operator=
class Object {
public:
	//Default Constructor
	Object();

	//Copy Constructor
	Object(const Object& that);

	//Default Destructor
	virtual ~Object();

	//=Operator
	Object& operator=(Object that);

	virtual std::string toString();

	virtual size_t hashCode();

//	virtual Object* clone() = 0;

protected:
	virtual void swap(Object& that);

	uintptr_t _addr;
	std::string _className;

private:

};

#endif /* ALGORITHM_OBJECT_H_ */
