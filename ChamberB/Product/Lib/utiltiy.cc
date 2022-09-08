/*
 * utiltiy.cc
 *
 *  Created on: May 20, 2022
 *      Author: HaihangRen
 */
#include "utility.h"

namespace UTILITY
{
void INITIALIZE_PTR(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING name, R2H_TASK_PDO_AREA_T area, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType, R2H_BYTE** pptr, R2H_UINT32 *bitPos)
{
	R2H_UINT32 objectIndex[1] = {NOT_A_VALID_OBJECT_INDEX};
	R2H_INT32 counter = 1;
	R2H_TASK_PDO_INDEX_T index;
	
	pObjectManager->SearchPDO(area, name, objectIndex, &counter);
	if(counter != 1)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND_OR_DUPLICATED));
	pObjectManager->UnsafeMemoryPointer(area, objectIndex[0], &index, pptr);
	if(index.variable_data_type != dataType)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));
	if(bitPos)
		*bitPos = index.offset_in_bit % 8;
}
}
