//
// Created by Michael Fong on 2016/11/12.
//

#ifndef LOSTINCOMPILATION_MATHCOMPILER_H
#define LOSTINCOMPILATION_MATHCOMPILER_H

#include "compile/Compilable.h"

class MathCompiler : public Compilable {
public:
    MathCompiler();

    virtual ~MathCompiler();

    virtual bool compile(std::string& fname);

    virtual bool compile(std::vector<std::string> content);
};


#endif //LOSTINCOMPILATION_MATHCOMPILER_H
