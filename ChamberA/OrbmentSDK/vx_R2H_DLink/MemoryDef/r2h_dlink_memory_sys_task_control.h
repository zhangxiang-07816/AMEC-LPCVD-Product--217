/*
 * r2h_dlink_memory_sys_task_control.h
 *
 *  Created on: 2017-7-28
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_SYS_TASK_CONTROL_H_
#define R2H_DLINK_MEMORY_SYS_TASK_CONTROL_H_

#include "r2h_dlink_memory_def.h"
#include "r2h_dlink_memory.h"
#include "../r2h_dlink_error_code.h"

typedef union MEMORY_CONTROL_REGION_MASK
{
	struct
	{
		R2H_UINT16	control_in : 1;
		R2H_UINT16	control_out : 1;
	};
	R2H_UINT16 control_mask;
}MEMORY_CONTROL_REGION_MASK_T;


class R2H_DLink_MemorySystemControl: public R2H_DLink_Memory
{
private:
	R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_IN_T 	__sys_control_in;
	R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_OUT_T 	__sys_control_out;
	void* __rw_lock;
public:
	R2H_DLink_MemorySystemControl();
	virtual ~R2H_DLink_MemorySystemControl();
	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength);
};

class R2H_DLink_MemoryTaskControl: public R2H_DLink_Memory
{
private:
	R2H_RINFO_MEMORY_SEGMENT_TASK_CONTROL_IN_T 		__task_control_in;
	R2H_RINFO_MEMORY_SEGMENT_TASK_CONTROL_OUT_T 	__task_control_out;
	void* __rw_lock;
public:
	R2H_DLink_MemoryTaskControl();
	virtual ~R2H_DLink_MemoryTaskControl();
	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength);
};

#endif /* R2H_DLINK_MEMORY_SYS_TASK_CONTROL_H_ */
