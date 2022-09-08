/*
 * r2h_extmodule_dnm_device_def.h
 *
 *  Created on: 2018-8-3
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_DNM_DEVICE_DEF_H_
#define R2H_EXTMODULE_DNM_DEVICE_DEF_H_

#include "../../r2h_extmodule_data_type.h"
#include "r2h_extmodule_dn_device_def.h"

#define R2H_DNM_SYNC_DATA_REFRESH_TASK_NAME									("R2H DNM Sync Data Refresh Task")

#pragma pack(2)
#define R2H_DNM_SLAVE_NODE_CAPACITY											(63)
#define R2H_DNM_NODE_CAPACITY												(64)

#define R2H_DNM_IO_RX_DATA_LENGTH_IN_WORD_MAX								(256)
#define R2H_DNM_IO_TX_DATA_LENGTH_IN_WORD_MAX								(256)


/*
1586 0632H Operation setting for bus
off error area
Sets whether to reset the CAN chip
(communication chip) of the RJ71DN91 to restart
the communication when a bus off error occurs.
The communication can be restarted even when a
value is changed after a bus off error occurs.


468 to 975 01D4H to 03CFH Master function
parameters*1
Sets the master function parameters.
*/




//Master Node Status
typedef enum R2H_DNM_DEVICE_IO_COMMUNICATION_STATUS
{
	R2H_DNM_DEVICE_IO_COMMUNICATION_OFFLINE		= 0x0000,
	R2H_DNM_DEVICE_IO_COMMUNICATION_STOP		= 0x0040,
	R2H_DNM_DEVICE_IO_COMMUNICATION_OPERATE		= 0x00C0,
	
	__R2H_DNM_DEVICE_IO_COMMUNICATION_STATUS	= 0xFFFFFFFF
}R2H_DNM_DEVICE_IO_COMMUNICATION_STATUS_T;

//Slave Node Information
typedef enum R2H_DNM_DEVICE_IO_COMMUNICATION_TYPE
{
	R2H_DNM_DEVICE_IO_COMMUNICATION_POLLING		= 0x0001,
	R2H_DNM_DEVICE_IO_COMMUNICATION_BIT_STROBE	= 0x0002,
	R2H_DNM_DEVICE_IO_COMMUNICATION_COS			= 0x0004,
	R2H_DNM_DEVICE_IO_COMMUNICATION_CYCLIC		= 0x0008,
	
	__R2H_DNM_DEVICE_IO_COMMUNICATION_TYPE 		= 0xFFFFFFFF
}R2H_DNM_DEVICE_IO_COMMUNICATION_TYPE_T;

typedef enum R2H_DNM_DEVICE_WATCHDOG_TIMEOUT_ACTION
{
	R2H_DNM_DEVICE_WATCHDOG_TIMEOUT_DEFAULT				= 0x0000,
	R2H_DNM_DEVICE_CONNECTION_TIMEOUT					= 0x0001,
	R2H_DNM_DEVICE_CONNECTION_AUTO_DELETE				= 0x0002,
	R2H_DNM_DEVICE_CONNECTION_AUTO_RESET				= 0x0003,
	__R2H_DNM_DEVICE_WATCHDOG_TIMEOUT_ACTION			= 0xFFFFFFFF
}R2H_DNM_DEVICE_WATCHDOG_TIMEOUT_ACTION_T;

typedef enum R2H_DNM_DEVICE_SLAVE_NODE_GROUP
{
	R2H_DNM_DEVICE_SLAVE_NODE_GROUP123_WITH_UCMM		= 0x01,
	R2H_DNM_DEVICE_SLAVE_NODE_GROUP1_WITH_UCMM			= 0x03,
	R2H_DNM_DEVICE_SLAVE_NODE_GROUP2_WITH_NO_UCMM		= 0x04,
	R2H_DNM_DEVICE_SLAVE_NODE_RESERVED					= 0x80,
	
	__R2H_DNM_DEVICE_SLAVE_NODE_GROUP					= 0xFFFFFFFF
}R2H_DNM_DEVICE_SLAVE_NODE_GROUP_T;

