/*
 * r2h_task_dlink_xy_device_helper_def.h
 *
 *  Created on: 2018-8-28
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_DLINK_XY_DEVICE_HELPER_DEF_H_
#define R2H_TASK_DLINK_XY_DEVICE_HELPER_DEF_H_

#pragma pack(2)

typedef union R2H_DLINK_XY_DEVICE_PROCESS_IN_DATE
{
	struct
	{
		R2H_UINT16			input_data[1];
		R2H_UINT16			output_data_readback[1];
	}xy16_device;
	struct
	{
		R2H_UINT16			input_data[1];
	}x16_device;
	struct
	{
		R2H_UINT16			output_data_readback[1];
	}y16_device;
	struct
	{
		R2H_UINT16			input_data[2];
		R2H_UINT16			output_data_readback[2];
	}xy32_device;
	struct
	{
		R2H_UINT16			input_data[2];
	}x32_device;
	struct
	{
		R2H_UINT16			output_data_readback[2];
	}y32_device;
	//struct
	//{
		//R2H_UINT16			input_data[4];
		//R2H_UINT16			output_data_readback[4];
	//}xy64_device;
	struct
	{
		R2H_UINT16			input_data[4];
	}x64_device;
	struct
	{
		R2H_UINT16			output_data_readback[4];
	}y64_device;
}R2H_DLINK_XY_DEVICE_PROCESS_IN_DATE_T;

typedef union	R2H_DLINK_XY_DEVICE_PROCESS_OUT_DATE
{
	struct
	{
		R2H_UINT16			output_data[1];
	}y16_device;
	struct
	{
		R2H_UINT16			output_data[1];
	}xy16_device;
	struct
	{
		R2H_UINT16			output_data[2];
	}y32_device;
	struct
	{
		R2H_UINT16			output_data[2];
	}xy32_device;
	struct
	{
		R2H_UINT16			output_data[4];
	}y64_device;
	//struct
	//{
		//R2H_UINT16			output_data[4];
	//}xy64_device;	
}R2H_DLINK_XY_DEVICE_PROCESS_OUT_DATE_T;



#pragma pack(0)



#endif /* R2H_TASK_DLINK_XY_DEVICE_HELPER_DEF_H_ */
