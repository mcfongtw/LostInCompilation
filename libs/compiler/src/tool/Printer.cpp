//
// Created by mcfong on 11/30/16.
//

#include "tool/Printer.h"

Printer::Printer() {

}

Printer::~Printer() {

}

Printer::Printer(Printer& that) {

}

void Printer::addAppender(AppenderPtr appender) {
    _appenderChain.push_back(appender);
}

void Printer::write(const std::string& msg) {
    for(AppenderPtr appender : _appenderChain) {
        appender->append(msg);
    }
}

void Printer::closeAppenders() {
    for(AppenderPtr appender : _appenderChain) {
        appender->close();
    }
}