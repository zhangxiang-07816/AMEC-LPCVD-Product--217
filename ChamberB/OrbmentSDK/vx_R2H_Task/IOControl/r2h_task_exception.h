/*
 * r2h_task_exception.h
 *
 *  Created on: 2019-8-16
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_EXCEPTION_H_
#define R2H_TASK_EXCEPTION_H_
#include "../r2h_task_data_type.h"
#include "../r2h_task_error_code.h"
#include <exception>

class R2H_Task_Exception : public std::exception
{
public:
	R2H_Task_Exception(R2H_INT32 errorCode);
	R2H_Task_Exception(std::exception &e);
	virtual ~R2H_Task_Exception();
	R2H_INT32 ReturnErrorCode();
	const std::exception& ReturnInnerSTDException();
private:
	R2H_INT32			__r2h_task_error_code;
	std::exception		__inner_std_exception;
};



#endif /* R2H_TASK_EXCEPTION_H_ */
