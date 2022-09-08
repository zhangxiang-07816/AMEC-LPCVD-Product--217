#ifndef R2H_DLINK_STARTUP_H_
#define R2H_DLINK_STARTUP_H_

#include <vxworks.h>
#include <assert.h>

#include "r2h_dlink_startup_constant_def.h"
#include "../RemoteVxWorksServer/r2h_dlink_remote_server.h"

#ifdef __cplusplus
	extern "C" {
#endif

R2H_DLINK::R2H_DLink_RemoteServer*	vx_R2H_DLink_ServerCreate(	R2H_DLink_MemorySysInfo* pMemorySysInfo,
													R2H_DLink_MemoryDeviceIO* pMemoryDeviceIO,
													R2H_DLink_MemoryUserIO* pMemoryUserIO,
													R2H_DLink_MemoryTaskInfo* pMemoryTaskInfo,
													R2H_DLink_MemorySystemControl* pMemorySystemControl,
													R2H_DLink_MemoryTaskControl* pMemoryTaskControl);
void vx_R2H_DLink_ServerDestory(R2H_DLINK::R2H_DLink_RemoteServer *pServer);
R2H_INT32 vx_R2H_DLink_ServerStartup(	R2H_DLINK::R2H_DLink_RemoteServer *pServer,
										R2H_TCP_PORT port, 
										R2H_INT32 timeout,
										R2H_INT32 listenBacklog, 
										R2H_INT32 listenPriority,
										R2H_INT32 workPriorityN,R2H_INT32 workPriorityL,
										R2H_INT32 workInitBudget_sec, R2H_INT32 workInitBudget_nsec,
										R2H_INT32 workReplPeriod_sec, R2H_INT32 workReplPeriod_nsec,
										R2H_INT32 workMaxRepl);
R2H_INT32 vx_R2H_DLink_ServerShutdown(R2H_DLINK::R2H_DLink_RemoteServer *pServer);

void vx_R2H_DLink_ServerVersion(R2H_UINT32 *pRelease, R2H_UINT32 *pBuild);


#ifdef __cplusplus
	}
#endif
#endif
