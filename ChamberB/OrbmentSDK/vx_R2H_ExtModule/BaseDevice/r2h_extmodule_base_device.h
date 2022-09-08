/*
 * r2h_extmodule_base_device.h
 *
 *  Created on: 2018-6-20
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_BASE_DEVICE_H_
#define R2H_EXTMODULE_BASE_DEVICE_H_


#include <vxworks.h>
#include <pthread.h>
#include <sysLib.h>
#include <exception>
#include <spinLockLib.h>
#include "r2h_extmodule_base_device_def.h"
#include "../r2h_extmodule_data_type.h"
#include "../r2h_extmodule_error_code.h"

class R2H_ExtModule_BaseDevice
{
public:
	R2H_ExtModule_BaseDevice(R2H_UINT16 baseAddress, R2H_UINT16 sizeInBit);
	virtual ~R2H_ExtModule_BaseDevice();
	
	R2H_EXTMODULE_DEVICE_MODEL_ID_T			DeviceModelIdentifier();
	virtual	R2H_UINT32						GetDeviceModuleSwitch();
	virtual	R2H_INT32						SetDeviceModuleSwitch(R2H_UINT32 sw);
	void									GetDeviceAddress(R2H_UINT16* pBaseAddress, R2H_UINT16* pSizeInBit);
	R2H_INT32								DeviceWriteLock(timespec* pTimeout);
	R2H_INT32								DeviceReadLock(timespec* pTimeout);
	R2H_INT32								DeviceUnlock();
private:
	SEM_ID									__device_rw_lock;
	R2H_INT32 								__sys_ticks_per_second;
	
	R2H_INT32 								__write_lock(SEM_ID lock, timespec* pTimeout);
	R2H_INT32 								__read_lock(SEM_ID lock, timespec* pTimeout);
	R2H_INT32 								__unlock(SEM_ID lock);

	
	R2H_ExtModule_BaseDevice(const R2H_ExtModule_BaseDevice&);
	R2H_ExtModule_BaseDevice& operator=(const R2H_ExtModule_BaseDevice&);
protected:
	R2H_INT32 								_device_write_lock(timespec* pTimeout);
	R2H_INT32 								_device_read_lock(timespec* pTimeout);
	R2H_INT32 								_device_unlock();
	
	R2H_INT32 								_write_lock(spinlockTask_t *lock);
	R2H_INT32 								_read_lock(spinlockTask_t *lock);
	R2H_INT32 								_unlock(spinlockTask_t *lock);

	R2H_EXTMODULE_DEVICE_MODEL_ID_T			_device_model_identifier;
	R2H_UINT16								_device_base_address;
	R2H_UINT16								_device_xy_size_in_bit;
};


class R2H_ExtModule_Exception : public std::exception
{
public:
	R2H_ExtModule_Exception(R2H_INT32 errorCode);
	virtual ~R2H_ExtModule_Exception();
	R2H_INT32 ReturnErrorCode();
private:
	R2H_INT32			__r2h_extmodule_error_code;
};


#endif /* R2H_EXTMODULE_BASE_DEVICE_H_ */
