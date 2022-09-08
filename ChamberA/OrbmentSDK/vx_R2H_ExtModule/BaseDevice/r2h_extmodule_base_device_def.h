/*
 * r2h_extmodule_base_device_def.h
 *
 *  Created on: 2018-6-20
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_BASE_DEVICE_DEF_H_
#define R2H_EXTMODULE_BASE_DEVICE_DEF_H_

#define CCPU_DEDICATED_FUNCTION_NORMAL_RESULT				(0)
#define CCPU_DEDICATED_FUNCTION_NORMAL_ACCESS				(0)

typedef enum R2H_EXTMODULE_DEVICE_MODEL_ID
{
	RX10											= 0x0001,//16bit AC110 Input
	RX40C7											= 0x0002,//16bit DC24 Input
	RX41C4											= 0x0003,//32bit DC24 Input
	RX42C4											= 0x0004,//64bit DC24 Input
	RX40PC6H										= 0x0005, //16bit DC24 PC High speed Input
	RX40NC6H										= 0x0006,//16bit DC24 NC High speed Input
	RX41C6HS										= 0x0007,//32bit DC24 High speed Input
	RX61C6HS										= 0x0008, //32bit DC5 High speed Input

	RY10R2											= 0x0009,//16bit Relay Output
	RY40NT5P										= 0x000A,//16bit Transistor Leak Output
	RY41NT2P										= 0x000B,//32bit Transistor Leak Output
	RY41NT2H										= 0x000C,//32bit Transistor Leak High speed Output
	RY42NT2P										= 0x000D,//64bit Transistor Leak Output
	RY40PT5P										= 0x000E,//16bit Transistor Source Output
	RY41PT1P										= 0x000F,//32bit Transistor Source Output
	RY41PT2H										= 0x0010,//32bit Transistor Source High speed Output
	RY42PT1P										= 0x0011,//64bit Transistor Source Output

	RH42C4NT2P										= 0x0012,//32bit DC24 Input + 32bit Transistor Leak Output	
	
	R60AD4											= 0x0020,
	R60ADV8											= 0x0021,
	R60ADI8											= 0x0022,
	
	R60DA4											= 0x0030,						
	R60DAV8											= 0x0031,						
	R60DAI8											= 0x0032,						

	R60TD8_G										= 0x0040,						
	R60RD8_G										= 0x0041,					

	R60TCRT4										= 0x0050,
	R60TCTRT2TT2									= 0x0051,						

	RJ71DN91_MASTER									= 0x0060,
	RJ71DN91_SLAVE									= 0x0061,
	
	RD77MS2											= 0x0070,
	RD77MS4											= 0x0071,
	RD77MS8											= 0x0072,
	RD77MS16										= 0x0073,
	
	RD55UP06_V										= 0x0100,
	RD55UP12_V										= 0x0101,
	RD55UP06_V_SMART_ECAT							= 0x0102,
	RD55UP12_V_SMART_ECAT							= 0x0103,
	
	R12CCPU_V										= 0x1000,
	R12CCPU_V_SMART_ECAT							= 0x1001,
	
	GENERAL_SOFT_CCPU_M								= 0x8000,
	GENERAL_SOFT_CCPU_SM							= 0x8001,
	GENERAL_SOFT_CCPU_D								= 0x8002,
	GENERAL_SOFT_CCPU_SD							= 0x8003,
	GENERAL_SOFT_CCPU_B								= 0x8004,
	GENERAL_SOFT_CCPU_W								= 0x8005,
	GENERAL_SOFT_CCPU_ZR							= 0x8006

}R2H_EXTMODULE_DEVICE_MODEL_ID_T;



#endif /* R2H_EXTMODULE_BASE_DEVICE_DEF_H_ */
