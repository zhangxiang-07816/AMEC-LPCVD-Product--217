/*
 * simple_data_exchange.h
 *
 *  Created on: Jul 2, 2022
 *      Author: HaihangRen
 */

#ifndef SIMPLE_DATA_EXCHANGE_H_
#define SIMPLE_DATA_EXCHANGE_H_

#include "simple_data_exchange_def.h"
#include <pthread.h>

namespace R2H_ETHMODULE_PROTOCOL_PACKAGE
{
class SDEProtocol
{
public:
	SDEProtocol(R2H_SOCKET tcp, pthread_mutex_t *pMutex);
	virtual ~SDEProtocol();
	
	void SetSocket(R2H_SOCKET tcp);
	R2H_BYTE SyncData(SDE_FUNC_CODE_T func,
				R2H_UINT16 diagStart, R2H_UINT16 diagSize, R2H_BYTE* pDiag,
				R2H_UINT16 devTxStart, R2H_UINT16 devTxSize, R2H_BYTE* pDevTx,
				R2H_UINT16 devRxStart, R2H_UINT16 devRxSize, const R2H_BYTE* pDevRx,
				R2H_INT32 wtimeout, R2H_INT32 rtimeout, bool &exception);
	
	static const R2H_UINT32 BATCH_READ_LIMIT = 65535;
	static const R2H_UINT32 BATCH_WRITE_LIMIT = 65535;
	static const R2H_UINT16 AREA_ADDR_SIZE = 3 * sizeof(SDE_ADDR_T);
	static const char PROTOCOL_IDENTIFIER[];
	
private:
	R2H_SOCKET __tcp;
	R2H_BYTE __datagram[sizeof(SDE_DATAGRAM_HEADER_T) + 64 * 1024 - 1];
	pthread_mutex_t __mutex;
	pthread_mutex_t* __mutex_ptr;
	bool __internal_mutex;
	R2H_UINT16 __transaction;

	R2H_BYTE __recv_ack_datagram(R2H_INT32 rtimeout, bool &exception);
};
}

#endif /* SIMPLE_DATA_EXCHANGE_H_ */
