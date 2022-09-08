/*
 * r2h_task_dlink_sys_control_helper_def.h
 *
 *  Created on: 2018-9-14
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SYS_CONTROL_HELPER_DEF_H_
#define R2H_TASK_DLINK_SYS_CONTROL_HELPER_DEF_H_

#include "../r2h_task_data_type.h"
#include "../r2h_task_error_code.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_task_control.h"

typedef enum R2H_DLINK_SYS_CONTROL_COMMAND
{
	R2H_DLINK_SYS_CONTROL_SWITCH_IO_MODE			= 0x00000001,
	
	__R2H__DLINK_SYS_CONTROL_COMMAND				= 0xFFFFFFFF
}R2H_DLINK_SYS_CONTROL_COMMAND_T;

typedef enum R2H_TASK_DEVICE_IO_SCAN_MODE
{
	R2H_TASK_DEVICE_IO_SCAN_LOCAL_MODE				= 0x00000001,
	R2H_TASK_DEVICE_IO_SCAN_REMOTE_MODE				= 0x00000002,
	
	__R2H_TASK_DEVICE_IO_SCAN_MODE					= 0xFFFFFFFF
}R2H_TASK_DEVICE_IO_SCAN_MODE_T;

#pragma pack(1)

typedef struct R2H_DLINK_SYS_CONTROL_REQUEST_HEAD
{
	R2H_BYTE 										host_handshake_byte;
	R2H_DLINK_SYS_CONTROL_COMMAND_T					command;
}R2H_DLINK_SYS_CONTROL_REQUEST_HEAD_T;

typedef struct R2H_DLINK_SYS_CONTROL_REQUEST
{
	R2H_DLINK_SYS_CONTROL_REQUEST_HEAD_T			head;
	union
	{
		//R2H_BYTE									param[R2H_RINFO_SYS_CONTROL_IN_SIZE];
		struct
		{
			R2H_TASK_DEVICE_IO_SCAN_MODE_T			mode;
		}swicth_io_mode;
	};
}R2H_DLINK_SYS_CONTROL_REQUEST_T;

typedef struct R2H_DLINK_SYS_CONTROL_RESPONSE_HEAD
{
	R2H_BYTE 										device_handshake_byte;
	R2H_INT32										result;
}R2H_DLINK_SYS_CONTROL_RESPONSE_HEAD_T;

typedef struct R2H_DLINK_SYS_CONTROL_RESPONSE
{
	R2H_DLINK_SYS_CONTROL_RESPONSE_HEAD_T			head;
	union
	{
		//R2H_BYTE									data[R2H_RINFO_SYS_CONTROL_OUT_SIZE];
	};
}R2H_DLINK_SYS_CONTROL_RESPONSE_T;

#pragma pack()


#endif /* R2H_TASK_DLINK_SYS_CONTROL_HELPER_DEF_H_ */
