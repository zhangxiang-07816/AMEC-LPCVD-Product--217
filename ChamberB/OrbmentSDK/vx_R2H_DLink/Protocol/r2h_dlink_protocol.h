/*
 * r2h_dlink_protocol.h
 *
 *  Created on: 2017-7-19
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_PROTOCOL_H_
#define R2H_DLINK_PROTOCOL_H_

#include "../DataPackager/r2h_dlink_data_packager.h"
#include "r2h_dlink_protocol_def.h"
#include "../MemoryDef/r2h_dlink_memory_def.h"
namespace R2H_DLINK
{

class R2H_DLink_Protocol : public R2H_DLink_DataPackager
{
public:
	virtual ~R2H_DLink_Protocol();
	R2H_INT32 HostWriteDataToRemote(R2H_BYTE segment,R2H_UINT32 start, R2H_INT32 length, R2H_BYTE *pData, R2H_INT32 timeout);
	R2H_INT32 HostReadDataFrRemote(R2H_BYTE segment,R2H_UINT32 start, R2H_INT32 length, R2H_BYTE *pData, R2H_INT32 timeout);

	R2H_INT32 RemoteDispatchHostRequest(R2H_INT32 timeout);


	virtual R2H_INT32 QueryRemoteDataPtr(R2H_DLINK_PROTOCOL_FUNC_CODE_T func, R2H_RINFO_MEMORY_SEGMENT_T segment,R2H_UINT32 start, R2H_INT32 length, R2H_BYTE **ppData) = 0;
	virtual R2H_INT32 SyncRemoteData(R2H_DLINK_PROTOCOL_FUNC_CODE_T func, R2H_BYTE segment,R2H_UINT32 start, R2H_INT32 length, R2H_BYTE *pData) = 0;
};

}

#endif /* R2H_DLINK_PROTOCOL_H_ */


