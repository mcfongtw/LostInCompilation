//
// Created by Michael Fong on 2016/11/19.
//

#ifndef LOSTINCOMPILATION_EVENTLISTENER_H
#define LOSTINCOMPILATION_EVENTLISTENER_H

#include "algorithm/event/Event.h"


/**
 * A enum that describes various type of Event Listener
 *
 * @since 0.1
 */
enum EventListenerType {
    EVENT_RECEIVED,
    EVENT_SENT
};


/**
 * A pure abstract listener class that expects to be triggered via #onEvent() w.r.t specific Event.
 *
 * @since 0.1
 */
//TODO: make template
class EventListener {

public:
    virtual void onEvent(Event event) = 0;

    virtual EventListenerType getType() = 0;
};

/**
 * A inherited listener class that expects to be triggered via #onEvent()/#onReceived() w.r.t EVENT_RECEIVED.
 *
 * @since 0.1
 */
class EventReceivedListener : public EventListener {
public :
    virtual void onEvent(Event event) {
        onReceived(event);
    }

    virtual EventListenerType getType() {
        return EVENT_RECEIVED;
    }

protected:
    virtual void onReceived(Event event) = 0;
};

/**
 * A inherited listener class that expects to be triggered via #onEvent()/#onSent() w.r.t EVENT_SENT.
 *
 * @since 0.1
 */
class EventSentListener: public EventListener {
public :
    virtual void onEvent(Event event) {
        onSent(event);
    }

    virtual EventListenerType getType() {
        return EVENT_SENT;
    }

protected:
    virtual void onSent(Event event) = 0;
};

typedef std::shared_ptr<EventListener> EventListenerPtr;


#endif //LOSTINCOMPILATION_EVENTLISTENER_H
