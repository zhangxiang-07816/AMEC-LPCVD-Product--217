/*
 * r2h_extmodule_soft_ccpu_device.h
 *
 *  Created on: 2021-2-18
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_SOFT_CCPU_DEVICE_H_
#define R2H_EXTMODULE_SOFT_CCPU_DEVICE_H_

#include <vxworks.h>
#include <assert.h>
#include "../BaseDevice/r2h_extmodule_base_device.h"
#include "../BaseDevice/r2h_extmodule_base_device_def.h"
#include "../r2h_extmodule_data_type.h"
#include "r2h_extmodule_soft_ccpu_device_def.h"
#include "CCPUFunc.h"

class R2H_ExtModule_SoftCCPUDevice: public R2H_ExtModule_BaseDevice
{
public:
	static R2H_INT32 						CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_SoftCCPUDevice **ppDevice);
	virtual 								~R2H_ExtModule_SoftCCPUDevice();
	
	void 									ReadInWord(R2H_UINT32 wordIndex, R2H_UINT32 sizeInWord, R2H_UINT16* pResult);
	void 									WriteInWord(R2H_UINT32 wordIndex, R2H_UINT32 sizeInWord, R2H_UINT16* pUserData);
	
	static void								ReadInWord(R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID_T id, R2H_UINT32 wordIndex, R2H_UINT32 sizeInWord, R2H_UINT16* pResult);
	static void								WriteInWord(R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID_T id, R2H_UINT32 wordIndex, R2H_UINT32 sizeInWord, R2H_UINT16* pUserData);
	
	R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID_T		GetSoftCCPUDeviceType();
protected:
	R2H_ExtModule_SoftCCPUDevice(R2H_UINT16 baseAddress, R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID_T id);
	R2H_INT32 								_cpu_soft_ccpu_device_write_lock();
	R2H_INT32 								_cpu_soft_ccpu_device_read_lock();
	R2H_INT32 								_cpu_soft_ccpu_device_unlock();
private:
	R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID_T		__soft_device_type;
	spinlockTask_t							__soft_ccpu_device_rw_lock;
};



#endif /* R2H_EXTMODULE_SOFT_CCPU_DEVICE_H_ */
