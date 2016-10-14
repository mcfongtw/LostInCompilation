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

ASTNode::ASTNode() :VisitedTreeNode() {
	this->_text = nullptr;
	this->_token = -1;

	LOG(Logger::LEVEL_TRACE,
			"Creating <<" + util::Converts::numberToString(this) + ">>ASTNode('"
			+ this->_text + "')");
}

ASTNode::ASTNode(const char* txt, int token) : VisitedTreeNode(){
	util::Conditions::requireGreaterThan<int>(token, 0,
			"ASTNode::ASTNode - token type");

	this->_text = (char*) malloc(sizeof(char) * strlen(txt));
	strcpy(this->_text, txt);
	this->_token = token;

	LOG(Logger::LEVEL_TRACE,
			"Creating <<" + util::Converts::numberToString(this) + ">>ASTNode('"
			+ this->_text + "')");
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
