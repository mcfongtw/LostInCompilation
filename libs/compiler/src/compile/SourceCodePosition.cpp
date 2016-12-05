//
// Created by Michael Fong on 2016/12/3.
//

#include <sstream>
#include <common/Utils.h>

#include "compile/SourceCodePosition.h"

SourceCodePosition::SourceCodePosition(int row, int col): _row(row), _col(col) {

}

SourceCodePosition::SourceCodePosition(int col): _row(1), _col(col) {

}

SourceCodePosition::SourceCodePosition() : _row(1), _col(1){

}

SourceCodePosition::~SourceCodePosition() {

}

int SourceCodePosition::getCol() {
    return _col;
}

int SourceCodePosition::getRow() {
    return _row;
}

std::string SourceCodePosition::toString() {
    std::stringstream ss;

    ss << " <row("
       << util::Converts::numberToString<int>(_row)
       << "),col(" << util::Converts::numberToString<int>(_col)
        << ")>"
       ;
    return ss.str();
}

