/*
 * r2h_extmodule_rd55up_ecat_device.h
 *
 *  Created on: 2020-12-28
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_RD55UP_ECAT_DEVICE_H_
#define R2H_EXTMODULE_RD55UP_ECAT_DEVICE_H_

#include <hash_map>

#include "r2h_extmodule_rd55up_ecat_device_buffer_address.h"
#include "../../../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../r2h_extmodule_smart_ecat_device_def.h"
#include "../r2h_extmodule_smart_ecat_device_interface.h"

class R2H_ExtModule_RD55UPECATDevice : public R2H_ExtModule_BufferDevice, public R2H_ExtModule_SmartECATDevice
{
public:
	static R2H_INT32 						CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_RD55UPECATDevice **ppDevice);
	virtual ~R2H_ExtModule_RD55UPECATDevice();
	void ModuleReadyFlag(R2H_UINT16 *pReadyFlag);
	
	void ReadECMasterDiagnosticInformation(R2H_SMART_ECAT_DEVICE_MASTER_DIAGNOSTIC_INFO *pInfo);
	void ReadSlaveErrorCode(R2H_UINT16 slaveNodeIndex, R2H_UINT16 *pSlaveNodeAddress, R2H_UINT16 *pErrorCode);
	R2H_INT32 ReadSlaveErrorCode(R2H_UINT16 slaveNodeAddress, R2H_UINT16 *pErrorCode);
	void ReadSlaveErrorCode(R2H_UINT16 firstSlaveNodeIndex, R2H_UINT16 *pQuantityOfSlaveNode, R2H_UINT16 *pSlaveNodeAddress, R2H_UINT16 *pErrorCode);
	void BuildSlaveNodesIndex(R2H_ULONG timeout, R2H_INT32 *pResult);
	void BuildSlaveNodesIndex(std::vector<R2H_SMART_ECAT_DEVICE_INDEX_INFO_T>& index);
	R2H_INT32 ReadSlaveNodeDataInfo(R2H_UINT16 slaveNodeIndex, R2H_UINT16 *pSlaveNodeAddress,
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pTxPDOInfo, 
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pRxPDOInfo);
	R2H_INT32 ReadSlaveNodeDataInfo(R2H_UINT16 slaveNodeAddress,
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pTxPDOInfo, 
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pRxPDOInfo);
	R2H_INT32 ReadSlaveNodeIndex(R2H_UINT16 slaveNodeAddress, R2H_UINT16 *pSlaveNodeIndex);
	
	void ReadSlavePDOData(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_UINT16 offsetInWord, R2H_UINT16 readSizeInWord, 
			R2H_UINT16 *pDataBuffer, R2H_UINT16 *pActualReadSizeInWord);
	void WriteSlavePDOData(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_UINT16 offsetInWord, R2H_UINT16 writeSizeInWord, 
			R2H_UINT16 *pDataBuffer, R2H_UINT16 *pActualWriteSizeInWord);
	void SDOUpload(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T* pSdoUpload);
	void SDODownload(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T* pSdoDownload);
protected:
	R2H_ExtModule_RD55UPECATDevice(R2H_UINT16 baseAddress);
private:
	bool __slave_node_index;
	R2H_UINT16 __slave_node_address[R2H_RD55UP_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE];
	R2H_UINT16 __quantity_of_slave_node;
	R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T __slave_node_tx_pdo_info[R2H_RD55UP_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE];
	R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T __slave_node_rx_pdo_info[R2H_RD55UP_ECAT_DEVICE_MAX_QUANTITY_OF_SLAVE_NODE];
	pthread_mutex_t __sync_access_mutex;
	std::hash_map<R2H_UINT16, R2H_UINT16> __slave_index_dict;
};



#endif /* R2H_EXTMODULE_RD55UP_ECAT_DEVICE_H_ */
