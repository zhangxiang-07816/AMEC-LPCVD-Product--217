/*
 * modbus_tcp_lite_def.h
 *
 *  Created on: 2019-1-31
 *      Author: CrazyHein
 */

#ifndef MODBUS_TCP_LITE_DEF_H_
#define MODBUS_TCP_LITE_DEF_H_

#include "../../../r2h_ethmodule_data_type.h"

namespace R2H_ETHMODULE_PROTOCOL_PACKAGE
{

#pragma pack(1)

typedef enum MODBUS_TCP_FUNCTION_CODE
{
	MODBUS_TCP_FUNCTION_READ_HOLDING_REGISTER 			= 0x03,
	MODBUS_TCP_FUNCTION_WRITE_MULTIPLE_REGISTER 		= 0x10
}MODBUS_TCP_FUNCTION_CODE_T;

typedef R2H_UINT16 MODBUS_TCP_HOLDING_REGISTER;

#define REGISTER_STOB(i)  ((R2H_UINT16)(((i)<<8) + ((i)>>8)))  
#define REGISTER_BTOS(i)  ((R2H_UINT16)(((i)<<8) + ((i)>>8))) 
#define MOD_TCP_REGISTER_MAX							(65535)
#define MOD_TCP_HOLDING_REGISTER_READ_MAX				(120)
#define MOD_TCP_MULTIPLE_REGISTER_WRITE_MAX				(120)

typedef struct MODBUS_TCP_APPLICATION_HEADER
{
	R2H_UINT16				transaction_identifier;
	R2H_UINT16				protocol_identifier;
	R2H_UINT16				message_length;
	R2H_BYTE				unit_identifier;
}MODBUS_TCP_APPLICATION_HEADER_T;

typedef struct MODBUS_TCP_PROCESS_DATA_UNIT
{
	union
	{
		struct
		{
			R2H_BYTE					function_code;
			R2H_UINT16					read_offset_in_register;
			R2H_UINT16					read_size_in_register;
		}read_holding_register_request;
		struct
		{
			R2H_BYTE					function_code;
			R2H_BYTE					read_size_in_byte;
		}read_holding_register_normal_response_header;
		struct
		{
			R2H_BYTE					function_code;
			R2H_BYTE					read_size_in_byte;
			MODBUS_TCP_HOLDING_REGISTER	register_array[MOD_TCP_HOLDING_REGISTER_READ_MAX];
		}read_holding_register_normal_response;
		struct
		{
			R2H_BYTE					function_code;
			R2H_BYTE					exception_code;
		}read_holding_register_exception_response;
		struct
		{
			R2H_BYTE					function_code;
			R2H_UINT16					write_offset_in_register;
			R2H_UINT16					write_size_in_register;
			R2H_BYTE					write_size_in_byte;
		}write_multiple_register_request_header;
		struct
		{
			R2H_BYTE					function_code;
			R2H_UINT16					write_offset_in_register;
			R2H_UINT16					write_size_in_register;
			R2H_BYTE					write_size_in_byte;
			MODBUS_TCP_HOLDING_REGISTER	register_array[MOD_TCP_MULTIPLE_REGISTER_WRITE_MAX];
		}write_multiple_register_request;
		struct
		{
			R2H_BYTE					function_code;
			R2H_UINT16					write_offset_in_register;
			R2H_UINT16					write_size_in_register;
		}write_multiple_register_normal_response;
		struct
		{
			R2H_BYTE					function_code;
			R2H_BYTE					exception_code;
		}write_multiple_register_exception_response;
	};	
}MODBUS_TCP_PROCESS_DATA_UNIT_T;

typedef struct MODBUS_TCP_APPLICATION_DATA_UNIT
{
	MODBUS_TCP_APPLICATION_HEADER_T ah;
	MODBUS_TCP_PROCESS_DATA_UNIT_T 	pdu;
}MODBUS_TCP_APPLICATION_DATA_UNIT_T;

#pragma pack()

}

#endif /* MODBUS_TCP_LITE_DEF_H_ */
