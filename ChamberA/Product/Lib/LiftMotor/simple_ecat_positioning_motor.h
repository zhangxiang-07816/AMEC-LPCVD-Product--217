/*
 * simple_ecat_positioning_motor.h
 *
 *  Created on: Oct 22, 2021
 *      Author: HaihangRen
 */

#ifndef SIMPLE_ECAT_POSITIONING_MOTOR_H_
#define SIMPLE_ECAT_POSITIONING_MOTOR_H_

#include "../IOControl/r2h_task_io_control.h"
#include "../common_def.h"
#include "simple_ecat_positioning_motor_def.h"

namespace R2H_AMEC_PRODUCT
{

class SimpleECATPosMotor
{
public:
	SimpleECATPosMotor();
	void Init(R2H_Task_ProcessDataObjectManager *pObjectManager,
			R2H_CONST_STRING ctlCMD, R2H_CONST_STRING ctlCMDPara, R2H_CONST_STRING ctlACK,
			R2H_CONST_STRING ctlStatus, R2H_CONST_STRING ctlMotorPos, R2H_CONST_STRING ctlError,
			R2H_CONST_STRING ecatCOMStatus, R2H_CONST_STRING ecatDRVOpMode, R2H_CONST_STRING ecatDRVStatus, R2H_CONST_STRING ecatMotorPos,
			R2H_CONST_STRING ecatDRVOpModeSet, R2H_CONST_STRING ecatDRVControl, R2H_CONST_STRING ecatMotorPosSet,
			R2H_DOUBLE coefficient);
	void Procceed(R2H_ULONG counterMicros);
private:
	SIMPLE_MOTOR_CONTROLLER_CMD_WORD_T*								__controller_cmd_ptr;
	R2H_UINT32*														__controller_cmd_para_ptr;
	SIMPLE_MOTOR_CONTROLLER_ACK_WORD_T*								__controller_ack_ptr;
	
	R2H_UINT16*														__controller_status_ptr;
	R2H_INT32*														__controller_motor_position_value_ptr;
	R2H_UINT32*														__controller_error_code_ptr;
	
	R2H_UINT16* 													__ecat_master_communication_status_ptr;
	R2H_BYTE*														__ecat_driver_operation_mode_ptr;
	CIA402_STATUS_WORD_T*											__ecat_driver_status_ptr;
	R2H_INT32*														__ecat_motor_position_value_ptr;
	
	R2H_BYTE*														__ecat_driver_operation_mode_set_ptr;
	CIA402_CONTROL_WORD_T*											__ecat_driver_control_ptr;
	R2H_INT32*														__ecat_motor_position_setpoint_ptr;
	
	R2H_BYTE														__ecat_driver_operation_mode_set;
	CIA402_CONTROL_WORD_T											__ecat_driver_control;
	R2H_INT32														__ecat_motor_position_setpoint;
	
	SIMPLE_MOTOR_CONTROLLER_STATUS_T								__controller_status;
	SIMPLE_MOTOR_CONTROLLER_TASK_T									__controller_task;
	R2H_UINT32														__task_start_ticks;
	R2H_UINT32														__task_delay_start_ticks;
	R2H_INT32														__task_step;
	R2H_UINT32														__operation_time_out;
	
	R2H_DOUBLE 														__coefficient;
	
	void 															__restore_rx_pdo();
	void 															__backup_rx_pdo();
	void															__initialize_ptr(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING name, 
																						R2H_TASK_PDO_AREA_T area, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType, R2H_BYTE** pptr);

};
}

#endif /* SIMPLE_ECAT_POSITIONING_MOTOR_H_ */
