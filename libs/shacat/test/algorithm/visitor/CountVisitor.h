//
// Created by shannaracat on 2016/10/22.
//

#ifndef MAINPROJECT_COUNTVISITOR_H
#define MAINPROJECT_COUNTVISITOR_H

#include "algorithm/visitor/Visitor.h"
#include "BlueAndRedVisitedObject.h"

class RedObject;
class BlueObject;

class CountVisitor : public Visitor {
public :
    CountVisitor() {

    }

    virtual ~CountVisitor() {

    }

    virtual int visit(std::shared_ptr<RedObject> ptr) {
        this->num_red++;
    };

    virtual int visit(std::shared_ptr<BlueObject> ptr) {
        this->num_blue++;
    };

    virtual int getRed() {
        return this->num_red;
    }

    virtual int getBlue() {
        return this->num_blue;
    }

protected:
    virtual int visit(VisitedObjectPtr ptr) {
        //do nothing, since it is hidden by protected modifer
    }

private:
    int num_red = 0;
    int num_blue = 0;

};

typedef std::shared_ptr<CountVisitor> CountVisitorPtr;
#endif //MAINPROJECT_COUNTVISITOR_H
