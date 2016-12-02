//
// Created by mcfong on 11/30/16.
//

#ifndef LOSTINCOMPILATION_PRINTER_H
#define LOSTINCOMPILATION_PRINTER_H


#include "tool/Appender.h"

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
