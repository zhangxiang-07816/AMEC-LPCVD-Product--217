/*
 * r2h_ethmodule_serial_port_server_def.h
 *
 *  Created on: Jul 3, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_ETHMODULE_SERIAL_PORT_SERVER_DEF_H_
#define R2H_ETHMODULE_SERIAL_PORT_SERVER_DEF_H_

#include "../r2h_ethmodule_data_type.h"

#define SERIAL_PORT_SERVER_SLV_DEVICE_NODES (32)

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_INFO
{
	R2H_CHAR					remote_ip[R2H_IP4_STR_SIZE];
	R2H_UINT16					remote_port;
	R2H_UINT32					sync_priority;
	R2H_INT32					timer_index;
	R2H_INT32					timeout;
	R2H_INT32					interval;
	R2H_UINT16					tx_size_in_byte;
	R2H_UINT16					rx_size_in_byte;
}__attribute__((packed))R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_INFO_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_DIAG
{
	R2H_BYTE					connection_status;
	R2H_BYTE					sde_exception_code;
	R2H_UINT32					interval;
	R2H_UINT32					interval_min;
	R2H_UINT32					interval_max;
}__attribute__((packed))R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_DIAG_T;

typedef enum R2H_ETHMODULE_SERIAL_PORT_SERVER_CONNECTION
{
	PORT_SERVER_NOT_CONNECTED				= 0x00,
	PORT_SERVER_CONNECTED					= 0x01,
	PORT_SERVER_CONNECTED_WITH_EXCEPTION	= 0x02,
	PORT_SERVER_SYNC_TASK_TERMINATED		= 0x03
}R2H_ETHMODULE_SERIAL_PORT_SERVER_CONNECTION_T;

typedef enum R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_EXP
{
	PORT_SERVER_SLV_NO_EXCEPTION						= 0x0000,
	PORT_SERVER_SLV_PROTOCOL_SPECIFIC					= (0xFF00),
	PORT_SERVER_SLV_COMMUNICATION_ERROR					= (0x0100),
	PORT_SERVER_SLV_PORT_DRIVER_EXCEPTION				= (0x0200),
	PORT_SERVER_SLV_MEMORY_ACCESS_OUT_OF_RANGE			= (0x0300)
}R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_EXP_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_INFO
{
	R2H_BYTE					port_id;
	R2H_BYTE					unit_id;
	R2H_BYTE					model;
	R2H_BYTE					instance;
	R2H_UINT16					rx_start;
	R2H_UINT16					rx_size;
	R2H_UINT16					tx_start;
	R2H_UINT16					tx_size;
	R2H_INT32					wtimeout;
	R2H_INT32					rtimeout;
	R2H_INT32					prohibit;
}__attribute__((packed)) R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_INFO_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_INFO
{
	R2H_CHAR										cookie[3];
	R2H_CHAR										server_name[16];
	R2H_BYTE										version;
	R2H_BYTE										revision;
	R2H_BYTE										number_of_serial_port_devices;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_INFO_T		serial_devices_info[SERIAL_PORT_SERVER_SLV_DEVICE_NODES];
}__attribute__((packed))R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_INFO_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_DIAG
{
	R2H_UINT16										exception;
	R2H_UINT32										ulast_access;
	R2H_UINT32										uacess_interval;
	R2H_UINT32										uacess_interval_max;
	R2H_UINT32										uacess_interval_min;
}__attribute__((packed)) R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_DIAG_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG
{
	R2H_UINT16										server_status;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_DIAG_T		serial_devices_status[SERIAL_PORT_SERVER_SLV_DEVICE_NODES];
}__attribute__((packed)) R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_AREA
{
	R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_INFO_T	remote_info;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_T	remote_diag;
}__attribute__((packed)) R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_AREA_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO
{
	R2H_UINT16			offset_in_byte;
	R2H_UINT16			size_in_byte;
}__attribute__((packed)) R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T;

typedef struct R2H_ETHMODULE_SERIAL_PORT_SERVER_SLVS_PDO
{
	R2H_UINT16									address;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T 	rx_pdo;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T 	tx_pdo;
}R2H_ETHMODULE_SERIAL_PORT_SERVER_SLVS_PDO_T;


#endif /* R2H_ETHMODULE_SERIAL_PORT_SERVER_DEF_H_ */
