/*
 * r2h_task_dlink_sys_control_helper.h
 *
 *  Created on: 2018-9-14
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SYS_CONTROL_HELPER_H_
#define R2H_TASK_DLINK_SYS_CONTROL_HELPER_H_


#include "r2h_task_dlink_sys_control_helper_def.h"

class R2H_Task_DLinkSysControlHelper
{
public:
	R2H_Task_DLinkSysControlHelper(R2H_DLink_MemorySystemControl *pMemory);
	R2H_Task_DLinkSysControlHelper();
	virtual ~R2H_Task_DLinkSysControlHelper();
	
	void ReadRemoteRequest(bool *pNewRequestArrived, R2H_DLINK_SYS_CONTROL_REQUEST_T *pRequest);
	void WriteDeviceResponse(R2H_DLINK_SYS_CONTROL_RESPONSE_T *pResponse);
	void BindToDLinkSystemControlObject(R2H_DLink_MemorySystemControl *pMemory);

private:
	R2H_DLink_MemorySystemControl*				__dlink_memory_system_control;
	//R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_IN_T 	__dlink_sys_control_in;
	//R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_OUT_T 	__dlink_sys_control_out;
};



#endif /* R2H_TASK_DLINK_SYS_CONTROL_HELPER_H_ */