typedef enum R2H_DNM_DEVICE_MESSAGE_COMMAND
{
	R2H_DNM_DEVICE_MESSAGE_GET_ATTRIBUTE				= 0x0101,
	R2H_DNM_DEVICE_MESSAGE_SET_ATTRIBUTE				= 0x0102,
	R2H_DNM_DEVICE_MESSAGE_READ_ERROR_INFO				= 0x0001,
	R2H_DNM_DEVICE_MESSAGE_RESET						= 0x0201,
	
	R2H_DNM_DEVICE_MESSAGE_OTHER						= 0xFE00,
	
	__R2H_DNM_DEVICE_MESSAGE_COMMAND 					= 0xFFFFFFFF
}R2H_DNM_DEVICE_MESSAGE_COMMAND_T;


typedef struct __R2H_DNM_DEVICE_SLAVE_NODE_INFO
{
	R2H_BYTE			slave_node_address;
	R2H_BYTE			slave_message_group;
	R2H_UINT16			io_connection_type;
	R2H_BYTE			number_of_input_byte_modules;
	R2H_BYTE			number_of_output_byte_modules;
	R2H_BYTE			number_of_input_word_modules;
	R2H_BYTE			number_of_output_word_modules;
	R2H_BYTE			number_of_input_dword_modules;
	R2H_BYTE			number_of_output_dword_modules;
	R2H_UINT16			expected_packet_rate;
	R2H_UINT16			watchdog_timeout_action;
	R2H_UINT16			production_inhibit_time;
}__R2H_DNM_DEVICE_SLAVE_NODE_INFO_T;

#define R2H_DNM_DISABLE_IO_CONNECTION_WATCHDOG				(0)
#define R2H_DNM_DISABLE_COS_CYCLIC_TRANSMISSION				(0)


typedef struct R2H_DNM_DEVICE_SLAVE_NODE_PARAM
{
	R2H_BYTE											slave_node_address;
	R2H_DNM_DEVICE_SLAVE_NODE_GROUP_T					slave_node_group;
	R2H_DNM_DEVICE_IO_COMMUNICATION_TYPE_T				connection_type;
	R2H_DNM_DEVICE_WATCHDOG_TIMEOUT_ACTION_T			watchdog_timeout_action;
	R2H_BYTE											number_of_input_byte_modules;
	R2H_BYTE											number_of_output_byte_modules;
	R2H_BYTE											number_of_input_word_modules;
	R2H_BYTE											number_of_output_word_modules;
	R2H_BYTE											number_of_input_dword_modules;
	R2H_BYTE											number_of_output_dword_modules;
	union
	{
		struct
		{
			R2H_UINT16									slave_node_watchdog_time;
			R2H_UINT16									polling_request_cycle;
		}polling_param;
		struct
		{
			R2H_UINT16									slave_node_watchdog_time;
			R2H_UINT16									bit_strobe_request_cycle;
		}bit_strobe_param;
		struct
		{
			R2H_UINT16									slave_node_watchdog_time;
			R2H_UINT16									master_to_slave_transmit_cycle;
		}change_of_state_param;
		struct
		{
			R2H_UINT16									slave_to_master_transmit_cycle;	
			R2H_UINT16									master_to_slave_transmit_cycle;
		}cyclic_param;
	};
}R2H_DNM_DEVICE_SLAVE_NODE_PARAM_T;

typedef struct R2H_DNM_DEVICE_MASTER_NODE_PARAM
{
	R2H_UINT16											master_constant_scan_interval;
	R2H_DN_DEVICE_OPERATION_FOR_BUS_ERROR_T				operation_setting_for_bus_error;
}R2H_DNM_DEVICE_MASTER_NODE_PARAM_T;

#define R2H_DNM_MESSAGE_DATA_LENGTH_IN_BYTE_MIN			(0)
#define R2H_DNM_MESSAGE_DATA_LENGTH_IN_BYTE_MAX			(240)
#define R2H_DNM_MESSAGE_COM_EXECUTION_NO_ERROR			(0)
typedef struct R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_COMMAND
{
	R2H_UINT16											command_number;
	R2H_BYTE											slave_node_address;
	R2H_BYTE											object_class_id;
	R2H_UINT16											object_instance_id;
	R2H_BYTE											object_attribute_id;
	R2H_BYTE											command_data_length;
}R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_COMMAND_T;

