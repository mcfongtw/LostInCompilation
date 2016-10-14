/*
 * Console.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#include <iostream>

#include "cli/Console.h"
#include "error/Exception.h"
#include "common/Utils.h"
#include "log/Logger.h"
#include "compile/parser/grammar/GrammarLibs.h"
#include "compile/parser/MathParser.h"
#include "compile/eval/MathEvaluator.h"

Console::Console() {

}

Console::~Console() {

}

void Console::run() {
	loop();
}

void Console::loop() {
	MathEvaluator evaluator;

	while (true) {
		ASTNodePtr root;

		try {
			std::cout << "-> ";
			std::string line;
			getline(std::cin, line);

			if (util::Strings::equalsIgnoreCase(line, "quit")) {
				break;
			} else if (line.empty()) {
				//User press 'ENTER'
				continue;
			}


			MathParser parser;

			parser.parse(root, line);

			evaluator.eval(std::shared_ptr<ASTNode>(root));
		} catch (Exception& e) {
			LOG_ERROR(e.what());
		}
	}

}

