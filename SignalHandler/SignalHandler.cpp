/*
 * SignalHandler.cpp
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#include "SignalHandler.h"
#include <stdexcept>

SighandlerBuilder* SignalHandler::mBuilder = NULL;
SignalHandler* SignalHandler::mInstance = NULL;

SignalHandler::SignalHandler()
{ }

SignalHandler::~SignalHandler()
{ }

SignalHandler* SignalHandler::getInstance()
{
	if (!mInstance)
	{
		mBuilder = new SighandlerBuilder();
		if (!mBuilder) return 0;

		return mBuilder->build();
	}

	return mInstance;
}

void SignalHandler::destroyInstance()
{
	if (mInstance) {
		delete mInstance;
		mInstance = NULL;
	}

	if (mBuilder) {
		delete mBuilder;
		mBuilder = NULL;
	}
}
