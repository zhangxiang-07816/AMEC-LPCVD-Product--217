/*
 * dummy_do_pulse.h
 *
 *  Created on: 2020-3-16
 *      Author: CrazyHein
 */

#ifndef DUMMY_DO_PULSE_H_
#define DUMMY_DO_PULSE_H_

#include "../IOControl/r2h_task_io_control.h"
#include "../common_def.h"
#include "dummy_do_pulse_def.h"

namespace R2H_AMEC_PRODUCT
{

class DummyDOPulse
{
public:
	DummyDOPulse();
	void Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_ULONG width);
	void Procceed(R2H_ULONG counterMicros);

private:
	R2H_BYTE* __dummy_do_unsafe_ptr;
	R2H_UINT32 __dummy_do_bit_index;
	R2H_ULONG __pulse_width;
	R2H_ULONG __pulse_counter;
	bool __turn_on;
};

}



#endif /* DUMMY_DO_PULSE_H_ */
