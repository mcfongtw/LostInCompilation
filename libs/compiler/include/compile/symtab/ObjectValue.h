/*
 * ObjectValue.h
 *
 *  Created on: May 7, 2014
 *      Author: Michael Fong
 */

#ifndef OBJECTVALUE_H_
#define OBJECTVALUE_H_

//for size_t
#include "stdlib.h"
#include <string>
#include <cstring>
//for typeid()
#include <typeinfo>
#include <vector>
#include <map>

#include "common/Utils.h"
#include "error/Exception.h"
#include "log/Logger.h"


//TODO:DataBindingUtils
class TypeUtils {
public:

	static std::string toString(const std::type_info& type) {
		std::string result = "nul";
		if (type == typeid(bool)) {
			result = "bool";
		} else if (type == typeid(char)) {
			result = "char";
		} else if (type == typeid(int)) {
			result = "int";
		} else if (type == typeid(short)) {
			result = "short";
		} else if (type == typeid(long)) {
			result = "long";
		} else if (type == typeid(float)) {
			result = "float";
		} else if (type == typeid(double)) {
			result = "double";
		} else if (type == typeid(void)) {
			result = "void";
		} else if (type == typeid(std::string)) {
			result = "string";
		} else if (type == typeid(nullptr) || type == typeid(NULL)) {
            result = "null";
        }
        else if (strstr(type.name(), "vector") != NULL) {
            //TODO: Add more checks on 'type' of element in vector
			result = "vector";
		} else if (strstr(type.name(), "map") != NULL) {
            //TODO: Add more checks on 'type' of element in map
			result = "map";
		} else {
			throw UndefinedSymbolException(
					"Unsupported TypeUtils::type " + std::string(type.name()));
		}

		return result;
	}
};

//TODO:RuntimeValue
class ObjectValue {
private:
    //TODO: ValueHolder
	class Value {
	public:
		Value() {
		}
		virtual ~Value() {
		}
		virtual const std::type_info& getType() const = 0;

		virtual Value* clone() const = 0;

		virtual bool equal(ObjectValue) = 0;

		virtual const size_t getSizeof() const = 0;
	};

    //TODO: ValueHolder
	template<typename T>
	class DataValue: public Value {
	public:
		DataValue() :
				_value() {

		}

		DataValue(const T &_Value) :
				_value(_Value) {
		}

		virtual ~DataValue() {
		}

		virtual const std::type_info& getType() const {
			return typeid(T);
		}

		virtual DataValue* clone() const {
			return new DataValue<T>(this->_value);
		}

		virtual bool equal(ObjectValue obj) {
			return obj.get<T>() == this->_value;
		}

		virtual const size_t getSizeof() const {
			return sizeof(T);
		}

		T _value;
	};

	Value *_data;
public:
	ObjectValue() :
			_data() {
		this->_data = 0;
	}

	template<typename T>
	ObjectValue(const T &_Value) :
			_data(new DataValue<T>(_Value)) {
	}

	ObjectValue(const ObjectValue &obj) :
			_data(obj._data->clone()) {
	}

	~ObjectValue() {
		if (!isNull()) {
			delete this->_data;
		}
	}

	const std::type_info& getType() const {
		return (this->isNull() ? typeid(void) : this->_data->getType());
	}

	const size_t getSizeof() const {
		return this->_data->getSizeof();
	}

	template<typename T>
	T get() const {
		if (this->getType() == typeid(T)) {
			LOG(Logger::LEVEL_TRACE,
					"Type match : " + TypeUtils::toString(this->getType()));
			return static_cast<DataValue<T>*>(this->_data)->_value;
		}
		throw TypeCastException(
				"Cannot cast <" + TypeUtils::toString(this->getType())
						+ "> to <" + TypeUtils::toString(typeid(T)) + ">");
	}

	ObjectValue& swap(ObjectValue &that) {
		std::swap(*this, that);
		return *this;
	}

	bool isNull() const {
		return this->_data == nullptr;
	}

	long hashCode() {
		int prime = 31;
		long result = 1;
		long addr = (long) this->_data;

		result = prime * result + addr;

		return result;
	}

	//FIXME: how to get string value out of this->_data->_value without using template
	std::string toString() {
		return "ObjectValue<" + TypeUtils::toString(this->getType()) + ">@"
				+ util::Converts::numberToString(this->_data);
	}

	bool equals(ObjectValue &that) {
		return *this == that;
	}

	ObjectValue& operator=(const ObjectValue& that) {
		if (&that != this) {
			this->_data = that._data->clone();
		}
		LOG(Logger::LEVEL_TRACE, "operator= ObjectValue");

		return *this;
	}

	template<typename T>
	ObjectValue& operator=(const T& val) {
		this->_data = new DataValue<T>(val);
		LOG(Logger::LEVEL_TRACE,
				"operator= const " + std::string(typeid(T).name()));
		return *this;
	}

	bool operator==(const ObjectValue &that) const {
		return (this->getType() == that._data->getType() ?
				this->_data->equal(that) : false);
	}

	template<typename T>
	bool operator==(const T val) const {
		return (this->getType() == typeid(T) ? this->get<T>() == val : false);
	}

	bool operator!=(const ObjectValue &that) const {
		return !(*this == that);
	}

	template<typename T>
	bool operator!=(const T val) const {
		return !(*this == val);
	}
};

#endif /* OBJECTVALUE_H_ */
