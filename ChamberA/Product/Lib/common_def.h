/*
 * common_def.h
 *
 *  Created on: Oct 18, 2021
 *      Author: HaihangRen
 */

#ifndef COMMON_DEF_H_
#define COMMON_DEF_H_

#include "../IOControl/r2h_task_io_control.h"

namespace R2H_AMEC_PRODUCT
{

#define MAKE_USER_ERROR_CODE(code)	(R2H_TASK_USER_EXCEPTION | code)


#define VARIABLE_NAME_DATA_TYPE_MISMATCH				(0x001)
#define VARIABLE_NAME_NOT_FOUND_OR_DUPLICATED			(0x002)
#define INVALID_USER_PARAMETER							(0x003)
#define VARIABLE_NAME_NOT_FOUND							(0x004)

}



#endif /* COMMON_DEF_H_ */
