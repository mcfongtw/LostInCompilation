//
// Created by Michael Fong on 2016/11/12.
//

#ifndef LOSTINCOMPILATION_COMPILABLE_H
#define LOSTINCOMPILATION_COMPILABLE_H

#include <string>

class Compilable {
public :
    Compilable() {

    }

    virtual ~Compilable() {

    }

    virtual bool compile(std::string& fname) = 0;
};


#endif //LOSTINCOMPILATION_COMPILABLE_H
