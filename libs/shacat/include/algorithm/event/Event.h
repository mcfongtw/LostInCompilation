//
// Created by Michael Fong on 2016/11/19.
//

#ifndef LOSTINCOMPILATION_EVENT_H
#define LOSTINCOMPILATION_EVENT_H

#include <string>
#include <memory>


/**
 * A generic Event class that encapsulates all meta information within.
 *
 * @since 0.1
 */
//TODO:Make it a template
class Event {
public:
    Event(std::string summary, std::string message);

    virtual ~Event();

    virtual std::string getMessage();

    virtual std::string getSummary();

protected:
    std::string _summary;

    std::string _message;
};



#endif //LOSTINCOMPILATION_EVENT_H
