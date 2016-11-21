//
// Created by Michael Fong on 2016/11/19.
//

#include "algorithm/event/Event.h"

Event::Event(std::string val):  _val(val) {

}

Event::~Event(){

}

std::string Event::getValue() {
    return this->_val;
}

