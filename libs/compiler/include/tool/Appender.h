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

/**
 * An Appender class is used to append a message to a type of destnation output.
 *
 * @since 0.1
 */
class Appender {
public:
    Appender();

    Appender(const Appender& that);

    virtual ~Appender();

    virtual void append(const std::string &msg);

    virtual void close() = 0;

protected:
    virtual void internalWrite(const std::string &msg) = 0;

};

/**
 * A ConsoleAppender is used to append message to stdout
 */
class ConsoleAppender : public Appender {
public:
    ConsoleAppender();

    ConsoleAppender(const ConsoleAppender& that);

    virtual ~ConsoleAppender();

    virtual void close();

protected:
    virtual void internalWrite(const std::string &msg);
};


/**
 * A StringAppender is used to append message to an in-memory string object.
 */
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


/**
 * A FileAppender is used to append message to a physical file output.
 */
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
