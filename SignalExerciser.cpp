/*
 * SignalExerciser.cpp
 *
 *  Created on: Jul 23, 2014
 *      Author: kal-el
 */

/* Deprecated Signal
 #include<stdio.h>
 #include<signal.h>
 #include<unistd.h>

 void sig_handler(int signo) {
 if (signo == SIGINT)
 printf("received SIGINT\n");
 }

 int main(void) {
 if (signal(SIGINT, sig_handler) == SIG_ERR)
 printf("\ncan't catch SIGINT\n");

 while (1)
 sleep(1);
 return 0;
 }
 */

/* Newer signal action
 #include <pthread.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <stdio.h>
 #include <signal.h>
 #include <pthread.h>
 #include <cstring>

 typedef struct data {
 char name[10];
 int age;
 };

 void sig_func(int sig) {
 write(1, "Caught signal 2\n", 17);
 signal(SIGSEGV, sig_func);
 }

 void *func(void *p) {
 fprintf(stderr, "This is from thread function\n");
 strcpy(((data*)p)->name, "Mr. Linux");
 ((data*)p)->age = 30;
 sleep(2);
 }

 int main() {
 pthread_t tid;
 data d;
 data *ptr = &d;

 signal(SIGINT, sig_func); // Register signal handler before going multithread
 pthread_create(&tid, NULL, &func, ptr);
 while(1)
 sleep(1); // Leave time for initialisation

 pthread_kill(tid, SIGSEGV);

 pthread_join(tid, NULL);
 fprintf(stderr, "Name:%s\n", ptr->name);
 fprintf(stderr, "Age:%d\n", ptr->age);
 }
 */

/* List of all Signals as defined in Linux

   Signal     Value     Action   Comment
   -------------------------------------------------------------------------
   SIGHUP        1       Term    Hangup detected on controlling terminal
                                 or death of controlling process
   SIGINT        2       Term    Interrupt from keyboard
   SIGQUIT       3       Core    Quit from keyboard
   SIGILL        4       Core    Illegal Instruction
   SIGABRT       6       Core    Abort signal from abort(3)
   SIGFPE        8       Core    Floating point exception
   SIGKILL       9       Term    Kill signal
   SIGSEGV      11       Core    Invalid memory reference
   SIGPIPE      13       Term    Broken pipe: write to pipe with no readers
   SIGALRM      14       Term    Timer signal from alarm(2)
   SIGTERM      15       Term    Termination signal
   SIGUSR1   30,10,16    Term    User-defined signal 1
   SIGUSR2   31,12,17    Term    User-defined signal 2
   SIGCHLD   20,17,18    Ign     Child stopped or terminated
   SIGCONT   19,18,25    Cont    Continue if stopped
   SIGSTOP   17,19,23    Stop    Stop process
   SIGTSTP   18,20,24    Stop    Stop typed at tty
   SIGTTIN   21,21,26    Stop    tty input for background process
   SIGTTOU   22,22,27    Stop    tty output for background process

 */

/* PROTOTYPE
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <cstring>
#include <syslog.h>
#include <cstdlib>

int quitflag;
sigset_t mask;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t wait = PTHREAD_COND_INITIALIZER;

void *thr_fn(void *arg) {
	int err, signo;

	for (;;) {
		err = sigwait(&mask, &signo);
		if (err != 0)
			syslog(err, "sigwait failed");
		switch (signo) {
		case SIGINT:
			printf("\ninterrupt\n");
			break;

		case SIGQUIT:
			pthread_mutex_lock(&lock);
			quitflag = 1;
			pthread_mutex_unlock(&lock);
			pthread_cond_signal(&wait);
			return (0);

		default:
			printf("unexpected signal %d\n", signo);
			break;
		}
	}

	return 0;
}

int main(void) {
	int err;
	sigset_t oldmask;
	pthread_t tid;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);
	sigaddset(&mask, 30);
	if ((err = pthread_sigmask(SIG_BLOCK, &mask, &oldmask)) != 0)
		syslog(err, "SIG_BLOCK error");

	err = pthread_create(&tid, NULL, thr_fn, 0);
	if (err != 0)
		syslog(err, "can't create thread");

	pthread_mutex_lock(&lock);
	while (quitflag == 0)
		pthread_cond_wait(&wait, &lock);
	pthread_mutex_unlock(&lock);

	// SIGQUIT has been caught and is now blocked; do whatever
	quitflag = 0;

	// reset signal mask which unblocks SIGQUIT
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		syslog(err, "SIG_SETMASK error");

	printf("Someone wants to kill me....");
	exit(0);
}
*/

#include <iostream>
#include "SighandlerBuilder.h"

int main()
{
	std::cout << "Signal Handler Exerciser..." << std::endl;
	SighandlerBuilder* mBuilder = new SighandlerBuilder();
	mBuilder->addSignalMask(SignalHandler::sigusr2)
			->addSignalMask(SignalHandler::sigabrt)
			->addSignalMask(SignalHandler::sigterm)
			->addSignalMask(SignalHandler::sigquit);

	SignalHandler* handler = mBuilder->build();

	mBuilder->demolish();
	delete mBuilder;

	return 0;
}
