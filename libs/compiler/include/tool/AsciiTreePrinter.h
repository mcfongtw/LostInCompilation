
#ifndef PARSETREEPRINTER_H_
#define PARSETREEPRINTER_H_

#include "algorithm/tree/visitor/traversal/TreeWalker.h"
#include "algorithm/tree/ast/ASTNode.h"
#include "tool/Printer.h"

/**
 * AsciiTreePrinter is a linux command 'tree'-like ascii text tree traversal algorithm
 *
 * Linux 'tree' command : http://mama.indstate.edu/users/ice/tree/
 *
 *  Created on: Dec 23, 2014
 *      Author: Michael Fong
 *
 * @since 0.1
 */
class AsciiTreePrinter: public TreeWalker, public Printer {
public:
	AsciiTreePrinter();

	AsciiTreePrinter(AsciiTreePrinter& that);

	virtual ~AsciiTreePrinter();

	virtual int startWalking();

	virtual int stopWalking();

	virtual int walk(VisitedTreeNodePtr ptr);
};

#endif /* PARSETREEPRINTER_H_ */
