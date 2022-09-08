/*
 * data_copy.h
 *
 *  Created on: Nov 22, 2021
 *      Author: HaihangRen
 */

#ifndef DATA_COPY_H_
#define DATA_COPY_H_

#include "../IOControl/r2h_task_io_control.h"
#include "../common_def.h"

namespace R2H_AMEC_PRODUCT
{

class DataCopy
{
public:
	DataCopy();
	void Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_TASK_PDO_AREA_T sourceArea, R2H_CONST_STRING sourceName, 
			R2H_TASK_PDO_AREA_T destinationArea, R2H_CONST_STRING destinationName, 
			R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
	void Procceed();
	static R2H_INT32 DATA_TYPE_SIZE_IN_BYTE(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType);
private:
	R2H_BYTE *__source, *__destination;
	R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T __data_type;
};

inline R2H_INT32 DataCopy::DATA_TYPE_SIZE_IN_BYTE(R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType)
{
	switch(dataType)
	{
	case SIDE_DATA_TYPE_BYTE:
	case SIDE_DATA_TYPE_SBYTE:
		return 1;
	case SIDE_DATA_TYPE_SHORT:
	case SIDE_DATA_TYPE_USHORT:
		return 2;
	case SIDE_DATA_TYPE_INT:
	case SIDE_DATA_TYPE_UINT:
	case SIDE_DATA_TYPE_FLOAT:
		return 4;
	case SIDE_DATA_TYPE_DOUBLE:
		return 8;
	case SIDE_DATA_TYPE_FP3201:
		return 4;
	case SIDE_DATA_TYPE_FP3202:
		return 4;
	case SIDE_DATA_TYPE_FP6401:
		return 8;
	case SIDE_DATA_TYPE_FP6402:
		return 8;
	case SIDE_DATA_TYPE_FP6404:
		return 8;
	case SIDE_DATA_TYPE_FINGERPRINT:
		return 16;			
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_TX:
		return 42;
	case SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_RX:
		return 30;	
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_TX:
		return 6;
	case SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_RX:
		return 4;
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_TX:
		return 10;
	case SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_RX:
		return 6;
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_RX:
	case SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_TX:
		return 6;
	default:
		return 0;
	}
}

}

#endif /* DATA_COPY_H_ */
