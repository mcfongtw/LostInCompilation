//
// Created by Michael Fong on 2016/11/12.
//

#ifndef LOSTINCOMPILATION_COMPILABLE_H
#define LOSTINCOMPILATION_COMPILABLE_H

#include <string>

/**
 * A pure abstract class that compiles input code from a given file path
 *
 * @since 0.1
 */
class Compilable {
public :
    Compilable() {

    }

    virtual ~Compilable() {

    }

    virtual bool compile(std::string& fname) = 0;
};


#endif //LOSTINCOMPILATION_COMPILABLE_H
