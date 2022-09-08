/*
 * r2h_task_dlink_temperature_ctl_helper.h
 *
 *  Created on: 2018-8-29
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_TEMPERATURE_CTL_HELPER_H_
#define R2H_TASK_DLINK_TEMPERATURE_CTL_HELPER_H_

#include "spinLockLib.h"

#include "../../r2h_task_dlink_device_io_helper.h"
#include "../../r2h_task_dlink_device_io_helper_def.h"
#include "r2h_task_dlink_temperature_ctl_helper_def.h"
#include "../../../../vx_R2H_ExtModule/AnalogIODevice/TemperatureCtl/r2h_extmodule_temp_ctl_device.h"
#include "../../../../vx_R2H_ExtModule/AnalogIODevice/TemperatureCtl/r2h_extmodule_temp_ctl_device_def.h"

class R2H_Task_DLinkTemperatureCtlHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkTemperatureCtlHelper(R2H_ExtModule_TemperatureControlDevice *pDevice);
	virtual ~R2H_Task_DLinkTemperatureCtlHelper();
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
	virtual void ClearSideBandRx();
	virtual void ClearSideBandTx();
private:
	R2H_ExtModule_TemperatureControlDevice*			__pointer_extmodule_device;
	R2H_UINT16	 									__base_address;
	R2H_TC_DEVICE_CONTROL_MODE_T					__device_control_mode;
	R2H_TC_CHANNEL_CONTROL_MODE_T					__channel_control_mode[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	
	
	
	R2H_DLINK_TEMPERATURE_CTL_PROCESS_IN_DATE_T 	__process_in_data;
	R2H_DLINK_TEMPERATURE_CTL_PROCESS_OUT_DATE_T	__process_out_data;
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_IN_DATE_T 	__control_in_data;
	R2H_DLINK_TEMPERATURE_CTL_CONTROL_OUT_DATE_T	__control_out_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 	__device_io_status;
	
	R2H_DLINK_TEMPERATURE_CTL_CHANNEL_INDEX_T		__channel_default_index_mask;
	R2H_DLINK_TEMPERATURE_CTL_CHANNEL_AREA_T		__channel_default_area_mask[R2H_TC_DEVICE_NUM_OF_CHANNEL];
	//spinlockTask_t								__rw_lock;
};

#endif /* R2H_TASK_DLINK_TEMPERATURE_CTL_HELPER_H_ */
