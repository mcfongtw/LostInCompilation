//
// Created by Michael Fong on 2016/11/20.
//

#ifndef LOSTINCOMPILATION_COMPILEREVENT_H
#define LOSTINCOMPILATION_COMPILEREVENT_H

#include "algorithm/event/Event.h"
#include "algorithm/event/ComponentType.h"

class InternalEvent : public Event {
public:
    InternalEvent(ComponentType comp, std::string val);

    virtual ~InternalEvent();

    virtual ComponentType getComponent();

protected:
    ComponentType _component;
};


class ParserEvent : public InternalEvent {
public:
    ParserEvent(std::string val): InternalEvent(COMPONENT_PARSER, val) {

    }

    virtual ~ParserEvent(){

    }
};

class AnalyzerEvent : public InternalEvent {
public:
    AnalyzerEvent(std::string val): InternalEvent(COMPONENT_ANALYZER, val) {

    }

    virtual ~AnalyzerEvent(){

    }
};

class SymbolBindingEvent : public InternalEvent {
public:
    SymbolBindingEvent(std::string val): InternalEvent(COMPONENT_BINDING, val) {

    }

    virtual ~SymbolBindingEvent(){

    }
};


#endif //LOSTINCOMPILATION_COMPILEREVENT_H
