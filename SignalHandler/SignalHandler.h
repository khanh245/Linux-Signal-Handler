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
