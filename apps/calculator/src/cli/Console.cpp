/*
 * Console.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#include <iostream>
#include <compile/MathInterpretor.h>

#include "cli/Console.h"
#include "error/Exception.h"
#include "common/Utils.h"
#include "log/Logger.h"
#include "compile/parser/grammar/GrammarLibs.h"
#include "compile/parser/MathParser.h"
#include "compile/eval/MathEvaluator.h"

Console::Console() {
	this->_metrics = MetricsManager::getInstance();
}

Console::~Console() {

}

void Console::run() {
	loop();
}

void Console::loop() {
    MathInterpretor interpretor;
    interpretor.startInterpret();

	while (true) {

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


            RuntimeData answer = interpretor.interpret(line);
            if(answer != nullptr) {
                double value = answer.get<double>();
                std::cout << "ANS : " << util::Converts::numberToString(value) << std::endl;
            }

			LOG(Logger::LEVEL_DEBUG, std::dynamic_pointer_cast<MetricsManager>(this->_metrics)->toString());
		} catch(ParseException& e) {
			LOG(Logger::LEVEL_WARN, std::dynamic_pointer_cast<MetricsManager>(this->_metrics)->toString());
		} catch (Exception& e) {
			LOG_ERROR(e.what());
		}
	}

	interpretor.stopInterpret();
}

