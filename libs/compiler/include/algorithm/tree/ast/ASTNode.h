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

class ASTNode;

typedef std::shared_ptr<ASTNode> ASTNodePtr;

/**
 * ASTNode is a derived class of TreeNode which further remembers token type and text.
 */
class ASTNode : public VisitedTreeNode {
public:
	ASTNode();

	ASTNode(const char*, int token);

	virtual ~ASTNode();

	virtual void setImage(const char*);

	virtual char* getText();

	virtual std::string getImage();

	virtual void setToken(int token);

	virtual int getToken();

protected:
	char* _text;

	int _token;

};

#endif /* ASTNODE_H_ */
