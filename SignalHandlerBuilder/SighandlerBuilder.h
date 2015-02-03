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

/**
 * The only class that allows user to access signal handler class
 */
class SighandlerBuilder
{
public:
	// Constructor
	SighandlerBuilder();

	// Destructor
	~SighandlerBuilder();

	/**
	 * Add signal mask to signal handler
	 * @param sig SignalHanlder::type
	 * @return
	 */
	SighandlerBuilder* addSignalMask(const unsigned& sig);

	/**
	 * Build the signal handler based on the masks
	 * @return The signal handler
	 */
	SignalHandler* build();

	/**
	 * Destroy the signal handler
	 */
	void demolish();

private:

};

#endif /* SIGNALBUILDER_H_ */
