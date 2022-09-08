/*
 * r2h_task_io_control_def.h
 *
 *  Created on: 2018-9-12
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_IO_CONTROL_DEF_H_
#define R2H_TASK_IO_CONTROL_DEF_H_

#include <msgQLib.h>

#include "../../vx_R2H_ExtModule/BaseDevice/r2h_extmodule_base_device.h"
#include "../../vx_R2H_ExtModule/BaseDevice/r2h_extmodule_base_device_def.h"
#include "../../vx_R2H_ExtModule/CPUDevice/r2h_extmodule_cpu_device.h"
#include "../../vx_R2H_ExtModule/CPUDevice/r2h_extmodule_cpu_device_def.h"
#include "../../vx_R2H_EthModule/SocketDevice/r2h_ethmodule_socket_device.h"
#include "../../vx_R2H_EthModule/SocketDevice/r2h_ethmodule_socket_device_def.h"
#include "../DLinkDeviceIOHelper/r2h_task_dlink_device_io_helper.h"
#include "../DLinkDeviceIOHelper/r2h_task_dlink_device_io_helper_def.h"

#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_device_io.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_info.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_task_control.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_task_info.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_user_io.h"

typedef R2H_ExtModule_BaseDevice * P_R2H_ExtModule_BaseDevice;
typedef R2H_EthModule_SocketDevice * P_R2H_EthModule_SocketDevice;
typedef R2H_Task_DLinkDeviceIOHelper * P_R2H_Task_DLinkDeviceIOHelper;

#define R2H_TASK_DLINK_SERVICE_INDEX			(0)
#define R2H_TASK_DEVICE_IO_SCAN_INDEX			(1)
#define R2H_TASK_DEVICE_CONTROL_INDEX			(2)
#define R2H_TASK_ILINK_SERVICE_INDEX			(3)

#define R2H_TASK_USER_TASK_INDEX				(R2H_TASK_ILINK_SERVICE_INDEX + 1)

#define R2H_TASK_DLINK_SERVICE_NAME				("R2H DLink Service")
#define R2H_TASK_DEVICE_IO_SCAN_NAME			("R2H Device IO Scan Task")
#define R2H_TASK_DEVICE_CONTROL_NAME			("R2H Device Control Task")
#define R2H_TASK_ILINK_SERVICE_NAME				("R2H ILink Service")

#define CCPU_INTER_MODULE_SYNC_INTERRUPT_POINTER	(44)

#pragma pack(1)

typedef enum R2H_TASK_DEVICE_IO_SCAN_HOST_COMMAND
{
	R2H_TASK_DEVICE_IO_SCAN_NO_COMMAND			= 0x00000000,
	R2H_TASK_DEVICE_IO_SCAN_TERMINATE			= 0x00000001,
	__R2H_TASK_DEVICE_IO_SCAN_HOST_COMMAND 		= 0xFFFFFFFF
}R2H_TASK_DEVICE_IO_SCAN_HOST_COMMAND_T;

typedef enum R2H_TASK_DEVICE_CONTROL_HOST_COMMAND
{
	R2H_TASK_DEVICE_CONTROL_NO_COMMAND			= 0x00000000,
	R2H_TASK_DEVICE_CONTROL_TERMINATE			= 0x00000001,
	__R2H_TASK_DEVICE_CONTROL_HOST_COMMAND 		= 0xFFFFFFFF
}R2H_TASK_DEVICE_CONTROL_HOST_COMMAND_T;

typedef struct R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA
{
	union
	{
		R2H_EXTMODULE_DEVICE_MODEL_ID_T				ext_module_model_id;
		R2H_ETHMODULE_DEVICE_MODEL_ID_T				eth_module_model_id;
	}model_id;
	void*										pData;
}R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T;

#pragma pack()

class R2H_Task_ProcessDataObjectManager;

typedef void (*USER_PROCESS_CONTROL_ROUTINE)(	std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
												std::vector<P_R2H_EthModule_SocketDevice>  				*pEthDeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryDeviceIO								*pDLinkMemoryDeviceIO,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
												R2H_ULONG 												counterMicros);

typedef void (*USER_IO_DEVICE_INIT)(			std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector);

typedef void (*USER_ETH_DEVICE_INIT)(			std::vector<P_R2H_EthModule_SocketDevice>  				*pEthDeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector);

typedef void (*USER_PROCESS_CONTROL_ROUTINE_EX)(std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
												std::vector<P_R2H_EthModule_SocketDevice>  				*pEthDeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryDeviceIO								*pDLinkMemoryDeviceIO,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
												R2H_Task_ProcessDataObjectManager						*pObjectManager,
												R2H_ULONG 												counterMicros);

typedef void (*USER_IO_DEVICE_INIT_EX)(			std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
												R2H_Task_ProcessDataObjectManager						*pObjectManager);

typedef void (*USER_ETH_DEVICE_INIT_EX)(		std::vector<P_R2H_EthModule_SocketDevice>  				*pEthDeviceVector,
												R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
												R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
												R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
												std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
												R2H_Task_ProcessDataObjectManager						*pObjectManager);


typedef struct R2H_TASK_INTER_MODULE_SYNC_ISR_MSG
{
	R2H_INT64									counter;
	R2H_TASK_INTER_MODULE_SYNC_ISR_MSG()
	{
		counter = 0;
	}
}R2H_TASK_INTER_MODULE_SYNC_ISR_MSG_T;

#define __R2H_TASK_INTER_MODULE_SYNC_ISR_MESSAGE_QUEUE \
		R2H_TASK_INTER_MODULE_SYNC_ISR_MSG _GLB_r2h_task_inter_module_sync_isr_message;\
		VX_MSG_Q(_GLB_r2h_task_inter_module_sync_isr_message_queue_name,1,sizeof(R2H_TASK_INTER_MODULE_SYNC_ISR_MSG_T));\
		MSG_Q_ID _EXT_R2H_TASK_INTER_MODULE_SYNC_ISR_MESSAGE_QUEUE = 0;
#define __INIT_R2H_TASK_INTER_MODULE_SYNC_ISR_MESSAGE_QUEUE \
		_EXT_R2H_TASK_INTER_MODULE_SYNC_ISR_MESSAGE_QUEUE = msgQInitialize(_GLB_r2h_task_inter_module_sync_isr_message_queue_name, 1, sizeof(R2H_TASK_INTER_MODULE_SYNC_ISR_MSG_T),MSG_Q_FIFO );

#define __R2H_TASK_INTER_MODULE_SYNC_ISR \
void _EXT_R2H_TASK_INTER_MODULE_SYNC_INTERRUPT_ROUTINE()\
{\
	_GLB_r2h_task_inter_module_sync_isr_message.counter++;\
	msgQSend(_EXT_R2H_TASK_INTER_MODULE_SYNC_ISR_MESSAGE_QUEUE, \
			(char*)&_GLB_r2h_task_inter_module_sync_isr_message, \
			sizeof(R2H_TASK_INTER_MODULE_SYNC_ISR_MSG_T), \
			NO_WAIT, MSG_PRI_NORMAL);\
}

#define __R2H_TASK_BIND_INTER_MODULE_SYNC_ISR\
		CCPU_EntryInt(CCPU_INTER_MODULE_SYNC_INTERRUPT_POINTER, _EXT_R2H_TASK_INTER_MODULE_SYNC_INTERRUPT_ROUTINE);

#endif /* R2H_TASK_IO_CONTROL_DEF_H_ */
