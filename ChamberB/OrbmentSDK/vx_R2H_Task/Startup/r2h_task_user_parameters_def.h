/*
 * r2h_task_user_parameters_def.h
 *
 *  Created on: 2018-9-11
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_USER_PARAMETERS_DEF_H_
#define R2H_TASK_USER_PARAMETERS_DEF_H_

#include "../r2h_task_data_type.h"
#include "../../vx_R2H_ExtModule/BaseDevice/r2h_extmodule_base_device_def.h"
#include "../../vx_R2H_EthModule/SocketDevice/r2h_ethmodule_socket_device_def.h"
#include "../../vx_R2H_DLink/Utility/r2h_dlink_socket.h"
#include <vector>

#define R2H_TASK_PARAM_EXTENSION_MODULE_RESERVED_QUANTITY			(24)
#define R2H_TASK_PARAM_ETHERNET_MODULE_RESERVED_QUANTITY			(4)
#define R2H_TASK_PARAM_POSIX_PRIORITY_MAX							(255)
#define R2H_TASK_PARAM_POSIX_PRIORITY_MIN							(0)
#define R2H_TASK_PARAM_PERIODIC_TASK_PERIOD_TIME_IN_MS_MAX			(1000)
#define R2H_TASK_PARAM_PERIODIC_TASK_PERIOD_TIME_IN_MS_MIN			(5)

#pragma pack(1)
typedef enum R2H_TASK_PARAM_CLOCK_SOURCE
{
	R2H_TASK_PARAM_TIMER_CLOCK				= 0x0001,
	R2H_TASK_PARAM_INTER_MODULE_SYNC_CLOCK	= 0x0002
}R2H_TASK_PARAM_CLOCK_SOURCE_T;

typedef enum R2H_TASK_PARAM_EVENT_LOGGER
{
	R2H_TASK_PARAM_CCPU_LOGGER				= 0x0001
}R2H_TASK_PARAM_EVENT_LOGGER_T;

typedef struct R2H_TASK_PARAM_SUB_MODULE
{
	R2H_INT32									sub_id;
	R2H_INT32 									input_data_offset; //master input
	R2H_INT32 									input_data_size;
	R2H_INT32 									output_data_offset;//master output
	R2H_INT32 									output_data_size;
	
	R2H_TASK_PARAM_SUB_MODULE()
	{
		sub_id = 0;
		input_data_offset = 0;
		input_data_size = 0;
		output_data_offset = 0;
		output_data_size = 0;
	}
}R2H_TASK_PARAM_SUB_MODULE_T;

typedef struct R2H_TASK_PARAM_EXTENSION_MODULE
{
	R2H_EXTMODULE_DEVICE_MODEL_ID_T				id;
	R2H_UINT32									sw;
	R2H_UINT16									address;
	R2H_UINT16									bit_size;
	R2H_INT32 									extra_input_data_offset_in_word; //master input
	R2H_INT32 									extra_input_data_size_in_word;
	R2H_INT32 									extra_output_data_offset_in_word;//master output
	R2H_INT32 									extra_output_data_size_in_word;
	std::vector<R2H_TASK_PARAM_SUB_MODULE_T> 	*subs;
	
	R2H_TASK_PARAM_EXTENSION_MODULE()
	{
		subs = 0;
	}
}R2H_TASK_PARAM_EXTENSION_MODULE_T;

typedef struct R2H_TASK_PARAM_ETHERNET_MODULE
{
	R2H_ETHMODULE_DEVICE_MODEL_ID_T				id;
	R2H_UINT32									sw;
	R2H_CHAR									ip[INET_ADDRSTRLEN];
	R2H_UINT16 									port;
	R2H_INT32									timeout;
	R2H_INT32									timer;
	R2H_INT32									interval;
	R2H_UINT32									priority;
	R2H_INT32 									input_data_offset_in_word; 
	R2H_INT32 									input_data_size_in_word;
	R2H_INT32 									output_data_offset_in_word;
	R2H_INT32 									output_data_size_in_word;
	std::vector<R2H_TASK_PARAM_SUB_MODULE_T> 	*subs;
	
	R2H_TASK_PARAM_ETHERNET_MODULE()
	{
		timer = 16;
		interval = 100;
		priority = 10;
		input_data_offset_in_word = 0;
		input_data_size_in_word = 256;
		output_data_offset_in_word = 256;
		output_data_size_in_word = 256;
		subs = 0;
	}
}R2H_TASK_PARAM_ETHERNET_MODULE_T;

typedef struct R2H_TASK_PARAM_DEVICE_IO_SCAN
{
	R2H_UINT32									task_posix_priority;
	R2H_UINT32									task_period_in_ms;
	R2H_TASK_PARAM_CLOCK_SOURCE_T				task_clock_source;
	R2H_UINT32									task_stack_size_in_byte;
	R2H_TASK_PARAM_DEVICE_IO_SCAN()
	{
		task_posix_priority = 255-47;
		task_period_in_ms = 5;
		//task_clock_source = R2H_TASK_PARAM_TIMER_CLOCK;
		task_clock_source = R2H_TASK_PARAM_INTER_MODULE_SYNC_CLOCK;
		task_stack_size_in_byte = 0;
	}
}R2H_TASK_PARAM_DEVICE_IO_SCAN_T;

typedef struct R2H_TASK_PARAM_DEVICE_CONTROL
{
	R2H_UINT32									task_posix_priority;
	R2H_UINT32									task_period_in_ms;
	R2H_UINT32									task_stack_size_in_byte;
	R2H_TASK_PARAM_DEVICE_CONTROL()
	{
		task_posix_priority = 255-201;
		task_period_in_ms = 100;
		task_stack_size_in_byte = 0;
	}
}R2H_TASK_PARAM_DEVICE_CONTROL_T;

typedef struct R2H_TASK_PARAM_R2H_DLINK_SERVER
{
	R2H_UINT32									task_posix_priority;
	R2H_TCP_PORT								server_port;
	R2H_INT32									timeout_in_ms;
	R2H_TASK_PARAM_R2H_DLINK_SERVER()
	{
		task_posix_priority = 255-100;
		server_port = 8366;
		timeout_in_ms = 20000;
	}
}R2H_TASK_PARAM_R2H_DLINK_SERVER_T;

typedef struct R2H_TASK_PARAM_R2H_ILINK_SERVER
{
	R2H_UINT32									task_posix_priority;
	R2H_TCP_PORT								server_port;
	R2H_INT32									timeout_in_ms;
	R2H_TASK_PARAM_R2H_ILINK_SERVER()
	{
		task_posix_priority = 255-202;
		server_port = 8367;
		timeout_in_ms = 300000;
	}
}R2H_TASK_PARAM_R2H_ILINK_SERVER_T;

typedef struct R2H_TASK_PARAM_RECIPE_PARSER
{
	R2H_UINT32									task_posix_priority;
	R2H_TASK_PARAM_RECIPE_PARSER()
	{
		task_posix_priority = 255-210;
	}
}R2H_TASK_PARAM_RECIPE_PARSER_T;

#pragma pack()

#endif /* R2H_TASK_USER_PARAMETERS_DEF_H_ */
