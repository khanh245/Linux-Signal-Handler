/*
 * SignalHandler.h
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include "../SignalHandlerBuilder/SighandlerBuilder.h"

class SighandlerBuilder;

class SignalHandler
{
public:
	enum type {					// These are from linux signal
		sighup 		=	1,
		sigint		=	2,
		sigquit		=	3,
		sigill		=	4,
		sigabrt		=	6,
		sigfpe		=	8,
		sigkill		=	9,
		sigsegv		=	11,
		sigpipe		=	13,
		sigalrm		=	14,
		sigterm		=	15,
		sigusr1		=	16,
		sigusr2		=	17,
		sigchld		=	18,
		sigcont		=	19,

		sigstop		=	23,
		sigtstp		=	24,

		sigttin		=	26,
		sigttou		=	27
	};

	static SignalHandler* getInstance();
	static void destroyInstance();

	SignalHandler();
	~SignalHandler();

private:
	SignalHandler(const SignalHandler*);
	SignalHandler &operator= (const SignalHandler*);

	static SignalHandler* mInstance;
	static SighandlerBuilder* mBuilder;
};

#endif /* SIGNALHANDLER_H_ */
