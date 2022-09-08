/*
 * r2h_extmodule_temp_ctl_device.h
 *
 *  Created on: 2018-7-25
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_TEMP_CTL_DEVICE_H_
#define R2H_EXTMODULE_TEMP_CTL_DEVICE_H_


#include "r2h_extmodule_temp_ctl_device_def.h"
#include "r2h_extmodule_temp_ctl_device_buffer_address.h"
#include "../../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../../r2h_extmodule_data_type.h"
#include "../../r2h_extmodule_error_code.h"
#include <vxWorks.h>

class R2H_ExtModule_TemperatureControlDevice: public R2H_ExtModule_BufferDevice
{
public:
	static R2H_INT32							CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, 
																R2H_ExtModule_TemperatureControlDevice **ppDevice);
	
	virtual ~R2H_ExtModule_TemperatureControlDevice();
	
	//Setting variation rate limiter setting selection = 1 : Individually set at temperature rise/temperature drop
	//Enable all channels : R2H_TC_CHANNEL_FUNCTION_SWITCH_T.R2H_TC_DEVICE_FUNCTION_ENABLE
	//Manual Reset Amount = 0
	static void									DefaultStartupParameter(R2H_TC_DEVICE_TYPE_T deviceType, R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T outputCycleUnit,
																		R2H_TC_DEVICE_CONTROL_MODE_T *deviceControlMode, 
																		R2H_TC_CHANNEL_STARTUP_PARAM_T *param);
	
	void 										StartupDevice(	R2H_TC_DEVICE_SAMPLE_CYCLE_T 				sampleCycle, 
																R2H_TC_DEVICE_AUTOMATIC_SETTING_T			automaticSetting,
																R2H_TC_DEVICE_FUNCTION_SWITCH_T 			movingAverage,
																R2H_TC_DEVICE_PID_CONTINUATION_FLAG_T		pidcontinuationFlag,
																R2H_TC_DEVICE_COLD_JUNCTION_T 				coldJunctionCompensation,
																R2H_INT16									transistor_output_on_flag_delay, //0-50
																R2H_TC_DEVICE_MV_RESOLUTION_T				mvResolution);//Sync Parameter
	
	R2H_INT32									SetStartupParameter(R2H_TC_DEVICE_CONTROL_MODE_T deviceControlMode, R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T outputCycleUnit,
																	const R2H_TC_CHANNEL_STARTUP_PARAM_T *param);							
	void										GetStartupParameter(R2H_TC_DEVICE_CONTROL_MODE_T *deviceControlMode, R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T *outputCycleUnit,
																	R2H_TC_CHANNEL_STARTUP_PARAM_T *param);
	
	void										SetAlertValue(R2H_INT32 channelIndex, R2H_INT32 alertIndex, R2H_INT16 value);//see settings range
	
	void										GetDeviceControlMode(R2H_TC_DEVICE_CONTROL_MODE_T *pMode);
	void										GetChannelControlMode(R2H_INT32 channelIndex, R2H_TC_CHANNEL_CONTROL_MODE_T *pMode);
	
	void										ReadDeviceXStatus(R2H_TC_DEVICE_X_STATUS_T *pStatus);
	
	void 										SwitchDeviceOperationMode(R2H_TC_DEVICE_OPERATION_MODE_T mode);
	void										GetDeviceOperationMode(R2H_TC_DEVICE_OPERATION_MODE_T *pMode);
	
	void 										SwitchChannelMVMode(R2H_INT32 channelIndex, R2H_TC_CHANNEL_MV_MODE_T mode);
	void 										GetChannelMVMode(R2H_INT32 channelIndex, R2H_TC_CHANNEL_MV_MODE_T* pMode);
	void 										WriteChannelManualMV(R2H_INT32 channelIndex, R2H_INT16 value);
	
	void										ClearDeviceError(R2H_ULONG timeout, R2H_INT32* pResult);
	void										ReadDeviceAlarmHistory(R2H_TC_DEVICE_ALARM_HISTORY_DETAIL_T* alarmHistroy,R2H_UINT16* lastestAlarmIndex, R2H_INT32 bufferSizeInSlot);
	void										ReadDeviceAlarmInfo(R2H_UINT16* latestAlarmCode);
	void										ReadDeviceErrorHistory(R2H_TC_DEVICE_ERROR_HISTORY_DETAIL_T* errorHistory, R2H_UINT16* lastestErrorIndex, R2H_INT32 bufferSizeInSlot);
	void										ReadDeviceErrorInfo(R2H_UINT16* latestErrorCode, R2H_UINT16* errorAddress);
	
	void										BackupDeviceSettingValue(R2H_ULONG timeout, R2H_INT32* pResult);
	void										GetChannelStoragePIDConstants(R2H_INT32 channelIndex, R2H_ULONG timeout, R2H_INT32* pResult,
																				R2H_UINT16* proportionalBand, R2H_UINT16* proportionalBandc, 
																				R2H_UINT16* integralTime, R2H_UINT16* derivativeTime,
																				R2H_UINT16* loopDisconnectionJudgmentTime);
	void 										SetChannelPIDConstants(	R2H_INT32 channelIndex, R2H_UINT16 proportionalBand, R2H_UINT16 proportionalBandc, 
																			R2H_UINT16 integralTime, R2H_UINT16 derivativeTime,
																			R2H_UINT16 loopDisconnectionJudgmentTime);
	void										GetChannelPIDConstants(R2H_INT32 channelIndex, R2H_UINT16* proportionalBand, R2H_UINT16* proportionalBandc, 
																		R2H_UINT16* integralTime, R2H_UINT16* derivativeTime,
																		R2H_UINT16* loopDisconnectionJudgmentTime);
	void										GetChannelStorageFFValue(R2H_INT32 channelIndex, R2H_ULONG timeout, R2H_INT32* pResult,
																				R2H_INT16* feedForwardValue);
	void										GetChannelFFValue(R2H_INT32 channelIndex, R2H_INT16* feedForwardValue);
	
	void 										EnableChannelAutoTuning(R2H_INT32 channelIndex);
	void 										EnableChannelAutoTuning(R2H_INT32 channelIndex, R2H_TC_CHANNEL_AT_MODE_SELECTION_T mode,
																		R2H_INT16 bias, R2H_UINT16 errorJudgmentTime);
	void 										DisableChannelAutoTuning(R2H_INT32 channelIndex);
	void										ReadChannelAutoTuningStatus(R2H_INT32 channelIndex, R2H_TC_CHANNEL_AUTO_TUNING_STATUS_T* status);
	void										ReadChannelSelfTuningStatus(R2H_INT32 channelIndex, R2H_TC_CHANNEL_SELF_TUNING_FLAG_T* flag);
	void										ReadChannelSimultaneousRiseStatus(R2H_INT32 channelIndex, 
																				R2H_TC_CHANNEL_SIMULTANEOUS_RISE_PARAM_FLAG_T* flag,
																				R2H_TC_CHANNEL_SIMULTANEOUS_RISE_STATUS_T* status);
	void										GetChannelSimultaneousRiseParam(R2H_INT32 channelIndex, R2H_INT16 *pGradient,R2H_INT16 *pDeadtime);
	void										SetChannelSimultaneousRiseParam(R2H_INT32 channelIndex, R2H_INT16 gradient,R2H_INT16 deadtime);
	
	void 										ReadDeviceTCConversionCompletedFlag(R2H_UINT16* pFlag);
	void										ReadDeviceColdJunctionTemperature(R2H_INT16* pValue);
	void										ReadChannelTemperature(R2H_INT32 channelIndex, R2H_TC_CHANNEL_DECIMAL_POINT_POSITION_T* decimalPoint, R2H_INT16* pValue, R2H_TC_CHANNEL_ALERT_DEFINITION_T* pAlert);
	void										ReadChannelScaledTemperature(R2H_INT32 channelIndex, R2H_INT16* pValue);
	
	void 										ReadChannelMV(R2H_INT32 channelIndex, R2H_INT16* pMVHeating, R2H_INT16* pMVCooling, 
																R2H_INT16* pMVHeatingForAnalogModule, R2H_INT16* pMVCoolingForAnalogModule);
	
	void 										WriteChannelSV(R2H_INT32 channelIndex, R2H_INT16 sv);
	void										ReadChannelSV(R2H_INT32 channelIndex, R2H_INT16* psv);
	void 										WriteChannelAnalogPV(R2H_INT32 channelIndex, R2H_INT16 analogPV);
	
	//void										ReadChannelFFControlForcedStartStatus(R2H_INT32 channelIndex, R2H_TC_CHANNEL_FF_CONTROL_FORCED_START_STATUS_T* status);
	//void										ReadChannelFFValueTuningStatus(R2H_INT32 channelIndex, R2H_TC_CHANNEL_FF_VALUE_TUNING_FLAG_T* flag);
	//void										ReadChannelFFControlReadyFlag(R2H_INT32 channelIndex, R2H_UINT16* flag);	
	//void										ReadChannelFFControlForcedStartReadyFlag(R2H_INT32 channelIndex, R2H_UINT16* flag);
	void										ReadChannelFFControlStatus(	R2H_INT32 channelIndex, 
																			R2H_UINT16* controlReadyFlag, R2H_UINT16* forcedStartReadyFlag,
																			R2H_TC_CHANNEL_FF_CONTROL_FORCED_START_STATUS_T* forcedStartStatus,
																			R2H_TC_CHANNEL_FF_VALUE_TUNING_FLAG_T* tuningFlag);
	void										WriteChannelFFControlForcedStartSignal(R2H_INT32 channelIndex, R2H_TC_CHANNEL_FF_CONTROL_FORCED_START_SIGNAL_T signal);
	void										SetChannelFFValue(R2H_INT32 channelIndex, R2H_INT16 value);
	void										SetChannelFFValueTuningSelection(R2H_INT32 channelIndex, R2H_TC_CHANNEL_FF_TUNING_SELECTION_T selection);
	void										GetChannelFFValueTuningSelection(R2H_INT32 channelIndex, R2H_TC_CHANNEL_FF_TUNING_SELECTION_T *pSelection);
	
	void										ReadChannelAlert(R2H_INT32 channelIndex, R2H_TC_CHANNEL_ALERT_DEFINITION_T* pAlert);
	
	void 										GetChannelInputRange(R2H_INT32 channelIndex, R2H_TC_CHANNEL_INPUT_RANGE_T* pRange);
	
	void 										ReadChannelBasicInfo(	R2H_INT32 channelIndex, 
																		R2H_TC_CHANNEL_DECIMAL_POINT_POSITION_T* decimalPoint, R2H_TC_CHANNEL_ALERT_DEFINITION_T* pAlert, R2H_INT16* pv, 
																		R2H_INT16* pMVHeating, 
																		R2H_INT16* sv,
																		R2H_INT16* pMVHeatingForAnalogModule,R2H_INT16* pMVCooling, R2H_INT16* pMVCoolingForAnalogModule,
																		R2H_TC_CHANNEL_SELF_TUNING_FLAG_T* flag,
																		R2H_INT16* scaledPV);

	void 										ModuleReadyFlag(R2H_UINT16 *pReadyFlag);
private:
	const static R2H_INT32						__check_channel_control_basic_parameter(const R2H_TC_CHANNEL_CONTROL_BASIC_PARAM_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info, R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T cycleUnit);
	const static R2H_INT32						__check_channel_limiter_setting(const R2H_TC_CHANNEL_LIMITER_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info, R2H_TC_CHANNEL_CONTROL_MODE mode);
	const static R2H_INT32						__check_channel_rise_completion_setting(const R2H_TC_CHANNEL_TEMP_RISE_COMPLETION_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_sv_adjustment_dead_band(R2H_INT16 param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_pv_primary_delay(R2H_INT16 param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_sensor_correction_setting(const R2H_TC_CHANNEL_SENSOR_CORRECTION_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_alert_function_setting(const R2H_TC_CHANNEL_ALERT_FUNCTION_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_moving_averaging_setting(R2H_INT16 param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_heating_cooling_control_setting(const R2H_TC_CHANNEL_HEATING_COOLING_CONTROL_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info, R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T cycleUnit);
	const static R2H_INT32						__check_channel_pv_scaling_function_setting(const R2H_TC_CHANNEL_PV_SCALING_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_pv_rate_alarm_setting(const R2H_TC_CHANNEL_PV_RATE_ALARM_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_pp_control_setting(const R2H_TC_CHANNEL_PP_CONTROL_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_loop_disconnection_setting(const R2H_TC_CHANNEL_LOOP_DISCONNECTION_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_auto_tuning_setting(const R2H_TC_CHANNEL_AUTO_TUNING_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_ff_control_setting(const R2H_TC_CHANNEL_FF_CONTROL_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_simultaneous_rise_setting(const R2H_TC_CHANNEL_SIMULTANEOUS_RISE_SETTING_T *param, const R2H_TC_CHANNEL_INPUT_INFO_T *info, R2H_TC_DEVICE_CONTROL_MODE_T deviceControlMode, R2H_TC_CHANNEL_CONTROL_MODE_T channelControlMode);
	const static R2H_INT32						__check_channel_overshot_suppression_level(R2H_INT16 param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	const static R2H_INT32						__check_channel_peak_current_suppression_group(R2H_INT16 param, const R2H_TC_CHANNEL_INPUT_INFO_T *info);
	
	R2H_TC_DEVICE_TYPE_T						__device_type;

	
	R2H_TC_DEVICE_CONTROL_MODE_T				__device_control_mode;
	R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T	__device_control_output_cycle_unit;
	R2H_TC_CHANNEL_STARTUP_PARAM_T				__channel_parameters[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	
	R2H_TC_DEVICE_CONTROL_MODE_T				__device_control_mode_in_use;
	R2H_TC_CHANNEL_CONTROL_MODE_T				__channel_control_mode_in_use[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	R2H_TC_DEVICE_CONTROL_OUTPUT_CYCLE_UNIT_T	__device_control_output_cycle_unit_in_use;
	R2H_TC_CHANNEL_STARTUP_PARAM_T				__channel_parameters_in_use[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	
	const static R2H_TC_CHANNEL_INPUT_INFO_T	__get_channel_input_info(R2H_TC_CHANNEL_INPUT_RANGE_T range);
	const static R2H_TC_CHANNEL_CONTROL_MODE_T	__get_channel_control_mode(R2H_TC_DEVICE_CONTROL_MODE_T device, R2H_INT32 channelIndex);
	static void									__init_internal_buffer_address();
	static bool									__internal_buffer_address_initialized;
protected:
	R2H_ExtModule_TemperatureControlDevice(R2H_UINT16 baseAddress,R2H_TC_DEVICE_TYPE_T type, R2H_INT32 bitSize);
	
protected:
	static R2H_UINT32 BUFC_CH_HOLD_CLEAR_SETTING[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(500)
	static R2H_UINT32 BUFC_CH_INPUT_RANGE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(501)
	static R2H_UINT32 BUFS_CH_UNUSED_SETTING[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(502)
	static R2H_UINT32 BUFS_CH_STOP_MODE_SETTING[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(503)
	static R2H_UINT32 BUFS_CH_CONTROL_OUTPUT_PERIOD[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(504)
	static R2H_UINT32 BUFS_CH_CONTROL_RESPONSE_PARAM[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(505)
	static R2H_UINT32 BUFS_CH_TEMP_RISE_COMPLETION_RANGE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(506)
	static R2H_UINT32 BUFS_CH_TEMP_RISE_COMPLETION_SOAK[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(507)
	static R2H_UINT32 BUFS_CH_MVH_UPPER_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(508)
	static R2H_UINT32 BUFS_CH_MV_LOWER_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(509)
	static R2H_UINT32 BUFS_CH_MV_VARIATION_AMOUNT_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(510)			
	static R2H_UINT32 BUFS_CH_SV_UPPER_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(511)
	static R2H_UINT32 BUFS_CH_SV_LOWER_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(512)
	static R2H_UINT32 BUFS_CH_SV_RISE_RATE_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(513)
	static R2H_UINT32 BUFS_CH_SV_DROP_RATE_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(514)
	static R2H_UINT32 BUFS_CH_ACTION_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(515)
	static R2H_UINT32 BUFS_CH_SV_ADJUSTMENT_DEAD_BAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(516)
	static R2H_UINT32 BUFS_CH_MANUAL_RESET_AMOUNT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(517)
	static R2H_UINT32 BUFS_CH_AUTO_MAN_MODE_SHIFT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(518)
	static R2H_UINT32 BUFS_CH_MANUAL_MV_SETTING[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(519)
	static R2H_UINT32 BUFS_CH_TEMPERATURE_CONVERSION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(520)
	static R2H_UINT32 BUFS_CH_MVC_UPPER_LIMITER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(521)
	static R2H_UINT32 BUFS_CH_CONTROL_OUTPUT_PERIOD_C[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(522)
	static R2H_UINT32 BUFS_CH_COOLING_METHOD[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(523)
	static R2H_UINT32 BUFS_CH_HEATING_COOLING_OVERLAP_DEAD_BAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//		(524)
	static R2H_UINT32 BUFS_CH_DERIVATIVE_ACTION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(525)
	static R2H_UINT32 BUFS_CH_SV_VARIATION_RATE_LIMITER_UNIT_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//		(526)
	static R2H_UINT32 BUFS_CH_PP_CTL_OUTPUT_NEUTRAL_BAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(527)
	static R2H_UINT32 BUFS_CH_PP_CTL_MOTOR_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(528)
	static R2H_UINT32 BUFS_CH_PP_CTL_INTEGRATION_OUTPUT_LIMIT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(529)
	static R2H_UINT32 BUFS_CH_PP_CTL_VALVE_OPERATION_AT_STOP[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(530)
	static R2H_UINT32 BUFS_CH_PV_ALERT_DEAD_BAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(531)
	static R2H_UINT32 BUFS_CH_ALERT_DELAY[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(532)
	static R2H_UINT32 BUFS_CH_ALERT0_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(533)
	static R2H_UINT32 BUFS_CH_ALERT1_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(534)
	static R2H_UINT32 BUFS_CH_ALERT2_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(535)
	static R2H_UINT32 BUFS_CH_ALERT3_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(536)
	static R2H_UINT32 BUFS_CH_LOOP_DISCONNECTION_JUDGMEMT_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(537)
	static R2H_UINT32 BUFS_CH_LOOP_DISCONNECTION_DEAD_BAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(538)
	static R2H_UINT32 BUFS_CH_PV_RATE_ALARM_SWITCH[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(539)
	static R2H_UINT32 BUFS_CH_PV_RATE_ALARM_CYCLE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(540)
	static R2H_UINT32 BUFS_CH_PV_RATE_ALARM_UPPER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(541)
	static R2H_UINT32 BUFS_CH_PV_RATE_ALARM_LOWER[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(542)
	static R2H_UINT32 BUFS_CH_AT_MODE_SELECTION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(543)
	static R2H_UINT32 BUFS_CH_AT_ERROR_JUDGMEMT_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(544)
	static R2H_UINT32 BUFS_CH_AT_LOOP_DISCONNECTION_DETECTION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(545)
	static R2H_UINT32 BUFS_CH_AT_BIAS[R2H_TC_DEVICE_NUM_OF_CHANNEL];//									(546)
	static R2H_UINT32 BUFS_CH_AT_AUTOMATIC_BACKUP[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(547)
	static R2H_UINT32 BUFS_CH_SELF_TUNING_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(548)
	static R2H_UINT32 BUFS_CH_PV_SCALING_FUNCTION_SWITCH[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(549)
	static R2H_UINT32 BUFS_CH_PV_SCALING_UPPER_LIMIT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(550)
	static R2H_UINT32 BUFS_CH_PV_SCALING_LOWER_LIMIT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(551)
	static R2H_UINT32 BUFS_CH_PEAK_CURRENT_SUPPRESSION_GROUP[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(552)
	static R2H_UINT32 BUFS_CH_SIMULTANEOUS_RISE_GROUP[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(553)
	static R2H_UINT32 BUFS_CH_SIMULTANEOUS_RISE_GRADIENT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(554)
	static R2H_UINT32 BUFS_CH_SIMULTANEOUS_RISE_DEAD_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(555)
	static R2H_UINT32 BUFS_CH_SIMULTANEOUS_RISE_AT_MODE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(556)
	static R2H_UINT32 BUFS_CH_FF_CTL_DISTURBANCE_JUDGMENT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(557)
	static R2H_UINT32 BUFS_CH_FF_CTL_SV_RETURN_ADJUSTMENT[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(558)
	static R2H_UINT32 BUFS_CH_FF_CTL_FORCED_START_SIGNAL[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(559)
	static R2H_UINT32 BUFS_CH_FF_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//									(560)
	static R2H_UINT32 BUFS_CH_FEED_FORWARD_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(560)
	static R2H_UINT32 BUFS_CH_FF_VALUE_TUNING_SELECTION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(561)
	static R2H_UINT32 BUFS_CH_OVERSHOOT_SUPPRESSION_LEVEL[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(562)
	static R2H_UINT32 BUFS_CH_PV_PRIMARY_DELAY[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(563)
	static R2H_UINT32 BUFS_CH_SENSOR_CORRECTION_METHOD[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(564)
	static R2H_UINT32 BUFS_CH_SENSOR_CORRECTION_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(565)
	static R2H_UINT32 BUFS_CH_NUMBER_OF_MOVING_AVERAGING[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(572)	
	static R2H_UINT32 BUFM_CH_DECIMAL_POINT_POSITION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(400)
	static R2H_UINT32 BUFM_CH_ALERT_DEFINITION[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(401)
	static R2H_UINT32 BUFM_CH_TEMPERATURE_PROCESS_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(402)
	static R2H_UINT32 BUFM_CH_MANIPULATED_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(403)
	static R2H_UINT32 BUFM_CH_SET_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(406)
	static R2H_UINT32 BUFM_CH_ANALOG_MANIPULATED_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(407)
	static R2H_UINT32 BUFM_CH_MANIPULATED_VALUE_C[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(408)
	static R2H_UINT32 BUFM_CH_ANALOG_MANIPULATED_VALUE_C[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(409)
	static R2H_UINT32 BUFM_CH_SELF_TUNING_FLAG[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(411)
	static R2H_UINT32 BUFM_CH_TEMPERATURE_PROCESS_SCALED_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(412)
	static R2H_UINT32 BUFM_CH_SIMULTANEOUS_RISE_PARAM_FLAG[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(413)
	static R2H_UINT32 BUFM_CH_SIMULTANEOUS_RISE_STATUS[R2H_TC_DEVICE_NUM_OF_CHANNEL];//					(414)
	static R2H_UINT32 BUFM_CH_FF_CTL_FORCED_START_STATUS[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(415)
	static R2H_UINT32 BUFM_CH_FF_VALUE_TUNING_FLAG[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(416)
	static R2H_UINT32 BUFM_CH_FF_CTL_READY_FLAG[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(417)
	static R2H_UINT32 BUFM_CH_FF_CTL_FORCED_START_READY_FLAG[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(418)
	static R2H_UINT32 BUFC_CH_SET_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//								(430)
	static R2H_UINT32 BUFC_CH_PROPORTIONAL_BAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(431)
	static R2H_UINT32 BUFC_CH_INTEGRAL_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(432)
	static R2H_UINT32 BUFC_CH_DERIVATIVE_TIME[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(433)
	static R2H_UINT32 BUFC_CH_ALERT0_SET_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(434)
	static R2H_UINT32 BUFC_CH_ALERT1_SET_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(435)
	static R2H_UINT32 BUFC_CH_ALERT2_SET_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(436)
	static R2H_UINT32 BUFC_CH_ALERT3_SET_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//							(437)
	static R2H_UINT32 BUFC_CH_ANALOG_PROCESS_VALUE[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(438)
	static R2H_UINT32 BUFC_CH_PROPORTIONAL_BAND_C[R2H_TC_DEVICE_NUM_OF_CHANNEL];//						(439)
	static R2H_UINT32 BUFC_CH_MEM_PID_CONSTANTS_READ_COMMAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//			(440)
	static R2H_UINT32 BUFC_CH_MEM_FF_VALUE_READ_COMMAND[R2H_TC_DEVICE_NUM_OF_CHANNEL];//				(441)
	
};

#endif /* R2H_EXTMODULE_TEMP_CTL_DEVICE_H_ */
