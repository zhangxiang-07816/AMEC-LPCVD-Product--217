/*
 * r2h_task_dlink_smart_ecat_helper_def.h
 *
 *  Created on: 2018-11-6
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SMART_ECAT_HELPER_DEF_H_
#define R2H_TASK_DLINK_SMART_ECAT_HELPER_DEF_H_

#include "../../../r2h_task_data_type.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/r2h_extmodule_smart_ecat_device_def.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/R12CCPU/r2h_extmodule_r12ccpu_ecat_device_buffer_address.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/RD55UPx/r2h_extmodule_rd55up_ecat_device_buffer_address.h"

#if R2H_R12CCPU_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD > R2H_RD55UP_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD
#define R2H_SMART_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD R2H_R12CCPU_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD
#else
#define R2H_SMART_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD R2H_RD55UP_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD
#endif

#if R2H_R12CCPU_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD > R2H_RD55UP_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD
#define R2H_SMART_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD R2H_R12CCPU_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD
#else
#define R2H_SMART_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD R2H_RD55UP_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD
#endif

#if R2H_RD55UP_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE > R2H_R12CCPU_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE
#define R2H_SMART_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE R2H_RD55UP_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE
#else
#define R2H_SMART_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE R2H_R12CCPU_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE
#endif

#pragma pack(2)

typedef enum R2H_DLINK_SMART_MODEL_TYPE
{
	R12CCPU,
	RD55,
}R2H_DLINK_SMART_MODEL_TYPE_T;

typedef struct R2H_DLINK_SMART_ECAT_PDO_REFRESH_RANGE
{
	R2H_UINT16 												tx_pdo_offset_in_word; 
	R2H_UINT16 												tx_pdo_size_in_word;
	R2H_UINT16 												read_data_size_in_word;
	R2H_UINT16 												rx_pdo_offset_in_word;
	R2H_UINT16 												rx_pdo_size_in_word;
	R2H_UINT16 												write_data_size_in_word;
}R2H_DLINK_SMART_ECAT_PDO_REFRESH_RANGE_T;

typedef struct R2H_DLINK_SMART_ECAT_PROCESS_IN_DATE
{
	R2H_SMART_ECAT_DEVICE_MASTER_DIAGNOSTIC_INFO			diagnostic_info;
	R2H_UINT16 												tx_pdo_data[R2H_SMART_ECAT_DEVICE_MAX_INPUT_DATA_SIZE_IN_WORD];
}R2H_DLINK_SMART_ECAT_PROCESS_IN_DATE_T;

typedef struct R2H_DLINK_SMART_ECAT_PROCESS_OUT_DATE
{
	R2H_UINT16 												rx_pdo_data[R2H_SMART_ECAT_HOST_MAX_OUTPUT_DATA_SIZE_IN_WORD];
}R2H_DLINK_SMART_ECAT_PROCESS_OUT_DATE_T;

typedef enum R2H_DLINK_SMART_ECAT_CONTROL_COMMAND
{
	R2H_DLINK_SMART_ECAT_CONTROL_UPLOAD_SDO					= 0x00000001,
	R2H_DLINK_SMART_ECAT_CONTROL_DOWNLOAD_SDO 				= 0x00000002,
	R2H_DLINK_SMART_ECAT_CONTROL_BUILD_INDEX 				= 0x00000003,
	//R2H_DLINK_SMART_ECAT_CONTROL_READ_DIAG_INFO 			= 0x00000004,
	R2H_DLINK_SMART_ECAT_CONTROL_READ_PDO_INFO 				= 0x00000005,
	R2H_DLINK_SMART_ECAT_CONTROL_READ_SLAVE_ERROR 			= 0x00000006,
	R2H_DLINK_SMART_ECAT_CONTROL_READ_PDO_INFO_BY_ADDR 		= 0x00000007,
	R2H_DLINK_SMART_ECAT_CONTROL_READ_SLAVE_ERROR_BY_ADDR 	= 0x00000008,
	
	__R2H_DLINK_SMART_ECAT_CONTROL_COMMAND					= 0xFFFFFFFF
}R2H_DLINK_SMART_ECAT_CONTROL_COMMAND_T;

typedef struct R2H_DLINK_SMART_ECAT_CONTROL_IN_DATE
{
	R2H_BYTE 												host_handshake_byte;
	R2H_DLINK_SMART_ECAT_CONTROL_COMMAND_T					control_command;
	union 
	{
		struct
		{
			R2H_ULONG 										timeout;
			R2H_UINT16										slave_address;
			R2H_UINT16										object_index;
			R2H_UINT16										object_sub_index;
		}upload_sdo;
		struct
		{
			R2H_ULONG 										timeout;
			R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T				sdo;
		}download_sdo;
		struct
		{
			R2H_ULONG 										timeout;
		}build_slave_node_index;
		/*
		struct
		{
		}read_master_diagnostic_info;
		*/
		struct
		{
			R2H_UINT16										slave_node_index;
		}read_slave_pdo_info;
		struct
		{
			R2H_UINT16 										slave_node_index;
		}read_slave_error_code;
		struct
		{
			R2H_UINT16 										slave_node_address;
		}read_slave_pdo_info_by_addr;
		struct
		{
			R2H_UINT16 										slave_node_address;
		}read_slave_error_code_by_addr;
	};
}R2H_DLINK_SMART_ECAT_CONTROL_IN_DATE_T;

typedef struct R2H_DLINK_SMART_ECAT_CONTROL_OUT_DATE
{
	R2H_BYTE 												device_handshake_byte;
	R2H_INT32												control_result;
	union 
	{
		struct
		{
			R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T				sdo;
		}upload_sdo;
		struct
		{
		}download_sdo;
		/*
		struct
		{
			R2H_SMART_ECAT_DEVICE_MASTER_DIAGNOSTIC_INFO	info;
		}read_master_diagnostic_info;
		*/
		struct
		{
			R2H_UINT16 										slave_node_address;
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T 		slave_node_tx_pdo_info;
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T 		slave_node_rx_pdo_info;
		}read_slave_pdo_info;
		struct
		{
			R2H_UINT16 										slave_node_address;
			R2H_UINT16 										slave_node_error_code;
		}read_slave_error_code;
		struct
		{
			R2H_UINT16 										slave_node_index;
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T 		slave_node_tx_pdo_info;
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T 		slave_node_rx_pdo_info;
		}read_slave_pdo_info_by_addr;
		struct
		{
			R2H_UINT16 										slave_node_index;
			R2H_UINT16 										slave_node_error_code;
		}read_slave_error_code_by_addr;
	};
}R2H_DLINK_SMART_ECAT_CONTROL_OUT_DATE_T;

#pragma pack()



#endif /* R2H_TASK_DLINK_SMART_ECAT_HELPER_DEF_H_ */
