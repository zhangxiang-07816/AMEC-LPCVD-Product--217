/*
 * r2h_extmodule_buffer_device.h
 *
 *  Created on: 2018-6-22
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_BUFFER_DEVICE_H_
#define R2H_EXTMODULE_BUFFER_DEVICE_H_

#include "r2h_extmodule_buffer_device_def.h"
#include "../XYDevice/r2h_extmodule_xy_device.h"
#include "../r2h_extmodule_data_type.h"
#include "../r2h_extmodule_error_code.h"

class R2H_ExtModule_BufferDevice: public R2H_ExtModule_XYDevice
{
public:
	R2H_ExtModule_BufferDevice(R2H_UINT16 baseAddress, R2H_UINT16 sizeInBit);
	virtual ~R2H_ExtModule_BufferDevice();
	
	void ReadBufferMemory(R2H_UINT32 offsetInWord, R2H_UINT32 readSizeInWord, R2H_UINT16* pDataBuffer);
	void WriteBufferMemory(R2H_UINT32 offsetInWord, R2H_UINT32 writeSizeInWord, R2H_UINT16* pDataBuffer);
	
	virtual	void ModuleReadyFlag(R2H_UINT16* pReadyFlag) = 0;
	
protected:
	R2H_INT32 								_buffer_write_lock();
	R2H_INT32 								_buffer_read_lock();
	R2H_INT32 								_buffer_unlock();
private:
	spinlockTask_t							__buffer_rw_lock;
};

#endif /* R2H_EXTMODULE_BUFFER_DEVICE_H_ */
