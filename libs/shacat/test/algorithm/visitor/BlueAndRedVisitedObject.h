//
// Created by shannaracat on 2016/10/22.
//

#ifndef MAINPROJECT_BLUEANDREDVISITEDOBJECT_H
#define MAINPROJECT_BLUEANDREDVISITEDOBJECT_H

#include "algorithm/visitor/VisitedObject.h"
#include "CountVisitor.h"

class CountVisitor;
typedef std::shared_ptr<CountVisitor> CountVisitorPtr;

class RedObject : public VisitedObject, public std::enable_shared_from_this<RedObject> {
public:
    RedObject() {

    }

    virtual ~RedObject() {

    }

    virtual void accept(VisitorPtr ptr) {
        CountVisitorPtr countPtr = std::dynamic_pointer_cast<CountVisitor>(ptr);
        countPtr->visit(shared_from_this());
    };
};

class BlueObject : public VisitedObject, public std::enable_shared_from_this<BlueObject> {
public:
    BlueObject() {

    }

    virtual ~BlueObject() {

    }

    virtual void accept(VisitorPtr ptr) {
        CountVisitorPtr countPtr = std::dynamic_pointer_cast<CountVisitor>(ptr);
        countPtr->visit(shared_from_this());
    };
};

#endif //MAINPROJECT_BLUEANDREDVISITEDOBJECT_H
