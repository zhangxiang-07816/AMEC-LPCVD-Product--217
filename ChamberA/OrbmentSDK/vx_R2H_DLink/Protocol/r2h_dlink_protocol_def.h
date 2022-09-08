/*
 * r2h_dlink_protocol_def.h
 *
 *  Created on: 2017-7-19
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_PROTOCOL_DEF_H_
#define R2H_DLINK_PROTOCOL_DEF_H_

namespace R2H_DLINK
{

#define R2H_DLINK_PROTOCOL_FLAG_INFO			("CYB")
#define R2H_DLINK_PROTOCOL_FLAG_SIZE			(3)

#define R2H_DLINK_PROTOCOL_FUNC_RESPONSE_FLAG 			(0x80)
typedef enum R2H_DLINK_PROTOCOL_FUNC_CODE
{
	R2H_H_FUNC_WRITE = 0x01,
	R2H_H_FUNC_READ = 0x02
}R2H_DLINK_PROTOCOL_FUNC_CODE_T;

//#pragma pack(push, 1)
#pragma pack(1)

typedef struct R2H_DLINK_PROTOCOL_HEAD
{
	R2H_BYTE 		transIndex;
	R2H_CHAR		protocolFlag[R2H_DLINK_PROTOCOL_FLAG_SIZE];
}R2H_DLINK_PROTOCOL_HEAD_T;

typedef struct R2H_DLINK_PROTOCOL_FUNCTION_HEAD
{
	R2H_BYTE 		function;
}R2H_DLINK_PROTOCOL_FUNCTION_HEAD_T;

typedef struct R2H_DLINK_FUNC_WRITE_REQUEST_HEAD
{
	R2H_BYTE 		r_memory_segment;
	R2H_UINT32 		r_memory_start_addr;
	R2H_UINT32 		r_memory_length;
	//R2H_BYTE*		r_memory_data;
}R2H_DLINK_FUNC_WRITE_REQUEST_HEAD_T;

typedef struct R2H_DLINK_FUNC_WRITE_RESPONSE_HEAD
{
	R2H_BYTE 		r_memory_segment;
	R2H_UINT32 		r_memory_start_addr;
	R2H_UINT32 		r_memory_length;
	R2H_UINT16		r_memory_exception_code;
}R2H_DLINK_FUNC_WRITE_RESPONSE_HEAD_T;

typedef struct R2H_DLINK_FUNC_READ_REQUEST_HEAD
{
	R2H_BYTE 		r_memory_segment;
	R2H_UINT32 		r_memory_start_addr;
	R2H_UINT32 		r_memory_length;
}R2H_DLINK_FUNC_READ_REQUEST_HEAD_T;

typedef struct R2H_DLINK_FUNC_READ_RESPONSE_HEAD
{
	R2H_BYTE 		r_memory_segment;
	R2H_UINT32 		r_memory_start_addr;
	R2H_UINT32 		r_memory_length;
	R2H_UINT16		r_memory_exception_code;
}R2H_DLINK_FUNC_READ_RESPONSE_HEAD_T;


typedef struct R2H_DLINK_PROTOCOL_FRAME
{
	R2H_DLINK_PROTOCOL_HEAD_T protocol_head;
	R2H_DLINK_PROTOCOL_FUNCTION_HEAD_T function_head;
	union
	{
		R2H_DLINK_FUNC_WRITE_REQUEST_HEAD_T 	write_request_head;
		R2H_DLINK_FUNC_WRITE_RESPONSE_HEAD_T 	write_response_head;
		R2H_DLINK_FUNC_READ_REQUEST_HEAD_T		read_request_head;
		R2H_DLINK_FUNC_READ_RESPONSE_HEAD_T		read_response_head;

	};
}R2H_DLINK_PROTOCOL_FRAME_T;

#pragma pack()
//#pragma pack(pop)

//typedef void (*OnHostReadRequest)();
}

#endif /* R2H_DLINK_PROTOCOL_DEF_H_ */
