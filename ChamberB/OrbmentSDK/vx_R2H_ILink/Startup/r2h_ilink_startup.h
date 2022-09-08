/*
 * r2h_ilink_startup.h
 *
 *  Created on: 2020-4-28
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_STARTUP_H_
#define R2H_ILINK_STARTUP_H_

#include "../Protocol/r2h_ilink_protocol_server.h"
#include "r2h_ilink_startup_constant_def.h"
#include "../r2h_ilink_env.h"

#ifdef __cplusplus
extern "C" {
#endif

void 								vx_R2H_ILink_ServerVersion(	R2H_UINT32 *pRelease, R2H_UINT32 *pBuild);
R2H_ILINK::Engine* 					vx_R2H_ILink_EngineCreate(	R2H_UINT32 maxSteps,
																void* pObjectManager,
																PSEARCH_OBJECT objectSearcher
																);
void 								vx_R2H_ILink_EngineDestory(R2H_ILINK::Engine* pEngine);
R2H_ILINK::ProtocolServer*			vx_R2H_ILink_ServerCreate(R2H_ILINK::Engine* pEngine);
void 								vx_R2H_ILink_ServerDestory(	R2H_ILINK::ProtocolServer *pServer);
R2H_INT32 							vx_R2H_ILink_ServerStartup(	R2H_ILINK::ProtocolServer *pServer,
																R2H_TCP_PORT port, 
																R2H_INT32 timeout,
																R2H_INT32 listenBacklog, 
																R2H_INT32 listenPriority,
																R2H_INT32 workerPriority);
R2H_INT32 							vx_R2H_ILink_ServerShutdown(R2H_ILINK::ProtocolServer *pServer);


#ifdef __cplusplus
}
#endif

#endif /* R2H_ILINK_STARTUP_H_ */
