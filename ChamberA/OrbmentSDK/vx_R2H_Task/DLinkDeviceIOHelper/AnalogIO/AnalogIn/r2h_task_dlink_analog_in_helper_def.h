/*
 * r2h_task_dlink_analog_in_helper_def.h
 *
 *  Created on: 2018-8-26
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_ANALOG_IN_HELPER_DEF_H_
#define R2H_TASK_DLINK_ANALOG_IN_HELPER_DEF_H_

#include "../../../r2h_task_data_type.h"
#include "../../../../vx_R2H_ExtModule/AnalogIODevice/AnalogIn/r2h_extmodule_analog_in_device_def.h"

#pragma pack(2)

typedef struct	R2H_DLINK_ANALOG_IN_PROCESS_IN_DATE
{
	R2H_UINT16 			latest_error_code;
	R2H_UINT16 			latest_alarm_code;
	R2H_INT16			channel_raw_value[8];
	R2H_INT16			channel_operation_value[8];
}R2H_DLINK_ANALOG_IN_PROCESS_IN_DATE_T;

typedef enum R2H_DLINK_ANALOG_IN_CONTROL_COMMAND
{
	R2H_DLINK_ANALOG_IN_CONTROL_READ_STARTUP_PARAM		= 0x00000001,
	R2H_DLINK_ANALOG_IN_CONTROL_READ_ALARM_INFO			= 0x00000002,
	R2H_DLINK_ANALOG_IN_CONTROL_READ_ERROR_INFO			= 0x00000003,
	R2H_DLINK_ANALOG_IN_CONTROL_CLEAR_DEVICE_ERROR		= 0x00000004,
	
	__R2H_DLINK_ANALOG_IN_CONTROL_COMMAND 				= 0xFFFFFFFF
}R2H_DLINK_ANALOG_IN_CONTROL_COMMAND_T;

typedef struct	R2H_DLINK_ANALOG_IN_CONTROL_OUT_DATE
{
	R2H_BYTE 								device_handshake_byte;
	R2H_INT32								control_result;
	union
	{
		struct
		{
			R2H_AD_CHANNEL_STARTUP_PARAM_T 	channel_startup_param;
		}startup_param;
		struct
		{
			R2H_UINT16 						process_upper_limit_alarm;
			R2H_UINT16 						process_lower_limit_alarm;
			R2H_UINT16 						rate_upper_limit_alarm;
			R2H_UINT16 						rate_lower_limit_alarm;
			R2H_UINT16 						signal_error_detection_flag;
			R2H_UINT16 						latest_alarm_code;
		}device_alarm_info;
		struct
		{
			R2H_UINT16 						latest_error_code;
		}device_error_info;
	};
}R2H_DLINK_ANALOG_IN_CONTROL_OUT_DATE_T;


typedef struct	R2H_DLINK_ANALOG_IN_CONTROL_IN_DATE
{
	R2H_BYTE 								host_handshake_byte;
	R2H_DLINK_ANALOG_IN_CONTROL_COMMAND_T	control_command;
	union
	{
		struct
		{
			R2H_INT32						channel_index;
		}read_startup_parameter;
		struct
		{
			R2H_ULONG						clear_timeout;
		}clear_device_error;
	};
}R2H_DLINK_ANALOG_IN_CONTROL_IN_DATE_T;



#pragma pack()



#endif /* R2H_TASK_DLINK_ANALOG_IN_HELPER_DEF_H_ */
