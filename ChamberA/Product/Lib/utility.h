/*
 * utility.h
 *
 *  Created on: May 20, 2022
 *      Author: HaihangRen
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include "r2h_task_io_control.h"
#include "common_def.h"

#ifdef __cplusplus
extern "C" {
#endif
namespace UTILITY
{

inline bool BIT_STATUS(R2H_BYTE* ptr, R2H_UINT32 bit)
{
	return (((*ptr) & (R2H_BYTE)(1 << bit)) == 0) ? false : true;	
}
inline void ENABLE_BIT(R2H_BYTE* ptr, R2H_UINT32 bit)
{
	(*ptr) |= (R2H_BYTE)(1 << bit);
}
inline void DISABLE_BIT(R2H_BYTE* ptr, R2H_UINT32 bit)
{
	(*ptr) &= ~(R2H_BYTE)(1 << bit);
}
inline void SET_BIT(R2H_BYTE* ptr, R2H_UINT32 bit, bool status)
{
	status ? ENABLE_BIT(ptr, bit) : DISABLE_BIT(ptr, bit);
}
void INITIALIZE_PTR(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING name, R2H_TASK_PDO_AREA_T area, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType, R2H_BYTE** pptr, R2H_UINT32 *bitPos);

}
#ifdef __cplusplus
}
#endif

#endif /* UTILITY_H_ */
