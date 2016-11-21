//
// Created by Michael Fong on 2016/11/19.
//

#include "algorithm/event/dispatcher/EventDispatcher.h"
#include "common/Utils.h"
#include "log/Logger.h"

#include <algorithm>

EventDispatcher::EventDispatcher() {

}

EventDispatcher::~EventDispatcher() {

}

void EventDispatcher::addListener(EventListenerPtr listener) {
    util::Conditions::requireNotNull(listener, "EventListenerPtr");

    LOG(Logger::LEVEL_TRACE, "Adding EventListener " + util::Converts::numberToHexString(listener.get()));

    this->_listeners.push_back(listener);
}


void EventDispatcher::removeListener(EventListenerPtr listener) {
    util::Conditions::requireNotNull(listener, "EventListenerPtr");

    bool isFound = false;
    std::vector <EventListenerPtr>::iterator listIterator;

    for(listIterator = _listeners.begin(); listIterator != _listeners.end(); )
    {
        if( (*listIterator) == listener) {
            isFound = true;
            break;
        }
        else {
            ++listIterator;
        }
    }

    if(isFound) {
        LOG(Logger::LEVEL_TRACE, "Removing EventListener " + util::Converts::numberToHexString(listener.get()));
        _listeners.erase(listIterator);
    } else {
        // == listeners.end() means the element was not found
        LOG(Logger::LEVEL_INFO, "Cannot find listener " + util::Converts::numberToHexString(listener.get()) + " to remove");
    }
}

std::vector<EventListenerPtr> EventDispatcher::getEventListeners(EventListenerType eventType) const {
    std::vector<EventListenerPtr> result;
    for(EventListenerPtr listener : _listeners) {
        if(listener->getType() == eventType) {
            result.push_back(listener);
        }
    }
    return result;
}

void EventDispatcher::sendMessage(Event event, EventListenerType eventType) {
    this->notifyListeners(event, eventType);
}

void EventDispatcher::notifyListeners(Event event, EventListenerType eventType) {
    std::vector<EventListenerPtr> listeners = getEventListeners(eventType);

    for(EventListenerPtr listener : listeners) {
        LOG(Logger::LEVEL_TRACE, "Trigger onEvent on EventListener " + util::Converts::numberToHexString(listener.get()));

        listener->onEvent(event);
    }
}