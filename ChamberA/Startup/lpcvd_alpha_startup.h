/*
 * lpcvd_alpha_startup.h
 *
 *  Created on: Oct 18, 2021
 *      Author: HaihangRen
 */

#ifndef LPCVD_ALPHA_STARTUP_H_
#define LPCVD_ALPHA_STARTUP_H_

#include "r2h_task_startup.h"

extern void __user_process_control_routine_ex(	std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
												std::vector<P_R2H_EthModule_SocketDevice>  				*pEthDeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryDeviceIO								*pDLinkMemoryDeviceIO,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
												R2H_Task_ProcessDataObjectManager						*pObjectManager,
												R2H_ULONG 												counterMicros);
extern void __user_io_device_init_ex(	std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
										R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
										R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
										R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
										std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
										R2H_Task_ProcessDataObjectManager						*pObjectManager);

#ifdef __cplusplus
	extern "C" {
#endif

void vx_LPCVD_Alpha_Startup_Ex();

#ifdef __cplusplus
	}
#endif


#endif
