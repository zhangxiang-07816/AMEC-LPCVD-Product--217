/*
 * lpcvd_alpha_init.cc
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

Version _GLB_VERSION;
//DummyDOPulse _GLB_DO_PULSE;
HeartbeatGenerator _GLB_HEARTBEAT_GENERATOR;
SimpleECATPosMotor _GLB_ST1_ECAT_POS_MOTOR;
SimpleECATPosMotor _GLB_ST2_ECAT_POS_MOTOR;
DataCopy _GLB_SIPE1;
DataCopy _GLB_SIPE2;
Tricker617 _GLB_Tricker617;

void __user_io_device_init_ex(	std::vector<P_R2H_ExtModule_BaseDevice>					*pIODeviceVector,
								R2H_DLink_MemorySysInfo									*pDLinkMemorySysInfo,
								R2H_DLink_MemoryTaskInfo								*pDLinkMemoryTaskInfo,
								R2H_DLink_MemoryUserIO									*pDLinkMemoryUserIO,
								std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	*pDeviceLocalProcessOutDataVector,
								R2H_Task_ProcessDataObjectManager						*pObjectManager)
{
	_GLB_VERSION.Init(pObjectManager, "Firmware Version");
	_GLB_VERSION.WriteVersion(0x00010002);
	//_GLB_DO_PULSE.Init(pObjectManager, 1000000);
	_GLB_HEARTBEAT_GENERATOR.Init(pObjectManager, "Host Heartbeat For Temperature Controller", 1000000, 1);
	_GLB_ST1_ECAT_POS_MOTOR.Init(pObjectManager, 
					"ST1 Lift Motor Controller CMD", "ST1 Lift Motor Controller CMD Parameter", "ST1 Lift Motor Controller ACK",
					"ST1 Lift Motor Controller Status", "ST1 Lift Motor Current Position", "ST1 Lift Motor Controller Error Code",
					"SMART ECAT Communication Status", "ST1 Heater Lift Motor Driver Operation Mode", "ST1 Heater Lift Motor Driver Status Word", "ST1 Heater Lift Motor Position Value",
					"ST1 Heater Lift Motor Driver Operation Mode Set", "ST1 Heater Lift Motor Driver Control Word", "ST1 Heater Lift Motor Position Setpoint", 
					200.0);
	_GLB_ST2_ECAT_POS_MOTOR.Init(pObjectManager, 
					"ST2 Lift Motor Controller CMD", "ST2 Lift Motor Controller CMD Parameter", "ST2 Lift Motor Controller ACK",
					"ST2 Lift Motor Controller Status", "ST2 Lift Motor Current Position", "ST2 Lift Motor Controller Error Code",
					"SMART ECAT Communication Status", "ST2 Heater Lift Motor Driver Operation Mode", "ST2 Heater Lift Motor Driver Status Word", "ST2 Heater Lift Motor Position Value",
					"ST2 Heater Lift Motor Driver Operation Mode Set", "ST2 Heater Lift Motor Driver Control Word", "ST2 Heater Lift Motor Position Setpoint", 
					200.0);
	_GLB_SIPE1.Init(pObjectManager,
					R2H_TASK_TX_BLOCK_AREA, "Clean Pressure Value", 
					R2H_TASK_RX_CONTROL_AREA, "Throttle Valve SIPE1", SIDE_DATA_TYPE_FLOAT);
	_GLB_SIPE2.Init(pObjectManager,
					R2H_TASK_TX_BLOCK_AREA, "PM Pressure Value", 
					R2H_TASK_RX_CONTROL_AREA, "Throttle Valve SIPE2", SIDE_DATA_TYPE_FLOAT);
	
	_GLB_Tricker617.Init(pObjectManager);
}
