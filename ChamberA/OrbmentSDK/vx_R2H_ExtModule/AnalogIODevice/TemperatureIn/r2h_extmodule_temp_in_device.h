/*
 * r2h_extmodule_temp_in_device.h
 *
 *  Created on: 2018-7-13
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_TEMP_IN_DEVICE_H_
#define R2H_EXTMODULE_TEMP_IN_DEVICE_H_

#include "r2h_extmodule_temp_in_device_def.h"
#include "r2h_extmodule_temp_in_device_buffer_address.h"
#include "../../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../../r2h_extmodule_data_type.h"
#include "../../r2h_extmodule_error_code.h"
#include <vxWorks.h>

class R2H_ExtModule_TemperatureInDevice: public R2H_ExtModule_BufferDevice
{
public:
	static R2H_INT32								CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, 
														R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T enableMask, 
														R2H_ExtModule_TemperatureInDevice **ppDevice);

	virtual ~R2H_ExtModule_TemperatureInDevice();
	
	void 											StartupDevice(R2H_TI_CHANNEL_FUNCTION_SWITCH disconnectionDetectionAutoClr, R2H_TI_DEVICE_COLD_JUNCTION_T coldJunctionCompensation);//Sync Parameter
	void 											ReadDeviceTIConversionCompletedFlag(R2H_UINT16* pFlag);
	
	void											GetHardwareFeature(R2H_TI_DEVICE_TYPE_T *pType, R2H_INT32 *pNumOfChannel,
																	R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T *pEnableMask, R2H_INT32 *pChannelConversionSpeed);
	
	
	R2H_INT32 										SetChannelStartupParameter(R2H_INT32 channelIndex, R2H_TI_CHANNEL_STARTUP_PARAM_T* param);
	R2H_INT32 										GetChannelStartupParameter(R2H_INT32 channelIndex, R2H_TI_CHANNEL_STARTUP_PARAM_T* param);
	R2H_INT32										SetChannelRange(R2H_INT32 channelIndex, R2H_TI_CHANNEL_SIGNAL_RANGE_T range);
	R2H_INT32										SetChannelConvMethod(R2H_INT32 channelIndex, R2H_TI_CHANNEL_CONV_METHOD_SETTING_T* setting);
	R2H_INT32										SetChannelScale(R2H_INT32 channelIndex, R2H_TI_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										SetChannelAlarm(R2H_INT32 channelIndex, R2H_TI_CHANNEL_ALARM_SETTING_T* setting);
	R2H_INT32										SetChannelDisconnectionDetection(R2H_INT32 channelIndex, R2H_TI_CHANNEL_DISCONNECTION_DETECTION_SETTING_T* setting);
	
	void											ClearDeviceError(R2H_ULONG timeout, R2H_INT32* pResult);
	
	void 											ReadChannelMeasuredTemperatureValue(R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T readMask,
																			R2H_INT16* pValue);
	void 											ReadChannelMeasuredTemperatureValue(R2H_INT32 channelIndex, R2H_INT16* pValue);
	void 											ReadChannelScalingValue(R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T readMask,
																			R2H_INT16* pValue);
	void 											ReadChannelScalingValue(R2H_INT32 channelIndex, R2H_INT16* pValue);
	
	void											ReadDeviceAlarmHistory(R2H_TI_DEVICE_ALARM_HISTORY_DETAIL_T* alarmHistroy,R2H_UINT16* lastestAlarmIndex, R2H_INT32 bufferSizeInSlot);
	void											ReadDeviceAlarmInfo(R2H_UINT16* processUpperLimitAlarm,
																		R2H_UINT16* processLowerLimitAlarm,
																		R2H_UINT16* rateUpperLimitAlarm,
																		R2H_UINT16* rateLowerLimitAlarm,
																		R2H_UINT16* disconnectionDetectionFlag,
																		R2H_UINT16* latestAlarmCode);
	void											ReadDeviceErrorHistory(R2H_TI_DEVICE_ERROR_HISTORY_DETAIL_T* errorHistory, R2H_UINT16* lastestErrorIndex, R2H_INT32 bufferSizeInSlot);
	void											ReadDeviceErrorInfo(R2H_UINT16* latestErrorCode);
	
	void											ModuleReadyFlag(R2H_UINT16 *pReadyFlag);
	virtual R2H_UINT32								GetDeviceModuleSwitch();
	virtual	R2H_INT32								SetDeviceModuleSwitch(R2H_UINT32 sw);
private:
	R2H_TI_DEVICE_TYPE_T							__device_type;
	R2H_INT32										__num_of_channel;
	R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T				__channel_enable_mask;
	R2H_INT32										__num_of_enabled_channel;
	R2H_INT32										__ad_conv_cycle;
	R2H_INT32 										__channel_conversion_speed;
	
	R2H_TI_CHANNEL_STARTUP_PARAM_T					__channel_parameters[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];
	R2H_TI_CHANNEL_STARTUP_PARAM_T					__channel_parameters_in_use[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];
	
	void 											__reset_channel_startup_parameter(R2H_INT32 channelIndex);
	R2H_INT32 										__check_channel_range_parameter(R2H_TI_CHANNEL_SIGNAL_RANGE_T range);
	R2H_INT32 										__check_channel_conv_method_parameter(R2H_TI_CHANNEL_CONV_METHOD_SETTING_T* setting);
	R2H_INT32										__check_channel_scale_parameter(R2H_TI_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										__check_channel_alarm_parameter(R2H_TI_CHANNEL_SIGNAL_RANGE_T range, R2H_TI_CHANNEL_ALARM_SETTING_T* setting);
	R2H_INT32										__check_channel_disconnection_detection_parameter(R2H_TI_CHANNEL_DISCONNECTION_DETECTION_SETTING_T* setting);
protected:
	R2H_ExtModule_TemperatureInDevice(R2H_UINT16 baseAddress,R2H_TI_DEVICE_TYPE_T type,
			R2H_INT32 numOfChannel, R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T enableMask, R2H_INT32 channelConversionSpeed);
public:
	const static R2H_UINT32 R2H_TI_DEVICE_BUFM_CH_MEASURED_VALUE[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//						(400)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFM_CH_SCALING_VALUE[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//						(402)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_CONV_ENABLE[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//							(500)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_AVERAGE_METHOD_SPEC[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//					(501)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_AVERAGE_METHOD_DATA[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//					(502)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_PV_ALARM_FUNCTION[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//					(512)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_RATE_ALARM_FUNCTION[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//					(513)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_PV_ALARM_UPPER_UPPER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//			(514)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_PV_ALARM_UPPER_LOWER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//			(516)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_PV_ALARM_LOWER_UPPER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//			(518)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_PV_ALARM_LOWER_LOWER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//			(520)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_RATE_ALARM_DETECTION_CYCLE[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//			(522)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_RATE_ALARM_UPPER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(524)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_RATE_ALARM_LOWER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(526)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_DISCONNECTION_DETECTION[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(530)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_CONVERSION_AT_DISCONNECTION[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//			(531)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_CONVERSION_VALUE_AT_DISCONNECTION[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//	(532)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_SCALE_ENABLE[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//							(546)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_SCALE_RANGE_UPPER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(548)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_SCALE_RANGE_LOWER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(550)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_SCALE_WIDTH_UPPER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(552)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_SCALE_WIDTH_LOWER_LIMIT[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//				(554)
	const static R2H_UINT32 R2H_TI_DEVICE_BUFS_CH_RANGE_SETTING[R2H_TI_DEVICE_MAX_NUM_OF_CHANNEL];//						(598)
	
	const static R2H_INT16 R2H_TI_DEVICE_THERMOCOUPLE_INPUT_SETTING_RANGE[8][2];
	const static R2H_INT16 R2H_TI_DEVICE_RTD_INPUT_SETTING_RANGE[10][2];
};



#endif /* R2H_EXTMODULE_TEMP_IN_DEVICE_H_ */
