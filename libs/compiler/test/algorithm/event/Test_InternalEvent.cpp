//
// Created by Michael Fong on 2016/11/20.
//
#include "gtest/gtest.h"
#include "algorithm/event/InternalEvent.h"

#include "hack/DebugLib.h"

TEST(INTERNAL_EVENT, UNIT_Simple_Parser_Event) {
    std::string message ="parser event";
    ParserEvent event(message);

    ASSERT_EQ(COMPONENT_PARSER, event.getComponent());
    ASSERT_EQ(message, event.getValue());
}

TEST(INTERNAL_EVENT, UNIT_Simple_Analyzer_Event) {
    std::string message ="analyzer event";
    AnalyzerEvent event(message);

    ASSERT_EQ(COMPONENT_ANALYZER, event.getComponent());
    ASSERT_EQ(message, event.getValue());
}

TEST(INTERNAL_EVENT, UNIT_Simple_Symbol_Binding_Event) {
    std::string message ="symbol binding event";
    SymbolBindingEvent event(message);

    ASSERT_EQ(COMPONENT_BINDING, event.getComponent());
    ASSERT_EQ(message, event.getValue());
}