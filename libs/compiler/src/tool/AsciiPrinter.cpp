/*
 * ParseTreePrinter.cpp
 *
 *  Created on: Dec 23, 2014
 *      Author: Michael Fong
 */

#include "tool/AsciiPrinter.h"

#include <cstring>
#include <sstream>

AsciiPrinter::AsciiPrinter() : TreeWalker(), Printer() {

}

AsciiPrinter::AsciiPrinter(AsciiPrinter &that) {

}

AsciiPrinter::~AsciiPrinter() {

}

int AsciiPrinter::startWalking() {
	return 1;
}

int AsciiPrinter::stopWalking() {
    this->closeAppenders();
	return 1;
}

int AsciiPrinter::walk(ASTNodePtr ptr) {
	TraverseAction action = ptr->getState();

	std::stringstream ss;

	if (action == TRAVERSE_IN) {
		size_t numOfChildren = ptr->getNumOfChildren();

		ss << ptr->getText();
		if (numOfChildren > 0) {
			for (size_t i = 0; i < numOfChildren; i++) {
				char buf[3 + strlen(ptr->getText()) + 1];

				for (size_t j = 0; j < strlen(ptr->getText()); j++) {
					strcat(buf, " ");
				}

				if (i == 0) {
					if (numOfChildren == 1) {
						ss << "───";
						strcat(buf, "   ");
					} else {
						ss << "─┬─";
						strcat(buf, " │ ");
					}
				} else {
					ss << buf << std::endl;
					if (numOfChildren == i + 1) {
						ss << " └─";
						strcat(buf, "   ");
					} else {
						ss << " ├─";
						strcat(buf, " │ ");
					}
				}
			}
		} else {
			ss << "\r\n";
		}
	} else if (action == TRAVERSE_OUT) {

	}

	this->write(ss.str());

	return 1;
}
