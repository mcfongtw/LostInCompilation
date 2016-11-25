//
// Created by mcfong on 11/22/16.
//

#ifndef LOSTINCOMPILATION_FUNCTION_H
#define LOSTINCOMPILATION_FUNCTION_H

#include <vector>
#include <string>
#include <memory>

#include "compile/binding/RuntimeData.h"

enum FunctionType {
    FUNCTION_BUILT_IN_CMATH,
    FUNCTION_CUSTOM
};

class Function {
public:

    Function(std::string name, FunctionType type) : _name(name), _type(type) {

    }

    virtual ~Function() {

    }

    virtual void setArguments(std::vector<RuntimeData> arguments) {
        this->_args = arguments;
    }

    virtual std::string getName() {
        return _name;
    }

    virtual std::string toString() {
        std::string result = "";
        result +=_name + "(";
        for(RuntimeData arg : _args) {
            result += util::Converts::numberToString<double>(arg.get<double>());
            result += ", ";
        }
        result += ")";

        return result;
    }

    virtual RuntimeData evaluate() {
        validateFunction();
    }

protected:

    virtual void validateFunction() = 0;

    std::string _name;

    std::vector<RuntimeData> _args;

    FunctionType _type;

};

typedef std::shared_ptr<Function> FunctionPtr;


#endif //LOSTINCOMPILATION_FUNCTION_H
