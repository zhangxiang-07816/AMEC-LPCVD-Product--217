/*
 * r2h_task_dlink_dnm_helper_def.h
 *
 *  Created on: 2018-9-5
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_DNM_HELPER_DEF_H_
#define R2H_TASK_DLINK_DNM_HELPER_DEF_H_

#include "../../../r2h_task_data_type.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/DeviceNet/r2h_extmodule_dnm_device_def.h"

#pragma pack(2)
typedef struct R2H_DLINK_DNM_MODEL_INFO
{
	R2H_DN_DEVICE_MODEL_NAME 							model_name;
	R2H_UINT16 											master_node_address;
	R2H_DN_DEVICE_MODE_SWITCH_T 						master_mode_switch;
}R2H_DLINK_DNM_MODEL_INFO_T;

typedef struct R2H_DLINK_DNM_MASTER_DIAGNOSTIC_INFO
{
	R2H_DNM_DEVICE_X_STATUS_T							x_status;
	R2H_DNM_DEVICE_IO_COMMUNICATION_STATUS_T			io_communication_status;
	R2H_DNM_DEVICE_NETWORK_STATUS_T						network_status;
	R2H_DNM_DEVICE_MASTER_NODE_DIAGNOSTIC_INFO_T		master_node_diagnostic_info;
}R2H_DLINK_DNM_MASTER_DIAGNOSTIC_INFO_T;

typedef struct R2H_DLINK_DNM_SCAN_TIME
{
	R2H_UINT16											current_link_scan_time;
	R2H_UINT16											minimum_link_scan_time;
	R2H_UINT16											maximum_link_scan_time;
}R2H_DLINK_DNM_SCAN_TIME_T;

typedef struct R2H_DLINK_DNM_PROCESS_IN_DATE
{
	R2H_DLINK_DNM_MODEL_INFO_T							model_info;
	R2H_DLINK_DNM_MASTER_DIAGNOSTIC_INFO_T				master_diagnostic_info;
	R2H_DLINK_DNM_SCAN_TIME_T							scan_time;
	R2H_UINT16											slave_production_data[R2H_DNM_IO_RX_DATA_LENGTH_IN_WORD_MAX];
}R2H_DLINK_DNM_PROCESS_IN_DATE_T;

typedef struct R2H_DLINK_DNM_PROCESS_OUT_DATE
{
	R2H_UINT16											slave_consumption_data[R2H_DNM_IO_TX_DATA_LENGTH_IN_WORD_MAX];
}R2H_DLINK_DNM_PROCESS_OUT_DATE_T;

typedef enum R2H_DLINK_DNM_CONTROL_COMMAND
{
	R2H_DLINK_DNM_CONTROL_START_IO_COMMUNICATION		= 0x00000001,
	R2H_DLINK_DNM_CONTROL_STOP_IO_COMMUNICATION 		= 0x00000002,
	R2H_DLINK_DNM_CONTROL_READ_SLAVE_ATTRIBUTE 			= 0x00000003,
	R2H_DLINK_DNM_CONTROL_WRITE_SLAVE_ATTRIBUTE 		= 0x00000004,
	R2H_DLINK_DNM_CONTROL_READ_SLAVE_DIAGNOSTIC_INFO	= 0x00000005,
	R2H_DLINK_DNM_CONTROL_READ_SLAVE_ERROR_CODE			= 0x00000006,
	R2H_DLINK_DNM_CONTROL_RESET_MASTER_FUNCTION_ERROR	= 0x00000007,
	
	R2H_DLINK_DNM_CONTROL_EXECUTE_CUSTOMIZED_MESSAGE	= 0x00000008,
	R2H_DLINK_DNM_CONTROL_SET_POLLING_ASSEMBLY_PATH		= 0x00000009,
	
	__R2H_DLINK_DNM_CONTROL_COMMAND						= 0xFFFFFFFF
}R2H_DLINK_DNM_CONTROL_COMMAND_T;

typedef struct R2H_DLINK_DNM_CONTROL_IN_DATE
{
	R2H_BYTE 												host_handshake_byte;
	R2H_DLINK_DNM_CONTROL_COMMAND_T							control_command;
	union 
	{
		struct
		{
			R2H_ULONG 										timeout;
		}start_io_communication;
		struct
		{
			R2H_ULONG 										timeout;
		}stop_io_communication;
		struct
		{
			R2H_ULONG 										timeout;
			R2H_BYTE 										slave_node_address;
			R2H_BYTE 										class_id; 
			R2H_UINT16 										instance_id;
			R2H_BYTE 										attribute_id;
		}read_slave_attribute;
		struct
		{
			R2H_ULONG 										timeout;
			R2H_BYTE 										slave_node_address;
			R2H_BYTE 										class_id; 
			R2H_UINT16 										instance_id;
			R2H_BYTE 										attribute_id;
			R2H_BYTE										buffer_data_size_in_byte;
			R2H_BYTE										data_buffer[R2H_DNM_MESSAGE_DATA_LENGTH_IN_BYTE_MAX];
		}write_slave_attribute;
		struct
		{
			R2H_ULONG 										timeout;
			R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_COMMAND	command;
			R2H_BYTE										data_buffer[R2H_DNM_MESSAGE_DATA_LENGTH_IN_BYTE_MAX];
		}execute_customized_message;
		struct 
		{
			R2H_ULONG 										timeout;
			R2H_BYTE 										master_node_address;
			R2H_BYTE 										slave_node_address;
			R2H_BYTE										produced_instance;
			R2H_BYTE										consumed_instance;
		}set_polling_assembly_path;
		struct
		{
			R2H_ULONG 										timeout;
			R2H_BYTE 										slave_node_address;
		}read_slave_diagnostic_info;
		struct
		{
			R2H_BYTE 										slave_node_address;
		}read_slave_error_code;
		struct
		{
			R2H_ULONG 										timeout;
		}reset_master_function_error;
	};
}R2H_DLINK_DNM_CONTROL_IN_DATE_T;

typedef struct R2H_DLINK_DNM_CONTROL_OUT_DATE
{
	R2H_BYTE 												device_handshake_byte;
	R2H_INT32												control_result;
	union
	{
		struct
		{
			R2H_UINT16										message_communication_error_code;
			R2H_BYTE										buffer_data_size_in_byte;
			R2H_BYTE										data_buffer[R2H_DNM_MESSAGE_DATA_LENGTH_IN_BYTE_MAX];
		}read_slave_attribute;
		struct
		{
			R2H_UINT16										message_communication_error_code;
			R2H_BYTE										write_data_size_in_byte;
		}write_slave_attribute;;
		struct
		{
			R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_RESULT		result;
			R2H_BYTE										data_buffer[R2H_DNM_MESSAGE_DATA_LENGTH_IN_BYTE_MAX];
		}execute_customized_message;
		struct 
		{
			R2H_UINT16										message_communication_error_code;
		}set_polling_assembly_path;
		struct
		{
			R2H_UINT16										message_communication_error_code;
			R2H_DNM_DEVICE_SLAVE_NODE_DIAGNOSTIC_INFO_T		info;
		}read_slave_diagnostic_info;
		struct
		{
			R2H_UINT16										error_code;
		}read_slave_error_code;
	};
}R2H_DLINK_DNM_CONTROL_OUT_DATE_T;

typedef struct R2H_DLINK_DNM_SLAVE_IO_DATA_REFRESH_RANGE
{
	R2H_UINT16 												production_data_offset_in_word; //master input
	R2H_UINT16 												production_data_size_in_word;
	R2H_UINT16 												read_data_size_in_word;
	R2H_UINT16 												consumption_data_offset_in_word;//master output
	R2H_UINT16 												consumption_data_size_in_word;
	R2H_UINT16 												write_data_size_in_word;
}R2H_DLINK_DNM_SLAVE_IO_DATA_REFRESH_RANGE_T;

typedef union R2H_DLINK_DNM_SIDE_BAND_CHANNEL_DATA
{
	R2H_UINT8						side_band_data_byte;
	R2H_INT8						side_band_data_sbyte;
	R2H_INT16						side_band_data_short;
	R2H_UINT16						side_band_data_ushort;
	R2H_INT32						side_band_data_int;
	R2H_UINT32						side_band_data_uint;
	R2H_FLOAT						side_band_data_float;
	R2H_DOUBLE						side_band_data_double;
	R2H_INT32						side_band_data_fp3201;
	R2H_INT32						side_band_data_fp3202;
	R2H_BYTE						side_band_data_raw[8];
}R2H_DLINK_DNM_SIDE_BAND_CHANNEL_DATA_T;

#pragma pack()

#endif /* R2H_TASK_DLINK_DNM_HELPER_DEF_H_ */
