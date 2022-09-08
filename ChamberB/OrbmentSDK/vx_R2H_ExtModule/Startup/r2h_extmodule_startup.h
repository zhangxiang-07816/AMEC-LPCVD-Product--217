/*
 * r2h_extmodule_startup.h
 *
 *  Created on: 2018-8-2
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_STARTUP_H_
#define R2H_EXTMODULE_STARTUP_H_

#include "r2h_extmodule_startup_constant_def.h"
#include "../BufferDevice/r2h_extmodule_buffer_device.h"
#include "../AnalogIODevice/AnalogIn/r2h_extmodule_analog_in_device.h"
#include "../AnalogIODevice/AnalogOut/r2h_extmodule_analog_out_device.h"
#include "../AnalogIODevice/TemperatureIn/r2h_extmodule_temp_in_device.h"
#include "../AnalogIODevice/TemperatureCtl/r2h_extmodule_temp_ctl_device.h"
#include "../NetworkDevice/DeviceNet/r2h_extmodule_dnm_device.h"
#include "../NetworkDevice/SMART-ECAT/r2h_extmodule_smart_ecat_device_interface.h"
#include "../NetworkDevice/SMART-ECAT/R12CCPU/r2h_extmodule_r12ccpu_ecat_device.h"
#include "../NetworkDevice/SMART-ECAT/RD55UPx/r2h_extmodule_rd55up_ecat_device.h"
#include "../SoftCCPUDevice/r2h_extmodule_soft_ccpu_device.h"

#ifdef __cplusplus
	extern "C" {
#endif

R2H_INT32 vx_R2H_ExtModule_CreateXYDevice				(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_XYDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateAnalogInDevice			(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_AD_DEVICE_CHANNEL_ENABLE_MASK_T mask, R2H_ExtModule_AnalogInDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateAnalogOutDevice		(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_DA_DEVICE_CHANNEL_ENABLE_MASK_T mask, R2H_ExtModule_AnalogOutDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateTemperatureInDevice	(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_TI_DEVICE_CHANNEL_ENABLE_MASK_T mask, R2H_ExtModule_TemperatureInDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateTemperatureCtlDevice	(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_TemperatureControlDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateDeviceNetMasterDevice	(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_UINT32 bufferSyncRefreshPosixPriority, R2H_UINT16 rxOffsetInWord, R2H_UINT16 rxSizeInWord, R2H_UINT16 txOffsetInWord, R2H_UINT16 txSizeInWord, R2H_ExtModule_DeviceNetMasterDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateR12CCPUECATDevice		(R2H_UINT16 baseAddress, R2H_UINT16 hostCPUAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_R12CCPUECATDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateRD55UPECATDevice		(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_RD55UPECATDevice **ppDevice);

R2H_INT32 vx_R2H_ExtModule_CreateSmartECATDevice		(R2H_UINT16 baseAddress, R2H_UINT16 hostCPUAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_SmartECATDevice **ppDevice, R2H_UINT16 *pAddress);

R2H_INT32 vx_R2H_ExtModule_CreateSoftCCPUDevice			(R2H_UINT16 baseAddress, R2H_EXTMODULE_DEVICE_MODEL_ID id, R2H_ExtModule_SoftCCPUDevice **ppDevice);

void vx_R2H_ExtModule_DestoryDevice						(R2H_ExtModule_BaseDevice* pDevice);

void vx_R2H_ExtModule_Version							(R2H_UINT32 *pRelease, R2H_UINT32 *pBuild);


#ifdef __cplusplus
	}
#endif


#endif /* R2H_EXTMODULE_STARTUP_H_ */
