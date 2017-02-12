//
// Created by Michael Fong on 2016/11/19.
//

#include "algorithm/event/Event.h"

Event::Event(std::string summary, std::string message):  _summary(summary), _message(message) {

}

Event::~Event(){

}

std::string Event::getMessage() {
    return this->_message;
}

std::string Event::getSummary() {
    return this->_summary;
}