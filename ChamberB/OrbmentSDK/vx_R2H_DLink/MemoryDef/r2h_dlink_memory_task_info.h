/*
 * r2h_dlink_memory_task_info.h
 *
 *  Created on: 2017-7-28
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_TASK_INFO_H_
#define R2H_DLINK_MEMORY_TASK_INFO_H_

#include "r2h_dlink_memory_def.h"
#include "r2h_dlink_memory.h"
#include "../r2h_dlink_error_code.h"
#include <vector>
using namespace std;


#define R2H_MEMORY_TASK_INFO_TASKHEAD_ADDR 				(0)
#define R2H_MEMORY_TASK_INFO_ADDR_TO_TASK_INDEX(addr)			(addr-1)
#define R2H_MEMORY_TASK_INFO_MAKE_TASK_ADDR(index)		(index+1)

typedef vector<R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM_P> 	TASK_INFO_PTR_VECTOR;
typedef vector<void*> 	TASK_INFO_RW_LOCK_VECTOR;

class R2H_DLink_MemoryTaskInfo: public R2H_DLink_Memory
{
private:
	TASK_INFO_PTR_VECTOR 						__task_info_ptr_vector;
	TASK_INFO_RW_LOCK_VECTOR					__task_info_rw_lock_vector;
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_HEAD_T	__task_info_segment_header;
public:
	R2H_DLink_MemoryTaskInfo(R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_HEAD_T *pTaskHead);
	virtual ~R2H_DLink_MemoryTaskInfo();
	R2H_INT32 AddTaskInfo(R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM_P pInfo);
	R2H_UINT32 QuantityOfTaskInfo();

	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength);
};



#endif /* R2H_DLINK_MEMORY_TASK_INFO_H_ */
