/*
 * r2h_ilink_error_code.h
 *
 *  Created on: 2020-3-26
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ERROR_CODE_H_
#define R2H_ILINK_ERROR_CODE_H_

#define R2H_ILINK_ERROR_CODE_PREFIX						(0x00050000)
#define R2H_ILINK_ERROR_CODE_MASK						(0xFFFF)

#define R2H_ILINK_NO_ERROR								(R2H_INT32)(0x00000000)

#define R2H_ILINK_NOT_IMPLEMENT							(R2H_INT32)(0x00008000|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_STD_EXCEPTION							(R2H_INT32)(0x00000001|R2H_ILINK_ERROR_CODE_PREFIX)


#define R2H_ILINK_EXP_DIVIDE_BY_ZERO					(R2H_INT32)(0x00000010|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_OBJECT_REFERENCE_STRING	(R2H_INT32)(0x00000011|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_UNDEFINED_OBJECT_REFERENCE_NAME	(R2H_INT32)(0x00000012|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_IMMEDIATE_OPERAND_STRING	(R2H_INT32)(0x00000013|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_EXPRESSION_STRING			(R2H_INT32)(0x00000014|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_OPERATOR_CHAR				(R2H_INT32)(0x00000015|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_OPERATOR_NAME				(R2H_INT32)(0x00000016|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_ENV_VARIABLE_NAME_UNDEFINED		(R2H_INT32)(0x00000017|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_ENV_VARIABLE_STR_UNDEFINED		(R2H_INT32)(0x00000018|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_ENV_VARIABLE_ADDR_UNDEFINED		(R2H_INT32)(0x00000019|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_OBJECT_DATA_TYPE			(R2H_INT32)(0x0000001A|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_UNDEFINED_PDO_OBJECT_INDEX		(R2H_INT32)(0x0000001B|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_PDO_OBJECT_SEARCHER		(R2H_INT32)(0x0000001C|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_INVALID_SPRITE_STRING				(R2H_INT32)(0x0000001D|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_UNDEFINED_SPRITE_FUNCTION			(R2H_INT32)(0x0000001E|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_SPRITE_FUNCTION_PARAM_COUNT		(R2H_INT32)(0x0000001F|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_SPRITE_LAYER_OUT_OF_RANGE			(R2H_INT32)(0x00000110|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXP_SPRITE_INVALID_FUNCTION_PARAM		(R2H_INT32)(0x00000111|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_TRIGGER_INVALID_LOGIC					(R2H_INT32)(0x00000020|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_TRIGGER_INVALID_EVENT_NAME			(R2H_INT32)(0x00000021|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_TRIGGER_UNDEFINED_EVENT_NAME			(R2H_INT32)(0x00000022|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_TRIGGER_LOGIC_LAYER_OUT_OF_RANGE		(R2H_INT32)(0x00000023|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_TRIGGER_INVALID_NOT_LOGIC				(R2H_INT32)(0x00000024|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_TRIGGER_INVALID_JSON_OBJECT			(R2H_INT32)(0x00000025|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_EVENT_INVALID_JSON_OBJECT				(R2H_INT32)(0x00000030|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EVENT_INVALID_OBJECT_ATTRIBUTE		(R2H_INT32)(0x00000031|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EVENT_UNKNOWN_EVENT_TYPE				(R2H_INT32)(0x00000032|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_SHADER_INVALID_JSON_OBJECT			(R2H_INT32)(0x00000040|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SHADER_INVALID_OBJECT_ATTRIBUTE		(R2H_INT32)(0x00000041|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_BRANCH_INVALID_JSON_OBJECT			(R2H_INT32)(0x00000050|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_BRANCH_INVALID_OBJECT_ATTRIBUTE		(R2H_INT32)(0x00000051|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_STEP_INVALID_JSON_OBJECT				(R2H_INT32)(0x00000060|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_STEP_DUPLICATED_LOCAL_EVENT_INDEX		(R2H_INT32)(0x00000061|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_STEP_INVALID_OBJECT_ATTRIBUTE			(R2H_INT32)(0x00000062|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_STEP_INDEX_OUT_OF_RANGE				(R2H_INT32)(0x00000063|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_STEP_TRI_TARGET_INDEX_OUT_OF_RANGE	(R2H_INT32)(0x00000064|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_SCROLL_INVALID_JSON_OBJECT			(R2H_INT32)(0x00000070|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SCROLL_INVALID_OBJECT_ATTRIBUTE		(R2H_INT32)(0x00000071|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SCROLL_DUPLICATED_LOCAL_EVENT_INDEX	(R2H_INT32)(0x00000072|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_EXC_INVALID_JSON_OBJECT				(R2H_INT32)(0x00000080|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXC_DUPLICATED_LOCAL_EVENT_INDEX		(R2H_INT32)(0x00000081|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXC_INVALID_OBJECT_ATTRIBUTE			(R2H_INT32)(0x00000082|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_EXC_TRI_TARGET_INDEX_OUT_OF_RANGE		(R2H_INT32)(0x00000083|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_ENGINE_STEP_INDEX_OUT_OF_RANGE		(R2H_INT32)(0x00000090|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_DUPLICATED_GLOBAL_EVENT_INDEX	(R2H_INT32)(0x00000091|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_UNDEFINED_GLOBAL_EVENT_INDEX	(R2H_INT32)(0x00000092|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_INVALID_JSON_OBJECT			(R2H_INT32)(0x00000093|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_EVENT_REFERENCED_BY_STEP		(R2H_INT32)(0x00000094|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_EVENT_REFERENCED_BY_SCROLL		(R2H_INT32)(0x00000095|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_EVENT_REFERENCED_BY_EXCEPTION	(R2H_INT32)(0x00000096|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_INVALID_OBJECT_ATTRIBUTE		(R2H_INT32)(0x00000097|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_EMPTY_STEP_SLOT				(R2H_INT32)(0x00000098|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_ECHO_STRING_OUT_OF_RANGE		(R2H_INT32)(0x00000099|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_LOCKED							(R2H_INT32)(0x0000009A|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_DUPLICATED_SCROLL_INDEX		(R2H_INT32)(0x00000190|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_UNDEFINED_SCROLL_INDEX			(R2H_INT32)(0x00000191|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_ENGINE_IS_NOT_ACTIVE					(R2H_INT32)(0x00000192|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_RECURSIVE_ACQUIRING			(R2H_INT32)(0x00000193|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_RECURSIVE_RELEASING			(R2H_INT32)(0x00000194|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_INVALID_OWNER_ID				(R2H_INT32)(0x00000195|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_ENGINE_OWNER_ID_MISMATCH				(R2H_INT32)(0x00000196|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_SOCKET_ERROR							(R2H_INT32)(0x00001000|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SOCKET_BIND_ERROR						(R2H_INT32)(0x00001001|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SOCKET_LISTEN_ERROR					(R2H_INT32)(0x00001002|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SOCKET_INVALID_IPADDR					(R2H_INT32)(0x00001003|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SOCKET_CONNECT_ERROR					(R2H_INT32)(0x00001004|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SOCKET_ACCEPT_ERROR					(R2H_INT32)(0x00001005|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_PACKAGER_CORRUPT_INDEX				(R2H_INT32)(0x00001010|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_CORRUPT_DATA					(R2H_INT32)(0x00001011|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_QUANTITY_OUT_OF_RANGE		(R2H_INT32)(0x00001012|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_INVALID_DATA_SIZE			(R2H_INT32)(0x00001013|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_OPERATION_TIMEOUT			(R2H_INT32)(0x00001014|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_INVALID_FRAME				(R2H_INT32)(0x00001015|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_DUPLICATED_INDEX				(R2H_INT32)(0x00001016|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_INVALID_INDEX				(R2H_INT32)(0x00001017|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PACKAGER_INDEX_OUT_OF_RANGE			(R2H_INT32)(0x00001018|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_PROTOCOL_ERROR_START					(R2H_INT32)(0x00001020|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_PROTOCOL_NETWORK_ERROR				(R2H_INT32)(0x00001020|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_RECV_DATA_TRUNC				(R2H_INT32)(0x00001021|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_TRANSID_MISMATCH				(R2H_INT32)(0x00001022|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_FUNC_CODE_MISMATCH			(R2H_INT32)(0x00001023|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_ADDRESS_MISMATCH				(R2H_INT32)(0x00001024|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_INVALID_FUNC_CODE			(R2H_INT32)(0x00001025|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_INVALID_PROTOCOL				(R2H_INT32)(0x00001026|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_PROTOCOL_RECV_DATA_CORRUPT			(R2H_INT32)(0x00001027|R2H_ILINK_ERROR_CODE_PREFIX)

#define R2H_ILINK_MASTER_REMOTE_CONNECTED				(R2H_INT32)(0x00001030|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_MASTER_REMOTE_DISCONNECTED			(R2H_INT32)(0x00001031|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_MASTER_OUT_OF_INTERNAL_BUFFER			(R2H_INT32)(0x00001032|R2H_ILINK_ERROR_CODE_PREFIX)	

#define R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE				(R2H_INT32)(0x00001040|R2H_ILINK_ERROR_CODE_PREFIX)	
#define R2H_ILINK_SERVER_IS_RUNNING						(R2H_INT32)(0x00001041|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SERVER_IS_NOT_RUNNING					(R2H_INT32)(0x00001042|R2H_ILINK_ERROR_CODE_PREFIX)
#define R2H_ILINK_SERVER_OUT_OF_INTERNAL_BUFFER			(R2H_INT32)(0x00001045|R2H_ILINK_ERROR_CODE_PREFIX)	

#endif /* R2H_ILINK_ERROR_CODE_H_ */