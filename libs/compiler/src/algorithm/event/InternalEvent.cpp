//
// Created by Michael Fong on 2016/11/20.
//

#include "algorithm/event/InternalEvent.h"

InternalEvent::InternalEvent(ComponentType comp, std::string summary, std::string msg): _component(comp), Event(summary, msg) {

}

InternalEvent::~InternalEvent() {

}

ComponentType InternalEvent::getComponent() {
    return this->_component;
}