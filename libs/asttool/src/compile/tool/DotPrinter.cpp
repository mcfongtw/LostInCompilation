/*
 * ASTWalker.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: shannaracat
 */

#include "compile/tool/DotPrinter.h"

#include "common/Utils.h"

DotPrinter::DotPrinter(std::string fname) :
	TreeWalker(), ASTPrinter() {
	if (this->_fout != nullptr) {
		this->_fout.close();
	}

	this->_fout.open(fname.c_str());
}

DotPrinter::~DotPrinter() {

}

int DotPrinter::startWalking() {
	this->_fout << "digraph G {\r\n";
	this->_fout << "\t node [style=rounded]\r\n";

	return 1;
}

int DotPrinter::stopWalking() {
	this->_fout << "}\r\n";

	this->_fout.flush();
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

int DotPrinter::walk(ASTNodePtr ptr) {
	util::Conditions::requireNotNull(ptr, "AST Node");
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {
		this->_fout << "\t node_"
				<< util::Converts::numberToString(ptr)
				<< " [label = \"'" << ptr->getText() << "' token = "
				<< ptr->getToken() << "\"]\r\n";

		for (size_t i = 0; i < ptr->getNumOfChildren(); i++) {
			ASTNodePtr child = std::dynamic_pointer_cast<ASTNode> (ptr->getChildAt(i));
			util::Conditions::requireNotNull(child,
					"AST Child at " + util::Converts::numberToString(i));

			this->_fout << "\t node_" << util::Converts::numberToString(
					ptr) << " -> node_"
					<< util::Converts::numberToString(child) << "\r\n";
		}
	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}
