//
// Created by Michael Fong on 2016/11/20.
//

#include "algorithm/event/InternalEvent.h"

InternalEvent::InternalEvent(ComponentType comp, std::string val): _component(comp), Event(val) {

}

InternalEvent::~InternalEvent() {

}

ComponentType InternalEvent::getComponent() {
    return this->_component;
}