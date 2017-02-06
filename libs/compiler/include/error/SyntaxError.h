//
// Created by mcfongtw on 2/5/17.
//

#ifndef LOSTINCOMPILATION_SYNTACTICEXCEPTION_H
#define LOSTINCOMPILATION_SYNTACTICEXCEPTION_H

#include "error/ParseException.h"

class SyntaxError : public ParseException {
public:
    SyntaxError(const std::string &msg);

};


#endif //LOSTINCOMPILATION_SYNTACTICEXCEPTION_H
