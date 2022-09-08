/*
 * r2h_data_package.h
 *
 *  Created on: 2017-7-12
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_DATA_PACKAGE_H_
#define R2H_DLINK_DATA_PACKAGE_H_

#include <string.h>
#include "../r2h_dlink_data_type.h"
#include "../Utility/r2h_dlink_socket.h"
#include "r2h_dlink_data_packager_def.h"
namespace R2H_DLINK
{
class R2H_DLink_DataPackager
{
public:
	R2H_DLink_DataPackager();
	virtual ~R2H_DLink_DataPackager();
	R2H_INT32 			R2H_DLink_DataRecv(R2H_BYTE *pBuffer, R2H_INT32 bufferSizeInByte, R2H_INT32* pRecvSizeInByte, R2H_INT32 timeout);
	R2H_INT32 			R2H_DLink_DataSend(R2H_BYTE *pData, R2H_INT32 dataSizeInByte, R2H_INT32* pSendSizeInByte, R2H_INT32 timeout);
private:
	R2H_INT32			__r2h_dlink_recv_package(	R2H_DLINK_DATA_PACKAGE_HEAD_T *header,
													R2H_BYTE *pBuffer,R2H_INT32 bufferSizeInByte, R2H_INT32* pRecvSizeInByte,
													R2H_INT32 timeout);
	R2H_INT32			__r2h_dlink_send_package(	R2H_BYTE *pBuffer,R2H_INT32 bufferSizeInByte, R2H_INT32* pSendSizeInByte,
													R2H_UINT32 totalLength, R2H_UINT16 index, R2H_INT32 timeout);

	R2H_UINT16			__r2h_package_data_length;
protected:
	R2H_SOCKET			_r2h_socket;
};
}

#endif /* R2H_DATA_PACKAGE_H_ */
