/*
 * r2h_ethmodule_startup.h
 *
 *  Created on: 2019-1-30
 *      Author: CrazyHein
 */

#ifndef R2H_ETHMODULE_STARTUP_H_
#define R2H_ETHMODULE_STARTUP_H_

#include "r2h_ethmodule_startup_constant_def.h"
#include "../r2h_ethmodule_data_type.h"
#include "../Socket/r2h_ethmodule_socket.h"
#include "../SocketDevice/r2h_ethmodule_socket_device_def.h"
#include "../SocketDevice/r2h_ethmodule_socket_device.h"
#include "../SmartGateway/r2h_ethmodule_smart_gateway.h"
#include "../SerialPortServer/r2h_ethmodule_serial_port_server.h"

#ifdef __cplusplus
	extern "C" {
#endif

R2H_INT32 vx_R2H_EthModule_CreateSmartGateway(
		R2H_CONST_STRING 				ip,
		R2H_TCP_PORT 					port,
		R2H_INT32						timeout, 
		R2H_INT32						timer, 
		R2H_INT32						interval, 
		R2H_ETHMODULE_DEVICE_MODEL_ID 	id, 
		R2H_UINT32 bufferSyncRefreshPosixPriority,
		R2H_UINT16 inputDataOffsetInWord, R2H_UINT16 inputDataSizeInWord,
		R2H_UINT16 outputDataOffsetInWord, R2H_UINT16 outputDataSizeInWord,
		R2H_EthModule_SmartGateway 		**ppDevice);

R2H_INT32 vx_R2H_EthModule_CreateSerialPortServer(
		R2H_CONST_STRING					remoteIP, 		R2H_UINT16							remotePort,
		R2H_UINT32							syncPriority, 	R2H_INT32							timerIndex,
		R2H_INT32							timeout, 		R2H_INT32							interval,
		std::vector<R2H_ETHMODULE_SERIAL_PORT_SERVER_SLVS_PDO> &slaves,
		R2H_ETHMODULE_DEVICE_MODEL_ID 		id, 			R2H_EthModule_SerialPortServer 		**ppDevice);

void vx_R2H_EthModule_DestoryDevice						(R2H_EthModule_SocketDevice* pDevice);

void vx_R2H_EthModule_Version							(R2H_UINT32 *pRelease, R2H_UINT32 *pBuild);
	
#ifdef __cplusplus
	}
#endif

#endif /* R2H_ETHMODULE_STARTUP_H_ */
