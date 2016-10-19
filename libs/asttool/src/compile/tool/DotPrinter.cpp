/*
 * ASTWalker.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: shannaracat
 */

#include "compile/tool/DotPrinter.h"
#include "log/Logger.h"
#include "common/Utils.h"


using namespace std;

DotPrinter::DotPrinter(std::string fname) :
	TreeWalker(), ASTPrinter() {
	if (this->_fout != nullptr) {
		this->_fout.close();
	}

	this->_fout.open(fname.c_str(), ios::out | ios::app | ios::binary);
}

DotPrinter::~DotPrinter() {

}

int DotPrinter::startWalking() {
    util::Conditions::requireTrue(this->_fout.is_open(), "output stream is closed");

    LOG(Logger::LEVEL_DEBUG, "Start walking");

	this->_fout << "digraph G {\r\n";
	this->_fout << "\t node [style=rounded]\r\n";

	return 1;
}

int DotPrinter::stopWalking() {
    util::Conditions::requireTrue(this->_fout.is_open(), "output stream is closed");

	this->_fout << "}\r\n";
	this->_fout.flush();

    LOG(Logger::LEVEL_DEBUG, "Stop walking");

	return this->close();
}

int DotPrinter::close() {
	if (this->_fout) {
		this->_fout.close();
		return 1;
	} else {
		return -1;
	}
}

static int continuousNodeId = 1;

int DotPrinter::walk(VisitedTreeNodePtr basePtr) {
	util::Conditions::requireNotNull(basePtr, "AST Node");
    util::Conditions::requireTrue(this->_fout.is_open(), "output stream is closed");

	ASTNodePtr ptr = std::dynamic_pointer_cast<ASTNode>(basePtr);

	TraverseAction action = ptr->getState();

    if(action== TRAVERSE_IN && ptr->isRoot()) {
        this->startWalking();
    }

    std::string message("Visit ASTNode[" + std::string(ptr->getText()) + "]");
    LOG(Logger::LEVEL_DEBUG, message);

	if (action == TRAVERSE_IN) {
		this->_fout << "\t node_"
				<< util::Converts::numberToString(continuousNodeId)
				<< " [label = \"'" << ptr->getText() << "' token = "
				<< ptr->getToken() << "\"]\r\n";

		for (size_t i = 0; i < ptr->getNumOfChildren(); i++) {
			ASTNodePtr child = std::dynamic_pointer_cast<ASTNode> (ptr->getChildAt(i));
			util::Conditions::requireNotNull(child,
					"AST Child at " + util::Converts::numberToString(i));

			this->_fout << "\t node_" << util::Converts::numberToString(
                    continuousNodeId) << " -> node_"
					<< util::Converts::numberToString(continuousNodeId + (i+1)) << "\r\n";
		}

        continuousNodeId++;
	} else if (action == TRAVERSE_OUT) {

	}

    if(action == TRAVERSE_OUT  && ptr->isRoot()) {
        this->stopWalking();
    }

	return 1;
}
