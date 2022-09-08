/*
 * r2h_extmodule_dnm_device.h
 *
 *  Created on: 2018-8-3
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_DNM_DEVICE_H_
#define R2H_EXTMODULE_DNM_DEVICE_H_

#include "r2h_extmodule_dn_device_buffer_address.h"
#include "r2h_extmodule_dnm_device_def.h"
#include "r2h_extmodule_dn_device.h"
#include "../../r2h_extmodule_data_type.h"
#include "../../r2h_extmodule_error_code.h"
#include <vxWorks.h>
#include <string>
#include <vector>

using namespace std;

class R2H_ExtModule_DeviceNetMasterDevice: public R2H_ExtModule_DeviceNetDevice
{
public:
	static R2H_INT32									CreateInstance(	R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id,
																		R2H_UINT32 bufferSyncRefreshPosixPriority,
																		R2H_UINT16 rxOffsetInWord, R2H_UINT16 rxSizeInWord,
																		R2H_UINT16 txOffsetInWord, R2H_UINT16 txSizeInWord,
																		R2H_ExtModule_DeviceNetMasterDevice **ppDevice);

	virtual ~R2H_ExtModule_DeviceNetMasterDevice();
	
	R2H_INT32											AddSlaveNode(R2H_INT32 pos, R2H_DNM_DEVICE_SLAVE_NODE_PARAM_T * param);
	R2H_INT32											AddSlaveNode(R2H_DNM_DEVICE_SLAVE_NODE_PARAM_T * param);
	R2H_INT32											RemoveSlaveNode(R2H_INT32 pos);
	R2H_INT32											ClearSlaveNodes();
	void												SyncSlaveNodeSettings();
	
	void												SyncMasterNodeSetting(R2H_DNM_DEVICE_MASTER_NODE_PARAM_T* param);
	
	void												StartIOCommunication(/*bool dataConsistency, */R2H_ULONG timeout, R2H_INT32* pResult);
	void												ForceStartIOCommunication();
	void												StopIOCommunication(R2H_ULONG timeout, R2H_INT32* pResult);
	void												ForceStopIOCommunication();
	
	void												ResetMaseterFunctionError(R2H_ULONG timeout, R2H_INT32* pResult);
	
	void												ExecuteMesseageCommunication(	R2H_INT32* pResult, R2H_ULONG timeout,
																						R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_COMMAND_T* command,
																						R2H_DNM_DEVICE_MESSAGE_COMMUNICATION_RESULT_T* commandResult,
																						R2H_BYTE* pWrData, R2H_BYTE wrDataBufferSizeInByte, R2H_BYTE* pActualWrDataBufferSizeInByte,
																						R2H_BYTE* pRdData, R2H_BYTE rdDataBufferSizeInByte, R2H_BYTE* pActualRdDataBufferSizeInByte);
	void												ReadSlaveNodeAttribute(	R2H_INT32* pResult, R2H_UINT16* pMessageComExecutionErrorCode, R2H_ULONG timeout,
																				R2H_BYTE slaveNodeAddress, R2H_BYTE classID, 
																				R2H_UINT16 instanceID, R2H_BYTE attributeID, 
																				R2H_BYTE* pAttributeData, R2H_BYTE dataBufferSizeInByte, R2H_BYTE* pActualRdDataBufferSizeInByte);
	void 												WriteSlaveNodeAttribute(R2H_INT32* pResult, R2H_UINT16* pMessageComExecutionErrorCode, R2H_ULONG timeout,
																				R2H_BYTE slaveNodeAddress, R2H_BYTE classID, 
																				R2H_UINT16 instanceID, R2H_BYTE attributeID, 
																				R2H_BYTE* pAttributeData, R2H_BYTE dataBufferSizeInByte, R2H_BYTE* pActualWrDataBufferSizeInByte);
	void												SetPollingAssemblyPath(	R2H_INT32* pResult, R2H_UINT16* pMessageComExecutionErrorCode, 
																				R2H_ULONG timeout,R2H_BYTE masterNodeAddress,
																				R2H_BYTE slaveNodeAddress, R2H_BYTE productedInstance, R2H_BYTE consumedInstance);
	
	void												ReadSlaveNodeDiagnosticInfo(R2H_INT32* pResult, R2H_UINT16* pMessageComExecutionErrorCode, R2H_ULONG timeout,
																					R2H_BYTE SlaveNodeAddress,
																					R2H_DNM_DEVICE_SLAVE_NODE_DIAGNOSTIC_INFO_T* info);
	void												ReadMasterNodeDiagnosticInfo(	R2H_DNM_DEVICE_X_STATUS_T* pXStatus,
																						R2H_DNM_DEVICE_IO_COMMUNICATION_STATUS_T* pIOCommunicationStatus,
																						R2H_DNM_DEVICE_NETWORK_STATUS_T* pNetworkStatus,
																						R2H_DNM_DEVICE_MASTER_NODE_DIAGNOSTIC_INFO_T* pMasterNodeDiagnosticInfo);
	void 												ReadSlaveNodeErrorCode(R2H_BYTE slaveNodeAddress, R2H_UINT16* error);
	
	void												ReadLinkScanTimeArea(R2H_UINT16* pCurrentLinkScanTime, R2H_UINT16* pMinimumLinkScanTime, R2H_UINT16* pMaximumLinkScanTime);
	
	//void												ReadMasterReceivedData(R2H_UINT16 *pDataBuffer, R2H_UINT16 offsetInWord, R2H_UINT16 readSizeInWord, R2H_UINT16 *pActualReadSizeInWord);
	//void												WriteMasterTransmitData(R2H_UINT16 *pDataBuffer, R2H_UINT16 offsetInWord, R2H_UINT16 writeSizeInWord, R2H_UINT16 *pActualWriteSizeInWord);
	void 												ExchangeProcessData(R2H_UINT16 *pReadDataBuffer, R2H_UINT16 readOffsetInWord, R2H_UINT16 readSizeInWord, R2H_UINT16 *pActualReadSizeInWord,
																				R2H_UINT16 *pWriteDataBuffer, R2H_UINT16 writeOffsetInWord, R2H_UINT16 writeSizeInWord, R2H_UINT16 *pActualWriteSizeInWord);
		
	void 												ResetDeviceDataBuffer();
	
	R2H_UINT32											SyncRefreshPriority();
