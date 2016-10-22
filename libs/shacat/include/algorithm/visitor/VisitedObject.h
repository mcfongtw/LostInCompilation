//
// Created by shannaracat on 2016/10/22.
//

#ifndef MAINPROJECT_VISITEDOBJECT_H
#define MAINPROJECT_VISITEDOBJECT_H

#include <memory>

#include "algorithm/visitor/Visitor.h"

//NOTE: Each derived Visitor / VisitedObject class should be in seperated header files for fulfilling proper forward declaration
class Visitor;
typedef std::shared_ptr<Visitor> VisitorPtr;

class VisitedObject {
public:
    VisitedObject() {

    }

    virtual ~VisitedObject() {

    }

    virtual void accept(VisitorPtr) = 0;
};


#endif //MAINPROJECT_VISITEDOBJECT_H
