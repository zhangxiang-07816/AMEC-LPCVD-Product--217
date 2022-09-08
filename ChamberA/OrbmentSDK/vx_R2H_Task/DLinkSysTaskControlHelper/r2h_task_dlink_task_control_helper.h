/*
 * r2h_task_dlink_task_control_helper.h
 *
 *  Created on: 2018-9-14
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_TASK_CONTROL_HELPER_H_
#define R2H_TASK_DLINK_TASK_CONTROL_HELPER_H_


#include "../r2h_task_data_type.h"
#include "../r2h_task_error_code.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_task_control.h"
#include "../../vx_R2H_ExtModule/r2h_extmodule_error_code.h"

class R2H_Task_DLinkTaskControlHelper
{
public:
	R2H_Task_DLinkTaskControlHelper();
	virtual ~R2H_Task_DLinkTaskControlHelper();
	
	virtual R2H_INT32 BindToDLinkMemoryObject(R2H_DLink_MemoryTaskControl *pMemory);
protected:
	R2H_DLink_MemoryTaskControl*				_dlink_memory_task_control;
};


#endif /* R2H_TASK_DLINK_TASK_CONTROL_HELPER_H_ */
