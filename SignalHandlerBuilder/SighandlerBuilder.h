/*
 * SigHandlerBuilder.h
 *
 *  Created on: Jul 24, 2014
 *      Author: kal-el
 */

#ifndef SIGHANDLERBUILDER_H_
#define SIGHANDLERBUILDER_H_

#include "../SignalHandler/SignalHandler.h"

class SignalHandler;

class SighandlerBuilder
{
public:
	SighandlerBuilder();
	~SighandlerBuilder();

	SighandlerBuilder* addSignalMask(const unsigned& sig);
	SignalHandler* build();
	void demolish();

private:

};

#endif /* SIGNALBUILDER_H_ */
