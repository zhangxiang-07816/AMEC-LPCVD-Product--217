/*
 * r2h_data_package_def.h
 *
 *  Created on: 2017-7-12
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_DATA_PACKAGE_DEF_H_
#define R2H_DLINK_DATA_PACKAGE_DEF_H_

#include "../r2h_dlink_data_type.h"

#define R2H_DLINK_MAX_PACKAGE_SIZE			1460
#define R2H_DLINK_MAX_PACKAGE_QUANTITY		1024

#define R2H_DLINK_DATA_PACKAGE_INDEX(i) 			(i&0x7FFF)
#define R2H_DLINK_DATA_LAST_PACKAGE_INDEX(i) 		(i&0x8000)
#define R2H_DLINK_DATA_MAKE_LAST_PACKAGE_INDEX(i) 	(i|0x8000)

#define R2H_DLINK_COOKIE_LENGTH 			(4)
#define R2H_DLINK_COOKIE_STR 				("AMEC")

//#pragma pack(push, 1)
#pragma pack(1)

typedef struct R2H_DLINK_DATA_PACKAGE_HEAD
{
	R2H_CHAR 		cookie[R2H_DLINK_COOKIE_LENGTH];
	R2H_UINT32 		totalLength;
	R2H_UINT16 		index;
	R2H_UINT16 		length;
}R2H_DLINK_DATA_PACKAGE_HEAD_T;

typedef struct R2H_DLINK_DATA_PACKAGE
{
	union
	{
		R2H_BYTE raw[R2H_DLINK_MAX_PACKAGE_SIZE];
		struct
		{
			R2H_DLINK_DATA_PACKAGE_HEAD header;
			R2H_BYTE 					pData[R2H_DLINK_MAX_PACKAGE_SIZE - sizeof(R2H_DLINK_DATA_PACKAGE_HEAD)];
		};
	};
}R2H_DLINK_DATA_PACKAGE_T;

#pragma pack()
//#pragma pack(pop)


#endif /* R2H_DATA_PACKAGE_DEF_H_ */
