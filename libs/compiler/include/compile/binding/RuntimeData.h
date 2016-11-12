/*
 * RuntimeData.h
 *
 *  Created on: May 7, 2014
 *      Author: Michael Fong
 */

#ifndef OBJECTVALUE_H_
#define OBJECTVALUE_H_


#include <vector>
#include <map>

#include "compile/binding/DataBindingUtils.h"
#include "compile/binding/ValueHolder.h"
#include "common/Utils.h"
#include "log/Logger.h"

class ValueHolder;

//TODO: Move the template function implementation to cpp
class RuntimeData {
public:
    RuntimeData();

	template<typename T>
    RuntimeData(const T &val):
            _holder(new DataValueHolder<T>(val)) {
    }

    RuntimeData(const RuntimeData &obj);

	~RuntimeData();

	const std::type_info& getType() const;

	const size_t getSizeof() const;

	template<typename T>
	T get() const {
        if (this->getType() == typeid(T)) {
            LOG(Logger::LEVEL_TRACE,
                "Type match : " + DataBindingUtils::toString(this->getType()));
            return static_cast<DataValueHolder<T>*>(this->_holder)->_value;
        }
        throw TypeCastException(
                "Cannot cast <" + DataBindingUtils::toString(this->getType())
                + "> to <" + DataBindingUtils::toString(typeid(T)) + ">");
    }

	RuntimeData& swap(RuntimeData &that);

	bool isNull() const;

	long hashCode();

	//FIXME: how to get string value out of this->_holder->_value without using template
	std::string toString();

	bool equals(RuntimeData &that);

	RuntimeData& operator=(const RuntimeData& that);

	template<typename T>
	RuntimeData& operator=(const T& val) {
        this->_holder = new DataValueHolder<T>(val);
        LOG(Logger::LEVEL_TRACE,
            "operator= const " + std::string(typeid(T).name()));
        return *this;
    }

	bool operator==(const RuntimeData &that) const;

	template<typename T>
	bool operator==(const T val) const {
        return (this->getType() == typeid(T) ? this->get<T>() == val : false);
    }

	bool operator!=(const RuntimeData &that) const;

	template<typename T>
	bool operator!=(const T val) const {
        return !(*this == val);
    }
private:

    //TODO: Replace with compile/binding/DataValueHolder class
    template<typename T>
    class DataValueHolder: public ValueHolder {
    public:
        DataValueHolder() :
                _value() {

        }

        DataValueHolder(const DataValueHolder &that) :
                _value(that._value) {
            this->init = that.init;
        }

        DataValueHolder(const T &val) :
                _value(val) {
            this->init = true;
        }


        virtual ~DataValueHolder() {
        }

        virtual const std::type_info& getType() const {
            return typeid(T);
        }

        virtual DataValueHolder* clone() const {
            return new DataValueHolder<T>(this->_value);
        }

        virtual bool equal(RuntimeData obj) {
            return obj.get<T>() == this->_value;
        }

        virtual const size_t getSizeof() const {
            return sizeof(T);
        }

        virtual bool isInit() const {
            return this->init;
        }

        T _value;

        bool init = false;
    };

    ValueHolder *_holder;
};

#endif /* OBJECTVALUE_H_ */
