/*
 * r2h_ethmodule_smart_gateway.h
 *
 *  Created on: 2019-1-30
 *      Author: CrazyHein
 */

#ifndef R2H_ETHMODULE_SMART_GATEWAY_H_
#define R2H_ETHMODULE_SMART_GATEWAY_H_

#include "r2h_ethmodule_smart_gateway_def.h"
#include "../SocketDevice/r2h_ethmodule_socket_device.h"
#include "../Protocol/TCP/ModbusLite/modbus_tcp_lite.h"

using namespace R2H_ETHMODULE_PROTOCOL_PACKAGE;

class R2H_EthModule_SmartGateway : public R2H_EthModule_SocketDevice
{
public:
	virtual ~R2H_EthModule_SmartGateway();
	
	static R2H_INT32 CreateInstance(
			R2H_CONST_STRING 				ip,
			R2H_TCP_PORT 					port,
			R2H_INT32						timeout, 
			R2H_INT32						timer, 
			R2H_INT32						interval, 
			R2H_ETHMODULE_DEVICE_MODEL_ID 	id, 
			R2H_UINT32 						bufferSyncRefreshPosixPriority,
			R2H_UINT16 						inputDataOffsetInWord, R2H_UINT16 inputDataSizeInWord,
			R2H_UINT16 						outputDataOffsetInWord, R2H_UINT16 outputDataSizeInWord,
			R2H_EthModule_SmartGateway 		**ppDevice);
	
	void ReadHostDiagnosticInfo(R2H_ETHMODULE_SMART_GATEWAY_HOST_DIAGNOSTIC_INFO_T* info);
	void ReadHostBasicInfo(R2H_ETHMODULE_SMART_GATEWAY_HOST_BASIC_INFO_T* info);
	void ReadDeviceDiagnosticInfo(R2H_ETHMODULE_SMART_GATEWAY_DEVICE_DIAGNOSTIC_INFO_T* info);
	void ReadUserData(R2H_UINT16 offsetInWord, R2H_UINT16 sizeInWord, R2H_UINT16* pDataBuffer);
	void WriteUserData(R2H_UINT16 offsetInWord, R2H_UINT16 sizeInWord, R2H_UINT16* pDataBuffer);
	void ReadHostControlResult(R2H_UINT16 offsetInWord, R2H_UINT16 sizeInWord, R2H_UINT16* pDataBuffer);
	void ReadHostControlCommand(R2H_UINT16 offsetInWord, R2H_UINT16 sizeInWord, R2H_UINT16* pDataBuffer);
	void WriteHostControlCommand(R2H_UINT16 offsetInWord, R2H_UINT16 sizeInWord, R2H_UINT16* pDataBuffer);
protected:
	R2H_EthModule_SmartGateway(	R2H_CONST_STRING 				ip,
								R2H_TCP_PORT 					port,
								R2H_INT32						timeout, 
								R2H_INT32						timer, 
								R2H_INT32						interval, 
								R2H_UINT32 						bufferSyncRefreshPosixPriority,
								R2H_UINT16 						inputDataOffsetInWord, R2H_UINT16 inputDataSizeInWord,
								R2H_UINT16 						outputDataOffsetInWord, R2H_UINT16 outputDataSizeInWord,
								R2H_UINT16 						userBufferSizeInWord);
private:
	MODBUS_TCP_HOLDING_REGISTER*							__host_buffer, *__device_buffer;
	R2H_UINT16												__user_buffer_size_in_word;
	R2H_ETHMODULE_SMART_GATEWAY_DEVICE_DIAGNOSTIC_INFO_T*  	__smart_gateway_device_diagnostic_info;
	MODBUS_TCP_HOLDING_REGISTER*							__host_user_data_buffer;
	MODBUS_TCP_HOLDING_REGISTER*							__host_control_result_buffer;
	MODBUS_TCP_HOLDING_REGISTER*							__host_control_command_buffer;
	R2H_ETHMODULE_SMART_GATEWAY_HOST_DIAGNOSTIC_INFO_T		__smart_gateway_host_diagnostic_info;
	R2H_ETHMODULE_SMART_GATEWAY_HOST_BASIC_INFO_T			__smart_gateway_host_basic_info;
	ModbusTcpLite 											__modbus_tcp_lite_protocol;
	//pthread_mutex_t										__sync_access_mutex;
	spinlockTask_t											__sync_access_mutex;
	bool													__sync_refresh_thread_exit;
	static void* 											__buffer_sync_refresh_routine(void *host);
	pthread_t 												__buffer_sync_refresh_task_id;
};


#endif /* R2H_ETHMODULE_SMART_GATEWAY_H_ */
