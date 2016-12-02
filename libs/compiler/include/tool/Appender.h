//
// Created by mcfong on 11/30/16.
//

#ifndef LOSTINCOMPILATION_APPENDER_H
#define LOSTINCOMPILATION_APPENDER_H

#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#include "log/Logger.h"
#include "common/Utils.h"
#include "algorithm/tree/visitor/traversal/TreeWalker.h"
#include "algorithm/tree/ast/ASTNode.h"

//Forward declaration
class Appender;

typedef std::shared_ptr<Appender> AppenderPtr;

class Appender {
public:
    Appender();

    Appender(const Appender& that);

    virtual ~Appender();

    virtual void write(const std::string &msg);

    virtual void close() = 0;

protected:
    virtual void internalWrite(const std::string &msg) = 0;

};


class ConsoleAppender : public Appender {
public:
    ConsoleAppender();

    ConsoleAppender(const ConsoleAppender& that);

    virtual ~ConsoleAppender();

    virtual void close();

protected:
    virtual void internalWrite(const std::string &msg);
};

class StringAppender : public Appender {
public:
    StringAppender();

    StringAppender(const StringAppender& that);

    virtual ~StringAppender();

    virtual std::string toString();

    virtual void close();

protected:
    virtual void internalWrite(const std::string &msg);

private:
    std::stringstream _ss;
};

class FileAppender : public Appender {
public:
    FileAppender(const std::string& fname);

    FileAppender(const FileAppender& that);

    virtual ~FileAppender();

    virtual void close();

protected:
    virtual void internalWrite(const std::string &msg);

private:
    std::ofstream _fout;
};



#endif //LOSTINCOMPILATION_APPENDER_H
