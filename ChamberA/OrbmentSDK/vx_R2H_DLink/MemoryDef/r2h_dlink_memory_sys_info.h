/*
 * r2h_dlink_remote_sys_info_utility.h
 *
 *  Created on: 2017-7-24
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_SYS_INFO_H_
#define R2H_DLINK_MEMORY_SYS_INFO_H_

#include "r2h_dlink_memory_def.h"
#include "r2h_dlink_memory.h"
#include "../r2h_dlink_error_code.h"


class R2H_DLink_MemorySysInfo: public R2H_DLink_Memory
{
private:
	R2H_RINFO_MEMORY_SEGMENT_SYS_INFO_T	__system_info;
	void* __rw_lock;
public:
	R2H_DLink_MemorySysInfo(R2H_RINFO_MEMORY_SEGMENT_SYS_INFO_T *pInfo);
	R2H_DLink_MemorySysInfo();
	virtual ~R2H_DLink_MemorySysInfo();
	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength);
};

#endif /* R2H_DLINK_REMOTE_SYS_INFO_UTILITY_H_ */
