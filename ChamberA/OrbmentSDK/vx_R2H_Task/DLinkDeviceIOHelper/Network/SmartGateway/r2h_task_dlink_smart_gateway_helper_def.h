/*
 * r2h_task_dlink_smart_gateway_helper_def.h
 *
 *  Created on: 2019-1-31
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_SMART_GATEWAY_HELPER_DEF_H_
#define R2H_TASK_DLINK_SMART_GATEWAY_HELPER_DEF_H_

#include "../../../r2h_task_data_type.h"
#include "../../../../vx_R2H_EthModule/SmartGateway/r2h_ethmodule_smart_gateway_def.h"
#include "../../../../vx_R2H_EthModule/SmartGateway/r2h_ethmodule_smart_gateway.h"

#pragma pack(2)

typedef struct R2H_DLINK_SMART_GATEWAY_PROCESS_IN_DATE
{
	R2H_ETHMODULE_SMART_GATEWAY_HOST_BASIC_INFO_T			host_basic_info;
	R2H_ETHMODULE_SMART_GATEWAY_HOST_DIAGNOSTIC_INFO_T		host_diagnostic_info;
	R2H_ETHMODULE_SMART_GATEWAY_DEVICE_DIAGNOSTIC_INFO_T	device_diagnostic_info;
	R2H_UINT16												user_input_data[R2H_ETHMODULE_PC104_SERIAL_PORT_SERVER_MEMORY_SIZE_IN_WORD];
}R2H_DLINK_SMART_GATEWAY_PROCESS_IN_DATE_T;

typedef struct R2H_DLINK_SMART_GATEWAY_PROCESS_OUT_DATE
{
	R2H_UINT16												user_output_data[R2H_ETHMODULE_PC104_SERIAL_PORT_SERVER_MEMORY_SIZE_IN_WORD];
}R2H_DLINK_SMART_GATEWAY_PROCESS_OUT_DATE_T;

typedef struct R2H_DLINK_SMART_GATEWAY_CONTROL_IN_DATE
{
	R2H_UINT16												host_control_command[MOD_TCP_MULTIPLE_REGISTER_WRITE_MAX];
}R2H_DLINK_SMART_GATEWAY_CONTROL_IN_DATE_T;

typedef struct R2H_DLINK_SMART_GATEWAY_CONTROL_OUT_DATE
{
	R2H_UINT16												host_control_result[MOD_TCP_HOLDING_REGISTER_READ_MAX];
}R2H_DLINK_SMART_GATEWAY_CONTROL_OUT_DATE_T;

typedef struct R2H_DLINK_SMART_GATEWAY_PROCESS_IO_REFRESH_RANGE
{
	R2H_UINT16					input_data_offset_in_word;
	R2H_UINT16					input_data_size_in_word;
	R2H_UINT16					output_data_offset_in_word;
	R2H_UINT16					output_data_size_in_word;
}R2H_DLINK_SMART_GATEWAY_PROCESS_IO_REFRESH_RANGE_T;

#pragma pack()

#endif /* R2H_TASK_DLINK_SMART_GATEWAY_HELPER_DEF_H_ */
