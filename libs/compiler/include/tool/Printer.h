//
// Created by mcfong on 11/30/16.
//

#ifndef LOSTINCOMPILATION_PRINTER_H
#define LOSTINCOMPILATION_PRINTER_H


#include "tool/Appender.h"

/**
 * A Printer is an abstract class that append a form of message to a sequence of Appender(s)
 *
 * @since 0.1
 */
class Printer {
public:
    Printer();

    virtual ~Printer();

    Printer(Printer& that);

    virtual void addAppender(AppenderPtr appender);

    virtual void write(const std::string& msg);

    virtual void closeAppenders();

protected:
    std::vector<AppenderPtr> _appenderChain;

};


#endif //LOSTINCOMPILATION_PRINTER_H
