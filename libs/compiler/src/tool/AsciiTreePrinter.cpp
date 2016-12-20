#include "tool/AsciiTreePrinter.h"

#include <cstring>
#include <sstream>

AsciiTreePrinter::AsciiTreePrinter() : TreeWalker(), Printer() {

}

AsciiTreePrinter::AsciiTreePrinter(AsciiTreePrinter &that) {

}

AsciiTreePrinter::~AsciiTreePrinter() {

}

int AsciiTreePrinter::startWalking() {
	return 1;
}

int AsciiTreePrinter::stopWalking() {
    this->closeAppenders();
	return 1;
}

//FIXME: does not work, due to unicode and font size
int AsciiTreePrinter::walk(VisitedTreeNodePtr basePtr) {
	ASTNodePtr ptr = std::dynamic_pointer_cast<ASTNode>(basePtr);

	TraverseAction action = ptr->getState();

	std::stringstream ss;

	if (action == TRAVERSE_IN) {
        if(ptr->isRoot()) {
            ss << "(" << ptr->getToken() << "," << ptr->getImage().c_str() << ")" << std::endl;
        } else {
            TreeNode* parent = ptr->getParent();

            //For 2nd+ generations
            for (int i = 0; i < ptr->getDepth() - 1; i++) {

                if(ptr->getDepth() > 1) {
                    TreeNode* grandparent = parent->getParent();

                    int lastIndexOfUncles = grandparent->getNumOfChildren() - 1;

                    if(grandparent->getChildAt(lastIndexOfUncles).get() == parent) {
                        ss << " ";
                    } else {
                        ss << "|";
                    }

                }
                ss << "    ";
            }


            int lastIndexOfSiblings = parent->getNumOfChildren() - 1;
            if(parent->getChildIndexOf(ptr) < lastIndexOfSiblings) {
                ss << "|";
            } else {
                ss << "`";
            }

            ss << "----";
            ss << "(" << ptr->getToken() << "," << ptr->getImage().c_str() << ")" << std::endl;
        }

	} else if (action == TRAVERSE_OUT) {

	}

	this->write(ss.str());

	return 1;
}
