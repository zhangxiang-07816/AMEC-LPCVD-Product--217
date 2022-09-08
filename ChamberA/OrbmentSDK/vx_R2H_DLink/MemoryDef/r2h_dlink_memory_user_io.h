/*
 * r2h_dlink_memory_user_io.h
 *
 *  Created on: 2017-7-28
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_USER_IO_H_
#define R2H_DLINK_MEMORY_USER_IO_H_

#include "r2h_dlink_memory_def.h"
#include "r2h_dlink_memory.h"
#include "../r2h_dlink_error_code.h"

class R2H_DLink_MemoryUserIO: public R2H_DLink_Memory
{
private:
	R2H_INT32 		__memory_size_in_byte;
	R2H_BYTE* 		__memory_ptr;
	void* 			__rw_lock;
public:
	R2H_DLink_MemoryUserIO(R2H_INT32 sizeInByte);
	virtual ~R2H_DLink_MemoryUserIO();
	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength);
};


#endif /* R2H_DLINK_MEMORY_USER_IO_H_ */
