/*
 * r2h_task_dlink_soft_ccpu_helper.h
 *
 *  Created on: 2021-2-18
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SOFT_CCPU_HELPER_H_
#define R2H_TASK_DLINK_SOFT_CCPU_HELPER_H_

#include "../r2h_task_dlink_device_io_helper.h"
#include "../r2h_task_dlink_device_io_helper_def.h"
#include "r2h_task_dlink_soft_ccpu_helper_def.h"


class R2H_Task_DLinkSoftCCPUHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkSoftCCPUHelper(R2H_ExtModule_SoftCCPUDevice *pDevice, 
			R2H_DLINK_SOFT_CCPU_PROCESS_IO_REFRESH_RANGE_T *param);
	virtual ~R2H_Task_DLinkSoftCCPUHelper();
	virtual void ExchangeProcessData(timespec* time, void *param, bool refreshDiagnostic, bool refreshProcessIn, bool refreshProcessOut, void* pLocalProcessOutData);
	virtual void ExchangeControlData(void *param);
	virtual void ProcessOutDataMigration(void *param, bool localToRemote, void* pLocalProcessOutData);
	virtual void SafeState(void* param);
	virtual bool AppendSideBandRx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand);
	virtual bool AppendSideBandTx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand);
	virtual bool AppendSideBandRx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
				R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData);
	virtual bool AppendSideBandTx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
				R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData);
private:
	R2H_ExtModule_SoftCCPUDevice*							__pointer_extmodule_device;
	R2H_UINT16	 											__base_address;
	R2H_DLINK_SOFT_CCPU_PROCESS_IO_REFRESH_RANGE_T			__process_io_refresh_range;
	
	R2H_DLINK_SOFT_CCPU_PROCESS_IN_DATE_T					__process_in_data;
	R2H_DLINK_SOFT_CCPU_PROCESS_OUT_DATE_T					__process_out_data;
	R2H_DLINK_SOFT_CCPU_PROCESS_OUT_DATE_T					__process_out_safe_data;
	R2H_DLINK_SOFT_CCPU_CONTROL_IN_DATE_T					__control_in_data;
	R2H_DLINK_SOFT_CCPU_CONTROL_OUT_DATE_T					__control_out_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 			__device_io_status;
};



#endif /* R2H_TASK_DLINK_SOFT_CCPU_HELPER_H_ */
