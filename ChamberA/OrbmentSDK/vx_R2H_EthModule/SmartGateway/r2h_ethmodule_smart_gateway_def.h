/*
 * r2h_ethmodule_smart_gateway_def.h
 *
 *  Created on: 2019-1-30
 *      Author: CrazyHein
 */

#ifndef R2H_ETHMODULE_SMART_GATEWAY_DEF_H_
#define R2H_ETHMODULE_SMART_GATEWAY_DEF_H_

#include "../r2h_ethmodule_data_type.h"
#include "../Socket/r2h_ethmodule_socket.h"

#define R2H_ETHMODULE_SMART_GATEWAY_DEVICE_DIAGNOSTIC_SIZE_IN_WORD		(1*256)
#define R2H_ETHMODULE_PC104_SERIAL_PORT_SERVER_MEMORY_SIZE_IN_WORD		(2*512)
#define R2H_ETHMODULE_SMART_GATEWAY_SYNC_DATA_REFRESH_TASK_NAME			("R2H Smart Gateway Sync Data Refresh Task")
#define R2H_ETHMODULE_SMART_GATEWAY_COOKIE_STRING						(R2H)

#pragma pack(2)

typedef struct R2H_ETHMODULE_SMART_GATEWAY_DEVICE_DIAGNOSTIC_INFO
{
	R2H_CHAR					cookie[4];
	R2H_CHAR					name[32];
	R2H_BYTE					firmware_version;
	R2H_BYTE					firmware_sub_version;
	R2H_UINT32					firmware_build_data;	//0x07222017
	R2H_INT32					memory_size_in_byte;
	R2H_UINT16					slave_device_model_id[32];
	R2H_UINT16					slave_device_port_address[32];
	R2H_UINT16					slave_device_io_instance[32];
	R2H_BYTE					slave_device_configuration_status[4];
	R2H_BYTE					slave_device_connection_status[4];
	R2H_INT32					slave_device_connection_error_code[32];
}R2H_ETHMODULE_SMART_GATEWAY_DEVICE_DIAGNOSTIC_INFO_T;

typedef struct R2H_ETHMODULE_SMART_GATEWAY_HOST_DIAGNOSTIC_INFO
{
	R2H_BYTE					device_connection_status;
	R2H_UINT32					interval;
	R2H_UINT32					max_interval;
	R2H_UINT32					min_interval;
	R2H_INT32					modbus_tcp_error_code;
	R2H_UINT16					host_actual_read_size_in_word;
	R2H_BYTE					host_read_exception_code;
	R2H_UINT16					host_actual_write_size_in_word;
	R2H_BYTE					host_write_exception_code;
}R2H_ETHMODULE_SMART_GATEWAY_HOST_DIAGNOSTIC_INFO_T;

typedef struct R2H_ETHMODULE_SMART_GATEWAY_HOST_BASIC_INFO
{
	R2H_UINT32					priority;
	R2H_CHAR					ip[R2H_IP4_STR_SIZE];
	R2H_UINT16					port;
	R2H_INT32					timeout;
	R2H_INT32					timer;
	R2H_UINT32					interval;
	R2H_UINT16					host_read_offset_in_word;
	R2H_UINT16					host_read_size_in_word;
	R2H_UINT16					host_write_offset_in_word;
	R2H_UINT16					host_write_size_in_word;
}R2H_ETHMODULE_SMART_GATEWAY_HOST_BASIC_INFO_T;

#pragma pack()

#endif /* R2H_ETHMODULE_SMART_GATEWAY_DEF_H_ */
