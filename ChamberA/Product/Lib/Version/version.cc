/*
 * version.cc
 *
 *  Created on: Nov 8, 2021
 *      Author: haihangren
 */

#include "version.h"

namespace R2H_AMEC_PRODUCT
{
Version::Version(): __version_unsafe_ptr(0)
{
	
}

void Version::Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING name)
{
	R2H_UINT32 objectIndex[1] = {NOT_A_VALID_OBJECT_INDEX};
	R2H_INT32 counter = 1;
	R2H_TASK_PDO_INDEX_T index;
		
	pObjectManager->SearchPDO(R2H_TASK_TX_DIAGNOSTIC_AREA, name, objectIndex, &counter);
	if(counter == 0)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND));
	pObjectManager->UnsafeMemoryPointer(R2H_TASK_TX_DIAGNOSTIC_AREA, objectIndex[0], &index, (R2H_BYTE**)&__version_unsafe_ptr);
	if(index.variable_data_type != SIDE_DATA_TYPE_UINT)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));
}

void Version::WriteVersion(R2H_UINT32 v)
{
	*__version_unsafe_ptr = v;
}

R2H_UINT32 Version::ReadVersion()
{
	return *__version_unsafe_ptr;
}

}
