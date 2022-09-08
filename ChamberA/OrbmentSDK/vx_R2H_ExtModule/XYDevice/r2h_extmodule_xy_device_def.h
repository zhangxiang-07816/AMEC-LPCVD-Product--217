/*
 * r2h_extmodule_xydevice_def.h
 *
 *  Created on: 2018-6-19
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_XY_DEVICE_DEF_H_
#define R2H_EXTMODULE_XY_DEVICE_DEF_H_


typedef enum R2H_XY_DEVICE_ACCESS_MODE
{
	X_ONLY_DEVICE 	= 0x01,
	Y_ONLY_DEVICE 	= 0x02,
	XY_DEVICE 		= 0x03
}R2H_XY_DEVICE_ACCESS_MODE_T;

#define RX10(base)					R2H_ExtModule_XYDevice(base,0x10,X_ONLY_DEVICE) //16bit AC110 Input
#define RX40C7(base)				R2H_ExtModule_XYDevice(base,0x10,X_ONLY_DEVICE) //16bit DC24 Input
#define RX41C4(base)				R2H_ExtModule_XYDevice(base,0x20,X_ONLY_DEVICE) //32bit DC24 Input
#define RX42C4(base)				R2H_ExtModule_XYDevice(base,0x40,X_ONLY_DEVICE) //64bit DC24 Input
#define RX40PC6H(base)				R2H_ExtModule_XYDevice(base,0x10,X_ONLY_DEVICE) //16bit DC24 PC High speed Input
#define RX40NC6H(base)				R2H_ExtModule_XYDevice(base,0x10,X_ONLY_DEVICE) //16bit DC24 NC High speed Input
#define RX41C6HS(base)				R2H_ExtModule_XYDevice(base,0x20,X_ONLY_DEVICE) //32bit DC24 High speed Input
#define RX61C6HS(base)				R2H_ExtModule_XYDevice(base,0x20,X_ONLY_DEVICE) //32bit DC5 High speed Input

#define RY10R2(base)				R2H_ExtModule_XYDevice(base,0x10,Y_ONLY_DEVICE) //16bit Relay Output
#define RY40NT5P(base)				R2H_ExtModule_XYDevice(base,0x10,Y_ONLY_DEVICE) //16bit Transistor Leak Output
#define RY41NT2P(base)				R2H_ExtModule_XYDevice(base,0x20,Y_ONLY_DEVICE) //32bit Transistor Leak Output
#define RY41NT2H(base)				R2H_ExtModule_XYDevice(base,0x20,Y_ONLY_DEVICE) //32bit Transistor Leak High speed Output
#define RY42NT2P(base)				R2H_ExtModule_XYDevice(base,0x40,Y_ONLY_DEVICE) //64bit Transistor Leak Output
#define RY40PT5P(base)				R2H_ExtModule_XYDevice(base,0x10,Y_ONLY_DEVICE) //16bit Transistor Source Output
#define RY41PT1P(base)				R2H_ExtModule_XYDevice(base,0x20,Y_ONLY_DEVICE) //32bit Transistor Source Output
#define RY41PT2H(base)				R2H_ExtModule_XYDevice(base,0x20,Y_ONLY_DEVICE) //32bit Transistor Source High speed Output
#define RY42PT1P(base)				R2H_ExtModule_XYDevice(base,0x40,Y_ONLY_DEVICE) //64bit Transistor Source Output

#define RH42C4NT2P(base)			R2H_ExtModule_XYDevice(base,0x20,XY_DEVICE) //32bit DC24 Input + 32bit Transistor Leak Output


#endif /* R2H_EXTMODULE_XYDEVICE_DEF_H_ */
