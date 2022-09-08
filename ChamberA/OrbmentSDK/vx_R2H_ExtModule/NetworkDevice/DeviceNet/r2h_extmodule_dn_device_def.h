/*
 * r2h_extmodule_dn_device_def.h
 *
 *  Created on: 2018-8-13
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_DN_DEVICE_DEF_H_
#define R2H_EXTMODULE_DN_DEVICE_DEF_H_

#include "../../r2h_extmodule_data_type.h"

#define R2H_DN_DEVICE_BIT_SIZE												(32)
#define R2H_DN_DEVICE_MODEL_NAME_LENGTH										(10)

#define R2H_DN_DEVICE_IO_COMMUNICATION_REQUEST_HOLD_PERIOD					(300000000)

typedef char																R2H_DN_DEVICE_MODEL_NAME[R2H_DN_DEVICE_MODEL_NAME_LENGTH];

typedef enum R2H_DN_DEVICE_MODE_SWITCH
{
	R2H_DN_DEVICE_MASTER_MODE_AT_125K				= 0x00,
	R2H_DN_DEVICE_MASTER_MODE_AT_250K				= 0x01,
	R2H_DN_DEVICE_MASTER_MODE_AT_500K				= 0x02,
	R2H_DN_DEVICE_SLAVE_MODE_AT_125K				= 0x03,
	R2H_DN_DEVICE_SLAVE_MODE_AT_250K				= 0x04,
	R2H_DN_DEVICE_SLAVE_MODE_AT_500K				= 0x05,
	R2H_DN_DEVICE_HYBRID_MODE_AT_125K				= 0x06,
	R2H_DN_DEVICE_HYBRID_MODE_AT_250K				= 0x07,
	R2H_DN_DEVICE_HYBRID_MODE_AT_500K				= 0x08,
	R2H_DN_DEVICE_HARDWARE_TEST						= 0x09,
	R2H_DN_DEVICE_COMMUNICATION_TEST_AT_125K		= 0x0A,
	R2H_DN_DEVICE_COMMUNICATION_TEST_AT_250K		= 0x0B,
	R2H_DN_DEVICE_COMMUNICATION_TEST_AT_500K		= 0x0C,
	
	__R2H_DN_DEVICE_MODE_SWITCH						= 0xFFFFFFFF			
}R2H_DN_DEVICE_MODE_SWITCH_T;


typedef enum R2H_DN_DEVICE_OPERATION_FOR_BUS_ERROR
{
	/*
	 * 0: Stop the communication without resetting the CAN chip. (Default value)
	 * 1: Reset the CAN chip and restart the communication.
	 */
	R2H_DN_DEVICE_STOP_CAN_CHIP_FOR_BUS_ERROR		= 0x00,
	R2H_DN_DEVICE_RESET_CAN_CHIP_FOR_BUS_ERROR		= 0x01,
	__R2H_DN_DEVICE_OPERATION_FOR_BUS_ERROR			= 0xFFFFFFFF
}R2H_DN_DEVICE_OPERATION_FOR_BUS_ERROR_T;

#pragma pack(2)

typedef union R2H_DN_DEVICE_DATA_CONSISTENCY_SETTING
{
	struct
	{
		R2H_UINT16										data_consistency_for_master 		: 1;
		R2H_UINT16										data_consistency_for_slave 			: 1;
		R2H_UINT16										dummy2 								: 1;
		R2H_UINT16										dummy3 								: 1;
		R2H_UINT16										dummy4 								: 1;
		R2H_UINT16										dummy5 								: 1;
		R2H_UINT16										dummy6 								: 1;
		R2H_UINT16										dummy7 								: 1;
		R2H_UINT16										data_consistency_for_refresh 		: 1;
	};
	R2H_UINT16											data_consistency_setting_word;
}R2H_DN_DEVICE_DATA_CONSISTENCY_SETTING_T;

#pragma pack()

#endif /* R2H_EXTMODULE_DN_DEVICE_DEF_H_ */
