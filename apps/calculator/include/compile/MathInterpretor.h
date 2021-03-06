//
// Created by Michael Fong on 2016/11/6.
//

#ifndef MAINPROJECT_MATHINTEPRETOR_H
#define MAINPROJECT_MATHINTEPRETOR_H

#include "compile/eval/MathEvaluator.h"
#include "compile/Interpretable.h"

/**
 * MathInterpretor inteprets math equations from string input
 *
 * @since 0.1
 */
class MathInterpretor: public Interpretable {
public:
    MathInterpretor();

    virtual ~MathInterpretor();

    virtual void startInterpret();

    virtual RuntimeData interpret(std::string& line);

    virtual void stopInterpret();

private :
    MathEvaluator _evaluator;
};


#endif //MAINPROJECT_MATHINTEPRETOR_H
