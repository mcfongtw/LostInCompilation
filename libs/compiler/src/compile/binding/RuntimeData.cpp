//
// Created by Michael Fong on 2016/11/11.
//

#include "compile/binding/RuntimeData.h"

RuntimeData::RuntimeData() :
        _holder() {
    this->_holder = 0;
}

RuntimeData::RuntimeData(const RuntimeData &obj) :
        _holder(obj._holder->clone()) {
}

RuntimeData::~RuntimeData() {
    if (!isNull()) {
        delete this->_holder;
    }
}

const std::type_info& RuntimeData::getType() const {
    return (this->isNull() ? typeid(void) : this->_holder->getType());
}

const size_t RuntimeData::getSizeof() const {
    return this->_holder->getSizeof();
}


RuntimeData& RuntimeData::swap(RuntimeData &that) {
    std::swap(*this, that);
    return *this;
}

bool RuntimeData::isNull() const {
    return this->_holder == nullptr || this->_holder == NULL;
}

long RuntimeData::hashCode() {
    int prime = 31;
    long result = 1;
    long addr = (long) this->_holder;

    result = prime * result + addr;

    return result;
}

//FIXME: how to get string value out of this->_holder->_value without using template
std::string RuntimeData::toString() {
    return "RuntimeData<" + DataBindingUtils::toString(this->getType()) + ">@"
           + util::Converts::numberToString(this->_holder);
}

bool RuntimeData::equals(RuntimeData &that) {
    return *this == that;
}

RuntimeData& RuntimeData::operator=(const RuntimeData& that) {
    if (&that != this) {
        this->_holder = that._holder->clone();
    }
    LOG(Logger::LEVEL_TRACE, "operator= RuntimeData");

    return *this;
}


bool RuntimeData::operator==(const RuntimeData &that) const {
    return (this->getType() == that._holder->getType() ?
            this->_holder->equal(that) : false);
}


bool RuntimeData::operator!=(const RuntimeData &that) const {
    return !(*this == that);
}
