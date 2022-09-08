/*
 * r2h_task_amec_io_control.h
 *
 *  Created on: 2018-9-19
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_AMEC_IO_CONTROL_H_
#define R2H_TASK_AMEC_IO_CONTROL_H_

#include "r2h_task_amec_io_control_def.h"
#include "../IOControl/r2h_task_io_control.h"

class R2H_Task_AMEC_IOControl : public R2H_Task_IOControl
{
public:
	R2H_Task_AMEC_IOControl(R2H_Task_UserParameters& userParam);
	virtual ~R2H_Task_AMEC_IOControl();
	
	R2H_INT32 												Start();
	void 													Stop();
	
private:
	R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM					__recipe_parser_task_info;
	R2H_TASK_RECIPE_PARSER_HOST_COMMAND_T					__recipe_parser_task_host_command;
	pthread_t 												__recipe_parser_task_id;
	pthread_mutex_t											__recipe_parser_task_mutex;
	pthread_cond_t											__recipe_parser_task_cond;
	
	virtual void 											__process_control();
	virtual void 											__io_device_init();
	
	void													__cleanup();
	R2H_INT32												__start_recipe_parser_task();
	void													__stop_recipe_parser_task();
	
	static void* 											__recipe_parser_routine(void *host);
};


#endif /* R2H_TASK_AMEC_IO_CONTROL_H_ */
