//
// Created by Michael Fong on 2016/11/6.
//

#ifndef MAINPROJECT_INTEPRETABLE_H
#define MAINPROJECT_INTEPRETABLE_H

#include <string>

/**
  *A pure abstract class that inteprets a line of input code and produces an answer
  *
 * @since 0.1
 */
class Interpretable {
public:
    Interpretable() {

    }

    virtual ~Interpretable() {

    }

    virtual void startInterpret() = 0;

    virtual RuntimeData interpret(std::string& line) = 0;

    virtual void stopInterpret() = 0;
};
#endif //MAINPROJECT_INTEPRETABLE_H
