/*
 * dummy_do_pulse.cc
 *
 *  Created on: 2020-3-16
 *      Author: CrazyHein
 */
#include "dummy_do_pulse.h"


namespace R2H_AMEC_PRODUCT
{

DummyDOPulse::DummyDOPulse():__dummy_do_unsafe_ptr(NULL), __dummy_do_bit_index(0), 
		__pulse_width(0), __pulse_counter(0), __turn_on(false)
{
	
}

void DummyDOPulse::Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_ULONG width)
{
	R2H_UINT32 objectIndex[1] = {NOT_A_VALID_OBJECT_INDEX};
	R2H_INT32 counter = 1;
	R2H_TASK_PDO_INDEX_T index;
	
	if(width == 0)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(INVALID_USER_PARAMETER));
	else
		__pulse_width = width;
	
	pObjectManager->SearchPDO(R2H_TASK_RX_BIT_AREA, DUMMY_DO, objectIndex, &counter);
	if(counter == 0)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND));
	pObjectManager->UnsafeMemoryPointer(R2H_TASK_RX_BIT_AREA, objectIndex[0], &index, (R2H_BYTE**)&__dummy_do_unsafe_ptr);
	if(index.variable_data_type != SIDE_DATA_TYPE_BIT)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));
	__dummy_do_bit_index = index.offset_in_bit%8;
}

void DummyDOPulse::Procceed(R2H_ULONG counterMicros)
{
	R2H_ULONG c = counterMicros/__pulse_width;
	if(__dummy_do_unsafe_ptr != NULL)
	{
		if(c !=__pulse_counter)
		{
			__turn_on = !__turn_on;
			__pulse_counter = c;
		}
		if(__turn_on)
			(*__dummy_do_unsafe_ptr) |= (1<<__dummy_do_bit_index);
		else
			(*__dummy_do_unsafe_ptr) &= ~(1<<__dummy_do_bit_index);
	}
}

}
