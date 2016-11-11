//
// Created by Michael Fong on 2016/11/11.
//

#include "compile/binding/DataBindingUtils.h"

std::string DataBindingUtils::toString(const std::type_info &type) {
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