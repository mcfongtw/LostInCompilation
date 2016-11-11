//
// Created by Michael Fong on 2016/11/11.
//

#ifndef LOSTINCOMPILATION_DATAVALUEHOLDER_H
#define LOSTINCOMPILATION_DATAVALUEHOLDER_H

#include "compile/binding/ValueHolder.h"

//template<typename T>
//class DatavalueHolder: public ValueHolder {
//public:
//    DatavalueHolder() :
//            _value() {
//
//    }
//
//    DatavalueHolder(const T &_Value) :
//            _value(_Value) {
//    }
//
//    virtual ~DatavalueHolder() {
//    }
//
//    virtual const std::type_info& getType() const {
//        return typeid(T);
//    }
//
//    virtual DatavalueHolder* clone() const {
//        return new DatavalueHolder<T>(this->_value);
//    }
//
//    virtual bool equal(ObjectValue obj) {
//        return obj.get<T>() == this->_value;
//    }
//
//    virtual const size_t getSizeof() const {
//        return sizeof(T);
//    }
//
//    T _value;
//};

#endif //LOSTINCOMPILATION_DATAVALUEHOLDER_H
