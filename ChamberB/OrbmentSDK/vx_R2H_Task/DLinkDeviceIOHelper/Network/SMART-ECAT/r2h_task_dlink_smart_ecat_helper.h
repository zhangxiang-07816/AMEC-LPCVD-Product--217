/*
 * r2h_task_dlink_smrat_ecat_helper.h
 *
 *  Created on: 2018-11-6
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SMART_ECAT_HELPER_H_
#define R2H_TASK_DLINK_SMART_ECAT_HELPER_H_

#include "r2h_task_dlink_smart_ecat_helper_def.h"
#include "../../r2h_task_dlink_device_io_helper.h"
#include "../../r2h_task_dlink_device_io_helper_def.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/r2h_extmodule_smart_ecat_device_interface.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/r2h_extmodule_smart_ecat_device_def.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/R12CCPU/r2h_extmodule_r12ccpu_ecat_device.h"
#include "../../../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/RD55UPx/r2h_extmodule_rd55up_ecat_device.h"

class R2H_Task_DLinkSmartECATHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkSmartECATHelper(R2H_ExtModule_R12CCPUECATDevice *pDevice, 
			R2H_DLINK_SMART_ECAT_PDO_REFRESH_RANGE_T *param, std::vector<R2H_SMART_ECAT_DEVICE_INDEX_INFO_T>* pSlaves);
	R2H_Task_DLinkSmartECATHelper(R2H_ExtModule_RD55UPECATDevice *pDevice, 
			R2H_DLINK_SMART_ECAT_PDO_REFRESH_RANGE_T *param, std::vector<R2H_SMART_ECAT_DEVICE_INDEX_INFO_T>* pSlaves);
	virtual ~R2H_Task_DLinkSmartECATHelper();
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
	R2H_ExtModule_SmartECATDevice*					__pointer_extmodule_device;
	R2H_UINT16	 									__base_address;
	
	R2H_DLINK_SMART_ECAT_PROCESS_IN_DATE_T			__process_in_data;
	R2H_DLINK_SMART_ECAT_PROCESS_OUT_DATE_T			__process_out_data;
	R2H_DLINK_SMART_ECAT_PROCESS_OUT_DATE_T			__process_out_safe_data;
	R2H_DLINK_SMART_ECAT_CONTROL_IN_DATE_T			__control_in_data;
	R2H_DLINK_SMART_ECAT_CONTROL_OUT_DATE_T			__control_out_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 	__device_io_status;
	
	R2H_DLINK_SMART_ECAT_PDO_REFRESH_RANGE_T		__slave_pdo_data_range;
	R2H_UINT16										__quantity_of_slaves;
	R2H_UINT16										__slaves_error[R2H_SMART_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE];
};

#endif /* R2H_TASK_DLINK_SMART_ECAT_HELPER_H_ */
