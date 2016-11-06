//
// Created by Michael Fong on 2016/11/6.
//

#include <compile/parser/MathParser.h>
#include "compile/MathInterpretor.h"

MathInterpretor::MathInterpretor(): Interpretable(), _evaluator(std::make_shared<SymbolTableStack>(ST_Simple)) {

}

MathInterpretor::~MathInterpretor() {

}

void MathInterpretor::startInterpret() {
    this->_evaluator.startEval();
}

void MathInterpretor::stopInterpret() {
    this->_evaluator.stopEval();
}

void MathInterpretor::interpret(std::string& line) {
    ASTNodePtr root = nullptr;

    MathParser parser;

    parser.parse(root, line);

    this->_evaluator.doEval(std::shared_ptr<ASTNode>(root));
}