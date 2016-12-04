//
// Created by mcfong on 11/30/16.
//

#include "tool/Appender.h"

Appender::Appender() {

}

Appender::Appender(const Appender& that) {

}

Appender::~Appender() {

}

void Appender::append(const std::string &msg) {
    this->internalWrite(msg);
}

ConsoleAppender::ConsoleAppender() : Appender() {

}

ConsoleAppender::ConsoleAppender(const ConsoleAppender& that) : Appender(that){

}

ConsoleAppender::~ConsoleAppender() {

}

void ConsoleAppender::close() {

}

void ConsoleAppender::internalWrite(const std::string &msg) {
    std::cout << msg << std::endl;
}

StringAppender::StringAppender() : Appender() {

}

StringAppender::StringAppender(const StringAppender& that) : Appender(that){

}

StringAppender::~StringAppender() {

}

std::string StringAppender::toString() {
    return _ss.str();
}

void StringAppender::close() {

}

void StringAppender::internalWrite(const std::string &msg) {
    _ss << msg;
}

FileAppender::FileAppender(const std::string& fname) : Appender() {
    _fout.open(fname.c_str(), std::ios::out | std::ios::app | std::ios::binary);
}

FileAppender::FileAppender(const FileAppender& that) : Appender(that){

}

FileAppender::~FileAppender() {

}

void FileAppender::close() {
    this->_fout.close();
}

void FileAppender::internalWrite(const std::string &msg) {
    util::Conditions::requireTrue(this->_fout.is_open(), "output stream is closed");

    this->_fout << msg <<  "\r\n";
    this->_fout.flush();
}