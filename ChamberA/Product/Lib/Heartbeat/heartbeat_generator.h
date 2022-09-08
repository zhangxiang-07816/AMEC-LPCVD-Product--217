/*
 * heartbeat_generator.h
 *
 *  Created on: Oct 22, 2021
 *      Author: HaihangRen
 */

#ifndef HEARTBEAT_GENERATOR_H_
#define HEARTBEAT_GENERATOR_H_

#include "../IOControl/r2h_task_io_control.h"
#include "../common_def.h"

namespace R2H_AMEC_PRODUCT
{

class HeartbeatGenerator
{
public:
	HeartbeatGenerator();
	void Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING heartbeat, R2H_ULONG interval, R2H_ULONG increment);
	void Procceed(R2H_ULONG counterMicros);

private:
	R2H_UINT16* __heartbeat_counter_unsafe_ptr;
	R2H_ULONG __interval;
	R2H_ULONG __increment;
	R2H_ULONG __last_counter_value;
	R2H_UINT16 __internal_counter;
};

}

#endif /* HEARTBEAT_GENERATOR_H_ */
