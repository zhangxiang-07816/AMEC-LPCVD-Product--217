/*
 * lpcvd_alpha_process.cc
 *
 *  Created on: Oct 18, 2021
 *      Author: HaihangRen
 */
#include "r2h_task_startup.h"

#include "Lib/Version/version.h"
#include "Lib/DummyDOPulse/dummy_do_pulse.h"
#include "Lib/Heartbeat/heartbeat_generator.h"
#include "Lib/LiftMotor/simple_ecat_positioning_motor.h"
#include "Lib/DataCopy/data_copy.h"
#include "Lib/Tricker/tricker.h"

using namespace R2H_AMEC_PRODUCT;

extern Version _GLB_VERSION;
//extern DummyDOPulse _GLB_DO_PULSE;
extern HeartbeatGenerator _GLB_HEARTBEAT_GENERATOR;
extern SimpleECATPosMotor _GLB_ST1_ECAT_POS_MOTOR;
extern SimpleECATPosMotor _GLB_ST2_ECAT_POS_MOTOR;
extern DataCopy _GLB_SIPE1;
extern DataCopy _GLB_SIPE2;
extern Tricker617 _GLB_Tricker617;

void __user_process_control_routine_ex(	std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
										std::vector<P_R2H_EthModule_SocketDevice>  				*pEthDeviceVector,
										R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
										R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
										R2H_DLink_MemoryDeviceIO								*pDLinkMemoryDeviceIO,
										R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
										std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
										R2H_Task_ProcessDataObjectManager						*pObjectManager,
										R2H_ULONG 												counterMicros)
{
	//_GLB_DO_PULSE.Procceed(counterMicros);
	_GLB_HEARTBEAT_GENERATOR.Procceed(counterMicros);
	_GLB_ST1_ECAT_POS_MOTOR.Procceed(counterMicros);
	_GLB_ST2_ECAT_POS_MOTOR.Procceed(counterMicros);
	_GLB_SIPE1.Procceed();
	_GLB_SIPE2.Procceed();
	
	_GLB_Tricker617.Procceed(counterMicros);
}
