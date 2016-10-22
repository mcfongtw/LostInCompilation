//
// Created by Michael Fong on 2016/10/22.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BlueAndRedVisitedObject.h"

TEST(Visitor, UNIT_Test_Count) {
    VisitorPtr visitor = std::static_pointer_cast<Visitor>(std::make_shared<CountVisitor>());

    VisitedObjectPtr red1 = std::make_shared<RedObject>();
    VisitedObjectPtr red2 = std::make_shared<RedObject>();
    VisitedObjectPtr red3 = std::make_shared<RedObject>();
    red1->accept(visitor);
    red2->accept(visitor);
    red3->accept(visitor);


    VisitedObjectPtr blue1 = std::make_shared<BlueObject>();
    VisitedObjectPtr blue2 = std::make_shared<BlueObject>();
    blue1->accept(visitor);
    blue2->accept(visitor);

    CountVisitorPtr countPtr = std::dynamic_pointer_cast<CountVisitor>(visitor);

    EXPECT_EQ(3, countPtr->getRed());
    EXPECT_EQ(2, countPtr->getBlue());
}