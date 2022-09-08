/*
 * lpcvd_alpha_startup.cc
 *
 *  Created on: Oct 18, 2021
 *      Author: HaihangRen
 */

#include "lpcvd_alpha_startup.h"

void vx_LPCVD_Alpha_Startup_Ex(R2H_CONST_STRING variableCatalogue, R2H_CONST_STRING ioList)
{
	vx_R2H_Task_StartupWithPDOManager(__user_process_control_routine_ex,__user_io_device_init_ex,0, variableCatalogue, ioList);
}