private:
	R2H_INT32											__check_slave_node_parameter(R2H_DNM_DEVICE_SLAVE_NODE_PARAM_T* param);
	vector<__R2H_DNM_DEVICE_SLAVE_NODE_INFO_T>			__slave_node_info;
	
	//bool												__sync_access_mutex_owned;
	bool												__sync_exchange_request;
	bool 												__sync_exchange_thread_exit;
	pthread_mutex_t										__sync_access_mutex;
	pthread_cond_t										__sync_exchange_event;
	R2H_UINT16											__sync_rx_data_buffer[R2H_DNM_IO_RX_DATA_LENGTH_IN_WORD_MAX];
	R2H_UINT16											__sync_tx_data_buffer[R2H_DNM_IO_TX_DATA_LENGTH_IN_WORD_MAX];
	
	static void* 										__dnet_buffer_sync_refresh_routine(void *host);
	pthread_t 											__dnet_buffer_sync_refresh_task_id;	
	R2H_UINT32											__sync_refresh_priority;
	
	R2H_UINT16 __rx_offset_in_word, __rx_size_in_word;
	R2H_UINT16 __tx_offset_in_word, __tx_size_in_word;
protected:
	R2H_ExtModule_DeviceNetMasterDevice(R2H_UINT16 baseAddress, R2H_UINT32 bufferSyncRefreshPosixPriority, 
			R2H_UINT16 rxOffsetInWord, R2H_UINT16 rxSizeInWord,
			R2H_UINT16 txOffsetInWord, R2H_UINT16 txSizeInWord);
};

inline R2H_UINT32 R2H_ExtModule_DeviceNetMasterDevice::SyncRefreshPriority()
{
	return __sync_refresh_priority;
}


#endif /* R2H_EXTMODULE_DNM_DEVICE_H_ */
