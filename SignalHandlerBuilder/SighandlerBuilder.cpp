/*
 * SighandlerBuilder.cpp
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#include "SighandlerBuilder.h"

SighandlerBuilder::SighandlerBuilder()
{ }

SighandlerBuilder::~SighandlerBuilder()
{ }

SighandlerBuilder* SighandlerBuilder::addSignalMask(const unsigned& signal)
{
	SignalHandler::getInstance()->addMask(signal);
	return this;
}

SignalHandler* SighandlerBuilder::build()
{
	return SignalHandler::getInstance();
}
