/*
 * Console.h
 *
 *  Created on: Apr 28, 2014
 *      Author: Michael Fong
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "MetricsManager.h"
#include <string>

/**
 * A simple Console class that realize the read-eval-print loop
 *
 * @since 0.1
 */
class Console {
public:
	Console();
	virtual ~Console();

	void run();

private:
	void loop();

	EventListenerPtr _metrics;
};

#endif /* CONSOLE_H_ */
