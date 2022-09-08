/*
 * r2h_extmodule_smart_ecat_device_interface.h
 *
 *  Created on: 2020-12-28
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_SMART_ECAT_DEVICE_INTERFACE_H_
#define R2H_EXTMODULE_SMART_ECAT_DEVICE_INTERFACE_H_

#include <vector>
#include "../../r2h_extmodule_data_type.h"
#include "r2h_extmodule_smart_ecat_device_def.h"

class R2H_ExtModule_SmartECATDevice
{
public:
	R2H_ExtModule_SmartECATDevice();
	virtual ~R2H_ExtModule_SmartECATDevice();
	
	virtual void ReadECMasterDiagnosticInformation(R2H_SMART_ECAT_DEVICE_MASTER_DIAGNOSTIC_INFO *pInfo) = 0;
	virtual void ReadSlaveErrorCode(R2H_UINT16 slaveNodeIndex, R2H_UINT16 *pSlaveNodeAddress, R2H_UINT16 *pErrorCode) = 0;
	virtual R2H_INT32 ReadSlaveErrorCode(R2H_UINT16 slaveNodeAddress, R2H_UINT16 *pErrorCode) = 0;
	virtual void ReadSlaveErrorCode(R2H_UINT16 firstSlaveNodeIndex, R2H_UINT16 *pQuantityOfSlaveNode, R2H_UINT16 *pSlaveNodeAddress, R2H_UINT16 *pErrorCode) = 0;
	virtual void BuildSlaveNodesIndex(R2H_ULONG timeout, R2H_INT32 *pResult) = 0;
	virtual void BuildSlaveNodesIndex(std::vector<R2H_SMART_ECAT_DEVICE_INDEX_INFO_T>& index) = 0;
	virtual R2H_INT32 ReadSlaveNodeDataInfo(R2H_UINT16 slaveNodeIndex, R2H_UINT16 *pSlaveNodeAddress,
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pTxPDOInfo, 
			R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pRxPDOInfo) = 0;
	virtual R2H_INT32 ReadSlaveNodeDataInfo(R2H_UINT16 slaveNodeAddress,
				R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pTxPDOInfo, 
				R2H_SMART_ECAT_DEVICE_SLAVE_DATA_INFO_T *pRxPDOInfo) = 0;
	virtual R2H_INT32 ReadSlaveNodeIndex(R2H_UINT16 slaveNodeAddress, R2H_UINT16 *pSlaveNodeIndex) = 0;
	
	virtual void ReadSlavePDOData(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_UINT16 offsetInWord, R2H_UINT16 readSizeInWord, 
			R2H_UINT16 *pDataBuffer, R2H_UINT16 *pActualReadSizeInWord) = 0;
	virtual void WriteSlavePDOData(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_UINT16 offsetInWord, R2H_UINT16 writeSizeInWord, 
			R2H_UINT16 *pDataBuffer, R2H_UINT16 *pActualWriteSizeInWord) = 0;
	virtual void SDOUpload(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T* pSdoUpload) = 0;
	virtual void SDODownload(R2H_ULONG timeout, R2H_INT32 *pResult, R2H_SMART_ECAT_DEVICE_SDO_OBJECT_T* pSdoDownload) = 0;
};


#endif /* R2H_EXTMODULE_SMART_ECAT_DEVICE_INTERFACE_H_ */
