/*
 * r2h_task_pdo_manager_def.h
 *
 *  Created on: 2019-8-13
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_PDO_MANAGER_DEF_H_
#define R2H_TASK_PDO_MANAGER_DEF_H_

#include "../r2h_task_data_type.h"
#include "../DLinkDeviceIOHelper/r2h_task_dlink_device_io_helper_def.h"
#include <map>
#define NOT_A_VALID_OBJECT_INDEX	(0xFFFFFFFF)

typedef struct R2H_TASK_PDO_INDEX
{
	R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T		variable_data_type;
	R2H_UINT32									offset_in_bit;
}R2H_TASK_PDO_INDEX_T;

typedef struct R2H_TASK_PDO_MAPPING
{
	R2H_UINT32									offset_in_word;
	R2H_UINT32									size_in_word;
	R2H_UINT32									actual_size_in_word;
	std::map<R2H_UINT32, R2H_TASK_PDO_INDEX_T> 	indexs;
	R2H_UINT16									*objects;
	R2H_TASK_PDO_MAPPING()
	{
		offset_in_word = 0;
		size_in_word = 0;
		actual_size_in_word = 0;
		objects = 0;
	}
}R2H_TASK_PDO_MAPPING_T;

typedef enum R2H_TASK_PDO_AREA
{
	R2H_TASK_TX_DIAGNOSTIC_AREA		= 0x0000,
	R2H_TASK_TX_BIT_AREA			= 0x0001,
	R2H_TASK_TX_BLOCK_AREA			= 0x0002,
	R2H_TASK_RX_CONTROL_AREA		= 0x0003,
	R2H_TASK_RX_BIT_AREA			= 0x0004,
	R2H_TASK_RX_BLOCK_AREA			= 0x0005
}R2H_TASK_PDO_AREA_T;

typedef struct R2H_TASK_PDO_AREA_MASK
{
	union
	{
		struct
		{
			R2H_UINT32			tx_diagnostic_area 	: 1;
			R2H_UINT32			tx_bit_area 		: 1;
			R2H_UINT32			tx_block_area 		: 1;
			R2H_UINT32			dummy 				: 1;
			R2H_UINT32			rx_control_area 	: 1;
			R2H_UINT32			rx_bit_area 		: 1;
			R2H_UINT32			rx_block_area 		: 1;
		};
		R2H_UINT32				raw_mask;
	};
	R2H_TASK_PDO_AREA_MASK()
	{
		raw_mask = 0;
	}
}R2H_TASK_PDO_AREA_MASK_T;

#define SET_ALL_TX_PDO_AREA_MASK(mask) (mask.raw_mask |= 0x07)
#define SET_ALL_RX_PDO_AREA_MASK(mask) (mask.raw_mask |= 0x70)
#define SET_USER_TX_PDO_AREA_MASK(mask) (mask.raw_mask |= 0x06)
#define SET_USER_RX_PDO_AREA_MASK(mask) (mask.raw_mask |= 0x60)
#define RESET_ALL_PDO_AREA_MASK(mask) (mask.raw_mask = 0)
#define ALL_TX_PDO_AREA_MASK(mask) (mask.raw_mask = 0x07)
#define ALL_RX_PDO_AREA_MASK(mask) (mask.raw_mask = 0x70)
#define USER_TX_PDO_AREA_MASK(mask) (mask.raw_mask = 0x06)
#define USER_RX_PDO_AREA_MASK(mask) (mask.raw_mask = 0x60)

typedef enum R2H_TASK_MANAGER_RESERVED_PDO_KEY
{
	CTRL_HOST_HEARTBEAT_COUNTER				= 0x00000004,
	CTRL_RX_HANDSHAKE_WORD_FOR_HOST			= 0x00000005,
	CTRL_TX_HANDSHAKE_WORD_FOR_HOST			= 0x00000006,
	
	DIAG_VARIABLE_CATALOGUE_MD5_HASH		= 0x80000001,
	DIAG_IO_LIST_MD5_HASH					= 0x80000002,
	DIAG_TASK_USER_PARAMETERS_MD5_HASH		= 0x80000003,
	DIAG_CONTROLLER_HEARTBEAT_COUNTER		= 0x80000004,
	
	DIAG_RX_HANDSHAKE_WORD_FOR_CONTROLLER	= 0x80000005,
	DIAG_TX_HANDSHAKE_WORD_FOR_CONTROLLER	= 0x80000006,
	
	CTRL_RECIPE_ENGINE_CONTROL_REQUEST		= 0x00000010,
	CTRL_RECIPE_ENGINE_INITIAL_STEP			= 0x00000011,
	
	DIAG_RECIPE_ENGINE_CONTROL_RESPONSE		= 0x80000010,
	DIAG_RECIPE_ENGINE_CONTROL_RESULT		= 0x80000011,
	DIAG_RECIPE_ENGINE_MILLISECOND_COUNTER	= 0x80000012,
	DIAG_RECIPE_ENGINE_STEP_COUNTER			= 0x80000013,
	DIAG_RECIPE_ENGINE_STATE				= 0x80000014,
	DIAG_RECIPE_ENGINE_USER_RETURN_CODE		= 0x80000015,
	
	NOT_A_MANAGER_RESERVED_PDO_KEY			= 0xFFFFFFFF,
	__R2H_TASK_MANAGER_RESERVED_PDO_KEY		= 0xFFFFFFFF
}R2H_TASK_MANAGER_RESERVED_PDO_KEY_T;

typedef struct CTRL_RECIPE_ENGINE_CONTROL_CMD
{
	union
	{
		struct
		{
			R2H_UINT32			activate_recipe_engine 		: 1;
			R2H_UINT32			shutdown_recipe_engine 		: 1;
			R2H_UINT32			reset_recipe_engine 		: 1;
		};
		R2H_UINT32				raw_cmd_dword;
	};
	CTRL_RECIPE_ENGINE_CONTROL_CMD()
	{
		raw_cmd_dword = 0;
	}
}CTRL_RECIPE_ENGINE_CONTROL_CMD_T;


#define RECIPE_ENGINE_IS_ACTIVE(state)\
	((state != 0)&&(((R2H_ILINK::ENGINE_STATE_T*)state)->active == 1))



#endif /* R2H_TASK_PDO_MANAGER_DEF_H_ */
