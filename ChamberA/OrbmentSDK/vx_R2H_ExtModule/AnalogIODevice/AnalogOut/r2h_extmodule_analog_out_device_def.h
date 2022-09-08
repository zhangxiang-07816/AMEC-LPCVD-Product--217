/*
 * r2h_extmodule_analog_out_device_def.h
 *
 *  Created on: 2018-7-9
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_ANALOG_OUT_DEVICE_DEF_H_
#define R2H_EXTMODULE_ANALOG_OUT_DEVICE_DEF_H_

#include "../../r2h_extmodule_data_type.h"

#pragma pack(2)
#define R2H_DA_DEVICE_BIT_SIZE										(16)
#define R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL							(8)
#define R2H_DA_DEVICE_MAX_NUM_OF_INTERRUPT							(16)

typedef enum R2H_DA_DEVICE_TYPE
{
	R2H_DA_DEVICE_VOLTAGE_OUT		= 0x01,
	R2H_DA_DEVICE_CURRENT_OUT		= 0x02,
	R2H_DA_DEVICE_MIX_SIGNAL_OUT		= 0x03,
	
	__R2H_DA_DEVICE_TYPE				= 0xFFFFFFFF
}R2H_DA_DEVICE_TYPE_T;


typedef enum R2H_DA_CHANNEL_FUNCTION_SWITCH
{
	R2H_DA_CHANNEL_FUNCTION_ENABLE 				= 0,
	R2H_DA_CHANNEL_FUNCTION_DISABLE 			= 1,
	
	__R2H_DA_CHANNEL_FUNCTION_SWITCH			= 0xFFFFFFFF
}R2H_DA_CHANNEL_FUNCTION_SWITCH_T;

typedef enum R2H_DA_CHANNEL_SIGNAL_RANGE
{
	R2H_DA_CHANNEL_ANALOG_OUT_4_20_MA 					= 0x0,
	R2H_DA_CHANNEL_ANALOG_OUT_0_20_MA 					= 0x1,
	R2H_DA_CHANNEL_ANALOG_OUT_1_5_V 					= 0x2,
	R2H_DA_CHANNEL_ANALOG_OUT_0_5_V 					= 0x3,
	R2H_DA_CHANNEL_ANALOG_OUT_10_10_V 					= 0x4,
	R2H_DA_CHANNEL_ANALOG_OUT_USER_RANGE_VOLTAGE 		= 0xE,
	R2H_DA_CHANNEL_ANALOG_OUT_USER_RANGE_CURRENT 		= 0xF,
	
	__R2H_DA_CHANNEL_SIGNAL_RANGE						= 0xFFFFFFFF
}R2H_DA_CHANNEL_SIGNAL_RANGE_T;

typedef union R2H_DA_DEVICE_CHANNEL_ENABLE_MASK
{
	struct
	{
		R2H_UINT8	enable_channel_0 : 1;
		R2H_UINT8	enable_channel_1 : 1;
		R2H_UINT8	enable_channel_2 : 1;
		R2H_UINT8	enable_channel_3 : 1;
		R2H_UINT8	enable_channel_4 : 1;
		R2H_UINT8	enable_channel_5 : 1;
		R2H_UINT8	enable_channel_6 : 1;
		R2H_UINT8	enable_channel_7 : 1;
	};
	R2H_UINT8 enable_mask_value;
}R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T;

#define R2H_DA_SCALE_UPPER_LIMIT						(+32000)
#define R2H_DA_SCALE_LOWER_LIMIT						(-32000)
/*
 * Set the scaling with the condition "Scaling upper limit value ¡Ù Scaling lower limit value".
 */
typedef struct R2H_DA_CHANNEL_SCALE_SETTING
{
	R2H_DA_CHANNEL_FUNCTION_SWITCH_T	scale_enable;
	R2H_INT16							upper_scale;
	R2H_INT16							lower_scale;
}R2H_DA_CHANNEL_SCALE_SETTING_T;

typedef struct R2H_DA_CHANNEL_ALERT_OUTPUT_SETTING
{
	R2H_DA_CHANNEL_FUNCTION_SWITCH_T	alert_output_enable;
	R2H_INT16							upper_limit_value;
	R2H_INT16							lower_limit_value;
}R2H_DA_CHANNEL_ALERT_OUTPUT_SETTING_T;

#define R2H_DA_RATE_CONTROL_INCREASE_MAX				(+64000)
#define R2H_DA_RATE_CONTROL_DECREASE_MAX				(+64000)
typedef struct R2H_DA_CHANNEL_RATE_CONTROL_SETTING
{
	R2H_DA_CHANNEL_FUNCTION_SWITCH_T	rate_control_enable;
	R2H_UINT16							increase_limit_value;
	R2H_UINT16							decrease_limit_value;
}R2H_DA_CHANNEL_RATE_CONTROL_SETTING_T;

typedef struct R2H_DA_CHANNEL_STARTUP_PARAM
{
	R2H_DA_CHANNEL_SIGNAL_RANGE_T					range;
	R2H_DA_CHANNEL_SCALE_SETTING_T					scale_setting;
	R2H_DA_CHANNEL_ALERT_OUTPUT_SETTING_T			alert_output_setting;
	R2H_DA_CHANNEL_RATE_CONTROL_SETTING_T			rate_control_setting;
}R2H_DA_CHANNEL_STARTUP_PARAM_T;


#define R2H_DA_ERROR_HISTORY_SLOTS_CNT					(16)
#define R2H_DA_ERROR_HISTORY_SLOT_SIZE_IN_WORD			(10)
typedef struct R2H_DA_DEVICE_ERROR_HISTORY_DETAIL
{
	R2H_UINT16					error_code;
	R2H_UINT16					year;
	R2H_BYTE					day;
	R2H_BYTE					month;
	R2H_BYTE					minute;
	R2H_BYTE					hour;
	R2H_BYTE					day_of_the_week;
	R2H_BYTE					second;
	R2H_UINT16					millisecond;
}R2H_DA_DEVICE_ERROR_HISTORY_DETAIL_T;


#define R2H_DA_ALARM_HISTORY_SLOTS_CNT					(16)
#define R2H_DA_ALARM_HISTORY_SLOT_SIZE_IN_WORD			(10)
typedef struct R2H_DA_DEVICE_ALARM_HISTORY_DETAIL
{
	R2H_UINT16					alarm_code;
	R2H_UINT16					year;
	R2H_BYTE					day;
	R2H_BYTE					month;
	R2H_BYTE					minute;
	R2H_BYTE					hour;
	R2H_BYTE					day_of_the_week;
	R2H_BYTE					second;
	R2H_UINT16					millisecond;
}R2H_DA_DEVICE_ALARM_HISTORY_DETAIL_T;

#pragma pack()


#endif /* R2H_EXTMODULE_ANALOG_OUT_DEVICE_DEF_H_ */
