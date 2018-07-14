/*
 * executive.h
 *
 *  Created on: 26 Jun 2018
 *      Author: jim
 */

#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

#include "Arduino.h"

const long MIN_YIELD_TIME_MS = 1;
const int DEFAULT_MAX_TASKS = 10;

class Executive {

public:
	const unsigned long DELAY_FOREVER = -1L;

	Executive(int maxTasks = DEFAULT_MAX_TASKS);
	~Executive();

	int addTask(unsigned long interval_ms, void (*doTask)(void), unsigned long timeToNext_ms = 0);

	void yield(void);
	void delay(unsigned long delay_ms);
	void loop(void);
};

#if !defined(NO_GLOBAL_INSTANCES)
extern Executive Exec;
#endif

#endif /* EXECUTIVE_H_ */
