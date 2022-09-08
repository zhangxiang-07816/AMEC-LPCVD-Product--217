/*
 * r2h_dlink_remote_device_io_utility.h
 *
 *  Created on: 2017-7-25
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_DEVICE_IO_H_
#define R2H_DLINK_MEMORY_DEVICE_IO_H_

#include "r2h_dlink_memory_def.h"
#include "r2h_dlink_memory.h"
#include "../r2h_dlink_error_code.h"
#include "r2h_dlink_memory.h"
//#include <pthread.h>
#include <vector>

using namespace std;

typedef class R2H_DLink_IODevice
{
private:
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_ATTR_T __device_attribute;
	void* __rw_lock;
protected:
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T _device_status;
	R2H_BYTE* _device_process_in;
	R2H_BYTE* _device_control_out;
	R2H_BYTE* _device_process_out;
	R2H_BYTE* _device_control_in;
	//pthread_rwlock_t 							syncLockProcessIn;
	//pthread_rwlock_t 							syncLockControlOut;
	//pthread_rwlock_t 							syncLockProcessOut;
	//pthread_rwlock_t 							syncLockControlIn;
	//pthread_rwlock_t 							syncLockOthers;
public:
	R2H_DLink_IODevice(R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_ATTR_T* pDeviceAttribute);
	virtual ~R2H_DLink_IODevice();
	//void SetIODeviceStatus(R2H_INT32 code,R2H_UINT32 sec, R2H_UINT32 nsec);
	//void GetIODeviceStatus(R2H_INT32 *code,R2H_UINT32 *sec, R2H_UINT32 *nsec);

	R2H_INT32 ReadDeviceAttribute(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 ReadDeviceStatus(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 ReadDeviceProcessIn(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 ReadDeviceControlOut(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 ReadDeviceProcessOut(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 ReadDeviceControlIn(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 WriteDeviceAttribute(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 WriteDeviceStatus(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 WriteDeviceProcessIn(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 WriteDeviceControlOut(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 WriteDeviceProcessOut(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_INT32 WriteDeviceControlIn(R2H_UINT32 offset, R2H_INT32 length, R2H_BYTE* pData);
	R2H_UINT32 ProcessInSize();
	R2H_UINT32 ControlOutSize();
	R2H_UINT32 ProcessOutSize();
	R2H_UINT32 ControlInSize();

}*R2H_DLink_IODevice_P,R2H_DLink_IODevice_T;

typedef vector<R2H_DLink_IODevice_P> 	IO_DEVICE_PTR_VECTOR;
#define R2H_MEMORY_DEVICE_IO_ADDR_TO_INDEX(address)			((R2H_UINT16)(address>>16))
#define R2H_MEMORY_DEVICE_IO_ADDR_TO_REGION(address)			((R2H_UINT16)(address&0x0000FFFF))
#define R2H_MEMORY_DEVICE_IO_MAKE_ADDR(index,region)		((R2H_UINT32)((index<<16) + region.io_mask))
typedef union MEMORY_DEVICE_IO_REGION_MASK
{
	struct
	{
		R2H_UINT16	memory_segment_info : 1;
		R2H_UINT16	device_attribute : 1;
		R2H_UINT16	device_status : 1;
		R2H_UINT16	device_process_in : 1;
		R2H_UINT16	device_control_out : 1;
		R2H_UINT16	device_process_out : 1;
		R2H_UINT16	device_control_in : 1;
	};
	R2H_UINT16 io_mask;
}MEMORY_DEVICE_IO_REGION_MASK_T;

class R2H_DLink_MemoryDeviceIO: public R2H_DLink_Memory
{
public:
	R2H_DLink_MemoryDeviceIO(R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_HEAD_T *head);
	virtual ~R2H_DLink_MemoryDeviceIO();
	virtual R2H_INT32 HostWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceWrite(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 DeviceRead(R2H_UINT32 start, R2H_INT32 *pLength, R2H_BYTE *pData);
	virtual R2H_INT32 HostCanRead(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	virtual R2H_INT32 HostCanWrite(R2H_UINT32 start, R2H_INT32 *pMaxLength);
	R2H_INT32 AddIODevice(R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_ATTR_T* pDeviceAttribute);
	void ClearIODevice();
	R2H_UINT32 QuantityOfDeviceIO();
private:
	IO_DEVICE_PTR_VECTOR 						__io_device_ptr_vector;
	R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_HEAD_T 	__segment_info;
};


#endif /* R2H_DLINK_MEMORY_DEVICE_IO_H_ */
