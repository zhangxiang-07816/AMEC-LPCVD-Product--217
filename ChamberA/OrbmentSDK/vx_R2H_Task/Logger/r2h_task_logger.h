/*
 * r2h_task_logger.h
 *
 *  Created on: May 24, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_TASK_LOGGER_H_
#define R2H_TASK_LOGGER_H_

#include "../r2h_task_data_type.h"

class R2H_Task_Logger
{
public:
	R2H_Task_Logger();
	virtual ~R2H_Task_Logger();
	virtual R2H_INT32 SyncRegistEventLog (void* rtc, R2H_INT32 eventCode, R2H_CONST_STRING pcEventMsg, bool alert) = 0;
	virtual R2H_INT32 AsyncRegistEventLog (void* rtc, R2H_INT32 eventCode, R2H_CONST_STRING pcEventMsg, bool alert) = 0;
	virtual R2H_INT32 FlushEventLog(void*) = 0;
	virtual R2H_INT32 StartLoading (void*) = 0;
	virtual R2H_INT32 FinishLoading (void*) = 0;
};

#endif /* R2H_TASK_LOGGER_H_ */
