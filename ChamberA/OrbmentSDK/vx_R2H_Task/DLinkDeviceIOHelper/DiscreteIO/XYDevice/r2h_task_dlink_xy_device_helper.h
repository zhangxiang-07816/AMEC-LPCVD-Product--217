/*
 * r2h_task_dlink_xy_device_helper.h
 *
 *  Created on: 2018-8-28
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_XY_DEVICE_HELPER_H_
#define R2H_TASK_DLINK_XY_DEVICE_HELPER_H_

#include "../../r2h_task_dlink_device_io_helper.h"
#include "../../r2h_task_dlink_device_io_helper_def.h"
#include "r2h_task_dlink_xy_device_helper_def.h"
#include "../../../../vx_R2H_ExtModule/XYDevice/r2h_extmodule_xy_device.h"
#include "../../../../vx_R2H_ExtModule/XYDevice/r2h_extmodule_xy_device_def.h"

class R2H_Task_DLinkXYDeviceHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkXYDeviceHelper(R2H_ExtModule_XYDevice *pDevice);
	virtual ~R2H_Task_DLinkXYDeviceHelper();
	virtual void ExchangeProcessData(timespec* time, void *param, bool refreshDiagnostic, bool refreshProcessIn, bool refreshProcessOut, void* pLocalProcessOutData);
	virtual void ExchangeControlData(void *param);
	virtual void SafeState(void *param);
	virtual void ProcessOutDataMigration(void *param, bool localToRemote, void* pLocalProcessOutData);
	virtual bool AppendSideBandRx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand);
	virtual bool AppendSideBandTx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand);
	virtual bool AppendSideBandRx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
				R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData);
	virtual bool AppendSideBandTx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
				R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData);
private:
	R2H_ExtModule_XYDevice*							__pointer_extmodule_device;
	R2H_UINT16										__device_xy_size_in_bit;
	R2H_XY_DEVICE_ACCESS_MODE_T						__device_access_mode;
	R2H_UINT16	 									__base_address;
	
	R2H_DLINK_XY_DEVICE_PROCESS_IN_DATE_T 			__process_in_data;
	R2H_DLINK_XY_DEVICE_PROCESS_OUT_DATE_T 			__process_out_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 	__device_io_status;
};



#endif /* R2H_TASK_DLINK_XY_DEVICE_HELPER_H_ */
