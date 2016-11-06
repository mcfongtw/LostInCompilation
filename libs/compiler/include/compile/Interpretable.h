//
// Created by Michael Fong on 2016/11/6.
//

#ifndef MAINPROJECT_INTEPRETABLE_H
#define MAINPROJECT_INTEPRETABLE_H

#include <string>

class Interpretable {
public:
    Interpretable() {

    }

    virtual ~Interpretable() {

    }

    virtual void startInterpret() = 0;

    virtual ObjectValue interpret(std::string& line) = 0;

    virtual void stopInterpret() = 0;
};
#endif //MAINPROJECT_INTEPRETABLE_H
