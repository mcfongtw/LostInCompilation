//
// Created by Michael Fong on 2016/10/22.
//

#ifndef MAINPROJECT_VISITOR_H
#define MAINPROJECT_VISITOR_H

#include <memory>

#include "algorithm/visitor/VisitedObject.h"

//NOTE: Each derived Visitor / VisitedObject class should be in seperated header files for fulfilling proper forward declaration
class VisitedObject;
typedef std::shared_ptr<VisitedObject> VisitedObjectPtr;

class Visitor {
public :
    Visitor() {

    }

    virtual ~Visitor() {

    }

protected:
    virtual int visit(VisitedObjectPtr ptr) = 0;
};


#endif //MAINPROJECT_VISITOR_H
