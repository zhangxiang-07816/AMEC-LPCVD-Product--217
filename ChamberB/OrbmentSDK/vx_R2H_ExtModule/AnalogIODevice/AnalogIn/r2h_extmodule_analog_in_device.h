/*
 * r2h_extmodule_analog_in_device.h
 *
 *  Created on: 2018-6-26
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_ANALOG_IN_DEVICE_H_
#define R2H_EXTMODULE_ANALOG_IN_DEVICE_H_

#include "r2h_extmodule_analog_in_device_def.h"
#include "r2h_extmodule_analog_in_device_buffer_address.h"
#include "r2h_extmodule_analog_in_device_static.h"
#include "../../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../../r2h_extmodule_data_type.h"
#include "../../r2h_extmodule_error_code.h"
#include <vxWorks.h>
#include <msgQLib.h>
#include <taskLib.h>


class R2H_ExtModule_AnalogInDevice: public R2H_ExtModule_BufferDevice
{
public:
	static R2H_INT32								CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, 
														R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T enableMask, 
														R2H_ExtModule_AnalogInDevice **ppDevice);
	virtual ~R2H_ExtModule_AnalogInDevice();
	
	void											GetHardwareFeature(R2H_AD_DEVICE_TYPE_T *pType, R2H_INT32 *pNumOfChannel,
																	R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T *pEnableMask, R2H_INT32 *pChannelConversionSpeed);
	
	R2H_INT32 										SetChannelStartupParameter(R2H_INT32 channelIndex, R2H_AD_CHANNEL_STARTUP_PARAM_T* param);
	R2H_INT32 										GetChannelStartupParameter(R2H_INT32 channelIndex, R2H_AD_CHANNEL_STARTUP_PARAM_T* param);
	R2H_INT32										GetChannelSignalRange(R2H_INT32 channelIndex, R2H_AD_CHANNEL_SIGNAL_RANGE_T* range);
	R2H_INT32										SetChannelRange(R2H_INT32 channelIndex, R2H_AD_CHANNEL_SIGNAL_RANGE_T range);
	R2H_INT32										SetChannelConvMethod(R2H_INT32 channelIndex, R2H_AD_CHANNEL_CONV_METHOD_SETTING_T* setting);
	R2H_INT32										SetChannelScale(R2H_INT32 channelIndex, R2H_AD_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										SetChannelDigitalClipping(R2H_INT32 channelIndex, R2H_AD_CHANNEL_CLIPPING_SETTING_T* setting);
	R2H_INT32										SetChannelAlarm(R2H_INT32 channelIndex, R2H_AD_CHANNEL_ALARM_SETTING_T* setting);
	R2H_INT32										SetChannelErrorSignalDetection(R2H_INT32 channelIndex, R2H_AD_CHANNEL_SIGNAL_ERROR_SETTING_T* setting);
	R2H_INT32										SetChannelLoggingFunc(R2H_INT32 channelIndex, R2H_AD_CHANNEL_LOGGING_FUNC_SETTING_T* setting);
	
	void											ClearDeviceError(R2H_ULONG timeout, R2H_INT32* pResult);
	
	void											ReadDeviceAlarmHistory(R2H_AD_DEVICE_ALARM_HISTORY_DETAIL_T* alarmHistroy,R2H_UINT16* lastestAlarmIndex, R2H_INT32 bufferSizeInSlot);
	void											ReadDeviceAlarmInfo(R2H_UINT16* processUpperLimitAlarm,
																		R2H_UINT16* processLowerLimitAlarm,
																		R2H_UINT16* rateUpperLimitAlarm,
																		R2H_UINT16* rateLowerLimitAlarm,
																		R2H_UINT16* signalErrorDetectionFlag,
																		R2H_UINT16* latestAlarmCode);
	void											ReadDeviceErrorHistory(R2H_AD_DEVICE_ERROR_HISTORY_DETAIL_T* errorHistory, R2H_UINT16* lastestErrorIndex, R2H_INT32 bufferSizeInSlot);
	void											ReadDeviceErrorInfo(R2H_UINT16* latestErrorCode);
	
	void 											StartupDevice();//Sync Parameter
	void 											ReadDeviceADConversionCompletedFlag(R2H_UINT16* pFlag);
	void 											ReadChannelDigitalOutputValue(R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T readMask,
																			R2H_INT16* pValue);
	void 											ReadChannelDigitalOutputValue(R2H_INT32 channelIndex, R2H_INT16* pValue);
	void 											ReadChannelDigitalOperationValue(R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T readMask,
																			R2H_INT16* pValue);
	void 											ReadChannelDigitalOperationValue(R2H_INT32 channelIndex, R2H_INT16* pValue);
	
	void 											ReadChannelHoldingLoggingData(R2H_INT32 channelIndex, R2H_INT32 headOffsetInWord, R2H_INT32 latestOffsetInWord, 
																		R2H_INT32 readSizeInWord, R2H_INT32* actualReadSizeInWord, R2H_INT16* dataBuffer);
	
	void											SetChannelDifferenceConversion(R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T setDiffConvMask,
																					R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T clrDiffConvMask);
	void											SetChannelDifferenceConversion(R2H_INT32 channelIndex, R2H_AD_CHANNEL_DIFF_CONV_TRIGGER_T trigger);
	void 											GetChannelDifferenceConversionStatus(R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T getDiffConvMask, 
																							R2H_AD_CHANNEL_DIFF_CONV_STATUS_T* pStatus);
	void 											GetChannelDifferenceConversionStatus(R2H_INT32 channelIndex, 
																							R2H_AD_CHANNEL_DIFF_CONV_STATUS_T* pStatus);
	
	void 											SetChannelConversionShift(R2H_INT32 channelIndex, R2H_INT16 shiftValue);
	void 											SetChannelConversionShift(R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T setShiftMask,
																				R2H_INT16* pShiftValue);
	
	void 											ReadChannelLoggingHoldStatus(R2H_INT32 channelIndex,R2H_AD_CHANNEL_LOGGING_HOLD_STATUS_T* pStatus);
	void 											ReadChannelLoggingHoldStatus(R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T getLogHoldingStatusMask,
																					R2H_AD_CHANNEL_LOGGING_HOLD_STATUS_T* pStatus);
	void											GetLoggingCycleValue(R2H_INT32 channelIndex, R2H_UINT16* second, R2H_UINT16* milliSecond, R2H_UINT16* microSecond);
	
	void											PostChannelLoggingHoldRequest(R2H_INT32 channelIndex);
	void 											ResumeChannelDataLogging(R2H_INT32 channelIndex);
	
	void											ModuleReadyFlag(R2H_UINT16 *pReadyFlag);
	virtual R2H_UINT32								GetDeviceModuleSwitch();
	virtual	R2H_INT32								SetDeviceModuleSwitch(R2H_UINT32 sw);
	
private:
	R2H_AD_DEVICE_TYPE_T							__device_type;
	R2H_INT32										__num_of_channel;
	R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T				__channel_enable_mask;
	R2H_INT32										__num_of_enabled_channel;
	R2H_INT32										__ad_conv_cycle;
	R2H_INT32 										__channel_conversion_speed;
	
	R2H_AD_CHANNEL_STARTUP_PARAM_T					__channel_parameters[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL];
	R2H_AD_CHANNEL_STARTUP_PARAM_T					__channel_parameters_in_use[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL];
	
	
	void 											__reset_channel_startup_parameter(R2H_INT32 channelIndex);
	R2H_INT32 										__check_channel_range_parameter(R2H_AD_CHANNEL_SIGNAL_RANGE_T range);
	R2H_INT32 										__check_channel_conv_method_parameter(R2H_AD_CHANNEL_CONV_METHOD_SETTING_T* setting);
	R2H_INT32										__check_channel_clipping_parameter(R2H_AD_CHANNEL_CLIPPING_SETTING_T* setting);
	R2H_INT32										__check_channel_scale_parameter(R2H_AD_CHANNEL_SCALE_SETTING_T* setting);
	R2H_INT32										__check_channel_alarm_parameter(R2H_AD_CHANNEL_ALARM_SETTING_T* setting);
	R2H_INT32										__check_channel_signal_error_parameter(R2H_AD_CHANNEL_SIGNAL_RANGE_T range, R2H_AD_CHANNEL_SIGNAL_ERROR_SETTING_T* setting);
	R2H_INT32										__check_channel_logging_func_parameter(R2H_AD_CHANNEL_CONV_METHOD_SETTING_T* convSetting,
																							R2H_AD_CHANNEL_LOGGING_FUNC_SETTING_T* logSetting);

protected:
	R2H_ExtModule_AnalogInDevice(R2H_UINT16 baseAddress,R2H_AD_DEVICE_TYPE_T type,
			R2H_INT32 numOfChannel, R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T enableMask, R2H_INT32 channelConversionSpeed);
	
public:
	//Device Internal Buffer Address
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_OUTPUT_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(400)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_OPERATION_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(402)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_MAX_OPERATION_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(404)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_MIN_OPERATION_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(406)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_DIFF_CONV_STATUS[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(408)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_FLAG[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(409)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_RANGE_MONITOR[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(430)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_DIFF_CONV_REF[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(432)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_OLDEST_LOGGING_OFFSET[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(434)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LATEST_LOGGING_OFFSET[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(435)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_NUM_OF_LOGGING[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(436)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_TRIGGER_LOGGING_OFFSET[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(437)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_CUR_READ_OFFSET[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(438)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_PRE_READ_OFFSET[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(439)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_READ_POINTS[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(440)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_CYCLE_IN_SEC[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(441)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_CYCLE_IN_MSEC[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(442)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_CYCLE_IN_USEC[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(443)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_TRIGGER_TIME0[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(444)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_TRIGGER_TIME1[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(445)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_TRIGGER_TIME2[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(446)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_TRIGGER_TIME4[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(447)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_TRIGGER_TIME5[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(448)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFC_CH_DIFF_CONV_TRIGGER[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(470)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFC_CH_LOGGING_HOLD_RSQ[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(471)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFC_CH_SHIFT_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(472)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_CONV_ENABLE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(500)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_AVERAGE_METHOD_SPEC[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(501)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_AVERAGE_METHOD_DATA[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(502)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_SCALE_ENABLE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(504)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_SCALE_UPPER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(506)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_SCALE_LOWER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(508)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_CLIPPING_FUNCTION[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(510)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_PV_ALARM_FUNCTION[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(512)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_RATE_ALARM_FUNCTION[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(513)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_PV_ALARM_UPPER_UPPER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(514)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_PV_ALARM_UPPER_LOWER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(516)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_PV_ALARM_LOWER_UPPER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(518)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_PV_ALARM_LOWER_LOWER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(520)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_RATE_ALARM_DETECTION_CYCLE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(522)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_RATE_ALARM_UPPER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(524)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_RATE_ALARM_LOWER_LIMIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(526)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_ERROR_DETECTION_METHOD[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(528)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_ERROR_DETECTION_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(529)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_ENABLE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(535)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_DATA_TARGET[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(536)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_CYCLE_VAULE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(537)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_CYCLE_UNIT[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(538)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_POST_TRIGGER_POINTS[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(539)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_LEVEL_TRIGGER_CONDITION[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(540)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_LEVEL_TRIGGER_DATA_POS[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(541)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_LEVEL_TRIGGER_DATA_VALUE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(542)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_READ_INTERRUPT_ENABLE[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(544)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_LOGGING_READ_INTERRUPT_POINTS[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(545)
	const static R2H_UINT32 R2H_AD_DEVICE_BUFS_CH_RANGE_SETTING[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(598)	
	const static R2H_UINT32 R2H_AD_DEVICE_BUFM_CH_LOGGING_DATA[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL]; //(10000)
};



#endif /* R2H_EXTMODULE_ANALOG_IN_DEVICE_H_ */
