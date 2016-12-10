//
// Created by Michael Fong on 2016/12/3.
//

#include "gtest/gtest.h"
#include "compile/SourceCodePosition.h"
#include "common/Utils.h"
#include "log/Logger.h"
#include "hack/DebugLib.h"

TEST(SCP, Unit_Simple_SCP_1) {
    SourceCodePosition scp1;

    ASSERT_EQ(1, scp1.getCol());
    ASSERT_EQ(1, scp1.getRow());

    SourceCodePosition scp2(11);

    ASSERT_EQ(11, scp2.getCol());
    ASSERT_EQ(1, scp2.getRow());

    SourceCodePosition scp3(123, 456);

    ASSERT_EQ(456, scp3.getCol());
    ASSERT_EQ(123, scp3.getRow());

    std::cout << scp3.toString() << std::endl;
}