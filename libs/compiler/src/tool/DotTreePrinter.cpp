/*
 * ASTWalker.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Michael Fong
 */

#include "tool/DotTreePrinter.h"
#include "log/Logger.h"
#include "common/Utils.h"

#include <sstream>

using namespace std;

DotTreePrinter::DotTreePrinter() : TreeWalker(), Printer() {

}

DotTreePrinter::DotTreePrinter(DotTreePrinter& that) {

}

DotTreePrinter::~DotTreePrinter() {

}

int DotTreePrinter::startWalking() {
    LOG(Logger::LEVEL_DEBUG, "Start walking");

	this->write("digraph G {\n");
    this->write("\t node [style=rounded]\n");

	return 1;
}

int DotTreePrinter::stopWalking() {
    this->write("}");

    LOG(Logger::LEVEL_DEBUG, "Stop walking");

    this->closeAppenders();
}

int DotTreePrinter::walk(VisitedTreeNodePtr basePtr) {
	util::Conditions::requireNotNull(basePtr, "AST Node");

	ASTNodePtr ptr = std::dynamic_pointer_cast<ASTNode>(basePtr);
	TraverseAction action = ptr->getState();

    if(action== TRAVERSE_IN && ptr->isRoot()) {
        this->startWalking();
    }

    std::string message("Visit ASTNode[" + std::string(ptr->getText()) + "]");
    LOG(Logger::LEVEL_DEBUG, message);
    std::stringstream ss;

	if (action == TRAVERSE_IN) {
		ss  << "\t node_"
		    << util::Converts::numberToString(_nodeIdForDot)
			<< " [label = \"'"
            << ptr->getText()
            << "' token = "
			<< ptr->getToken()
            << "\"]\n";

		for (size_t i = 0; i < ptr->getNumOfChildren(); i++) {
			ASTNodePtr child = std::dynamic_pointer_cast<ASTNode> (ptr->getChildAt(i));
			util::Conditions::requireNotNull(child,
					"AST Child at " + util::Converts::numberToString(i));

			ss << "\t node_"
               << util::Converts::numberToString(_nodeIdForDot)
               << " -> node_"
               << util::Converts::numberToString(_nodeIdForDot + (i+1))
               << "\n";
		}

        _nodeIdForDot++;
	} else if (action == TRAVERSE_OUT) {

	}

    this->write(ss.str());

    if(action == TRAVERSE_OUT  && ptr->isRoot()) {
        this->stopWalking();
    }

	return 1;
}
