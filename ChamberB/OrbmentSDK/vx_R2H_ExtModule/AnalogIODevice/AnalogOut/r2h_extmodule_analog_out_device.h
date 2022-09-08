/*
 * r2h_extmodule_analog_out_device.h
 *
 *  Created on: 2018-7-9
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_ANALOG_OUT_DEVICE_H_
#define R2H_EXTMODULE_ANALOG_OUT_DEVICE_H_

#include "r2h_extmodule_analog_out_device_def.h"
#include "r2h_extmodule_analog_out_device_buffer_address.h"
#include "../../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../../r2h_extmodule_data_type.h"
#include "../../r2h_extmodule_error_code.h"

class R2H_ExtModule_AnalogOutDevice: public R2H_ExtModule_BufferDevice
{
public:
	static R2H_INT32								CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, 
														R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T enableMask, 
														R2H_ExtModule_AnalogOutDevice **ppDevice);
	
	virtual ~R2H_ExtModule_AnalogOutDevice();
	
	void											GetHardwareFeature(R2H_DA_DEVICE_TYPE_T *pType, R2H_INT32 *pNumOfChannel,
																	R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T *pEnableMask, R2H_INT32 *pChannelConversionSpeed);
	
	R2H_INT32 										SetChannelStartupParameter(R2H_INT32 channelIndex, R2H_DA_CHANNEL_STARTUP_PARAM_T* param);
	R2H_INT32 										GetChannelStartupParameter(R2H_INT32 channelIndex, R2H_DA_CHANNEL_STARTUP_PARAM_T* param);
	R2H_INT32										GetChannelSignalRange(R2H_INT32 channelIndex, R2H_DA_CHANNEL_SIGNAL_RANGE_T* range);
	R2H_INT32										GetChannelScale(R2H_INT32 channelIndex, R2H_DA_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										GetChannelScale(R2H_INT32 channelIndex, R2H_DA_CHANNEL_FUNCTION_SWITCH_T* function);
	R2H_INT32										SetChannelRange(R2H_INT32 channelIndex, R2H_DA_CHANNEL_SIGNAL_RANGE_T range);
	R2H_INT32										SetChannelScale(R2H_INT32 channelIndex, R2H_DA_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										SetChannelAlertOutput(R2H_INT32 channelIndex, R2H_DA_CHANNEL_ALERT_OUTPUT_SETTING_T* setting);
	R2H_INT32										SetChannelRateControl(R2H_INT32 channelIndex, R2H_DA_CHANNEL_RATE_CONTROL_SETTING_T* setting);
	
	void 											SetChannelConversionShift(R2H_INT32 channelIndex, R2H_INT16 shiftValue);
	void 											SetChannelConversionShift(R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T setShiftMask,
																				R2H_INT16* pShiftValue);
	
	void											ReadDeviceAlarmHistory(R2H_DA_DEVICE_ALARM_HISTORY_DETAIL_T* alarmHistory, R2H_UINT16* lastestAlarmIndex, R2H_INT32 bufferSizeInSlot);
	void											ReadDeviceAlarmInfo(R2H_UINT16* digitalInputUpperLimitAlarm,
																		R2H_UINT16* digitalInputLowerLimitAlarm,
																		R2H_UINT16* latestAlarmCode);
	void											ReadDeviceErrorHistory(R2H_DA_DEVICE_ERROR_HISTORY_DETAIL_T* errorHistory, R2H_UINT16* lastestErrorIndex, R2H_INT32 bufferSizeInSlot);
	void											ReadDeviceErrorInfo(R2H_UINT16* channelSetValueCheckCode,
																		R2H_UINT16* disconnectionDetectionFlag,
																		R2H_UINT16* latestErrorCode);
	
	void											ClearDeviceError(R2H_ULONG timeout, R2H_INT32* pResult);
	void											ClearDeviceAlarm(R2H_ULONG timeout, R2H_INT32* pResult);
	
	void 											StartupDevice();//Sync Parameter
	void 											EnableChannelOutput(R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T enableMask);
	void 											WriteChannelDigitalInputValue(R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T writeMask,
																			R2H_INT16* pValue);
	void 											WriteChannelDigitalInputValue(R2H_INT32 channelIndex, R2H_INT16 value);
	void 											ReadChannelDigitalInputValue(R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T readMask,
																			R2H_INT16* pValue);
	void 											ReadChannelDigitalInputValue(R2H_INT32 channelIndex, R2H_INT16* pValue);
	
	void											ModuleReadyFlag(R2H_UINT16 *pReadyFlag);
	virtual R2H_UINT32								GetDeviceModuleSwitch();
	virtual	R2H_INT32								SetDeviceModuleSwitch(R2H_UINT32 sw);
private:
	R2H_DA_DEVICE_TYPE_T							__device_type;
	R2H_INT32										__num_of_channel;
	R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T				__channel_enable_mask;
	R2H_INT32										__num_of_enabled_channel;
	R2H_INT32										__da_conv_cycle;
	R2H_INT32 										__channel_conversion_speed;
		
	R2H_DA_CHANNEL_STARTUP_PARAM_T					__channel_parameters[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];
	R2H_DA_CHANNEL_STARTUP_PARAM_T					__channel_parameters_in_use[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];
		
	void 											__reset_channel_startup_parameter(R2H_INT32 channelIndex);
	R2H_INT32 										__check_channel_range_parameter(R2H_DA_CHANNEL_SIGNAL_RANGE_T range);
	R2H_INT32										__check_channel_scale_parameter(R2H_DA_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										__check_channel_alert_output_parameter(R2H_DA_CHANNEL_ALERT_OUTPUT_SETTING_T* setting);
	R2H_INT32										__check_channel_rate_control_parameter(R2H_DA_CHANNEL_RATE_CONTROL_SETTING_T* setting);

protected:
	R2H_ExtModule_AnalogOutDevice(R2H_UINT16 baseAddress,R2H_DA_DEVICE_TYPE_T type,
				R2H_INT32 numOfChannel, R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T enableMask, R2H_INT32 channelConversionSpeed);
public:
	const static R2H_UINT32 R2H_DA_DEVICE_BUFM_CH_SETTING_VALUE_CHECK_CODE[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(400)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFC_CH_DIGITAL_INPUT_VALUE[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(460)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFC_CH_SHIFT_VALUE[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(480)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_CONV_ENABLE[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(500)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_SCALE_ENABLE[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(502)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_SCALE_UPPER_LIMIT[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(504)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_SCALE_LOWER_LIMIT[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(506)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_ALERT_OUTPUT_FUNC[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(508)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_RATE_CONTROL_FUNC[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(509)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_ALERT_OUTPUT_UPPER_LIMIT[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(510)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_ALERT_OUTPUT_LOWER_LIMIT[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(512)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_INCREASE_DIGITAL_LIMIT[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(514)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_DECREASE_DIGITAL_LIMIT[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(516)
	const static R2H_UINT32 R2H_DA_DEVICE_BUFS_CH_RANGE_SETTING[R2H_DA_DEVICE_MAX_NUM_OF_CHANNEL];//(598)
};







#endif /* R2H_EXTMODULE_ANALOG_OUT_DEVICE_H_ */
