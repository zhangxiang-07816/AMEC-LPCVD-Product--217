/*
 * r2h_task_dlink_dnm_helper.h
 *
 *  Created on: 2018-9-5
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_DNM_HELPER_H_
#define R2H_TASK_DLINK_DNM_HELPER_H_

#include "../../r2h_task_dlink_device_io_helper.h"
#include "../../r2h_task_dlink_device_io_helper_def.h"
#include "r2h_task_dlink_dnm_helper_def.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/DeviceNet/r2h_extmodule_dnm_device.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/DeviceNet/r2h_extmodule_dnm_device_def.h"

class R2H_Task_DLinkDeviceNetMasterHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkDeviceNetMasterHelper(R2H_ExtModule_DeviceNetMasterDevice *pDevice, 
			R2H_DLINK_DNM_SLAVE_IO_DATA_REFRESH_RANGE_T *param, R2H_UINT16 taskIndex);
	virtual ~R2H_Task_DLinkDeviceNetMasterHelper();
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
	virtual R2H_INT32 BindToDLinkMemoryObject(R2H_DLink_MemoryDeviceIO *pDeviceIOMemory, R2H_DLink_MemoryTaskInfo *pTaskInfoMemory);
private:
	R2H_ExtModule_DeviceNetMasterDevice*			__pointer_extmodule_device;
	R2H_UINT16	 									__base_address;
	R2H_DN_DEVICE_MODEL_NAME 						__model_name;
	R2H_UINT16 										__master_node_address;
	R2H_DN_DEVICE_MODE_SWITCH_T 					__master_mode_switch;
	
	R2H_DLINK_DNM_PROCESS_IN_DATE_T					__process_in_data;
	R2H_DLINK_DNM_PROCESS_OUT_DATE_T				__process_out_data;
	R2H_DLINK_DNM_PROCESS_OUT_DATE_T				__process_out_safe_data;
	R2H_DLINK_DNM_CONTROL_IN_DATE_T					__control_in_data;
	R2H_DLINK_DNM_CONTROL_OUT_DATE_T				__control_out_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 	__device_io_status;
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM			__dlink_task_info;
	
	R2H_DLINK_DNM_SLAVE_IO_DATA_REFRESH_RANGE_T		__slave_io_data_range;
	
	static void __DATA_COPY(void* pDst, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dstType,
			void* pSrc, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T srcType);
};

#endif /* R2H_TASK_DLINK_DNM_HELPER_H_ */
