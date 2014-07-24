/*
 * SignalHandler.cpp
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#include "SignalHandler.h"
#include <stdexcept>

SignalHandler* SignalHandler::mInstance = NULL;

SignalHandler::SignalHandler()
{
// TODO: add sig action from linux
}

SignalHandler::~SignalHandler()
{
// TODO: remove sigset when signal handler is destructed
//		 which I don't think it will.
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
