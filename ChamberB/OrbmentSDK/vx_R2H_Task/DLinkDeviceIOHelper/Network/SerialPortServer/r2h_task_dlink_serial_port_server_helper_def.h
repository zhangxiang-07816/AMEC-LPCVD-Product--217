/*
 * r2h_task_dlink_serial_port_server_helper_def.h
 *
 *  Created on: Jul 6, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_TASK_DLINK_SERIAL_PORT_SERVER_HELPER_DEF_H_
#define R2H_TASK_DLINK_SERIAL_PORT_SERVER_HELPER_DEF_H_

#include "../../../r2h_task_data_type.h"
#include "../../../../vx_R2H_EthModule/SerialPortServer/r2h_ethmodule_serial_port_server_def.h"
#include "../../../../vx_R2H_EthModule/SerialPortServer/r2h_ethmodule_serial_port_server.h"

#pragma pack(1)

typedef struct R2H_DLINK_SERIAL_PORT_SERVER_H_DIAG_AREA
{
	R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_INFO_T	local_info;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_LOCAL_DIAG_T	local_diag;
	R2H_ETHMODULE_SERIAL_PORT_SERVER_REMOTE_DIAG_AREA_T	remote_area;
}R2H_DLINK_SERIAL_PORT_SERVER_H_DIAG_AREA_T;

#pragma pack()

#endif /* R2H_TASK_DLINK_SERIAL_PORT_SERVER_HELPER_DEF_H_ */
