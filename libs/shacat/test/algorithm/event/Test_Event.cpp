//
// Created by Michael Fong on 2016/11/19.
//

#include "gtest/gtest.h"
#include "algorithm/event/Event.h"

#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"


TEST(EVENT, UNIT_Simple_Literal_Event) {
    std::string message ="parser event";
    std::string summary = "summary";
    Event event(summary, message);

    ASSERT_EQ(summary, event.getSummary());
    ASSERT_EQ(message, event.getMessage());
}
