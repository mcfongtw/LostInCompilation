//
// Created by Michael Fong on 2016/11/11.
//

#ifndef LOSTINCOMPILATION_VALUEHOLDER_H
#define LOSTINCOMPILATION_VALUEHOLDER_H

//for size_t
#include "stdlib.h"
//for typeid()
#include <typeinfo>

#include "compile/binding/RuntimeData.h"

class RuntimeData;

/**
 * A pure abstract class that encapsulates all data generated at runtime.
 *
 * @since 0.1
 */
class ValueHolder {
public:
    ValueHolder() {
    }

    virtual ~ValueHolder() {
    }

    virtual const std::type_info& getType() const = 0;

    virtual ValueHolder* clone() const = 0;

    virtual bool equal(RuntimeData) = 0;

    virtual const size_t getSizeof() const = 0;

    virtual bool isInit() const = 0;
};

#endif //LOSTINCOMPILATION_VALUEHOLDER_H
