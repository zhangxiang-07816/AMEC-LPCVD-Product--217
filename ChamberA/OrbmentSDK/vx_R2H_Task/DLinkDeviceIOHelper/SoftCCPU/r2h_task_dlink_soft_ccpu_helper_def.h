/*
 * r2h_task_dlink_soft_ccpu_helper_def.h
 *
 *  Created on: 2021-2-18
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SOFT_CCPU_HELPER_DEF_H_
#define R2H_TASK_DLINK_SOFT_CCPU_HELPER_DEF_H_

#include "../../r2h_task_data_type.h"
#include "../../../vx_R2H_ExtModule/SoftCCPUDevice/r2h_extmodule_soft_ccpu_device.h"

#pragma pack(2)

typedef struct R2H_DLINK_SOFT_CCPU_PROCESS_IN_DATE
{
	R2H_INT32												input_data_offset_in_word;
	R2H_INT32												input_data_size_in_word;
	R2H_INT32												output_data_offset_in_word;
	R2H_INT32												output_data_size_in_word;
	R2H_UINT16												user_input_data[R2H_EXTMODULE_SLMP_DATA_BUFFER_SIZE_IN_WORD];
}R2H_DLINK_SOFT_CCPU_PROCESS_IN_DATE_T;

typedef struct R2H_DLINK_SOFT_CCPU_PROCESS_OUT_DATE
{
	R2H_UINT16												user_output_data[R2H_EXTMODULE_SLMP_DATA_BUFFER_SIZE_IN_WORD];
}R2H_DLINK_SOFT_CCPU_PROCESS_OUT_DATE_T;

typedef struct R2H_DLINK_SOFT_CCPU_CONTROL_IN_DATE
{
	R2H_UINT16												host_control_command[R2H_EXTMODULE_SLMP_CTRL_BUFFER_SIZE_IN_WORD];
}R2H_DLINK_SOFT_CCPU_CONTROL_IN_DATE_T;

typedef struct R2H_DLINK_SOFT_CCPU_CONTROL_OUT_DATE
{
	R2H_UINT16												host_control_result[R2H_EXTMODULE_SLMP_CTRL_BUFFER_SIZE_IN_WORD];
}R2H_DLINK_SOFT_CCPU_CONTROL_OUT_DATE_T;

typedef struct R2H_DLINK_SOFT_CCPU_PROCESS_IO_REFRESH_RANGE
{
	R2H_INT32					input_data_offset_in_word;
	R2H_INT32					input_data_size_in_word;
	R2H_INT32					output_data_offset_in_word;
	R2H_INT32					output_data_size_in_word;
}R2H_DLINK_SOFT_CCPU_PROCESS_IO_REFRESH_RANGE_T;

#pragma pack()



#endif /* R2H_TASK_DLINK_SOFT_CCPU_HELPER_DEF_H_ */