typedef struct R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_RESULT
{
	R2H_UINT16											command_number;
	R2H_UINT16											execution_error_code;
	R2H_BYTE											slave_node_address;
	R2H_BYTE											object_class_id;
	R2H_UINT16											object_instance_id;
	R2H_BYTE											object_attribute_id;
	R2H_BYTE											command_data_length;
}R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_RESULT_T;


typedef struct R2H_DNM_DEVICE_SLAVE_NODE_DIAGNOSTIC_INFO
{
	struct
	{
		R2H_UINT16										not_respond							: 1;
		R2H_UINT16										used_by_system_1					: 1;
		R2H_UINT16										attr_write_access_denied			: 1;
		R2H_UINT16										io_data_set_inconsistence			: 1;
		R2H_UINT16										used_by_system_4					: 1;
		R2H_UINT16										used_by_system_5					: 1;
		R2H_UINT16										used_by_system_6					: 1;
		R2H_UINT16										reserved_node						: 1;
		R2H_UINT16										used_by_system_8					: 1;
		R2H_UINT16										used_by_system_9					: 1;
		R2H_UINT16										used_by_system_10					: 1;
		R2H_UINT16										used_by_system_11					: 1;
		R2H_UINT16										used_by_system_12					: 1;
		R2H_UINT16										used_by_system_13					: 1;
		R2H_UINT16										used_by_system_14					: 1;
		R2H_UINT16										used_by_system_15					: 1;
	}slave_status;
	R2H_UINT16											dummy1;
	R2H_UINT16											communication_error_code;
	R2H_UINT16											general_dnet_error_code;
	R2H_UINT16											additional_error_code;
	R2H_UINT16											number_of_heartbeat_timeout;
}R2H_DNM_DEVICE_SLAVE_NODE_DIAGNOSTIC_INFO_T;

typedef struct R2H_DNM_DEVICE_MASTER_NODE_DIAGNOSTIC_INFO
{
	//R2H_UINT16											master_communication_status;
	R2H_UINT16											master_communication_error_code;
	R2H_UINT16											bus_error_counter;
	R2H_UINT16											bus_off_counter;
	R2H_UINT16											node_configuration_status[4];
	R2H_UINT16											dummy8[4];
	R2H_UINT16											node_io_com_status[4];
	R2H_UINT16											node_io_com_err_status[4];
	R2H_UINT16											node_diagnostic_info_status[4];
}R2H_DNM_DEVICE_MASTER_NODE_DIAGNOSTIC_INFO_T;


typedef union R2H_DNM_DEVICE_X_STATUS
{
	struct
	{
		R2H_UINT16										watchdog_timer_error 				: 1;
		R2H_UINT16										io_communicating 					: 1;
		R2H_UINT16										message_communication_completion 	: 1;
		R2H_UINT16										master_function_error_set_signal 	: 1;
		R2H_UINT16										slave_down_signal 					: 1;
		R2H_UINT16										message_communication_error 		: 1;
		R2H_UINT16										parameter_saving 					: 1;
		R2H_UINT16										parameter_save_completion 			: 1;
		R2H_UINT16 										slave_function_error_set_signal		: 1;
		R2H_UINT16 										prohibited09						: 1;
		R2H_UINT16										hardware_testing					: 1;
		R2H_UINT16										hardware_test_completion			: 1;
		R2H_UINT16										hardware_test_error_detection		: 1;
		R2H_UINT16										prohibited13						: 1;
		R2H_UINT16										prohibited14						: 1;
		R2H_UINT16										module_ready						: 1;
	};
	R2H_UINT16											x_status;
}R2H_DNM_DEVICE_X_STATUS_T;

typedef union R2H_DNM_DEVICE_NETWORK_STATUS
{
	struct
	{
		R2H_BYTE										node_communication_error 			: 1;
		R2H_BYTE										dummy1 								: 1;
		R2H_BYTE										parameter_error 					: 1;
		R2H_BYTE										network_serious_problem 			: 1;
		R2H_BYTE										dummy4 								: 1;
		R2H_BYTE										dummy5 								: 1;
		R2H_BYTE										dummy6 								: 1;
		R2H_BYTE										dummy7 								: 1;
	};
	R2H_BYTE											network_status;
}R2H_DNM_DEVICE_NETWORK_STATUS_T;


#pragma pack()

#endif /* R2H_EXTMODULE_DNM_DEVICE_DEF_H_ */
