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

SighandlerBuilder* SighandlerBuilder::addSignal(const unsigned& signal)
{
	switch(signal)
	{
	case SignalHandler::sighup:
		break;
	case SignalHandler::sigint:
		break;

	default:
		break;
	}

	return this;
}

SignalHandler* SighandlerBuilder::build()
{

	return (SignalHandler*)0;
}
