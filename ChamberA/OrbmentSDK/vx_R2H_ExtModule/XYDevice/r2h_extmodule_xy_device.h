/*
 * r2h_extmodule_xydevice.h
 *
 *  Created on: 2018-6-19
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_XY_DEVICE_H_
#define R2H_EXTMODULE_XY_DEVICE_H_

#include <vxworks.h>
#include <assert.h>
//#include <spinLockLib.h>
#include "../BaseDevice/r2h_extmodule_base_device.h"
#include "../BaseDevice/r2h_extmodule_base_device_def.h"
#include "../r2h_extmodule_data_type.h"
#include "../r2h_extmodule_error_code.h"
#include "r2h_extmodule_xy_device_def.h"
#include "CCPUFunc.h"

class R2H_ExtModule_XYDevice: public R2H_ExtModule_BaseDevice
{
public:
	static R2H_INT32 						CreateInstance(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_XYDevice **ppDevice);
	virtual ~R2H_ExtModule_XYDevice();
	
	void 									ReadXInBit(R2H_UINT16 bitIndex, R2H_UINT16* pResult);
	void 									ReadYInBit(R2H_UINT16 bitIndex, R2H_UINT16* pResult);	
	void 									WriteYInBit(R2H_UINT16 bitIndex, R2H_UINT16 userData);
	
	void 									ReadXInWord(R2H_UINT16 wordIndex, R2H_UINT16 sizeInWord, R2H_UINT16* pResult);
	void 									ReadYInWord(R2H_UINT16 wordIndex, R2H_UINT16 sizeInWord, R2H_UINT16* pResult);
	void 									WriteYInWord(R2H_UINT16 wordIndex, R2H_UINT16 sizeInWord, R2H_UINT16* pUserData);

	void									GetDeviceXYAccessMode(R2H_XY_DEVICE_ACCESS_MODE_T *pAccessMode);
protected:
	R2H_ExtModule_XYDevice(R2H_UINT16 baseAddress, R2H_UINT16 sizeInBit, R2H_XY_DEVICE_ACCESS_MODE_T mode);
	
	R2H_INT32 								_xy_write_lock();
	R2H_INT32 								_xy_read_lock();
	R2H_INT32 								_xy_unlock();
private:
	R2H_XY_DEVICE_ACCESS_MODE_T				__device_access_mode;

	spinlockTask_t							__xy_rw_lock;
};



#endif /* R2H_EXTMODULE_XYDEVICE_H_ */
