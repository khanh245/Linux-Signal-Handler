/*
 * SignalHandler.cpp
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#include "SignalHandler.h"

SignalHandler* SignalHandler::mInstance = NULL;

SignalHandler::SignalHandler()
{ }

SignalHandler::~SignalHandler()
{
	/* This is for unlocking mask not destruct it
	if (sigprocmask(SIG_SETMASK, &mMask, NULL) < 0)
		std::cerr << "removing mask error" << std::endl;
	*/
	sigemptyset(&mMask);
}

SignalHandler* SignalHandler::getInstance()
{
	if (!mInstance)
		mInstance = new SignalHandler();

	return mInstance;
}

void SignalHandler::destroyInstance()
{
	if (mInstance) {
		delete mInstance;
		mInstance = NULL;
	}
}

void SignalHandler::addMask(const unsigned& mask)
{
	sigset_t newmask;
	int error;

	sigemptyset(&newmask);
	if ((error = sigaddset(&newmask, mask)) < 0)
		std::cerr << "'signum' arg is invalid" << std::endl;

	if ((error = pthread_sigmask(SIG_BLOCK, &newmask, &mMask)) < 0)
		std::cerr << "'how' arg is invalid" << std::endl;
}
