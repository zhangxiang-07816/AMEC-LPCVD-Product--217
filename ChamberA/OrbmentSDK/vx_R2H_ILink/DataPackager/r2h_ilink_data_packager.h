/*
 * r2h_ilink_data_packager.h
 *
 *  Created on: 2020-4-10
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_DATA_PACKAGER_H_
#define R2H_ILINK_DATA_PACKAGER_H_

#ifdef _WRS_VX_SMP
#include <pthread.h>
#include <vxWorks.h>
#elif WIN32
#include <winsock2.h>
#include <windows.h>
#endif

#include <string.h>
#include <assert.h>
#include "../r2h_ilink_data_type.h"
#include "../Utility/socket/r2h_ilink_socket.h"
#include "r2h_ilink_data_packager_def.h"
#include "../Exception/r2h_ilink_exception.h"

namespace R2H_ILINK
{

class ILinkPackagerAccessLock
{
public:
	ILinkPackagerAccessLock();
	ILinkPackagerAccessLock(const ILinkPackagerAccessLock&);
	ILinkPackagerAccessLock& operator=(const ILinkPackagerAccessLock&);
	virtual ~ILinkPackagerAccessLock();
	inline void				Lock() const;
	inline void				Unlock() const;
private:
#ifdef _WRS_VX_SMP
	SEM_ID					__sync_access_mutex;
#elif WIN32	
	HANDLE					__sync_access_mutex;
#endif
};


#ifdef _WRS_VX_SMP
void ILinkPackagerAccessLock::Lock() const
{
	semTake(__sync_access_mutex, WAIT_FOREVER);
}
void ILinkPackagerAccessLock::Unlock() const
{
	semGive(__sync_access_mutex);
}
#elif WIN32
void ILinkPackagerAccessLock::Lock() const
{
	WaitForSingleObject(__sync_access_mutex, INFINITE);
}
void ILinkPackagerAccessLock::Unlock() const
{
	ReleaseMutex(__sync_access_mutex);
}
#endif

class DataPackager
{
public:
	DataPackager(ILinkPackagerAccessLock *pLock);
	DataPackager(const DataPackager&);
	DataPackager& operator=(const DataPackager&);
	virtual ~DataPackager();
	R2H_INT32 			DataRecv(R2H_BYTE *pBuffer, R2H_INT32 bufferSizeInByte, R2H_INT32* pRecvSizeInByte, R2H_INT32 timeout);
	R2H_INT32 			DataSend(R2H_BYTE *pData, R2H_INT32 dataSizeInByte, R2H_INT32* pSendSizeInByte, R2H_INT32 timeout);
private:
	R2H_INT32			__recv_package(	DATA_PACKAGE_HEAD_T *header,
										R2H_BYTE *pBuffer,R2H_INT32 bufferSizeInByte, R2H_INT32* pRecvSizeInByte,
										R2H_INT32 timeout);
	R2H_INT32			__send_package(	R2H_BYTE *pBuffer,R2H_INT32 bufferSizeInByte, R2H_INT32* pSendSizeInByte,
										R2H_UINT32 totalLength, R2H_UINT16 index, R2H_INT32 timeout);

	R2H_UINT16					__r2h_package_data_length;
	ILinkPackagerAccessLock* 		__sync_access_mutex;

	R2H_BYTE					__package_index_mask[MAX_PACKAGE_QUANTITY / 8];
	inline void					__reset_package_index_mask();
	inline void					__set_package_index_mask(R2H_UINT16);
	inline bool					__test_package_index_mask(R2H_UINT16);
protected:
	R2H_SOCKET					_r2h_socket;
};

inline void DataPackager::__reset_package_index_mask()
{
	memset(__package_index_mask, 0, MAX_PACKAGE_QUANTITY / 8);
}

inline void DataPackager::__set_package_index_mask(R2H_UINT16 index)
{
	*(__package_index_mask + index / 8) |= (1 << index % 8);
}

inline bool DataPackager::__test_package_index_mask(R2H_UINT16 index)
{
	return ((*(__package_index_mask + index / 8)) & (1 << index % 8)) != 0;
}

}

#endif /* R2H_ILINK_DATA_PACKAGER_H_ */
