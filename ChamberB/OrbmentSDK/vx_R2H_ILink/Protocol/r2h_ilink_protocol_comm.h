/*
 * r2h_ilink_protocol_comm.h
 *
 *  Created on: 2020-4-26
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_PROTOCOL_COMM_H_
#define R2H_ILINK_PROTOCOL_COMM_H_

namespace R2H_ILINK
{
#define PROTOCOL_FLAG_INFO						("ARK")
#define PROTOCOL_FLAG_SIZE						(3)

#define PROTOCOL_FUNC_RESPONSE_FLAG 			(0x80)

#define EOK										(OK)
#define R2H_ILINK_SERVER_THREAD_NAME_LENGTH		(64)
#define R2H_ILINK_SERVER_LISTEN_ROUTINE_NAME	("R2H ILink Server Listening Task")
#define R2H_ILINK_SERVER_WORK_ROUTINE_NAME		("R2H ILink Server Working Task")

typedef enum PROTOCOL_FUNC_CODE
{
	FUNC_RECIPE_DOWNLOAD						= 0x01,
	FUNC_RECIPE_ECHO 							= 0x02,
	FUNC_RECIPE_CLEAR							= 0x03
}PROTOCOL_FUNC_CODE_T;

typedef enum PROTOCOL_RECIPE_SEGMENT
{
	RECIPE_GLOBAL_EVENT							= 0x01,
	RECIPE_SCROLL								= 0x03,
	RECIPE_STEP									= 0x04,
	RECIPE_EXCEPTION							= 0x05, //Reliability Availability Serviceability	
}PROTOCOL_RECIPE_SEGMENT_T;

#pragma pack(1)

typedef struct PROTOCOL_HEAD
{
	R2H_BYTE 									transIndex;
	R2H_CHAR									protocolFlag[PROTOCOL_FLAG_SIZE];
}PROTOCOL_HEAD_T;

typedef struct PROTOCOL_FUNCTION_HEAD
{
	R2H_BYTE 									function;
}PROTOCOL_FUNCTION_HEAD_T;

typedef struct RECIPE_DOWNLOAD_REQUEST_HEAD
{
	R2H_BYTE 									recipe_segment;
	R2H_UINT32 									content_size_in_byte;
}RECIPE_DOWNLOAD_REQUEST_HEAD_T;

typedef struct RECIPE_DOWNLOAD_RESPONSE_HEAD
{
	R2H_BYTE 									recipe_segment;
	R2H_UINT32 									content_size_in_byte;
	R2H_INT32									exception;
}RECIPE_DOWNLOAD_RESPONSE_HEAD_T;

typedef struct RECIPE_ECHO_REQUEST_HEAD
{
	R2H_BYTE 									recipe_segment;
	R2H_UINT32 									start_index;
	R2H_UINT32 									end_index;
}RECIPE_ECHO_REQUEST_HEAD_T;

typedef struct RECIPE_ECHO_RESPONSE_HEAD
{
	R2H_BYTE 									recipe_segment;
	R2H_UINT32 									start_index;
	R2H_UINT32 									end_index;
	R2H_INT32									exception;
	R2H_UINT32 									content_size_in_byte;
}RECIPE_ECHO_RESPONSE_HEAD_T;

typedef struct RECIPE_CLEAR_REQUEST_HEAD
{
	R2H_BYTE 									recipe_segment;
	R2H_UINT32 									start_index;
	R2H_UINT32 									end_index;
}RECIPE_CLEAR_REQUEST_HEAD_T;

typedef struct RECIPE_CLEAR_RESPONSE_HEAD
{
	R2H_BYTE 									recipe_segment;
	R2H_UINT32 									start_index;
	R2H_UINT32 									end_index;
	R2H_INT32									exception;
}RECIPE_CLEAR_RESPONSE_HEAD_T;


typedef struct PROTOCOL_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	union
	{
		RECIPE_DOWNLOAD_REQUEST_HEAD_T 			download_request_head;
		RECIPE_DOWNLOAD_RESPONSE_HEAD_T 		download_response_head;
		RECIPE_ECHO_REQUEST_HEAD_T				echo_request_head;
		RECIPE_ECHO_RESPONSE_HEAD_T				echo_response_head;
		RECIPE_CLEAR_REQUEST_HEAD_T				clear_request_head;
		RECIPE_CLEAR_RESPONSE_HEAD_T			clear_response_head;
	};
}PROTOCOL_FRAME_T;

typedef struct PROTOCOL_RECIPE_DOWNLOAD_RSQ_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	RECIPE_DOWNLOAD_REQUEST_HEAD_T				request;
}PROTOCOL_RECIPE_DOWNLOAD_RSQ_FRAME_T;

typedef struct PROTOCOL_RECIPE_DOWNLOAD_RSP_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	RECIPE_DOWNLOAD_RESPONSE_HEAD_T				response;
}PROTOCOL_RECIPE_DOWNLOAD_RSP_FRAME_T;

typedef struct PROTOCOL_RECIPE_ECHO_RSQ_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	RECIPE_ECHO_REQUEST_HEAD_T					request;
}PROTOCOL_RECIPE_ECHO_RSQ_FRAME_T;

typedef struct PROTOCOL_RECIPE_ECHO_RSP_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	RECIPE_ECHO_RESPONSE_HEAD_T					response;
}PROTOCOL_RECIPE_ECHO_RSP_FRAME_T;

typedef struct PROTOCOL_RECIPE_CLEAR_RSQ_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	RECIPE_CLEAR_REQUEST_HEAD_T					request;
}PROTOCOL_RECIPE_CLEAR_RSQ_FRAME_T;

typedef struct PROTOCOL_RECIPE_CLEAR_RSP_FRAME
{
	PROTOCOL_HEAD_T 							protocol_head;
	PROTOCOL_FUNCTION_HEAD_T 					function_head;
	RECIPE_CLEAR_RESPONSE_HEAD_T				response;
}PROTOCOL_RECIPE_CLEAR_RSP_FRAME_T;


#pragma pack()

}



#endif /* R2H_ILINK_PROTOCOL_COMM_H_ */
