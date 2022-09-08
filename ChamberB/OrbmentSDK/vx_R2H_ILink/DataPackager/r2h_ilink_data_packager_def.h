/*
 * r2h_ilink_data_packager_def.h
 *
 *  Created on: 2020-4-10
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_DATA_PACKAGER_DEF_H_
#define R2H_ILINK_DATA_PACKAGER_DEF_H_

#include "../r2h_ilink_data_type.h"

namespace R2H_ILINK
{

#define MAX_PACKAGE_SIZE					1460
#define MAX_PACKAGE_QUANTITY				4096

#define DATA_PACKAGE_INDEX(i) 				(i&0x7FFF)
#define DATA_LAST_PACKAGE_INDEX(i) 			(i&0x8000)
#define DATA_MAKE_LAST_PACKAGE_INDEX(i) 	(i|0x8000)

#define COOKIE_LENGTH 						(4)
#define COOKIE_STR 							("AMEC")

#pragma pack(1)

typedef struct DATA_PACKAGE_HEAD
{
	R2H_CHAR 		cookie[COOKIE_LENGTH];
	R2H_UINT32 		totalLength;
	R2H_UINT16 		index;
	R2H_UINT16 		length;
}DATA_PACKAGE_HEAD_T;

typedef struct DATA_PACKAGE
{
	union
	{
		R2H_BYTE raw[MAX_PACKAGE_SIZE];
		struct
		{
			DATA_PACKAGE_HEAD 			header;
			R2H_BYTE 					pData[MAX_PACKAGE_SIZE - sizeof(DATA_PACKAGE_HEAD)];
		};
	};
}DATA_PACKAGE_T;

#pragma pack()

}

#endif /* R2H_ILINK_DATA_PACKAGER_DEF_H_ */
