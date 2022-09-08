/*
 * r2h_ecat_slave_mr_j4_tm_def.h
 *
 *  Created on: 2018-11-6
 *      Author: CrazyHein
 */

#ifndef R2H_ECAT_SLAVE_MR_J4_TM_DEF_H_
#define R2H_ECAT_SLAVE_MR_J4_TM_DEF_H_

#include "../../vx_R2H_Common/r2h_data_type.h"

namespace R2H_ECAT_SLAVE_PROFILE_MR_J4_TM
{

#pragma pack(1)
typedef struct __attribute__((__aligned__((2)))) MR_J4_MT_ECAT_DEFAULT_TXPDO
{
	R2H_BYTE				mode_of_operation;
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
	
	struct
	{
		R2H_UINT16			reserved0 					: 2;
		R2H_UINT16			speed_reached 				: 1;
		R2H_UINT16			brake_interlock				: 1;
		R2H_UINT16			variable_gain_selection		: 1;
		R2H_UINT16			fully_closed_loop_control	: 1;
		R2H_UINT16			reserved6 					: 6;
		R2H_UINT16			in_position 				: 1;
		R2H_UINT16			limiting_torque 			: 1;
		R2H_UINT16			abs_position_erased 		: 1;
		R2H_UINT16			battery_warning 			: 1;
	}status_do_1;
	struct
	{
		R2H_UINT16			z_phase_passed 						: 1;
		R2H_UINT16			reserved1 							: 2;
		R2H_UINT16			zero_speed_detection 				: 1;
		R2H_UINT16			torque_limiting_speed 				: 1;
		R2H_UINT16			reserved5							: 1;
		R2H_UINT16			during_ipf 							: 1;
		R2H_UINT16			reserved7 							: 1;
		R2H_UINT16			under_proportional_control 			: 1;
		R2H_UINT16			reserved9 							: 1;
		R2H_UINT16			external_dynamic_brake 				: 1;
		R2H_UINT16			reserved11 							: 4;
		R2H_UINT16			home_position_return_completion2	: 1;
	}status_do_2;
	struct
	{
		R2H_UINT16			reserved0 							: 5;
		R2H_UINT16			during_sto 							: 1;
		R2H_UINT16			reserved6 							: 2;
		R2H_UINT16			scale_abs_position_erased 			: 1;
		R2H_UINT16			reserved9 							: 2;
		R2H_UINT16			tough_drive_mode_in_process 		: 1;
		R2H_UINT16			reserved12							: 4;
	}status_do_3;
	R2H_INT32				position_value;
	R2H_INT32				velocity_value;
	R2H_INT32				following_error_value;
	R2H_INT16				torque_value;
	R2H_UINT16				touch_probe_status;
	R2H_INT32				touch_probe_position1_pos_value;
	R2H_INT32				touch_probe_position1_neg_value;
	R2H_INT32				touch_probe_position2_pos_value;
	R2H_INT32				touch_probe_position2_neg_value;
	
}MR_J4_MT_ECAT_DEFAULT_TXPDO_T;

typedef struct __attribute__((__aligned__((2)))) MR_J4_MT_ECAT_DEFAULT_RXPDO
{
	R2H_BYTE				mode_of_operation;
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
	struct
	{
		R2H_UINT16		reserved0 							: 4;
		R2H_UINT16		gain_switching						: 1;
		R2H_UINT16		fully_closed_loop_control_switching	: 1;
		R2H_UINT16		reserved6 							: 10;
	}control_di_1;
	struct
	{
		R2H_UINT16		reserved0 							: 8;
		R2H_UINT16		proportional_control				: 1;
		R2H_UINT16		reserved9							: 6;
		R2H_UINT16		operation_alarm_reset 				: 1;
	}control_di_2;
	struct
	{
		R2H_UINT16		reserved0 								: 8;
		R2H_UINT16		scale_home_position_return_completion	: 1;
		R2H_UINT16		reserved9								: 7;
	}control_di_3;
	
	R2H_INT32			target_position;
	R2H_INT32			target_velocity;
	R2H_UINT32			torque_velocity_limit_value;
	R2H_INT16 			target_torque;
	R2H_UINT16			positive_torque_limit_value;
	R2H_UINT16			negative_torque_limit_value;
	R2H_UINT16			touch_probe_function;
}MR_J4_MT_ECAT_DEFAULT_RXPDO_T;
#pragma pack(0)

typedef enum MR_J4_MT_ECAT_OPERATION_MODE
{
	MR_J4_MT_ECAT_NO_OPERATION_MODE_ASSIGNED				= 0,
	MR_J4_MT_ECAT_PROFILE_POSITION_MODE						= 1,
	MR_J4_MT_ECAT_PROFILE_VELOCITY_MODE						= 3,
	MR_J4_MT_ECAT_PROFILE_TORQUE_MODE						= 4,
	
	MR_J4_MT_ECAT_HOMING_MODE								= 6,
	
	MR_J4_MT_ECAT_CYCLIC_SYNC_POSITION_MODE					= 8,
	MR_J4_MT_ECAT_CYCLIC_SYNC_VELOCITY_MODE					= 9,
	MR_J4_MT_ECAT_CYCLIC_SYNC_TORQUE_MODE					= 10,
	
	MR_J4_MT_ECAT_JOG_MODE									= -100,
	MR_J4_MT_ECAT_POINT_TABLE_MODE							= -101,
	MR_J4_MT_ECAT_INDEXER_MODE								= -103,
}MR_J4_MT_ECAT_OPERATION_MODE_T;

typedef enum MR_J4_MT_ECAT_FSA_STATE
{
	ECAT_FSA_NOT_READY_TO_SWITCH_ON		= 0x0000,
	ECAT_FSA_SWITCH_ON_DISABLED			= 0x0040,
	ECAT_FSA_READY_TO_SWITCH_ON			= 0x0021,
	ECAT_FSA_SWITCHED_ON				= 0x0023,
	ECAT_FSA_OPERATION_ENABLED			= 0x0027,
	ECAT_FSA_QUICK_STOP_ACTIVE			= 0x0007,
	ECAT_FSA_FAULT_REACTION_ACTIVE		= 0x000F,
	ECAT_FSA_FAULT						= 0x0008
}MR_J4_MT_ECAT_FSA_STATE_T;


#define MR_J4_MT_ECAT_SET_SHUTDOWN_COMMAND(controlword) 				(controlword) = (((controlword)&(0xFF7E))|(0x0006))
#define MR_J4_MT_ECAT_SET_SWITCH_ON_COMMAND(controlword) 				(controlword) = (((controlword)&(0xFF77))|(0x0007))
#define MR_J4_MT_ECAT_SET_DISABLE_VOLTAGE_COMMAND(controlword) 			(controlword) = (((controlword)&(0xFF7D))|(0x0000))
#define MR_J4_MT_ECAT_SET_QUICK_STOP_COMMAND(controlword) 				(controlword) = (((controlword)&(0xFF7B))|(0x0002))
#define MR_J4_MT_ECAT_SET_DISABLE_OPERATION_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFF77))|(0x0007))
#define MR_J4_MT_ECAT_SET_ENABLE_OPERATION_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFF7F))|(0x000F))
#define MR_J4_MT_ECAT_SET_FAULT_RESET_REQUEST_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFFFF))|(0x0080))
#define MR_J4_MT_ECAT_SET_FAULT_RESET_RESTORE_COMMAND(controlword) 		(controlword) = (((controlword)&(0xFF7F))|(0x0000))

#define MR_J4_MT_ECAT_IS_NOT_READY_TO_SWITCH_ON(statusword)				((((statusword)&(0x414F)) == 0) && (((statusword)|(0xFFFF)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_SWITCH_ON_DISABLE(statusword)					((((statusword)&(0x410F)) == 0) && (((statusword)|(0xFFBF)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_READY_TO_SWITCH_ON(statusword)					((((statusword)&(0x414E)) == 0) && (((statusword)|(0xFFDE)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_SWITCHED_ON(statusword)						((((statusword)&(0x414C)) == 0) && (((statusword)|(0xFFDC)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_OPERATION_ENABLED(statusword)					((((statusword)&(0x4148)) == 0) && (((statusword)|(0xFFD8)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_QUICK_STOP_ACTIVE(statusword)					((((statusword)&(0x4168)) == 0) && (((statusword)|(0xFFF8)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_FAULT_REACTION_ACTIVE(statusword)				((((statusword)&(0x4140)) == 0) && (((statusword)|(0xFFF0)) == 0xFFFF))
#define MR_J4_MT_ECAT_IS_FAULT_STATE(statusword)						((((statusword)&(0x4147)) == 0) && (((statusword)|(0xFFF7)) == 0xFFFF))

}

#endif /* R2H_ECAT_SLAVE_MR_J4_TM_DEF_H_ */
