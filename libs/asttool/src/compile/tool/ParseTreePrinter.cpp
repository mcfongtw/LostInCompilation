/*
 * ParseTreePrinter.cpp
 *
 *  Created on: Dec 23, 2014
 *      Author: Michael Fong
 */

#include "compile/tool/ParseTreePrinter.h"

#include <cstring>
#include <iostream>

ParseTreePrinter::ParseTreePrinter() :
		TreeWalker(), ASTPrinter() {
}

ParseTreePrinter::~ParseTreePrinter() {

}

int ParseTreePrinter::startWalking() {
	return 1;
}

int ParseTreePrinter::stopWalking() {
	return 1;
}

int ParseTreePrinter::walk(ASTNodePtr ptr) {
	TraverseAction action = ptr->getState();

	if (action == TRAVERSE_IN) {
		size_t numOfChildren = ptr->getNumOfChildren();

		std::cout << ptr->getText();
		if (numOfChildren > 0) {
			for (size_t i = 0; i < numOfChildren; i++) {
				char buf[3 + strlen(ptr->getText()) + 1];

				for (size_t j = 0; j < strlen(ptr->getText()); j++) {
					strcat(buf, " ");
				}

				if (i == 0) {
					if (numOfChildren == 1) {
						std::cout << "───";
						strcat(buf, "   ");
					} else {
						std::cout << "─┬─";
						strcat(buf, " │ ");
					}
				} else {
					std::cout << buf << std::endl;
					if (numOfChildren == i + 1) {
						std::cout << " └─";
						strcat(buf, "   ");
					} else {
						std::cout << " ├─";
						strcat(buf, " │ ");
					}
				}
			}
		} else {
			std::cout << std::endl;
		}
	} else if (action == TRAVERSE_OUT) {

	}

	return 1;
}
