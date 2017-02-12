//
// Created by Michael Fong on 2016/11/20.
//

#ifndef LOSTINCOMPILATION_COMPILEREVENT_H
#define LOSTINCOMPILATION_COMPILEREVENT_H

#include "algorithm/event/Event.h"
#include "algorithm/event/ComponentType.h"

/**
 * InternalEvent is for internal compiler event
 *
 * @since 0.1
 */
class InternalEvent : public Event {
public:
    InternalEvent(ComponentType comp, std::string summary, std::string msg);

    virtual ~InternalEvent();

    virtual ComponentType getComponent();

protected:
    ComponentType _component;
};

/**
 * ParserEvent is for parsing related event
 *
 * @since 0.1
 */
class ParserEvent : public InternalEvent {
public:
    ParserEvent(std::string summary, std::string msg): InternalEvent(COMPONENT_PARSER, summary, msg) {

    }

    virtual ~ParserEvent(){

    }
};

/**
 * AnalyzerEvent is for analyzing related event
 *
 * @since 0.1
 */
class AnalyzerEvent : public InternalEvent {
public:
    AnalyzerEvent(std::string summary, std::string msg): InternalEvent(COMPONENT_ANALYZER, summary, msg) {

    }

    virtual ~AnalyzerEvent(){

    }
};

/**
 * SymbolBindingEvent is for symbol related event
 *
 * @since 0.1
 */
class SymbolBindingEvent : public InternalEvent {
public:
    SymbolBindingEvent(std::string summary, std::string msg): InternalEvent(COMPONENT_BINDING, summary, msg) {

    }

    virtual ~SymbolBindingEvent(){

    }
};


#endif //LOSTINCOMPILATION_COMPILEREVENT_H
