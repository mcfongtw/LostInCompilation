//
// Created by mcfongtw on 2/5/17.
//

#include "error/SyntaxError.h"

SyntaxError::SyntaxError(const std::string &msg) : ParseException("Syntax Error", msg, false) {

}
