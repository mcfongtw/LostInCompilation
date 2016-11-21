//
// Created by Michael Fong on 2016/11/19.
//

#include "gtest/gtest.h"
#include "algorithm/event/Event.h"
#include "algorithm/event/listener/EventListener.h"
#include "algorithm/event/dispatcher/EventDispatcher.h"

#include "hack/DebugLib.h"

static int numOfReceived = 0;
static int numOfSent = 0;


class TestEventReceivedListener : public EventReceivedListener {
public :
    virtual void onReceived(Event event) {
        numOfReceived++;
    }
};

class TestEventSentListener : public EventSentListener {
public :
    virtual void onSent(Event event) {
        numOfSent++;
    }
};

class EVENT_LISTENER : public ::testing::Test {
public:
    // Per-test-case set-up.
    // Called before the first test in this test case.
    // Can be omitted if not needed.
    static void SetUpTestCase() {

    }

    // Per-test-case tear-down.
    // Called after the last test in this test case.
    // Can be omitted if not needed.
    static void TearDownTestCase() {

    }

    virtual void SetUp() {

    }

    virtual void TearDown() {
        numOfReceived = 0;
        numOfSent = 0;
    }

};

TEST_F(EVENT_LISTENER, UNIT_Simple_EventReceivedListener) {
    std::string message ="random message";
    Event event(message);

    EventDispatcher dispatcher;
    EventListenerPtr listener = std::make_shared<TestEventReceivedListener>();
    dispatcher.addListener(listener);

    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(1, dispatcher.getEventListeners(EVENT_RECEIVED).size());

    dispatcher.sendMessage(event, EVENT_RECEIVED);
    dispatcher.sendMessage(event, EVENT_RECEIVED);

    ASSERT_EQ(2, numOfReceived);
    ASSERT_EQ(0, numOfSent);

    dispatcher.removeListener(listener);

    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());
}

TEST_F(EVENT_LISTENER, UNIT_Simple_EventSentListener) {
    std::string message ="random message";
    Event event(message);

    EventDispatcher dispatcher;
    EventListenerPtr listener = std::make_shared<TestEventSentListener>();
    dispatcher.addListener(listener);

    ASSERT_EQ(1, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());

    dispatcher.sendMessage(event, EVENT_RECEIVED);
    dispatcher.sendMessage(event, EVENT_SENT);
    dispatcher.sendMessage(event, EVENT_SENT);

    ASSERT_EQ(0, numOfReceived);
    ASSERT_EQ(2, numOfSent);

    dispatcher.removeListener(listener);

    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());
}

TEST_F(EVENT_LISTENER, UNIT_Simple_Remove_EventSentListener) {
    EventDispatcher dispatcher;
    EventListenerPtr listener = std::make_shared<TestEventSentListener>();
    dispatcher.addListener(listener);

    ASSERT_EQ(1, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());

    dispatcher.removeListener(listener);

    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());
}

TEST_F(EVENT_LISTENER, UNIT_Simple_Remove_Unexisted_EventSentListener) {
    EventDispatcher dispatcher;
    EventListenerPtr listener = std::make_shared<TestEventSentListener>();

    dispatcher.removeListener(listener);

    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());
}

TEST_F(EVENT_LISTENER, UNIT_Simple_All_Listener) {
    std::string message ="random message";
    Event event( message);

    EventDispatcher dispatcher;
    EventListenerPtr listener1 = std::make_shared<TestEventSentListener>();
    dispatcher.addListener(listener1);
    EventListenerPtr listener2 = std::make_shared<TestEventReceivedListener>();
    dispatcher.addListener(listener2);

    ASSERT_EQ(1, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(1, dispatcher.getEventListeners(EVENT_RECEIVED).size());

    dispatcher.sendMessage(event, EVENT_SENT);
    dispatcher.sendMessage(event, EVENT_RECEIVED);

    ASSERT_EQ(1, numOfSent);
    ASSERT_EQ(1, numOfReceived);

    dispatcher.removeListener(listener1);
    dispatcher.removeListener(listener2);

    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_SENT).size());
    ASSERT_EQ(0, dispatcher.getEventListeners(EVENT_RECEIVED).size());
}