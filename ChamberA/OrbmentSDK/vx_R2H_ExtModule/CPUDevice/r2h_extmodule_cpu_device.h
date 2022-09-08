/*
 * r2h_extmodule_cpu_device.h
 *
 *  Created on: 2018-11-1
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_CPU_DEVICE_H_
#define R2H_EXTMODULE_CPU_DEVICE_H_

#include <vxworks.h>
#include <assert.h>
#include "../BaseDevice/r2h_extmodule_base_device.h"
#include "../BaseDevice/r2h_extmodule_base_device_def.h"
#include "../r2h_extmodule_data_type.h"
#include "../r2h_extmodule_error_code.h"
#include "r2h_extmodule_cpu_device_def.h"
#include "CCPUFunc.h"

//typedef __attribute__((__aligned__((2))))R2H_UINT16 		HBUFFER_REGISTER;

class R2H_ExtModule_CPUDevice: public R2H_ExtModule_BaseDevice
{
public:
	R2H_ExtModule_CPUDevice(R2H_UINT16 baseAddress);	
	virtual ~R2H_ExtModule_CPUDevice();
	
	void									GetCPUAddress(R2H_UINT16* pBaseAddress);
	
	void 									ReadCPUHBufferMemory(R2H_UINT32 offsetInWord, R2H_UINT32 readSizeInWord, R2H_UINT16* pDataBuffer);
	void 									WriteCPUHBufferMemory(R2H_UINT32 offsetInWord, R2H_UINT32 writeSizeInWord, R2H_UINT16* pDataBuffer);
	
protected:
	R2H_UINT16								_cpu_base_address;
	
	R2H_INT32 								_cpu_buffer_write_lock();
	R2H_INT32 								_cpu_buffer_read_lock();
	R2H_INT32 								_cpu_buffer_unlock();
	R2H_INT32 								_cpu_h_buffer_write_lock();
	R2H_INT32 								_cpu_h_buffer_read_lock();
	R2H_INT32 								_cpu_h_buffer_unlock();
private:
	spinlockTask_t							__cpu_buffer_rw_lock;
	spinlockTask_t							__cpu_h_buffer_rw_lock;
};

#endif /* R2H_EXTMODULE_CPU_DEVICE_H_ */
