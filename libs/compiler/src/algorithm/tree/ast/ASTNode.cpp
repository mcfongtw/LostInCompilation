/*
 * ASTNode.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */
#include "algorithm/tree/ast/ASTNode.h"
#include "common/Utils.h"
#include "log/Logger.h"

#include <cstring>
#include "algorithm/tree/visitor/VisitedTreeNode.h"

ASTNode::ASTNode() : ASTNode("UNDEFINED", -1) {

}

ASTNode::ASTNode(const char* txt, int token) : ASTNode(txt, token, SourceCodePosition()){

}

ASTNode::ASTNode(const char* txt, int token, SourceCodePosition position) : VisitedTreeNode() {
	this->_text = (char*) malloc(sizeof(char) * strlen(txt));
	strcpy(this->_text, txt);
    this->_token = token;
    this->_pos = position;

	LOG(Logger::LEVEL_TRACE,
			"Creating <<" + util::Converts::numberToString(this) + ">>ASTNode('"
			+ this->_text + " | " + this->_pos.toString() + "')");
}

ASTNode::~ASTNode() {
	LOG(Logger::LEVEL_TRACE,
			"Deleting <<" + util::Converts::numberToString(this) + ">>ASTNode('"
					+ this->_text + "')");
}

void ASTNode::setImage(const char* txt) {
	this->_text = (char*) malloc(sizeof(char) * strlen(txt));
	strcpy(this->_text, txt);
}

char* ASTNode::getText() {
	return this->_text;
}

std::string ASTNode::getImage() {
	return std::string(this->_text);
}

void ASTNode::setToken(int token) {
	util::Conditions::requireGreaterThan<int>(token, 0,
			"ASTNode::setToken - token type");

	this->_token = token;
}

int ASTNode::getToken() {
	return this->_token;
}

SourceCodePosition ASTNode::getPosition() {
	return this->_pos;
}
