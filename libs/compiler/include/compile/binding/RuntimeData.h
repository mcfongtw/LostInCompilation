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

class RuntimeData {
private:


    template<typename T>
	class DataValueHolder: public ValueHolder {
	public:
        DataValueHolder() :
				_value() {

		}

        DataValueHolder(const T &val) :
				_value(val) {
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

		T _value;
	};

    ValueHolder *_holder;
public:
    RuntimeData() :
			_holder() {
		this->_holder = 0;
	}

	template<typename T>
    RuntimeData(const T &_Value) :
			_holder(new DataValueHolder<T>(_Value)) {
	}

    RuntimeData(const RuntimeData &obj) :
			_holder(obj._holder->clone()) {
	}

	~RuntimeData() {
		if (!isNull()) {
			delete this->_holder;
		}
	}

	const std::type_info& getType() const {
		return (this->isNull() ? typeid(void) : this->_holder->getType());
	}

	const size_t getSizeof() const {
		return this->_holder->getSizeof();
	}

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

	RuntimeData& swap(RuntimeData &that) {
		std::swap(*this, that);
		return *this;
	}

	bool isNull() const {
		return this->_holder == nullptr;
	}

	long hashCode() {
		int prime = 31;
		long result = 1;
		long addr = (long) this->_holder;

		result = prime * result + addr;

		return result;
	}

	//FIXME: how to get string value out of this->_holder->_value without using template
	std::string toString() {
		return "RuntimeData<" + DataBindingUtils::toString(this->getType()) + ">@"
				+ util::Converts::numberToString(this->_holder);
	}

	bool equals(RuntimeData &that) {
		return *this == that;
	}

	RuntimeData& operator=(const RuntimeData& that) {
		if (&that != this) {
			this->_holder = that._holder->clone();
		}
		LOG(Logger::LEVEL_TRACE, "operator= RuntimeData");

		return *this;
	}

	template<typename T>
	RuntimeData& operator=(const T& val) {
		this->_holder = new DataValueHolder<T>(val);
		LOG(Logger::LEVEL_TRACE,
				"operator= const " + std::string(typeid(T).name()));
		return *this;
	}

	bool operator==(const RuntimeData &that) const {
		return (this->getType() == that._holder->getType() ?
				this->_holder->equal(that) : false);
	}

	template<typename T>
	bool operator==(const T val) const {
		return (this->getType() == typeid(T) ? this->get<T>() == val : false);
	}

	bool operator!=(const RuntimeData &that) const {
		return !(*this == that);
	}

	template<typename T>
	bool operator!=(const T val) const {
		return !(*this == val);
	}
};

#endif /* OBJECTVALUE_H_ */
