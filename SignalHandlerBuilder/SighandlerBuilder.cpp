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

	return this;
}

SignalHandler* SighandlerBuilder::build()
{

	return (SignalHandler*)0;
}
