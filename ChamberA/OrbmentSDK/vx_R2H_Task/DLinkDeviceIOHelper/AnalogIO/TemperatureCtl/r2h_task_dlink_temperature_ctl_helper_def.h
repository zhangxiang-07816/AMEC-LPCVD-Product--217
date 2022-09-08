/*
 * r2h_task_dlink_temperature_ctl_helper_def.h
 *
 *  Created on: 2018-8-29
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_TEMPERATURE_CTL_HELPER_DEF_H_
#define R2H_TASK_DLINK_TEMPERATURE_CTL_HELPER_DEF_H_

#include "../../../r2h_task_data_type.h"
#include "../../../../vx_R2H_ExtModule/AnalogIODevice/TemperatureCtl/r2h_extmodule_temp_ctl_device_def.h"

#pragma pack(2)

typedef struct R2H_DLINK_TEMPERATURE_CTL_CHANNEL_BASIC_INFO
{
	R2H_TC_CHANNEL_ALERT_DEFINITION_T					alert;//R2H_TC_CHANNEL_ALERT_DEFINITION_T
	//R2H_TC_CHANNEL_CONTROL_MODE_T						control_mode;//R2H_TC_CHANNEL_CONTROL_MODE_T
	R2H_TC_CHANNEL_MV_MODE_T							mv_mode;
	R2H_INT16 											sv;
	R2H_INT16											measured_temperature;
	R2H_TC_CHANNEL_DECIMAL_POINT_POSITION_T				measured_temperature_decimal_point;//R2H_TC_CHANNEL_DECIMAL_POINT_POSITION_T
	R2H_INT16											scaling_temperature;
	R2H_INT16											mv_for_heating;
	R2H_INT16											mv_for_coolinging;
	R2H_INT16											analog_mv_for_heating;
	R2H_INT16											analog_mv_for_colling;
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_BASIC_INFO_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AT_INFO
{
	R2H_TC_CHANNEL_AUTO_TUNING_STATUS_T					at_status;
	R2H_UINT16											proportional_band;
	R2H_UINT16											proportional_bandc; 
	R2H_UINT16 											integral_time;
	R2H_UINT16											derivative_time;
	R2H_UINT16											loop_disconnection_judgment_time;
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AT_INFO_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_CHANNEL_ST_INFO
{
	R2H_TC_CHANNEL_SELF_TUNING_FLAG_T					st_flag;
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_ST_INFO_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_CHANNEL_SRISE_INFO
{
	R2H_TC_CHANNEL_SIMULTANEOUS_RISE_STATUS_T			simultaneous_rise_status;
	R2H_TC_CHANNEL_SIMULTANEOUS_RISE_PARAM_FLAG_T		simultaneous_rise_param_flag;
	R2H_INT16 											gradient;
	R2H_INT16 											dead_time;
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_SRISE_INFO_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_CHANNEL_FF_INFO
{
	R2H_INT16											feed_forward_value;
	R2H_TC_CHANNEL_FF_TUNING_SELECTION_T				ff_value_tuning_selection;
	R2H_TC_CHANNEL_FF_VALUE_TUNING_FLAG_T				ff_vaule_tuning_flag;
	R2H_UINT16 											ff_control_ready_flag;
	R2H_UINT16											ff_control_forced_start_ready_flag;
	R2H_TC_CHANNEL_FF_CONTROL_FORCED_START_STATUS_T		ff_control_forced_start_status;
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_FF_INFO_T;

typedef union  R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AREA_T
{
	R2H_BYTE											area_mask;
	struct
	{
		R2H_BYTE										basic_info_area		:1;
		R2H_BYTE										at_info_area		:1;
		R2H_BYTE										st_info_area		:1;
		R2H_BYTE										srise_info_area		:1;
		R2H_BYTE										ff_control_info		:1;
		R2H_BYTE										sv					:1;
		R2H_BYTE										manual_mv			:1;
		R2H_BYTE										analog_pv			:1;
	};
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AREA_T;

typedef union  R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T
{
	R2H_BYTE											index_mask;
	struct
	{
		R2H_BYTE										channel0			:1;
		R2H_BYTE										channel1			:1;
		R2H_BYTE										channel2			:1;
		R2H_BYTE										channel3			:1;
	};
}R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_PROCESS_IN_DATE
{
	R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T				channel_in_index_mask;
	R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AREA_T				channel_in_area_mask[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	struct 
	{
		//R2H_TC_DEVICE_CONTROL_MODE_T						control_mode;//R2H_TC_DEVICE_CONTROL_MODE
		R2H_UINT16 											latest_error_code;
		R2H_UINT16 											latest_alarm_code;
		R2H_TC_DEVICE_OPERATION_MODE_T						operation_mode;
		R2H_INT16											cold_junction_temperature;
		R2H_TC_DEVICE_X_STATUS_T							x_status;
	}device_basic_info;
	struct
	{
		R2H_DLINK_TEMPERATURE_CTL_CHANNEL_BASIC_INFO_T 		basic_info;
		R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AT_INFO_T			at_info;
		R2H_DLINK_TEMPERATURE_CTL_CHANNEL_ST_INFO_T			st_info;
		R2H_DLINK_TEMPERATURE_CTL_CHANNEL_SRISE_INFO_T		srise_info;
		R2H_DLINK_TEMPERATURE_CTL_CHANNEL_FF_INFO_T			ff_control_info;
	}channel_info[4];
}R2H_DLINK_TEMPERATURE_CTL_PROCESS_IN_DATE_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_PROCESS_OUT_DATE
{
	R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T				channel_out_index_mask;
	R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AREA_T				channel_out_area_mask[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	struct
	{
		R2H_INT16											sv;
		R2H_INT16											manual_mv;
		R2H_INT16											analog_pv;
	}channel_out_data[4];	
}R2H_DLINK_TEMPERATURE_CTL_PROCESS_OUT_DATE_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_CONTROL_OUT_DATE
{
	R2H_BYTE 												device_handshake_byte;
	R2H_INT32												control_result;
	union 
	{
		struct
		{
			R2H_UINT16 										latest_alarm_code;
		}device_alarm_info;
		struct
		{
			R2H_UINT16 										latest_error_code;
			R2H_UINT16										error_address;
		}device_error_info;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_UINT16 										proportional_band;
			R2H_UINT16 										proportional_bandc; 
			R2H_UINT16 										integral_time;
			R2H_UINT16 										derivative_time;
			R2H_UINT16 										loop_disconnection_judgment_time;
		}channel_storage_pid_constants;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_INT16										feed_forward_value;
		}channel_storage_ff_value;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_UINT16 										proportional_band;
			R2H_UINT16 										proportional_bandc; 
			R2H_UINT16 										integral_time;
			R2H_UINT16 										derivative_time;
			R2H_UINT16 										loop_disconnection_judgment_time;
		}channel_pid_constants;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_INT16										feed_forward_value;
		}channel_ff_value;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_INT16 										gradient;
			R2H_INT16 										dead_time;
		}channel_srise_param;
		struct
		{
			R2H_TC_DEVICE_CONTROL_MODE_T					control_mode;
		}device_control_mode;
		struct
		{
			R2H_TC_CHANNEL_CONTROL_MODE_T					control_mode[R2H_TC_DEVICE_NUM_OF_CHANNEL];
		}channel_control_mode;
		struct
		{
			R2H_TC_CHANNEL_INPUT_RANGE_T					input_range[R2H_TC_DEVICE_NUM_OF_CHANNEL];
		}channel_input_range;
	};
	
}R2H_DLINK_TEMPERATURE_CTL_CONTROL_OUT_DATE_T;

typedef enum R2H_DLINK_TEMPERATURE_CTL_CONTROL_COMMAND
{
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_SWITCH_DEVICE_OPT_MODE						= 0x00000001,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_SWITCH_CHANNEL_MV_MODE						= 0x00000002,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_ALARM_INFO								= 0x00000003,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_ERROR_INFO								= 0x00000004,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_CLEAR_DEVICE_ERROR							= 0x00000005,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_BACKUP_SETTINGS								= 0x00000006,
	
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_ENABLE_AUTO_TUNING							= 0x00000007,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_DISABLE_AUTO_TUNING							= 0x00000008,
	
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_STORAGE_PID						= 0x00000009,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_WRITE_CHANNEL_PID								= 0x0000000A,
	
	
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_STORAGE_FF						= 0x0000000B,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_WRITE_CHANNEL_FF								= 0x0000000C,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_WRITE_CHANNEL_FF_FORCED_START_SIGNAL			= 0x0000000D,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_WRITE_CHANNEL_FF_VALUE_TUNING_SELECTION		= 0x0000000E,
	
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_WRITE_CHANNEL_SRISE_PARAM						= 0x0000000F,
	
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_DEVICE_CONTROL_MODE						= 0x00000010,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_CONTROL_MODE						= 0x00000011,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_INPUT_RANGE						= 0x00000012,
	
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_PID								= 0x00000013,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_FF								= 0x00000014,
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_READ_CHANNEL_SRISE_PARAM						= 0x00000015,
	
	//R2H_DLINK_TEMPERATURE_CTL_CONTROL_CHANGE_PD_MASK								= 0x10000000,
	__R2H_DLINK_TEMPERATURE_CTL_CONTROL_COMMAND 									= 0xFFFFFFFF
}R2H_DLINK_TEMPERATURE_CTL_CONTROL_COMMAND_T;

typedef struct R2H_DLINK_TEMPERATURE_CTL_CONTROL_IN_DATE
{
	R2H_BYTE 												host_handshake_byte;
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_COMMAND_T				control_command;
	union 
	{
		struct
		{
			R2H_TC_DEVICE_OPERATION_MODE_T					mode;
		}sw_device_opt_mode;
		struct
		{
			R2H_INT32 										channelIndex;
			R2H_TC_CHANNEL_MV_MODE_T				 		mode;
		}sw_channel_mv_mode;
		struct
		{
			R2H_ULONG										clear_timeout;
		}clear_device_error;
		struct
		{
			R2H_ULONG										backup_timeout;
		}backup_device_settings;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_TC_CHANNEL_AT_MODE_SELECTION_T 				mode;
			R2H_INT16 										bias;
			R2H_UINT16 										error_judgment_time;
		}enable_channel_auto_tuning;
		struct
		{
			R2H_INT32 										channel_index;
		}disable_channel_auto_tuning;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_ULONG 										timeout;
		}read_channel_storage_pid_constants;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_UINT16 										proportional_band;
			R2H_UINT16 										proportional_bandc; 
			R2H_UINT16 										integral_time;
			R2H_UINT16 										derivative_time;
			R2H_UINT16 										loop_disconnection_judgment_time;
		}write_channel_pid_constants;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_ULONG 										timeout;
		}read_channel_storage_ff_value;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_INT16										feed_forward_value;
		}write_channel_ff_value;
		struct
		{
			R2H_INT32 										channel_index;
			R2H_TC_CHANNEL_FF_CONTROL_FORCED_START_SIGNAL_T signal;
		}write_channel_ff_control_forced_start_signal;
		struct
		{
			R2H_INT32 										channel_index; 
			R2H_TC_CHANNEL_FF_TUNING_SELECTION_T 			selection;
		}write_channel_ff_value_tuning_selection;
		struct
		{
			R2H_INT32 										channel_index; 
			R2H_INT16 										gradient;
			R2H_INT16 										dead_time;
		}write_channel_srise_param;
		struct
		{
			R2H_INT32 										channel_index; 
		}read_channel_pid_constants;
		struct
		{
			R2H_INT32 										channel_index; 
		}read_channel_ff_value;
		struct
		{
			R2H_INT32 										channel_index; 
		}read_channel_srise_param;
		struct
		{
			R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T		channel_index_mask;
		}read_channel_control_mode;
		struct
		{
			R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T		channel_index_mask;
		}read_channel_input_range;
		//struct
		//{
			//R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T		channel_in_index_mask;
			//R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AREA_T		channel_in_area_mask[R2H_TC_DEVICE_NUM_OF_CHANNEL];
		//}change_pd_mask;
	};
}R2H_DLINK_TEMPERATURE_CTL_CONTROL_IN_DATE_T;

#pragma pack()

#endif /* R2H_TASK_DLINK_TEMPERATURE_CTL_HELPER_DEF_H_ */
