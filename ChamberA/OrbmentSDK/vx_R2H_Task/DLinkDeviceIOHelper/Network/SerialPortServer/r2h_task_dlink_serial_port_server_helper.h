/*
 * r2h_task_dlink_serial_port_server_helper.h
 *
 *  Created on: Jul 6, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_TASK_DLINK_SERIAL_PORT_SERVER_HELPER_H_
#define R2H_TASK_DLINK_SERIAL_PORT_SERVER_HELPER_H_

#include "../../r2h_task_dlink_device_io_helper.h"
#include "../../r2h_task_dlink_device_io_helper_def.h"
#include "r2h_task_dlink_serial_port_server_helper_def.h"
#include "../../../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_task_info.h"

class R2H_Task_DLinkSerialPortServerHelper : public R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkSerialPortServerHelper(R2H_EthModule_SerialPortServer *pDevice, R2H_UINT16 taskIndex);
	virtual ~R2H_Task_DLinkSerialPortServerHelper();
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
	R2H_EthModule_SerialPortServer*									__pointer_ethmodule_device;
	R2H_BYTE*														__process_tx_data;
	R2H_BYTE*														__process_tx_io_data;
	R2H_DLINK_SERIAL_PORT_SERVER_H_DIAG_AREA_T*						__process_tx_diag_data;
	R2H_BYTE*														__process_rx_io_data;
	R2H_BYTE*														__process_rx_safe_io_data;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T 					__device_io_status;
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM							__dlink_task_info;
};


#endif /* R2H_TASK_DLINK_SERIAL_PORT_SERVER_HELPER_H_ */
