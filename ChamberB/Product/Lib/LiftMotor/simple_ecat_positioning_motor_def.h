/*
 * simple_ecat_positioning_motor_def.h
 *
 *  Created on: Oct 22, 2021
 *      Author: HaihangRen
 */

#ifndef SIMPLE_ECAT_POSITIONING_MOTOR_DEF_H_
#define SIMPLE_ECAT_POSITIONING_MOTOR_DEF_H_
namespace R2H_AMEC_PRODUCT
{

#pragma pack(2)
typedef struct CIA402_STATUS_WORD
{
	union
	{
		R2H_UINT16				raw_status_word;
		struct
		{
			R2H_UINT16			ready_to_switch_on			: 1;
			R2H_UINT16			switch_on					: 1;
			R2H_UINT16			operation_enabled			: 1;
			R2H_UINT16			fault						: 1;
			R2H_UINT16			voltage_enabled				: 1;
			R2H_UINT16			no_during_quick_stop		: 1;
			R2H_UINT16			switch_on_disabled			: 1;
			R2H_UINT16			warning						: 1;
			R2H_UINT16			reserved8 					: 1;
			R2H_UINT16			following_control_word		: 1;
			R2H_UINT16			target_position_reached		: 1;
			R2H_UINT16			internal_limit_active		: 1;
			R2H_UINT16			set_point_acknowledge		: 1;
			R2H_UINT16			following_error				: 1;
			R2H_UINT16			reserved14 					: 2;
		}pp_status_word;
		struct
		{
			R2H_UINT16			ready_to_switch_on			: 1;
			R2H_UINT16			switch_on					: 1;
			R2H_UINT16			operation_enabled			: 1;
			R2H_UINT16			fault						: 1;
			R2H_UINT16			voltage_enabled				: 1;
			R2H_UINT16			no_during_quick_stop		: 1;
			R2H_UINT16			switch_on_disabled			: 1;
			R2H_UINT16			warning						: 1;
			R2H_UINT16			reserved8 					: 1;
			R2H_UINT16			following_control_word		: 1;
			R2H_UINT16			home_position_reached		: 1;
			R2H_UINT16			internal_limit_active		: 1;
			R2H_UINT16			homing_attained				: 1;
			R2H_UINT16			homing_error				: 1;
			R2H_UINT16			reserved14 					: 2;
		}hm_status_word;
	}status_word;
}CIA402_STATUS_WORD_T;

typedef struct CIA402_CONTROL_WORD
{
	union
	{
		R2H_UINT16			raw_control_word;
		struct
		{
			R2H_UINT16		switch_on 							: 1;
			R2H_UINT16		enable_voltage 						: 1;
			R2H_UINT16		quick_stop 							: 1;
			R2H_UINT16		enable_operation 					: 1;
			R2H_UINT16		new_setpoint 						: 1;
			R2H_UINT16		change_sp_immediately 				: 1;
			R2H_UINT16		relative_position_command 			: 1;
			R2H_UINT16		fault_reset_request 				: 1;
			R2H_UINT16		temporary_stop 						: 1;
			R2H_UINT16		change_on_setpoint 					: 1;
			R2H_UINT16		reserved10 							: 6;
		}pp_control_word;
		struct
		{
			R2H_UINT16		switch_on 							: 1;
			R2H_UINT16		enable_voltage 						: 1;
			R2H_UINT16		quick_stop 							: 1;
			R2H_UINT16		enable_operation 					: 1;
			R2H_UINT16		homing_operation_start 				: 1;
			R2H_UINT16		reserved5							: 2;
			R2H_UINT16		fault_reset_request 				: 1;
			R2H_UINT16		temporary_stop 						: 1;
			R2H_UINT16		reserved9 							: 7;
		}hm_control_word;
	}control_word;
}CIA402_CONTROL_WORD_T;

typedef struct SIMPLE_MOTOR_CONTROLLER_ACK_WORD
{
	union
	{
		struct
		{
			R2H_UINT32			enable_driver_and_motor 		: 1;
			R2H_UINT32			disable_driver_and_motor 		: 1;
			R2H_UINT32			reset_driver_fault		 		: 1;
			R2H_UINT32			reset_driver_encoder	 		: 1;
			R2H_UINT32			move_to_absolute_position	 	: 1;
			R2H_UINT32			move_to_relative_position	 	: 1;
		};
		R2H_UINT32				ack_word;
	};
}SIMPLE_MOTOR_CONTROLLER_ACK_WORD_T;

typedef struct SIMPLE_MOTOR_CONTROLLER_CMD_WORD
{
	union
	{
		struct
		{
			R2H_UINT32			enable_driver_and_motor 		: 1;
			R2H_UINT32			disable_driver_and_motor 		: 1;
			R2H_UINT32			reset_driver_fault		 		: 1;
			R2H_UINT32			reset_driver_encoder	 		: 1;
			R2H_UINT32			move_to_absolute_position	 	: 1;
			R2H_UINT32			move_to_relative_position	 	: 1;
		};
		R2H_UINT32				cmd_word;
	};
}SIMPLE_MOTOR_CONTROLLER_CMD_WORD_T;
#pragma pack()

typedef enum SIMPLE_MOTOR_CONTROLLER_STATUS
{
	MOTOR_CONTROLLER_IDLE							= 0x00000001,
	MOTOR_CONTROLLER_BUSY							= 0x00000002,
	MOTOR_CONTROLLER_CLEAN							= 0x00000003,
}SIMPLE_MOTOR_CONTROLLER_STATUS_T;

typedef enum SIMPLE_MOTOR_CONTROLLER_TASK
{
	MOTOR_CONTROLLER_NO_TASK						= 0x00000000,
	MOTOR_CONTROLLER_ENABLE_DRIVER					= 0x00000001,
	MOTOR_CONTROLLER_DISABLE_DRIVER					= 0x00000002,
	MOTOR_CONTROLLER_RESET_DRIVER_FAULT				= 0x00000003,
	MOTOR_CONTROLLER_RESET_DRIVER_ENCODER			= 0x00000004,
	MOTOR_CONTROLLER_ABS_MOVEMENT					= 0x00000005,
	MOTOR_CONTROLLER_REL_MOVEMENT					= 0x00000006
}SIMPLE_MOTOR_CONTROLLER_TASK_T;

#define MOTOR_CONTROLLER_NO_ERROR					(0x00000000)
#define MOTOR_CONTROLLER_ECAT_FAULT					(0x00000001)
#define MOTOR_CONTROLLER_DIFFERENCE_ERROR			(0x00000002)
#define MOTOR_CONTROLLER_DRV_FAULT					(0x00000003)
#define MOTOR_CONTROLLER_DRV_OPT_MODE_ERROR			(0x00000004)
#define MOTOR_CONTROLLER_DRV_LIMIT_ERROR			(0x00000005)
#define MOTOR_CONTROLLER_OPT_TIMEOUT				(0x00000006)
#define MOTOR_CONTROLLER_DRV_WARNING				(0x00000007)
#define MOTOR_CONTROLLER_HOMING_ERROR				(0x00000008)
#define MOTOR_CONTROLLER_DRV_NOT_ENABLED			(0x00000009)

typedef enum CIA402_OPERATION_MODE
{
	CIA402_NO_OPERATION_MODE_ASSIGNED				= 0,
	CIA402_PROFILE_POSITION_MODE					= 1,
	CIA402_PROFILE_VELOCITY_MODE					= 3,
	CIA402_PROFILE_TORQUE_MODE						= 4,
	
	CIA402_HOMING_MODE								= 6,
	
	CIA402_CYCLIC_SYNC_POSITION_MODE				= 8,
	CIA402_CYCLIC_SYNC_VELOCITY_MODE				= 9,
	CIA402_CYCLIC_SYNC_TORQUE_MODE					= 10,
	
	CIA402_JOG_MODE									= -100,
	CIA402_POINT_TABLE_MODE							= -101,
	CIA402_INDEXER_MODE								= -103,
}CIA402_OPERATION_MODE_T;


#define CIA402_SET_SHUTDOWN_COMMAND(controlword) 				(controlword) = (((controlword)&(0xFF7E))|(0x0006))
#define CIA402_SET_SWITCH_ON_COMMAND(controlword) 				(controlword) = (((controlword)&(0xFF77))|(0x0007))
#define CIA402_SET_DISABLE_VOLTAGE_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFF7D))|(0x0000))
#define CIA402_SET_QUICK_STOP_COMMAND(controlword) 				(controlword) = (((controlword)&(0xFF7B))|(0x0002))
#define CIA402_SET_DISABLE_OPERATION_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFF77))|(0x0007))
#define CIA402_SET_ENABLE_OPERATION_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFF7F))|(0x000F))
#define CIA402_SET_FAULT_RESET_REQUEST_COMMAND(controlword) 	(controlword) = (((controlword)&(0xFFFF))|(0x0080))
#define CIA402_SET_FAULT_RESET_RESTORE_COMMAND(controlword) 	(controlword) = (((controlword)&(0xFF7F))|(0x0000))

#define CIA402_IS_NOT_READY_TO_SWITCH_ON(statusword)			((((statusword)&(0x414F)) == 0) && (((statusword)|(0xFFFF)) == 0xFFFF))
#define CIA402_IS_SWITCH_ON_DISABLE(statusword)					((((statusword)&(0x410F)) == 0) && (((statusword)|(0xFFBF)) == 0xFFFF))
#define CIA402_IS_READY_TO_SWITCH_ON(statusword)				((((statusword)&(0x414E)) == 0) && (((statusword)|(0xFFDE)) == 0xFFFF))
#define CIA402_IS_SWITCHED_ON(statusword)						((((statusword)&(0x414C)) == 0) && (((statusword)|(0xFFDC)) == 0xFFFF))
#define CIA402_IS_OPERATION_ENABLED(statusword)					((((statusword)&(0x4148)) == 0) && (((statusword)|(0xFFD8)) == 0xFFFF))
#define CIA402_IS_QUICK_STOP_ACTIVE(statusword)					((((statusword)&(0x4168)) == 0) && (((statusword)|(0xFFF8)) == 0xFFFF))
#define CIA402_IS_FAULT_REACTION_ACTIVE(statusword)				((((statusword)&(0x4140)) == 0) && (((statusword)|(0xFFF0)) == 0xFFFF))
#define CIA402_IS_FAULT_STATE(statusword)						((((statusword)&(0x4147)) == 0) && (((statusword)|(0xFFF7)) == 0xFFFF))

}
#endif /* SIMPLE_ECAT_POSITIONING_MOTOR_DEF_H_ */
