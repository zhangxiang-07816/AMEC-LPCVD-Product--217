/*
 * modbus_tcp_lite.h
 *
 *  Created on: 2019-1-31
 *      Author: CrazyHein
 */

#ifndef MODBUS_TCP_LITE_H_
#define MODBUS_TCP_LITE_H_

#include "modbus_tcp_lite_def.h"
#include "../../../Socket/r2h_ethmodule_socket.h"
#include <vxWorks.h>
#include <string>
#include <pthread.h>

namespace R2H_ETHMODULE_PROTOCOL_PACKAGE
{

class ModbusTcpLite
{
public:
	ModbusTcpLite(R2H_SOCKET socket);
	virtual ~ModbusTcpLite();
	R2H_INT32 ReadHoldingRegister(R2H_UINT16 offsetInRegister, R2H_UINT16 sizeInRegister, MODBUS_TCP_HOLDING_REGISTER *pRegisterValues, R2H_BYTE* pReadSizeInByte, R2H_BYTE* pExceptionCode, R2H_INT32 timeout);
	R2H_INT32 WriteMultipleRegister(R2H_UINT16 offsetInRegister, R2H_UINT16 sizeInRegister, MODBUS_TCP_HOLDING_REGISTER *pRegisterValues, R2H_BYTE* pWriteSizeInByte, R2H_BYTE* pExceptionCode, R2H_INT32 timeout);
	R2H_INT32 ReadHoldingRegisterEx(R2H_UINT16 offsetInRegister, R2H_UINT16 sizeInRegister, MODBUS_TCP_HOLDING_REGISTER *pRegisterValues, R2H_UINT16* pReadSizeInWord, R2H_BYTE* pExceptionCode, R2H_INT32 timeout);
	R2H_INT32 WriteMultipleRegisterEx(R2H_UINT16 offsetInRegister, R2H_UINT16 sizeInRegister, MODBUS_TCP_HOLDING_REGISTER *pRegisterValues, R2H_UINT16* pWriteSizeInWord, R2H_BYTE* pExceptionCode, R2H_INT32 timeout);
		
	void SetSocket(R2H_SOCKET socket);
private:
	R2H_SOCKET 											__socket;
	
	SEM_ID												__sync_access_mutex;
	MODBUS_TCP_APPLICATION_DATA_UNIT_T					__send_buffer;
	MODBUS_TCP_APPLICATION_DATA_UNIT_T					__recv_buffer;
	R2H_INT32											__send_modbus_tcp_message(R2H_UINT16 messageLength, R2H_UINT16 transactionIdentifier, R2H_BYTE unitIdentifier, R2H_INT32 timeout);
	R2H_INT32											__recv_modbus_tcp_message(R2H_UINT16 *pMessageLength, R2H_UINT16 *pTransactionIdentifier, R2H_BYTE *pUnitIdentifier, R2H_INT32 timeout);
	R2H_UINT16											__transaction_identifier;
	R2H_BYTE											__unit_identifier;
};




}

#endif /* MODBUS_TCP_LITE_H_ */
