/*
 * r2h_dlink_memory.h
 *
 *  Created on: 2017-7-26
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_H_
#define R2H_DLINK_MEMORY_H_

#include "r2h_dlink_memory_def.h"
#include <new>

class R2H_DLink_Memory
{
public:
	virtual ~R2H_DLink_Memory();
	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData) = 0;
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData) = 0;
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData) = 0;
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData) = 0;
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength) = 0;
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength) = 0;
	static void* CreateRWLock();
	static void DestoryRWLock(void* lock);
	static void	ReadLock(void* lock);
	static void	WriteLock(void* lock);
	static void	ReleaseLock(void* lock);
};


#endif /* R2H_DLINK_MEMORY_H_ */
