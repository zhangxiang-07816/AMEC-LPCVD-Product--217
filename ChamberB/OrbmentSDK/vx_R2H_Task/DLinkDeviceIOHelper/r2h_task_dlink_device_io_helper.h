/*
 * r2h_task_dlink_device_io_helper.h
 *
 *  Created on: 2018-8-24
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_DEVICE_IO_HELPER_H_
#define R2H_TASK_DLINK_DEVICE_IO_HELPER_H_

#include "../r2h_task_data_type.h"
#include "../r2h_task_error_code.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_device_io.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_task_info.h"
#include "../../vx_R2H_ExtModule/r2h_extmodule_error_code.h"
#include "r2h_task_dlink_device_io_helper_def.h"
#include <vxworks.h>
#include <pthread.h>
#include <vector>

class R2H_Task_DLinkDeviceIOHelper
{
public:
	R2H_Task_DLinkDeviceIOHelper();
	virtual ~R2H_Task_DLinkDeviceIOHelper();
	virtual void ExchangeProcessData(timespec* time, void *param, bool refreshDiagnostic, bool refreshProcessIn, bool refreshProcessOut, void* pLocalProcessOutData) = 0;
	virtual void ExchangeControlData(void *param) = 0;
	virtual void ProcessOutDataMigration(void *param, bool localToRemote, void* pLocalProcessOutData) = 0;
	virtual void SafeState(void *param) = 0;
	
	virtual R2H_INT32 BindToDLinkMemoryObject(R2H_DLink_MemoryDeviceIO *pDeviceIOMemory, R2H_DLink_MemoryTaskInfo *pTaskInfoMemory);
	virtual bool AppendSideBandRx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand) = 0;
	virtual bool AppendSideBandTx(const R2H_TASK_DLINK_DEVICE_SIDE_BAND_T* pBand) = 0;
	virtual bool AppendSideBandRx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
			R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData) = 0;
	virtual bool AppendSideBandTx(R2H_CONST_STRING channelName, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType,
			R2H_INT32 index, R2H_INT32 bitIndex, R2H_DOUBLE up, R2H_DOUBLE down, void* pData) = 0;
	virtual void ClearSideBandRx();
	virtual void ClearSideBandTx();
	virtual void SetSideBandRWLock(SEM_ID txLock, SEM_ID rxLock);
	static R2H_INT32 DATA_SIZE_IN_BIT(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
	static R2H_UINT32 DATA_ALIGN_IN_BYTE(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
protected:
	R2H_UINT16										_device_io_index;
	R2H_DLink_MemoryDeviceIO*						_dlink_memory_device_io;
	R2H_DLink_MemoryTaskInfo*						_dlink_memory_task_info;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_ATTR_T		_dlink_device_io_attribute;
	std::vector<R2H_TASK_DLINK_DEVICE_SIDE_BAND_T>	_side_band_rx_vector;
	std::vector<R2H_TASK_DLINK_DEVICE_SIDE_BAND_T>	_side_band_tx_vector;
	SEM_ID 											_side_band_rx_rwlock;
	SEM_ID											_side_band_tx_rwlock;
	static R2H_INT32								_data_type_size_in_byte(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
	static R2H_INT32								_data_type_size_in_bit(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
	static bool 									_is_basic_data_type(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
	static void 									_raw_data_merge(std::vector<R2H_TASK_DLINK_DEVICE_SIDE_BAND_T> &v, 
														R2H_TASK_DLINK_DEVICE_SIDE_CHANNEL_T rawChannel);
	static bool 									_bit_area_data_merge(std::vector<R2H_TASK_DLINK_DEVICE_SIDE_BAND_T> &v,
														R2H_TASK_DLINK_DEVICE_SIDE_CHANNEL_T bit, R2H_TASK_DLINK_DEVICE_SIDE_CHANNEL_T byte);
};

inline R2H_INT32 R2H_Task_DLinkDeviceIOHelper::_data_type_size_in_byte(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	switch(dataType)
	{
	case SIDE_DATA_TYPE_BYTE:
	case SIDE_DATA_TYPE_SBYTE:
		return 1;
	case SIDE_DATA_TYPE_SHORT:
	case SIDE_DATA_TYPE_USHORT:
		return 2;
	case SIDE_DATA_TYPE_INT:
	case SIDE_DATA_TYPE_UINT:
	case SIDE_DATA_TYPE_FLOAT:
		return 4;
	case SIDE_DATA_TYPE_DOUBLE:
		return 8;
	case SIDE_DATA_TYPE_FP3201:
		return 4;
	case SIDE_DATA_TYPE_FP3202:
		return 4;
	case SIDE_DATA_TYPE_FP6401:
		return 8;
	case SIDE_DATA_TYPE_FP6402:
		return 8;
	case SIDE_DATA_TYPE_FP6404:
		return 8;
	case SIDE_DATA_TYPE_FINGERPRINT:
		return 16;			
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_TX:
		return 42;
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_RX:
		return 30;	
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_TX:
		return 6;
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_RX:
		return 4;
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_TX:
		return 10;
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_RX:
		return 6;
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_RX:
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_TX:
		return 6;
	default:
		return 0;
	}
}

inline R2H_INT32 R2H_Task_DLinkDeviceIOHelper::_data_type_size_in_bit(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	switch(dataType)
	{
	case SIDE_DATA_TYPE_BIT:
		return 1;
	default:
		return _data_type_size_in_byte(dataType)*8;
	}
}

inline bool R2H_Task_DLinkDeviceIOHelper::_is_basic_data_type(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	return ((R2H_UINT32)dataType) < 0x0010;
}

inline R2H_INT32 R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	switch(dataType)
	{
	case SIDE_DATA_TYPE_BIT:
		return 1;
	case SIDE_DATA_TYPE_BYTE:
	case SIDE_DATA_TYPE_SBYTE:
		return 1*8;
	case SIDE_DATA_TYPE_SHORT:
	case SIDE_DATA_TYPE_USHORT:
		return 2*8;
	case SIDE_DATA_TYPE_INT:
	case SIDE_DATA_TYPE_UINT:
	case SIDE_DATA_TYPE_FLOAT:
		return 4*8;
	case SIDE_DATA_TYPE_DOUBLE:
		return 8*8;
	case SIDE_DATA_TYPE_FP3201:
		return 4*8;
	case SIDE_DATA_TYPE_FP3202:
		return 4*8;
	case SIDE_DATA_TYPE_FP6401:
		return 8*8;
	case SIDE_DATA_TYPE_FP6402:
		return 8*8;
	case SIDE_DATA_TYPE_FP6404:
		return 8*8;
	case SIDE_DATA_TYPE_FINGERPRINT:
		return 16*8;			
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_TX:
		return 42*8;
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_RX:
		return 30*8;	
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_TX:
		return 6*8;
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_RX:
		return 4*8;
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_TX:
		return 10*8;
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_RX:
		return 6*8;
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_RX:
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_TX:
		return 6*8;
	default:
		return 0;
	}
}

inline R2H_UINT32 R2H_Task_DLinkDeviceIOHelper::DATA_ALIGN_IN_BYTE(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	switch(dataType)
	{
	case SIDE_DATA_TYPE_BYTE:
	case SIDE_DATA_TYPE_SBYTE:
		return 1;
	case SIDE_DATA_TYPE_SHORT:
	case SIDE_DATA_TYPE_USHORT:
		return 2;
	case SIDE_DATA_TYPE_INT:
	case SIDE_DATA_TYPE_UINT:
	case SIDE_DATA_TYPE_FLOAT:
		return 4;
	case SIDE_DATA_TYPE_DOUBLE:
		return 8;
	case SIDE_DATA_TYPE_FP3201:
		return 4;
	case SIDE_DATA_TYPE_FP3202:
		return 4;
	case SIDE_DATA_TYPE_FP6401:
		return 8;
	case SIDE_DATA_TYPE_FP6402:
		return 8;
	case SIDE_DATA_TYPE_FP6404:
		return 8;
	case SIDE_DATA_TYPE_FINGERPRINT:
		return 1;			
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_TX:
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_RX:	
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_TX:
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_RX:
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_TX:
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_RX:
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_RX:
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_TX:
		return 2;
	default:
		return 0;
	}
}

#endif /* R2H_TASK_DLINK_DEVICE_IO_HELPER_H_ */
