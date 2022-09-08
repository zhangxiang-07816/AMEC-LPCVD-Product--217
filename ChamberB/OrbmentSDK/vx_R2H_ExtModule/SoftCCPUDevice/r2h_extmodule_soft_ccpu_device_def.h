/*
 * r2h_extmodule_soft_ccpu_device_def.h
 *
 *  Created on: 2021-2-18
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_SOFT_CCPU_DEVICE_DEF_H_
#define R2H_EXTMODULE_SOFT_CCPU_DEVICE_DEF_H_

typedef enum R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID
{
	SOFT_CCPU_M 									= 4,
	SOFT_CCPU_SM									= 5,
	SOFT_CCPU_D										= 13,
	SOFT_CCPU_SD									= 14,
	SOFT_CCPU_B										= 23,
	SOFT_CCPU_W										= 24,
	SOFT_CCPU_ZR									= 220,
}R2H_EXTMODULE_SOFT_CCPU_DEVICE_ID_T;

#define R2H_EXTMODULE_SLMP_DATA_BUFFER_SIZE_IN_WORD		(512)
#define R2H_EXTMODULE_SLMP_CTRL_BUFFER_SIZE_IN_WORD		(64)

#endif /* R2H_EXTMODULE_SOFT_CCPU_DEVICE_DEF_H_ */
