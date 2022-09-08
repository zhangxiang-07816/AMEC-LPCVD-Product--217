/*
 * r2h_task_dlink_system_status_helper.h
 *
 *  Created on: 2018-10-18
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SYSTEM_STATUS_HELPER_H_
#define R2H_TASK_DLINK_SYSTEM_STATUS_HELPER_H_

#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_info.h"
#include "r2h_task_dlink_system_status_helper_def.h"

class R2H_Task_DLinkSystemStatusHelper
{
public:
	R2H_Task_DLinkSystemStatusHelper(R2H_DLink_MemorySysInfo *pMemory);
	R2H_Task_DLinkSystemStatusHelper();
	virtual ~R2H_Task_DLinkSystemStatusHelper();
	
	R2H_UINT32 ReadSystemStatusCode();
	void WriteSystemStatusCode(R2H_UINT32 code);
	
	void BindToDLinkSystemInfoObject(R2H_DLink_MemorySysInfo *pMemory);

private:
	R2H_DLink_MemorySysInfo*				__dlink_memory_sys_info;
};

#endif /* R2H_TASK_DLINK_SYSTEM_STATUS_HELPER_H_ */
