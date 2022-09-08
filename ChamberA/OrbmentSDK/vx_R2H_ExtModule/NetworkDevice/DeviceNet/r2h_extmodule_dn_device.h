/*
 * r2h_extmodule_dn_device.h
 *
 *  Created on: 2018-8-13
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_DN_DEVICE_H_
#define R2H_EXTMODULE_DN_DEVICE_H_

#include "r2h_extmodule_dn_device_buffer_address.h"
#include "r2h_extmodule_dn_device_def.h"
#include "../../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../../r2h_extmodule_data_type.h"
#include "../../r2h_extmodule_error_code.h"
#include <vxWorks.h>


class R2H_ExtModule_DeviceNetDevice: public R2H_ExtModule_BufferDevice
{
public:
	R2H_ExtModule_DeviceNetDevice(R2H_UINT16 baseAddress);
	virtual ~R2H_ExtModule_DeviceNetDevice();
	
	void							GetModelInfo(	R2H_DN_DEVICE_MODEL_NAME nameBuffer,
													R2H_UINT16 *pNodeAddress,
													R2H_DN_DEVICE_MODE_SWITCH_T *pModeSwitch);
	void							ModuleReadyFlag(R2H_UINT16 *pReadyFlag);	
	R2H_INT16 						DNTRefreshBufferMemory(R2H_ULONG timeout);	
	virtual void 					ResetDeviceDataBuffer() = 0;
};


#endif /* R2H_EXTMODULE_DN_DEVICE_H_ */
