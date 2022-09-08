/*
 * r2h_task_dlink_temperature_in_helper.h
 *
 *  Created on: 2018-8-28
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_TEMPERATURE_IN_HELPER_H_
#define R2H_TASK_DLINK_TEMPERATURE_IN_HELPER_H_

#include "../../r2h_task_dlink_device_io_helper.h"
#include "../../r2h_task_dlink_device_io_helper_def.h"
#include "r2h_task_dlink_temperature_in_helper_def.h"
#include "../../../../vx_R2H_ExtModule/AnalogIODevice/TemperatureIn/r2h_extmodule_temp_in_device.h"
#include "../../../../vx_R2H_ExtModule/AnalogIODevice/TemperatureIn/r2h_extmodule_temp_in_device_def.h"

class R2H_Task_DLinkTemperatureInHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkTemperatureInHelper(R2H_ExtModule_TemperatureInDevice *pDevice);
	virtual ~R2H_Task_DLinkTemperatureInHelper();
	virtual void ExchangeProcessData(timespec* time, void *param, bool refreshDiagnostic, bool refreshProcessIn, bool refreshProcessOut, void* pLocalProcessOutData);
	virtual void ExchangeControlData(void *param);
	virtual void ProcessOutDataMigration(void *param, bool localToRemote, void* pLocalProcessOutData);
	virtual void SafeState(void *param);
	virtual bool AppendSideBandRx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand);
	virtual bool AppendSideBandTx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand);
	virtual bool AppendSideBandRx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
				R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData);
	virtual bool AppendSideBandTx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
				R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData);
private:
	R2H_ExtModule_TemperatureInDevice*				__pointer_extmodule_device;
	R2H_TI_DEVICE_TYPE_T							__device_type;
	R2H_INT32										__num_of_channel;
	R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T				__channel_enable_mask;
	R2H_INT32 										__channel_conversion_speed;
	R2H_UINT16	 									__base_address;
	
	R2H_DLINK_TEMPERATURE_IN_PROCESS_IN_DATE_T 		__process_in_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 	__device_io_status;
	R2H_DLINK_TEMPERATURE_IN_CONTROL_IN_DATE_T		__control_in_data;
	R2H_DLINK_TEMPERATURE_IN_CONTROL_OUT_DATE_T		__control_out_data;

};

#endif /* R2H_TASK_DLINK_TEMPERATURE_IN_HELPER_H_ */
