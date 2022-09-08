/*
 * heartbeat_generator.cc
 *
 *  Created on: Oct 22, 2021
 *      Author: HaihangRen
 */
#include "heartbeat_generator.h"

namespace R2H_AMEC_PRODUCT
{

HeartbeatGenerator::HeartbeatGenerator(): __heartbeat_counter_unsafe_ptr(0), __interval(0), 
		__increment(0), __last_counter_value(0), __internal_counter(0)
{
	
}

void HeartbeatGenerator::Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING heartbeat, R2H_ULONG interval, R2H_ULONG increment)
{
	__interval = interval;
	__increment = increment;
	__internal_counter = 0;
	
	R2H_UINT32 objectIndex[1] = {NOT_A_VALID_OBJECT_INDEX};
	R2H_INT32 counter = 1;
	R2H_TASK_PDO_INDEX_T index;
	
	pObjectManager->SearchPDO(R2H_TASK_RX_CONTROL_AREA, heartbeat, objectIndex, &counter);
	if(counter == 0)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND));
	pObjectManager->UnsafeMemoryPointer(R2H_TASK_RX_CONTROL_AREA, objectIndex[0], &index, (R2H_BYTE**)&__heartbeat_counter_unsafe_ptr);
	if(index.variable_data_type != SIDE_DATA_TYPE_USHORT)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));
}

void HeartbeatGenerator::Procceed(R2H_ULONG counterMicros)
{
	if(__heartbeat_counter_unsafe_ptr != 0)
	{
		R2H_ULONG c = counterMicros/__interval;
		if(c != __last_counter_value)
		{
			__last_counter_value = c;
			__internal_counter += __increment;
		}
		(*__heartbeat_counter_unsafe_ptr) = __internal_counter;
	}
}

}
