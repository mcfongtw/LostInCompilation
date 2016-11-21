//
// Created by Michael Fong on 2016/11/19.
//

#ifndef LOSTINCOMPILATION_EVENTDISPATCHER_H
#define LOSTINCOMPILATION_EVENTDISPATCHER_H

#include "algorithm/event/Event.h"
#include "algorithm/event/listener/EventListener.h"
#include <map>
#include <vector>

/**
 * This class dispatch events via #sendEvent(), and would trigger associated Event w.r.t. their event types.
 *
 * @since 0.1
 */
class EventDispatcher {
public :

    EventDispatcher();

    virtual ~EventDispatcher();

    virtual void addListener(EventListenerPtr listener);

    virtual void removeListener(EventListenerPtr listener);

    virtual void sendMessage(Event event, EventListenerType eventType);

    virtual std::vector<EventListenerPtr> getEventListeners(EventListenerType eventType) const;

private:
    void notifyListeners(Event event, EventListenerType eventType);

    std::map<EventListenerType, std::vector<EventListenerPtr>> _listenersMap;

    std::vector<EventListenerPtr> _listeners;

};


#endif //LOSTINCOMPILATION_EVENTDISPATCHER_H
