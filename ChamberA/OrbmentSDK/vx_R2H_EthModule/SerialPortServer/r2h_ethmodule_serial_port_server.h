/*
 * r2h_ethmodule_serial_port_server.h
 *
 *  Created on: Jul 3, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_ETHMODULE_SERIAL_PORT_SERVER_H_
#define R2H_ETHMODULE_SERIAL_PORT_SERVER_H_

#include <vector>
#include <hash_map>
#include "r2h_ethmodule_serial_port_server_def.h"
#include "../Protocol/TCP/SimpleDataExchange/simple_data_exchange.h"
#include "../SocketDevice/r2h_ethmodule_socket_device.h"
#include "../Socket/r2h_ethmodule_socket_utility.h"

using namespace R2H_ETHMODULE_PROTOCOL_PACKAGE;
using namespace NEO_Socket;

class R2H_EthModule_SerialPortServer : public R2H_EthModule_SocketDevice
{
public:
	virtual ~R2H_EthModule_SerialPortServer();
	static R2H_INT32 CreateInstance(
			R2H_CONST_STRING					remoteIP, 		R2H_UINT16							remotePort,
			R2H_UINT32							syncPriority, 	R2H_INT32							timerIndex,
			R2H_INT32							timeout, 		R2H_INT32							interval,
			std::vector<R2H_ETHMODULE_SERIAL_PORT_SERVER_SLVS_PDO> &slaves,
			R2H_ETHMODULE_DEVICE_MODEL_ID 		id, 			R2H_EthModule_SerialPortServer 		**ppDevice);
	
	R2H_UINT16 QuantityOfDevices() const;
	R2H_UINT16 RxSizeInByte() const;
	R2H_UINT16 TxSizeInByte() const;
	
	R2H_INT32 SlaveTxPDOInfo(R2H_UINT16 addr, R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T* pPDO);
	R2H_INT32 SlaveRxPDOInfo(R2H_UINT16 addr, R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T* pPDO);
	R2H_INT32 SlaveIndex(R2H_UINT16 addr, R2H_UINT16* pIndex);
	
	void ReadLocalConfiguration(R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_INFO_T *pInfo);
	void ReadLocalDiagnostics(R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_DIAG_T *pDiag);
	
	void ReadRemoteConfiguration(R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_INFO_T *pInfo);
	void ReadRemoteDiagnostics(R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_T *pDiag);
	void ReadRemoteDiagnosticArea(R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_AREA_T *pArea);
	
	void ReadAll(R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_INFO_T *pLocalInfo, 
			R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_DIAG_T *pLocalDiag,
			R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_AREA_T *pRemoteDiagArea,
			R2H_UINT16 start, R2H_UINT16 size, R2H_BYTE* pData, R2H_UINT16* pReadSize);
	
	void ReadTxData(R2H_UINT16 start, R2H_UINT16 size, R2H_BYTE* pData, R2H_UINT16* pReadSize);
	void WriteRxData(R2H_UINT16 start, R2H_UINT16 size, R2H_BYTE* pData, R2H_UINT16* pWriteSize);
	
	static const char*									DATA_SYNC_TASK_NAME;
private:
	R2H_EthModule_SerialPortServer(			
			R2H_CONST_STRING					remoteIP, 		R2H_UINT16							remotePort,
			R2H_UINT32							syncPriority, 	R2H_INT32							timerIndex,
			R2H_INT32							timeout, 		R2H_INT32							interval,
			std::vector<R2H_ETHMODULE_SERIAL_PORT_SERVER_SLVS_PDO> &slaves);
	
	R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_AREA_T	__remote_diag_area;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_INFO_T		__local_info;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_DIAG_T		__local_diag;
	
	pthread_t 											__sync_task;
	static void* 										__sync_routine(void *host);
	pthread_mutex_t										__sync_access_mutex;
	
	SDEProtocol											__protocol;
	
	bool												__sync_task_terminate;
	
	R2H_BYTE											*__tx_data;
	R2H_BYTE											*__rx_data;
	R2H_BYTE											*__tx_data_temp;
	R2H_BYTE											*__rx_data_temp;
	R2H_UINT16											__quantity_of_slave_node;
	std::hash_map<R2H_UINT16, R2H_UINT16> 				__slave_addr_to_index;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T			__tx_data_pdo_index[SERIAL_PORT_SERVER_SLV_DEVICE_NODES];
	R2H_ETHMODULE_SERIAL_PORT_SERVER_SLV_PDO_T			__rx_data_pdo_index[SERIAL_PORT_SERVER_SLV_DEVICE_NODES];
	void												__build_slave_index(std::vector<R2H_ETHMODULE_SERIAL_PORT_SERVER_SLVS_PDO> &slaves);
	void												__clear_slave_index();
	
	
};

inline R2H_UINT16 R2H_EthModule_SerialPortServer::QuantityOfDevices() const{return __quantity_of_slave_node;}
inline R2H_UINT16 R2H_EthModule_SerialPortServer::RxSizeInByte() const{return __local_info.rx_size_in_byte;}
inline R2H_UINT16 R2H_EthModule_SerialPortServer::TxSizeInByte() const{return __local_info.tx_size_in_byte;}



#endif /* R2H_ETHMODULE_SERIAL_PORT_SERVER_H_ */
