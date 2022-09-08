/*
 * r2h_ilink_protocol_master.h
 *
 *  Created on: 2020-4-26
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_PROTOCOL_MASTER_H_
#define R2H_ILINK_PROTOCOL_MASTER_H_

#include "../DataPackager/r2h_ilink_data_packager.h"
#include "r2h_ilink_protocol_comm.h"

namespace R2H_ILINK
{
class ProtocolMaster: public DataPackager
{
public:
	ProtocolMaster(R2H_INT32 timeout = 2000, ILinkPackagerAccessLock *pLock = 0);
	ProtocolMaster(ProtocolMaster&);
	virtual ~ProtocolMaster();
	
	void Connect(R2H_CONST_STRING remoteIP, R2H_TCP_PORT remotePort = 8367);
	void Disconnect();

	void Download(const PROTOCOL_RECIPE_SEGMENT_T segment, R2H_CONST_STRING pJSON, R2H_INT32 length);
	void Echo(const PROTOCOL_RECIPE_SEGMENT_T segment, R2H_UINT32 startIndex, R2H_UINT32 endIndex, R2H_BYTE *pData, R2H_INT32 *pLength);
	void Clear(const PROTOCOL_RECIPE_SEGMENT_T segment, R2H_UINT32 startIndex, R2H_UINT32 endIndex);

	inline static R2H_INT32							MAX_DOWNLOAD_DATA_SIZE_IN_BYTE();
	inline static R2H_INT32							MAX_ECHO_DATA_SIZE_IN_BYTE();
	inline static R2H_INT32							MAX_DOWNLOAD_STR_LENGTH_IN_BYTE();
	inline static R2H_INT32							MAX_ECHO_STR_LENGTH_IN_BYTE();
private:
	static R2H_INT32								__USER_DATA_SIZE_IN_BYTE;
	static R2H_INT32								__MAX_DOWNLOAD_DATA_SIZE_IN_BYTE;
	static R2H_INT32								__MAX_ECHO_DATA_SIZE_IN_BYTE;
	static R2H_INT32								__MAX_DOWNLOAD_STR_LENGTH_IN_BYTE;
	static R2H_INT32								__MAX_ECHO_STR_LENGTH_IN_BYTE;
	R2H_BYTE*										__user_data_array_ptr;
	R2H_INT32										__connection_timeout;
	ILinkPackagerAccessLock*						__sync_access_lock;
	R2H_INT32										__remote_server_connected;
	//PROTOCOL_FRAME_T								__master_frame_buffer;
};

inline R2H_INT32 ProtocolMaster::MAX_DOWNLOAD_DATA_SIZE_IN_BYTE()
{
	return __MAX_DOWNLOAD_DATA_SIZE_IN_BYTE;
}
inline R2H_INT32 ProtocolMaster::MAX_ECHO_DATA_SIZE_IN_BYTE()
{
	return __MAX_ECHO_DATA_SIZE_IN_BYTE;
}
inline R2H_INT32 ProtocolMaster::MAX_DOWNLOAD_STR_LENGTH_IN_BYTE()
{
	return __MAX_DOWNLOAD_STR_LENGTH_IN_BYTE;
}
inline R2H_INT32 ProtocolMaster::MAX_ECHO_STR_LENGTH_IN_BYTE()
{
	return __MAX_ECHO_STR_LENGTH_IN_BYTE;
}
}



#endif /* R2H_ILINK_PROTOCOL_MASTER_H_ */
