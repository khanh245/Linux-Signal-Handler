/*
 * SignalHandler.h
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include <iostream>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

class SignalHandler
{
public:
	friend class SighandlerBuilder;

	enum type {					// These are from Linux signal

		sighup 		=	1,		// Death of Process or Hangup on terminal
		sigint		=	2,		// Interrupt from keyboard (Ctrl + C)
		sigquit		=	3,		// Quit Signal (keyboard)
		sigill		=	4,		// Illegal instruction
		sigabrt		=	6,		// Abort Signal ("abort")
		sigfpe		=	8,		// Floating point exception
		sigkill		=	9,		// Kill Signal
		sigsegv		=	11,		// Invalid memory reference
		sigpipe		=	13,		// Broken Pipe
		sigalrm		=	14,		// Timer signal from ("alarm")
		sigterm		=	15,		// Termination Signal
		sigusr1		=	16,		// User-defined Signal 1
		sigusr2		=	17,		// User-defined Signal 2
		sigchld		=	18,		// Child terminated
		sigcont		=	19,		// Continue if stopped

		sigstop		=	23,		// Stop process
		sigtstp		=	24,		// Stop at tty ("stop")

		sigttin		=	26,		// tty input for background process
		sigttou		=	27 		// tty output for background process

	};

	int getID() { return mPID; }

protected:
	SignalHandler();
	~SignalHandler();

	static SignalHandler* getInstance();
	static void destroyInstance();

	void addMask (const unsigned& mask);

private:
	SignalHandler(const SignalHandler*);
	SignalHandler &operator= (const SignalHandler*);

	static SignalHandler* mInstance;
	sigset_t mMask;
	int mPID;
};

#endif /* SIGNALHANDLER_H_ */
