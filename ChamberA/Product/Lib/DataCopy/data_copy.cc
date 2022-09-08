/*
 * data_copy.cc
 *
 *  Created on: Nov 22, 2021
 *      Author: HaihangRen
 */
#include "data_copy.h"

namespace R2H_AMEC_PRODUCT
{

DataCopy::DataCopy(): __source(0), __destination(0)
{
	
}

void DataCopy::Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_TASK_PDO_AREA_T sourceArea, R2H_CONST_STRING sourceName, 
		R2H_TASK_PDO_AREA_T destinationArea, R2H_CONST_STRING destinationName, 
		R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	R2H_UINT32 objectIndex[1] = {NOT_A_VALID_OBJECT_INDEX};
	R2H_INT32 counter = 1;
	R2H_TASK_PDO_INDEX_T index;
	
	pObjectManager->SearchPDO(sourceArea, sourceName, objectIndex, &counter);
	if(counter == 0)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND));
	pObjectManager->UnsafeMemoryPointer(sourceArea, objectIndex[0], &index, (R2H_BYTE**)&__source);
	if(index.variable_data_type != dataType)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));
	
	pObjectManager->SearchPDO(destinationArea, destinationName, objectIndex, &counter);
	if(counter == 0)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_NOT_FOUND));
	pObjectManager->UnsafeMemoryPointer(destinationArea, objectIndex[0], &index, (R2H_BYTE**)&__destination);
	if(index.variable_data_type != dataType)
		throw R2H_Task_Exception(MAKE_USER_ERROR_CODE(VARIABLE_NAME_DATA_TYPE_MISMATCH));
	
	__data_type = dataType;
}

void DataCopy::Procceed()
{
	memcpy(__destination, __source, DATA_TYPE_SIZE_IN_BYTE(__data_type));
}

}
