/*
 * r2h_task_io_control.h
 *
 *  Created on: 2018-9-12
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_IO_CONTROL_H_
#define R2H_TASK_IO_CONTROL_H_

#include "../r2h_task_system_constant_def.h"

#include "r2h_task_io_control_def.h"
#include "r2h_task_pdo_manager.h"
#include "r2h_task_exception.h"

#include "../Startup/r2h_task_user_parameters_def.h"
#include "../Startup/r2h_task_user_parameters.h"


#include "../../vx_R2H_ExtModule/BaseDevice/r2h_extmodule_base_device.h"
#include "../../vx_R2H_ExtModule/BaseDevice/r2h_extmodule_base_device_def.h"
#include "../../vx_R2H_ExtModule/CPUDevice/r2h_extmodule_cpu_device.h"
#include "../../vx_R2H_ExtModule/CPUDevice/r2h_extmodule_cpu_device_def.h"
#include "../../vx_R2H_ExtModule/XYDevice/r2h_extmodule_xy_device.h"
#include "../../vx_R2H_ExtModule/XYDevice/r2h_extmodule_xy_device_def.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/AnalogIn/r2h_extmodule_analog_in_device.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/AnalogIn/r2h_extmodule_analog_in_device_def.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/AnalogOut/r2h_extmodule_analog_out_device.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/AnalogOut/r2h_extmodule_analog_out_device_def.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/TemperatureIn/r2h_extmodule_temp_in_device.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/TemperatureIn/r2h_extmodule_temp_in_device_def.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/TemperatureCtl/r2h_extmodule_temp_ctl_device.h"
#include "../../vx_R2H_ExtModule/AnalogIODevice/TemperatureCtl/r2h_extmodule_temp_ctl_device_def.h"
#include "../../vx_R2H_ExtModule/NetworkDevice/DeviceNet/r2h_extmodule_dnm_device.h"
#include "../../vx_R2H_ExtModule/NetworkDevice/DeviceNet/r2h_extmodule_dnm_device_def.h"
#include "../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/r2h_extmodule_smart_ecat_device_def.h"
#include "../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/r2h_extmodule_smart_ecat_device_interface.h"
#include "../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/R12CCPU/r2h_extmodule_r12ccpu_ecat_device.h"
#include "../../vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/RD55UPx/r2h_extmodule_rd55up_ecat_device.h"
#include "../../vx_R2H_ExtModule/SoftCCPUDevice/r2h_extmodule_soft_ccpu_device.h"

#include "../../vx_R2H_EthModule/SocketDevice/r2h_ethmodule_socket_device.h"
#include "../../vx_R2H_EthModule/SocketDevice/r2h_ethmodule_socket_device_def.h"
#include "../../vx_R2H_EthModule/SmartGateway/r2h_ethmodule_smart_gateway.h"
#include "../../vx_R2H_EthModule/SmartGateway/r2h_ethmodule_smart_gateway_def.h"

#include "../../vx_R2H_ExtModule/Startup/r2h_extmodule_startup.h"
#include "../../vx_R2H_EthModule/Startup/r2h_ethmodule_startup.h"

#include "../DLinkDeviceIOHelper/r2h_task_dlink_device_io_helper.h"
#include "../DLinkDeviceIOHelper/r2h_task_dlink_device_io_helper_def.h"
#include "../DLinkDeviceIOHelper/DiscreteIO/XYDevice/r2h_task_dlink_xy_device_helper.h"
#include "../DLinkDeviceIOHelper/DiscreteIO/XYDevice/r2h_task_dlink_xy_device_helper_def.h"
#include "../DLinkDeviceIOHelper/AnalogIO/AnalogIn/r2h_task_dlink_analog_in_helper.h"
#include "../DLinkDeviceIOHelper/AnalogIO/AnalogIn/r2h_task_dlink_analog_in_helper_def.h"
#include "../DLinkDeviceIOHelper/AnalogIO/AnalogOut/r2h_task_dlink_analog_out_helper.h"
#include "../DLinkDeviceIOHelper/AnalogIO/AnalogOut/r2h_task_dlink_analog_out_helper_def.h"
#include "../DLinkDeviceIOHelper/AnalogIO/TemperatureIn/r2h_task_dlink_temperature_in_helper.h"
#include "../DLinkDeviceIOHelper/AnalogIO/TemperatureIn/r2h_task_dlink_temperature_in_helper_def.h"
#include "../DLinkDeviceIOHelper/AnalogIO/TemperatureCtl/r2h_task_dlink_temperature_ctl_helper.h"
#include "../DLinkDeviceIOHelper/AnalogIO/TemperatureCtl/r2h_task_dlink_temperature_ctl_helper_def.h"
#include "../DLinkDeviceIOHelper/Network/DeviceNet/r2h_task_dlink_dnm_helper.h"
#include "../DLinkDeviceIOHelper/Network/DeviceNet/r2h_task_dlink_dnm_helper_def.h"
#include "../DLinkDeviceIOHelper/Network/SMART-ECAT/r2h_task_dlink_smart_ecat_helper.h"
#include "../DLinkDeviceIOHelper/Network/SMART-ECAT/r2h_task_dlink_smart_ecat_helper_def.h"
#include "../DLinkDeviceIOHelper/Network/SmartGateway/r2h_task_dlink_smart_gateway_helper.h"
#include "../DLinkDeviceIOHelper/Network/SmartGateway/r2h_task_dlink_smart_gateway_helper_def.h"
#include "../DLinkDeviceIOHelper/SoftCCPU/r2h_task_dlink_soft_ccpu_helper_def.h"
#include "../DLinkDeviceIOHelper/SoftCCPU/r2h_task_dlink_soft_ccpu_helper.h"
#include "../DLinkDeviceIOHelper/Network/SerialPortServer/r2h_task_dlink_serial_port_server_helper.h"
#include "../DLinkDeviceIOHelper/Network/SerialPortServer/r2h_task_dlink_serial_port_server_helper_def.h"

#include "../DLinkSystemStatusHelper/r2h_task_dlink_system_status_helper.h"
#include "../DLinkSysTaskControlHelper/r2h_task_dlink_sys_control_helper.h"

#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_device_io.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_info.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_sys_task_control.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_task_info.h"
#include "../../vx_R2H_DLink/MemoryDef/r2h_dlink_memory_user_io.h"

#include "../../vx_R2H_DLink/Startup/r2h_dlink_startup.h"

#include "../../vx_R2H_ILink/Startup/r2h_ilink_startup.h"

#include "../Logger/r2h_task_logger.h"

#include <vector>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <assert.h>
#include <mqueue.h>
#include <math.h>

extern void _EXT_R2H_TASK_INTER_MODULE_SYNC_INTERRUPT_ROUTINE();
extern MSG_Q_ID _EXT_R2H_TASK_INTER_MODULE_SYNC_ISR_MESSAGE_QUEUE;

class R2H_Task_IOControl
{
public:
	R2H_Task_IOControl(	R2H_Task_UserParameters& userParam,
						USER_PROCESS_CONTROL_ROUTINE userProcessControl = 0,
						USER_IO_DEVICE_INIT userIODeviceInit = 0,
						USER_ETH_DEVICE_INIT userEthDeviceInit = 0,
						R2H_CONST_STRING variableCatalogue = 0, 
						R2H_CONST_STRING ioList = 0,
						USER_PROCESS_CONTROL_ROUTINE_EX userProcessControlEx = 0,
						USER_IO_DEVICE_INIT_EX userIODeviceInitEx = 0,
						USER_ETH_DEVICE_INIT_EX userEthDeviceInitEx = 0,
						R2H_Task_Logger *logger = 0);
	virtual ~R2H_Task_IOControl();
	
	R2H_INT32 Start();
	void Stop();
	
	bool SearchObject(R2H_UINT32 objectIndex, R2H_TASK_PDO_AREA_T* pArea, R2H_TASK_PDO_INDEX_T *pIndex, R2H_BYTE** ptr);
private:
	R2H_TASK_DEVICE_IO_SCAN_MODE_T							__device_io_control_mode;
	
	//std::vector<P_R2H_ExtModule_BaseDevice> 				__io_device_vector;
	std::vector<P_R2H_Task_DLinkDeviceIOHelper> 			__io_device_helper_vector;
	R2H_Task_DLinkSysControlHelper							__sys_control_helper;
	R2H_Task_DLinkSystemStatusHelper						__sys_status_helper;

	//logging thread??
	pthread_mutex_t											__device_io_scan_task_mutex;
	pthread_mutex_t											__device_control_task_mutex;
	
	R2H_TASK_DEVICE_IO_SCAN_HOST_COMMAND_T					__device_io_scan_task_host_command;
	R2H_TASK_DEVICE_CONTROL_HOST_COMMAND_T					__device_control_task_host_command;
	
	pthread_t 												__device_io_scan_task_id;
	pthread_t 												__device_control_task_id;
	
	R2H_DLINK::R2H_DLink_RemoteServer*						__p_dlink_remote_server;
	
	R2H_ILINK::ProtocolServer*								__p_ilink_remote_server;
							
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM					__r2h_dlink_service_task_info;
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM					__device_io_scan_task_info;
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM					__device_control_task_info;
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM					__r2h_ilink_service_task_info;

	
	void 													__cleanup();
	R2H_INT32												__start_device_io_scan_task();
	R2H_INT32												__start_device_control_task();
	void													__stop_device_io_scan_task();
	void													__stop_device_control_task();

	
	static void* 											__device_io_scan_routine(void *host);
	static void* 											__device_control_routine(void *host);
	
	virtual void 											__device_io_scan(timespec* time, bool processRequest = true, bool refreshDiagnostic = true, bool refreshProcessIn = true, bool refreshProcessOut = true);
	virtual void 											__device_control();
	virtual void 											__device_io_safe_state(void *param);
	
	R2H_TASK_PARAM_CLOCK_SOURCE_T							__device_io_scan_clock_source;
	R2H_UINT32												__device_io_scan_task_stack_size_in_byte;
	R2H_UINT32												__device_control_task_stack_size_in_byte;
	R2H_INT32 												__sys_ticks_per_second;
	R2H_TCP_PORT											__r2h_dlink_server_port;
	R2H_INT32												__r2h_dlink_server_timeout_in_ms;
	R2H_TCP_PORT											__r2h_ilink_server_port;
	R2H_INT32												__r2h_ilink_server_timeout_in_ms;
	
	virtual void 											__process_control(R2H_ULONG counterMicros);
	virtual void 											__io_device_init();
	virtual void 											__eth_device_init();
	
	USER_PROCESS_CONTROL_ROUTINE							__user_process_control;
	USER_IO_DEVICE_INIT										__user_io_device_init;
	USER_ETH_DEVICE_INIT									__user_eth_device_init;
	USER_PROCESS_CONTROL_ROUTINE_EX							__user_process_control_ex;
	USER_IO_DEVICE_INIT_EX									__user_io_device_init_ex;
	USER_ETH_DEVICE_INIT_EX									__user_eth_device_init_ex;
	
	bool 													__check_system_required();
	R2H_INT32 												__check_startup_parameters(	USER_PROCESS_CONTROL_ROUTINE userProcessControl,
																						USER_IO_DEVICE_INIT userIODeviceInit,
																						USER_ETH_DEVICE_INIT userEthDeviceInit,
																						R2H_CONST_STRING variableCatalogue, 
																						R2H_CONST_STRING ioList,
																						USER_PROCESS_CONTROL_ROUTINE_EX userProcessControlEx,
																						USER_IO_DEVICE_INIT_EX userIODeviceInitEx,
																						USER_ETH_DEVICE_INIT_EX userEthDeviceInitEx);
	//static void												__inter_module_sync_interrupt_routine();
	//static R2H_TASK_INTER_MODULE_SYNC_ISR_MSG_T				__inter_module_sync_isr_message;
	//static MSG_Q_ID											__inter_module_sync_isr_message_queue = 0;
protected:
	std::vector<P_R2H_ExtModule_BaseDevice> 				_io_device_vector;
	std::vector<P_R2H_EthModule_SocketDevice> 				_eth_device_vector;
	R2H_DLink_MemorySysInfo* 								_p_dlink_memory_sys_info;
	R2H_DLink_MemoryTaskInfo* 								_p_dlink_memory_task_info;
	R2H_DLink_MemorySystemControl* 							_p_dlink_memory_system_control;
	R2H_DLink_MemoryTaskControl* 							_p_dlink_memory_task_control;
	R2H_DLink_MemoryDeviceIO* 								_p_dlink_memory_device_io;
	R2H_DLink_MemoryUserIO* 								_p_dlink_memory_user_io;

	std::vector<R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATA_T>	_device_local_process_out_data_vector;		
	
	//R2H_INT32												_configuration_warning;
	//R2H_INT32												_pdo_mapping_warning;
	//R2H_INT32												_ilink_service_warning;
	
	R2H_Task_ProcessDataObjectManager						_pdo_manager;
	bool 													_pdo_manager_ready;
	
	R2H_ILINK::Engine*										_p_ilink_engine;
	bool													_ilink_engine_ready;
	
	R2H_Task_Logger*										_logger;
};



#endif /* R2H_TASK_IO_CONTROL_H_ */
