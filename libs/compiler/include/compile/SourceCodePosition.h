//
// Created by Michael Fong on 2016/12/3.
//

#ifndef LOSTINCOMPILATION_SOURCECODEPOSITION_H
#define LOSTINCOMPILATION_SOURCECODEPOSITION_H

#include <string>

/**
 * SourceCodePosition used to encapsulate the textual position of a certain statement in source code.
 * A textual position may be represented by a tunple of <row, col>, which indicates the position at
 * specific row and column. Row may also be referred as line number.
 *
 * The default value for both row and col is 1.
 *
 * @since 0.1
 */
class SourceCodePosition {
public:
    SourceCodePosition(int row, int col);

    SourceCodePosition(int col);

    SourceCodePosition();

    virtual ~SourceCodePosition();

    virtual int getRow();

    virtual int getCol();

    virtual std::string toString();

private:
    int _col;
    int _row;
};


#endif //LOSTINCOMPILATION_SOURCECODEPOSITION_H
