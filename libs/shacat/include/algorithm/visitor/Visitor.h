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

/**
 * A pure abstract class to a visitor as of Visitor design pattern. Each visitor class should implement how the data structure (VisitedObject) being visited is processed
 *
 * @since 0.1
 */
class Visitor {
public :
    Visitor() {

    }

    virtual ~Visitor() {

    }

protected:
    /**
     * how the data structure being visited is processed
     *
     * @param ptr pointer to VisitedObject
     *
     * @return integeral code as visited result.
     */
    virtual int visit(VisitedObjectPtr ptr) = 0;
};


#endif //MAINPROJECT_VISITOR_H
