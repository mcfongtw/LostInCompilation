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

/**
 * A pure abstract class to a visited data as of Visitor design pattern.
 *
 * @since 0.1
 */
class VisitedObject {
public:
    VisitedObject() {

    }

    virtual ~VisitedObject() {

    }

    /**
     * VisitedObject accepts a visit from the desginated Visitor
     *
     * @param visitor pointer to a Visitor
     */
    virtual void accept(VisitorPtr visitor) = 0;
};


#endif //MAINPROJECT_VISITEDOBJECT_H
