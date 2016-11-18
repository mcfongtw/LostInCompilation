/*
 * StackTraceUtils.h
 *
 *  Created on: May 22, 2014
 *      Author: Michael Fong
 */

#ifndef STACKTRACEUTILS_H_
#define STACKTRACEUTILS_H_

#include <string>
#include <execinfo.h>
#include <signal.h>
#include <string.h>

#include <iostream>
#include <cstdlib>
#include <stdexcept>

/*
 * You can install your own terminate() function by using std::set_terminate(). You should be able to
 * set a breakpoint on your terminate function in gdb. You may be able to generate a stack backtrace
 * from your terminate() function and this backtrace may help in identifying the location of the exception.
 */
//namespace {
//    // invoke set_terminate as part of global constant initialization
//    static const bool SET_TERMINATE = std::set_terminate(my_terminate);
//}

// This structure mirrors the one found in /usr/include/asm/ucontext.h
typedef struct _sig_ucontext {
   unsigned long     uc_flags;
   struct ucontext   *uc_link;
   stack_t           uc_stack;
   struct sigcontext uc_mcontext;
   sigset_t          uc_sigmask;
} sig_ucontext_t;

//void abort_err_handler(int, siginfo_t* , void* );

/**
 * A utility class that is used to retrieve the continuous stack of function call.
 *
 * @since 0.1
 */
class StackTraceUtils {
public:
    /**
     * Enable Stack Trace Agent.
     *
     * \note
     * StackTraceAgent needs to be setup before using
     *
     */
	static void setupStackTraceAgent();

    /**
     * Retrieve a string of list of functional trace message. Maximum 50 stacks
     *
     * @return a std::string of stack trace message
     */
	static std::string getStackTraceMessage();
};

#endif /* STACKTRACEUTILS_H_ */
