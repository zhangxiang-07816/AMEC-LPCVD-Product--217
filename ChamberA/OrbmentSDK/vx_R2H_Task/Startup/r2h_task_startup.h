/*
 * r2h_task_startup.h
 *
 *  Created on: 2018-9-10
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_STARTUP_H_
#define R2H_TASK_STARTUP_H_

#include "../IOControl/r2h_task_io_control.h"

#ifdef __cplusplus
	extern "C" {
#endif

void 			vx_R2H_Task_Startup();
	
void			vx_R2H_Task_StartupWithUserCallback(USER_PROCESS_CONTROL_ROUTINE processControlCallback, 
													USER_IO_DEVICE_INIT ioDeviceInitCallback,
													USER_ETH_DEVICE_INIT ethDeviceInitCallback);

void			vx_R2H_Task_StartupWithPDOManager(	USER_PROCESS_CONTROL_ROUTINE_EX processControlCallback, 
													USER_IO_DEVICE_INIT_EX ioDeviceInitCallback,
													USER_ETH_DEVICE_INIT_EX ethDeviceInitCallback,
													R2H_CONST_STRING variableCatalogue, R2H_CONST_STRING ioList);

void 			vx_R2H_Task_Version(R2H_UINT32 *pRelease, R2H_UINT32 *pBuild);

bool			vx_R2H_Task_SearchObject(R2H_UINT32 objectIndex, R2H_TASK_PDO_AREA_T* pArea, R2H_TASK_PDO_INDEX_T *pIndex, R2H_BYTE** ptr);

#ifdef __cplusplus
	}
#endif

#endif /* R2H_TASK_STARTUP_H_ */
