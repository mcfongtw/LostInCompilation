/*
 * ASTNode.h
 *
 *  Created on: Feb 6, 2014
 *      Author: Michael Fong
 */

#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <string>

#include "algorithm/tree/visitor/VisitedTreeNode.h"
#include "compile/SourceCodePosition.h"

class ASTNode;

typedef std::shared_ptr<ASTNode> ASTNodePtr;

/**
 * ASTNode is a derived class of VisitedTreeNode which further has AST related data, including token type and token text.
 *
 * @since 0.1
 */
class ASTNode : public VisitedTreeNode {
public:
	ASTNode();

	ASTNode(const char*, int token);

	ASTNode(const char*, int token, SourceCodePosition position);

	virtual ~ASTNode();

	virtual void setImage(const char*);

	virtual char* getText();

	virtual std::string getImage();

	virtual void setToken(int token);

	virtual int getToken();

	virtual SourceCodePosition getPosition();

protected:
	char* _text;

	int _token;

	SourceCodePosition _pos;

};

#endif /* ASTNODE_H_ */
