/*
 * StackTraceUtils.cpp
 *
 *  Created on: May 22, 2014
 *      Author: Michael Fong
 */

#include <sstream>

#include "error/StackTraceUtils.h"

//void abort_err_handler(int sig_num, siginfo_t * info, void * ucontext) {
//	sig_ucontext_t * uc = (sig_ucontext_t *) ucontext;

	// Get the address at the time the signal was raised from the EIP (x86)
//	void * caller_address = (void *) uc->uc_mcontext.err;

//	std::cerr << "signal " << sig_num << " (" << strsignal(sig_num)
//			<< "), address is " << info->si_addr << " from " << caller_address
//			<< std::endl;

//	void * array[50];
//	int size = backtrace(array, 50);

//	std::cerr << __FUNCTION__ << " backtrace returned " << size
//			<< " frames\n\n";

	// overwrite sigaction with caller's address
//	array[1] = caller_address;

//	char ** messages = backtrace_symbols(array, size);
//
//	// skip first stack frame (points here)
//	for (int i = 1; i < size && messages != NULL; ++i) {
//		std::cerr << "[Step " << i << "] : " << messages[i] << std::endl;
//	}
//	std::cerr << std::endl;
//
//	free(messages);

//	exit(EXIT_FAILURE);
//}

void StackTraceUtils::setupStackTraceAgent() {
	struct sigaction sigact;

//	sigact.sa_sigaction = abort_err_handler;
	sigact.sa_flags = SA_RESTART | SA_SIGINFO;

	if (sigaction(SIGABRT, &sigact, (struct sigaction *) NULL) != 0) {
		std::cerr << "error setting handler for signal " << SIGABRT << " ("
				<< strsignal(SIGABRT) << ")\n";
		exit(EXIT_FAILURE);
	}
}

std::string StackTraceUtils::getStackTraceMessage() {
	std::stringstream ss;

	void * array[50];
	int size = backtrace(array, 50);

	ss << std::endl << " Stack Trace returned " << size
			<< " Steps" << std::endl;

	char ** messages = backtrace_symbols(array, size);

	for (int i = 0; i < size && messages != 0; i++) {
		ss << "[Step " << i << " ] :" << messages[i] << std::endl;
	}
	ss << std::endl;

	free(messages);

	return ss.str();
}
