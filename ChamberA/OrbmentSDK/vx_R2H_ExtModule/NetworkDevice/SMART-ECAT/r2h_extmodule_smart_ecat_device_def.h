/*
 * r2h_extmodule_smart_ecat_device_def.h
 *
 *  Created on: 2018-11-1
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_SMART_ECAT_DEVICE_DEF_H_
#define R2H_EXTMODULE_SMART_ECAT_DEVICE_DEF_H_

#include "../../r2h_extmodule_data_type.h" 

#pragma pack(2)

typedef enum R2H_SMART_ECAT_HOST_SDO_COMMAND
{
	R2H_SMART_ECAT_HOST_SDO_NO_COMMAND	 						= 0x0000,
	R2H_SMART_ECAT_HOST_SDO_UPLOAD_COMMAND 						= 0x0001,
	R2H_SMART_ECAT_HOST_SDO_DOWNLOAD_COMMAND					= 0x0002
}R2H_SMART_ECAT_HOST_SDO_COMMAND_T;

typedef struct __attribute__((__aligned__((2)))) R2H_SMART_ECAT_DEVICE_MASTER_DIAGNOSTIC_INFO
{
	R2H_UINT16			slave_node_number;
	R2H_UINT16			configuration_status;
	R2H_UINT16			communication_status;
	R2H_UINT16			reserved03;
	R2H_UINT32			communication_time_max;
	R2H_UINT16			reserved06;
	R2H_UINT16			reservde07;
	R2H_UINT32			communication_time_current;
	R2H_UINT32			event_code;
	R2H_UINT16			event_information[4];
	R2H_UINT16			user_control_command_response;
	R2H_UINT16			reservde17;
	R2H_UINT16			reservde18;
	R2H_UINT16			reservde19;
	R2H_UINT16			reservde20;
	R2H_UINT16			reservde21;
	R2H_UINT16			reservde22;
	R2H_UINT16			reservde23;
	R2H_UINT16			reservde24;
	R2H_UINT16			reservde25;
	R2H_UINT16			reservde26;
	R2H_UINT16			reservde27;
	R2H_UINT16			reservde28;
	R2H_UINT16			reservde29;
	R2H_UINT16			reservde30;
	R2H_UINT16			reservde31;
}R2H_SMART_ECAT_DEVICE_MASTER_DIAGNOSTIC_INFO_T;

typedef struct __attribute__((__aligned__((2)))) R2H_SMART_ECAT_HOST_MASTER_CONTROL_INFO
{
	R2H_UINT16			reservde0;
	R2H_UINT16			reservde1;
	R2H_UINT16			reservde2;
	R2H_UINT16			reservde3;
	R2H_UINT16			reservde4;
	R2H_UINT16			reservde5;
	R2H_UINT16			reservde6;
	R2H_UINT16			reservde7;
	R2H_UINT16			reservde8;
	R2H_UINT16			reservde9;
	R2H_UINT16			reservde10;
	R2H_UINT16			reservde11;
	R2H_UINT16			reservde12;
	R2H_UINT16			reservde13;
	R2H_UINT16			reservde14;
	R2H_UINT16			reservde15;
	R2H_UINT16			user_control_command_code;
	R2H_UINT16			reservde17;
	R2H_UINT16			reservde18;
	R2H_UINT16			reservde19;
	R2H_UINT16			reservde20;
	R2H_UINT16			reservde21;
	R2H_UINT16			reservde22;
	R2H_UINT16			reservde23;
	R2H_UINT16			reservde24;
	R2H_UINT16			reservde25;
	R2H_UINT16			reservde26;
	R2H_UINT16			reservde27;
	R2H_UINT16			reservde28;
	R2H_UINT16			reservde29;
	R2H_UINT16			reservde30;
	R2H_UINT16			reservde31;
}R2H_SMART_ECAT_HOST_MASTER_CONTROL_INFO_T;

typedef enum R2H_SMART_ECAT_CONTROL_COMMAND
{
	R2H_SMART_ECAT_CONTROL_NO_COMMAND						= 0x0000,
	R2H_SMART_ECAT_CONTROL_STOP_COMMUNICATION_REQUEST		= 0x0001,
	R2H_SMART_ECAT_CONTROL_CLEAR_EVENT_INFORMATION			= 0x0002
}R2H_SMART_ECAT_CONTROL_COMMAND_T;

typedef enum R2H_SMART_ECAT_CONFIGURATION_STATUS
{
	R2H_SMART_ECAT_CONFIGURATION_NOT_COMPLETED				= 0x0000,
	R2H_SMART_ECAT_CONFIGURATION_COMPLETED					= 0x0001			
}R2H_SMART_ECAT_CONFIGURATION_STATUS_T;

typedef enum R2H_SMART_ECAT_COMMUNICATION_STATUS
{
	R2H_SMART_ECAT_COMMUNICATION_NOT_START					= 0x0000,
	R2H_SMART_ECAT_COMMUNICATING							= 0x0001,
	R2H_SMART_ECAT_DISCONNECTION							= 0x0002,
}R2H_SMART_ECATCOMMUNICATION_STATUS_T;

typedef enum R2H_SMART_ECAT_NETWORK_OPERATION_STATUS
{
	R2H_SMART_ECAT_NETWORK_OPERATION_INIT					= 0x00000001,
	R2H_SMART_ECAT_NETWORK_OPERATION_PREOP					= 0x00000002,
	R2H_SMART_ECAT_NETWORK_OPERATION_SAFEOP					= 0x00000004,
	R2H_SMART_ECAT_NETWORK_OPERATION_OP						= 0x00000008,
	
	__R2H_SMART_NETWORK_ECAT_OPERATION_STATUS				= 0xFFFFFFFF
}R2H_SMART_ECAT_NETWORK_OPERATION_STATUS_T;

typedef enum R2H_SMART_ECAT_SLAVE_INIT_COMMAND_ERROR_TYPE
{
	R2H_SMART_ECAT_SLAVE_INIT_COMMAND_NO_RESPONSE			= 0x00000001,
	R2H_SMART_ECAT_SLAVE_INIT_COMMAND_VALIDATION_ERROR		= 0x00000002,
	R2H_SMART_ECAT_SLAVE_INIT_COMMAND_FAILED				= 0x00000003,
	
	__R2H_SMART_ECAT_SLAVE_INIT_COMMAND_ERROR_TYPE			= 0xFFFFFFFF
}R2H_SMART_ECAT_SLAVE_INIT_COMMAND_ERROR_TYPE_T;

typedef enum R2H_SMART_ECAT_EVENT_CODE
{
	R2H_SMART_ECAT_OPERATION_STATUS_CHANGE					= 0x00000001,
	R2H_SMART_ECAT_BUS_MISMATCH								= 0x00001001,
	R2H_SMART_ECAT_ALIAS_ADDRESS_OVERLAPPED					= 0x00001002,
	R2H_SMART_ECAT_CABLE_DISCONNECTION						= 0x00001003,
	R2H_SMART_ECAT_WORKING_COUNTER_ERROR					= 0x00010001,
	R2H_SMART_ECAT_SLAVE_INIT_COMMAND_ERROR					= 0x0001000B,
	R2H_SMART_ECAT_NOT_ALL_SLAVE_IS_OP						= 0x0001000F,
	R2H_SMART_ECAT_LINK_CONNECTION_ERROR					= 0x00010010,
	R2H_SMART_ECAT_SLAVE_ERROR_INFORMATION					= 0x00010014,
	R2H_SMART_ECAT_COE_SDO_ABORT							= 0x00010019,
	R2H_SMART_ECAT_PDI_WATCHDOG_EXPIRED_ON_SLAVE			= 0x0001001E,
	R2H_SMART_ECAT_HC_GROUP_DETECTION_AT_BOOT				= 0x00040002,
	R2H_SMART_ECAT_HC_GROUP_DETECTION_AT_RUNNING			= 0x00040003,
	R2H_SMART_ECAT_HC_GROUP_TOPOLOGY_CHANGE_COMPLETION		= 0x00040004,
	R2H_SMART_ECAT_HC_GROUP_SLAVE_REMOVED					= 0x00040005,
	R2H_SMART_ECAT_HC_GROUP_SLAVE_ADDED						= 0x00040006
}R2H_SMART_ECAT_EVENT_CODE_T;

typedef union R2H_SMART_ECAT_EVENT_INFO
{
	struct
	{
		R2H_UINT16							event_information[4];
	}raw_event_info;
	struct
	{
		R2H_SMART_ECAT_NETWORK_OPERATION_STATUS_T 	old_status;
		R2H_SMART_ECAT_NETWORK_OPERATION_STATUS_T 	new_status;
	}operataion_status_change;
	struct
	{
		R2H_UINT16 							phyical_address;
		R2H_UINT16 							alias_address;
	}bus_mismatch;
	struct
	{
		R2H_UINT16 							phyical_address_of_first_slave;
		R2H_UINT16 							phyical_address_of_second_slave;
	}alias_address_overlapped;
	struct
	{
		R2H_UINT32							adp_ado_address;
		R2H_UINT16							working_counter_set_value;
		R2H_UINT16							working_counter_actual_value;
	}working_counter_error;
	struct
	{
		R2H_SMART_ECAT_SLAVE_INIT_COMMAND_ERROR_TYPE_T	error_type;
		R2H_UINT16										slave_address;
	}slave_init_command_error;
	struct
	{
		R2H_UINT16							slave_address;
		R2H_UINT16							slave_al_status;
		R2H_UINT16							slave_al_control_status;
	}slave_error_information;
	struct
	{
		R2H_UINT32							error_code;
		R2H_UINT16							sdo_index;
		R2H_UINT16							sdo_sub_index;
	}coe_sdo_abort;
	struct
	{
		R2H_UINT16							slave_address;
	}pdi_watchdog_expired;
	struct
	{
		R2H_UINT32							result_code;
	}hc_group_detection_at_boot;
	struct
	{
		R2H_UINT32							result_code;
	}hc_group_detection_at_running;
	struct
	{
		R2H_UINT32							result_code;
	}hc_group_topology_change_completion;
	struct
	{
		R2H_UINT16							slave_address;
	}hc_group_slave_removed;
	struct
	{
		R2H_UINT16							slave_address;
	}hc_group_slave_added;
}R2H_SMART_ECAT_EVENT_INFO_T;



typedef enum R2H_SMART_ECAT_SLAVE_ERROR_CODE
{
	R2H_SMART_ECAT_SLAVE_NO_ERROR 							= 0x0000,
	R2H_SMART_ECAT_SLAVE_DISCONNECTION						= 0x0001,
	R2H_SMART_ECAT_SLAVE_NOT_OP								= 0x0002
}R2H_SMART_ECAT_SLAVE_ERROR_CODE_T;

//typedef __attribute__((__aligned__((2))))R2H_UINT16 		SMART_ECAT_DATA_REGISTER;

typedef struct __attribute__((__aligned__((2)))) R2H_SMART_ECAT_DEVICE_SDO_OBJECT
{
	R2H_UINT16			slave_address;
	R2H_UINT16			object_index;
	R2H_UINT16			object_sub_index;
	R2H_UINT32			data_size_in_byte;
	R2H_UINT16			data[40];
}R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T;

typedef struct __attribute__((__aligned__((2)))) R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO
{
	R2H_UINT16			slave_data_offset_in_word;
	R2H_UINT16			slave_data_size_in_bit;
}R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T;

typedef struct R2H_SMART_ECAT_DEVICE_INDEX_INFO
{
	R2H_UINT16								slave_address;
	R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T rx_index;
	R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T tx_index;
}R2H_SMART_ECAT_DEVICE_INDEX_INFO_T;


#pragma pack()


#endif /* R2H_EXTMODULE_SMART_ECAT_DEVICE_DEF_H_ */
