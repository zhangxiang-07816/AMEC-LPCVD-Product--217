/*
 * simple_ecat_positioning_motor.cc
 *
 *  Created on: Oct 22, 2021
 *      Author: HaihangRen
 */
#include "simple_ecat_positioning_motor.h"

namespace R2H_AMEC_PRODUCT
{

SimpleECATPosMotor::SimpleECATPosMotor():__controller_cmd_ptr(0), __controller_cmd_para_ptr(0), __controller_ack_ptr(0),
		__controller_status_ptr(0), __controller_motor_position_value_ptr(0), __controller_error_code_ptr(0),
		__ecat_master_communication_status_ptr(0), __ecat_driver_operation_mode_ptr(0), __ecat_driver_status_ptr(0),__ecat_motor_position_value_ptr(0),
		__ecat_driver_operation_mode_set_ptr(0), __ecat_driver_control_ptr(0), __ecat_motor_position_setpoint_ptr(0),
		__ecat_driver_operation_mode_set(CIA402_NO_OPERATION_MODE_ASSIGNED),
		__ecat_motor_position_setpoint(0), 
		__controller_status(MOTOR_CONTROLLER_IDLE),
		__controller_task(MOTOR_CONTROLLER_NO_TASK)
{
	memset(&__ecat_driver_control, 0, sizeof(__ecat_driver_control));
}

void SimpleECATPosMotor::Init(R2H_Task_ProcessDataObjectManager *pObjectManager, 
					R2H_CONST_STRING ctlCMD, R2H_CONST_STRING ctlCMDPara, R2H_CONST_STRING ctlACK,
					R2H_CONST_STRING ctlStatus, R2H_CONST_STRING ctlMotorPos, R2H_CONST_STRING ctlError,
					R2H_CONST_STRING ecatCOMStatus, R2H_CONST_STRING ecatDRVOpMode, R2H_CONST_STRING ecatDRVStatus, R2H_CONST_STRING ecatMotorPos,
					R2H_CONST_STRING ecatDRVOpModeSet, R2H_CONST_STRING ecatDRVControl, R2H_CONST_STRING ecatMotorPosSet, 
					R2H_DOUBLE coefficient)
{
	__initialize_ptr(pObjectManager, ctlCMD, R2H_TASK_RX_BLOCK_AREA, SIDE_DATA_TYPE_UINT, (R2H_BYTE**)&__controller_cmd_ptr);
	__initialize_ptr(pObjectManager, ctlCMDPara, R2H_TASK_RX_BLOCK_AREA, SIDE_DATA_TYPE_UINT, (R2H_BYTE**)&__controller_cmd_para_ptr);
	
	__initialize_ptr(pObjectManager, ctlACK, R2H_TASK_TX_BLOCK_AREA, SIDE_DATA_TYPE_UINT, (R2H_BYTE**)&__controller_ack_ptr);
	__initialize_ptr(pObjectManager, ctlStatus, R2H_TASK_TX_BLOCK_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__controller_status_ptr);
	__initialize_ptr(pObjectManager, ctlMotorPos, R2H_TASK_TX_BLOCK_AREA, SIDE_DATA_TYPE_INT, (R2H_BYTE**)&__controller_motor_position_value_ptr);
	__initialize_ptr(pObjectManager, ctlError, R2H_TASK_TX_BLOCK_AREA, SIDE_DATA_TYPE_UINT, (R2H_BYTE**)&__controller_error_code_ptr);
	
	__initialize_ptr(pObjectManager, ecatCOMStatus, R2H_TASK_TX_DIAGNOSTIC_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__ecat_master_communication_status_ptr);
	__initialize_ptr(pObjectManager, ecatDRVOpMode, R2H_TASK_TX_DIAGNOSTIC_AREA, SIDE_DATA_TYPE_BYTE, (R2H_BYTE**)&__ecat_driver_operation_mode_ptr);
	__initialize_ptr(pObjectManager, ecatDRVStatus, R2H_TASK_TX_DIAGNOSTIC_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__ecat_driver_status_ptr);
	__initialize_ptr(pObjectManager, ecatMotorPos, R2H_TASK_TX_DIAGNOSTIC_AREA, SIDE_DATA_TYPE_INT, (R2H_BYTE**)&__ecat_motor_position_value_ptr);
	
	__initialize_ptr(pObjectManager, ecatDRVOpModeSet, R2H_TASK_RX_CONTROL_AREA, SIDE_DATA_TYPE_BYTE, (R2H_BYTE**)&__ecat_driver_operation_mode_set_ptr);
	__initialize_ptr(pObjectManager, ecatDRVControl, R2H_TASK_RX_CONTROL_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__ecat_driver_control_ptr);
	__initialize_ptr(pObjectManager, ecatMotorPosSet, R2H_TASK_RX_CONTROL_AREA, SIDE_DATA_TYPE_INT, (R2H_BYTE**)&__ecat_motor_position_setpoint_ptr);
	
	__controller_status = MOTOR_CONTROLLER_IDLE;
	__controller_task = MOTOR_CONTROLLER_NO_TASK;
	__coefficient = coefficient;
}

void SimpleECATPosMotor::Procceed(R2H_ULONG counterMicros)
{
	//for performance concerns, null pointers are not checked here !

	//Copy diagnostic info
	*__controller_status_ptr = __ecat_driver_status_ptr->status_word.raw_status_word;
	*__controller_motor_position_value_ptr = (*__ecat_motor_position_value_ptr)/__coefficient;
	
	__restore_rx_pdo();
	//State Machine
	switch(__controller_status)
	{
	case MOTOR_CONTROLLER_IDLE:
		if(__controller_cmd_ptr->enable_driver_and_motor)
		{
			__controller_ack_ptr->enable_driver_and_motor = 1;
			__controller_task= MOTOR_CONTROLLER_ENABLE_DRIVER;	
			__operation_time_out = 2000000;
		}else if(__controller_cmd_ptr->disable_driver_and_motor)
		{
			__controller_ack_ptr->disable_driver_and_motor = 1;		
			__controller_task = MOTOR_CONTROLLER_DISABLE_DRIVER;	
			__operation_time_out = 2000000;
		}else if(__controller_cmd_ptr->reset_driver_fault)
		{
			__controller_ack_ptr->reset_driver_fault = 1;
			__controller_task = MOTOR_CONTROLLER_RESET_DRIVER_FAULT;	
			__operation_time_out = 2000000;
		}else if(__controller_cmd_ptr->reset_driver_encoder)
		{
			__controller_ack_ptr->reset_driver_encoder = 1;
			__controller_task = MOTOR_CONTROLLER_RESET_DRIVER_ENCODER;	
			__operation_time_out = 2000000;
		}else if(__controller_cmd_ptr->move_to_absolute_position)
		{
			__controller_ack_ptr->move_to_absolute_position = 1;
			__controller_task = MOTOR_CONTROLLER_ABS_MOVEMENT;	
			__operation_time_out = 20000000;
			//Setup Parameters
			*__ecat_motor_position_setpoint_ptr = (*((R2H_INT32*)__controller_cmd_para_ptr) * __coefficient);
		}else if(__controller_cmd_ptr->move_to_relative_position)
		{
			__controller_ack_ptr->move_to_relative_position = 1;
			__controller_task = MOTOR_CONTROLLER_REL_MOVEMENT;	
			__operation_time_out = 20000000;
			//Setup Parameters
			*__ecat_motor_position_setpoint_ptr = (*((R2H_INT32*)__controller_cmd_para_ptr) * __coefficient);
		}
		else
			break;
		__controller_status = MOTOR_CONTROLLER_BUSY;
		__task_start_ticks = counterMicros;
		__task_step = 0;
		
	case MOTOR_CONTROLLER_BUSY:
		//check errors
		if(*__ecat_master_communication_status_ptr != R2H_SMART_ECAT_COMMUNICATING)
		{
			__controller_status = MOTOR_CONTROLLER_CLEAN;
			*__controller_error_code_ptr = MOTOR_CONTROLLER_ECAT_FAULT;
		}//else if(*__ecat_driver_operation_mode_ptr != CIA402_PROFILE_POSITION_MODE && 
				//*__ecat_driver_operation_mode_ptr != CIA402_HOMING_MODE)
		//{
			//__controller_status = MOTOR_CONTROLLER_CLEAN;
			//*__controller_error_code_ptr = MOTOR_CONTROLLER_DRV_OPT_MODE_ERROR;
		//}
		else if(__ecat_driver_status_ptr->status_word.pp_status_word.internal_limit_active == 1)
		{
			__controller_status = MOTOR_CONTROLLER_CLEAN;
			*__controller_error_code_ptr = MOTOR_CONTROLLER_DRV_LIMIT_ERROR;
		}else if(__controller_task != MOTOR_CONTROLLER_RESET_DRIVER_FAULT &&
				__ecat_driver_status_ptr->status_word.pp_status_word.fault == 1)
		{
			__controller_status = MOTOR_CONTROLLER_CLEAN;
			*__controller_error_code_ptr = MOTOR_CONTROLLER_DRV_FAULT;
		}
		else if(counterMicros - __task_start_ticks > __operation_time_out)
		{
			__controller_status = MOTOR_CONTROLLER_CLEAN;
			*__controller_error_code_ptr = MOTOR_CONTROLLER_OPT_TIMEOUT;
		}
		
		if(__controller_status == MOTOR_CONTROLLER_CLEAN)
		{
			CIA402_SET_DISABLE_OPERATION_COMMAND(__ecat_driver_control_ptr->control_word.raw_control_word);
			CIA402_SET_FAULT_RESET_RESTORE_COMMAND(__ecat_driver_control_ptr->control_word.raw_control_word);
			
			__ecat_driver_control_ptr->control_word.hm_control_word.homing_operation_start = 0;	
			__ecat_driver_control_ptr->control_word.pp_control_word.new_setpoint = 0;
		}
		else
		{
			switch(__controller_task)
			{
			case MOTOR_CONTROLLER_ENABLE_DRIVER:
				switch(__task_step)
				{
				case 0:
					CIA402_SET_ENABLE_OPERATION_COMMAND(__ecat_driver_control_ptr->control_word.raw_control_word);
					*__ecat_driver_operation_mode_set_ptr = CIA402_PROFILE_POSITION_MODE;
					__task_step++;
					break;
				case 1:
					if(CIA402_IS_OPERATION_ENABLED(__ecat_driver_status_ptr->status_word.raw_status_word))
					{
						*__controller_error_code_ptr = MOTOR_CONTROLLER_NO_ERROR;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
					}
				}
				break;
			case MOTOR_CONTROLLER_DISABLE_DRIVER:
				switch(__task_step)
				{
				case 0:
					CIA402_SET_DISABLE_OPERATION_COMMAND(__ecat_driver_control_ptr->control_word.raw_control_word);
					__task_step++;
					break;
				case 1:
					if(CIA402_IS_SWITCHED_ON(__ecat_driver_status_ptr->status_word.raw_status_word))
					{
						*__controller_error_code_ptr = MOTOR_CONTROLLER_NO_ERROR;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
					}
				}
				break;
			case MOTOR_CONTROLLER_RESET_DRIVER_FAULT:
				switch(__task_step)
				{
				case 0:
					CIA402_SET_FAULT_RESET_REQUEST_COMMAND(__ecat_driver_control_ptr->control_word.raw_control_word);
					*__ecat_driver_operation_mode_set_ptr = CIA402_PROFILE_POSITION_MODE;
					__task_step++;
					break;
				case 1:
					if(CIA402_IS_FAULT_STATE(__ecat_driver_status_ptr->status_word.raw_status_word) == false)
					{
						CIA402_SET_FAULT_RESET_RESTORE_COMMAND(__ecat_driver_control_ptr->control_word.raw_control_word);
						*__controller_error_code_ptr = MOTOR_CONTROLLER_NO_ERROR;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
					}
				}
				break;
			case MOTOR_CONTROLLER_RESET_DRIVER_ENCODER:
				switch(__task_step)
				{
				case 0://swith opt mode to homing mode
					*__ecat_driver_operation_mode_set_ptr = CIA402_HOMING_MODE;
					__task_step++;
					break;
				case 1:
					if(*__ecat_driver_operation_mode_ptr == CIA402_HOMING_MODE)
					{
						__ecat_driver_control_ptr->control_word.hm_control_word.homing_operation_start = 1;
						__task_delay_start_ticks = counterMicros;
						__task_step++;
					}
					break;
				case 2:// delay 100ms
					if(counterMicros - __task_delay_start_ticks > 100000)
						__task_step++;
					break;
				case 3:
					if(__ecat_driver_status_ptr->status_word.hm_status_word.home_position_reached == 1)
					{
						__ecat_driver_control_ptr->control_word.hm_control_word.homing_operation_start = 0;
						if(__ecat_driver_status_ptr->status_word.hm_status_word.homing_attained == 1 && __ecat_driver_status_ptr->status_word.hm_status_word.homing_error != 1)
							*__controller_error_code_ptr = MOTOR_CONTROLLER_NO_ERROR;
						else
							*__controller_error_code_ptr = MOTOR_CONTROLLER_HOMING_ERROR;
						
						__task_delay_start_ticks = counterMicros;
						__task_step++;
					}
					break;
				case 4:// delay 50ms
					if(counterMicros - __task_delay_start_ticks > 50000)
						__controller_status = MOTOR_CONTROLLER_CLEAN;
				}
				break;
			case MOTOR_CONTROLLER_ABS_MOVEMENT:
				switch(__task_step)
				{
				case 0://swith opt mode to pp mode
					if(CIA402_IS_OPERATION_ENABLED(__ecat_driver_status_ptr->status_word.raw_status_word) == false)
					{
						*__controller_error_code_ptr = MOTOR_CONTROLLER_DRV_NOT_ENABLED;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
						break;
					}
					else
					{
						*__ecat_driver_operation_mode_set_ptr = CIA402_PROFILE_POSITION_MODE;
						__task_step++;
					}
				case 1:
					if(*__ecat_driver_operation_mode_ptr == CIA402_PROFILE_POSITION_MODE)
					{

						__ecat_driver_control_ptr->control_word.pp_control_word.new_setpoint = 1;
						__ecat_driver_control_ptr->control_word.pp_control_word.relative_position_command = 0;
						__ecat_driver_control_ptr->control_word.pp_control_word.change_sp_immediately = 1;
						__task_step++;
					}
					break;
				case 2:
					if(__ecat_driver_status_ptr->status_word.pp_status_word.set_point_acknowledge == 1)
					{
						__ecat_driver_control_ptr->control_word.pp_control_word.new_setpoint = 0;
						__task_step++;
					}
					break;
				case 3:
					if(__ecat_driver_status_ptr->status_word.pp_status_word.set_point_acknowledge == 0 && 
							__ecat_driver_status_ptr->status_word.pp_status_word.target_position_reached == 1) //discard "target_position_reached == 1" if you want to use <Set of set-points>
					{
						*__controller_error_code_ptr = MOTOR_CONTROLLER_NO_ERROR;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
					}
				}
				break;
			case MOTOR_CONTROLLER_REL_MOVEMENT:
				switch(__task_step)
				{
				case 0://swith opt mode to pp mode
					if(CIA402_IS_OPERATION_ENABLED(__ecat_driver_status_ptr->status_word.raw_status_word) == false)
					{
						*__controller_error_code_ptr = MOTOR_CONTROLLER_DRV_NOT_ENABLED;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
						break;
					}
					else
					{
						*__ecat_driver_operation_mode_set_ptr = CIA402_PROFILE_POSITION_MODE;
						__task_step++;
					}
				case 1:
					if(*__ecat_driver_operation_mode_ptr == CIA402_PROFILE_POSITION_MODE)
					{

						__ecat_driver_control_ptr->control_word.pp_control_word.new_setpoint = 1;
						__ecat_driver_control_ptr->control_word.pp_control_word.relative_position_command = 1;
						__ecat_driver_control_ptr->control_word.pp_control_word.change_sp_immediately = 1;
						__task_step++;
					}
					break;
				case 2:
					if(__ecat_driver_status_ptr->status_word.pp_status_word.set_point_acknowledge == 1)
					{
						__ecat_driver_control_ptr->control_word.pp_control_word.new_setpoint = 0;
						__task_step++;
					}
					break;
				case 3:
					if(__ecat_driver_status_ptr->status_word.pp_status_word.set_point_acknowledge == 0 &&
							__ecat_driver_status_ptr->status_word.pp_status_word.target_position_reached == 1)//discard "target_position_reached == 1" if you want to use <Set of set-points>
					{
						*__controller_error_code_ptr = MOTOR_CONTROLLER_NO_ERROR;
						__controller_status = MOTOR_CONTROLLER_CLEAN;
					}
				}
				break;
			default:
				break;
			}
			
		}
		
		if(__controller_status == MOTOR_CONTROLLER_BUSY)
			break;
		
	case MOTOR_CONTROLLER_CLEAN:
		if((__controller_cmd_ptr->cmd_word & (1 << (__controller_task - 1))) == 0)
		{
			__controller_ack_ptr->ack_word &= ~(1 << (__controller_task - 1));
			__controller_status = MOTOR_CONTROLLER_IDLE;
		}
		break;
	}
	__backup_rx_pdo();
}

void SimpleECATPosMotor::__restore_rx_pdo()
{
	*__ecat_driver_operation_mode_set_ptr = __ecat_driver_operation_mode_set;
	*__ecat_driver_control_ptr = __ecat_driver_control;
	*__ecat_motor_position_setpoint_ptr = __ecat_motor_position_setpoint;
}

void SimpleECATPosMotor::__backup_rx_pdo()
{
	__ecat_driver_operation_mode_set = *__ecat_driver_operation_mode_set_ptr;
	__ecat_driver_control = *__ecat_driver_control_ptr;
	__ecat_motor_position_setpoint = *__ecat_motor_position_setpoint_ptr;
}

void SimpleECATPosMotor::__initialize_ptr(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING name, 
		R2H_TASK_PDO_AREA_T area, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType, R2H_BYTE** pptr)
{
	R2H_UINT32 objectIndex[1] = {NOT_A_VALID_OBJECT_INDEX};
	R2H_INT32 counter = 1;
	R2H_TASK_PDO_INDEX_T index;
	
	pObjectManager->SearchPDO(area, name, objectIndex, &counter);
	if(counter != 1)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND_OR_DUPLICATED));
	pObjectManager->UnsafeMemoryPointer(area, objectIndex[0], &index, pptr);
	if(index.variable_data_type != dataType)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));	
}

}
