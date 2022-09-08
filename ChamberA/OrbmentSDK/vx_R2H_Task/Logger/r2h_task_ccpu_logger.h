/*
 * r2h_task_ccpu_logger.h
 *
 *  Created on: May 24, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_TASK_CCPU_LOGGER_H_
#define R2H_TASK_CCPU_LOGGER_H_

#include <pthread.h>
#include "r2h_task_logger.h"

class R2H_Task_CCPU_Logger: public R2H_Task_Logger
{
public:
	R2H_Task_CCPU_Logger();
	R2H_Task_CCPU_Logger(pthread_mutex_t mutex);
	virtual ~R2H_Task_CCPU_Logger();
	virtual R2H_INT32 SyncRegistEventLog (void* rtc, R2H_INT32 eventCode, R2H_CONST_STRING pcEventMsg, bool alert);
	virtual R2H_INT32 AsyncRegistEventLog (void* rtc, R2H_INT32 eventCode, R2H_CONST_STRING pcEventMsg, bool alert);
	virtual R2H_INT32 FlushEventLog(void*);
	virtual R2H_INT32 StartLoading (void*);
	virtual R2H_INT32 FinishLoading (void*);
private:
	pthread_mutex_t __mutex;
	bool __external_mutex, __alert;
	static const size_t __MAX_MSG_LENGTH = 200;
	R2H_CHAR __msg[__MAX_MSG_LENGTH + 1];
	void __clean();
};

#endif /* R2H_TASK_CCPU_LOGGER_H_ */
