/*
 * r2h_dlink_remote_sever.h
 *
 *  Created on: 2017-7-31
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_REMOTE_SERVER_H_
#define R2H_DLINK_REMOTE_SERVER_H_

#include <vxworks.h>
#include "../Protocol/r2h_dlink_protocol.h"
#include "../MemoryDef/r2h_dlink_memory.h"
#include "../MemoryDef/r2h_dlink_memory_sys_info.h"
#include "../MemoryDef/r2h_dlink_memory_device_io.h"
#include "../MemoryDef/r2h_dlink_memory_user_io.h"
#include "../MemoryDef/r2h_dlink_memory_task_info.h"
#include "../MemoryDef/r2h_dlink_memory_sys_task_control.h"
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

namespace R2H_DLINK
{

#define EOK											(OK)
#define R2H_SERVER_THREAD_NAME_LENGTH				(64)
#define R2H_SERVER_LISTEN_ROUTINE_NAME				("R2H DLink Server Listening Task")
#define R2H_SERVER_WORK_ROUTINE_NAME				("R2H DLink Server Working Task")


class R2H_DLink_RemoteServer: private R2H_DLink_Protocol
{
public:
	R2H_DLink_RemoteServer(R2H_DLink_MemorySysInfo* pMemorySysInfo,
			R2H_DLink_MemoryDeviceIO* pMemoryDeviceIO,
			R2H_DLink_MemoryUserIO* pMemoryUserIO,
			R2H_DLink_MemoryTaskInfo* pMemoryTaskInfo,
			R2H_DLink_MemorySystemControl* pMemorySystemControl,
			R2H_DLink_MemoryTaskControl* pMemoryTaskControl);
	virtual ~R2H_DLink_RemoteServer();
	R2H_INT32 StartServer(R2H_TCP_PORT port, R2H_INT32 timeout,
			R2H_INT32 listenBacklog, R2H_INT32 listenPriority,
			R2H_INT32 workPriorityN, R2H_INT32 workPriorityL,
			R2H_INT32 workInitBudget_sec, R2H_INT32 workInitBudget_nsec,
			R2H_INT32 workReplPeriod_sec, R2H_INT32 workReplPeriod_nsec,
			R2H_INT32 workMaxRepl);
	R2H_INT32 StopServer();

private:
	virtual R2H_INT32 QueryRemoteDataPtr(R2H_DLINK_PROTOCOL_FUNC_CODE_T func, R2H_RINFO_MEMORY_SEGMENT_T segment,R2H_UINT32 start, R2H_INT32 length, R2H_BYTE **ppData);
	virtual R2H_INT32 SyncRemoteData(R2H_DLINK_PROTOCOL_FUNC_CODE_T func, R2H_BYTE segment,R2H_UINT32 start, R2H_INT32 length, R2H_BYTE *pData);
	void*										__server_buffer_ptr;
	R2H_INT32									__server_buffer_size_in_byte;
	//R2H_DLink_MemorySysInfo* 					__memory_sys_info_ptr;
	//R2H_DLink_MemoryDeviceIO* 					__memory_device_io_ptr;
	//R2H_DLink_MemoryUserIO* 					__memory_user_io_ptr;
	//R2H_DLink_MemoryTaskInfo* 					__memory_task_info_ptr;
	//R2H_DLink_MemorySystemControl* 				__memory_sys_control_ptr;
	//R2H_DLink_MemoryTaskControl* 				__memory_task_control_ptr;
	R2H_DLink_Memory*							__memory_object_ptr[R2H_R_MEMORY_SEGMENT_COUNT];
	//pthread_rwlock_t* 							__sync_lock_ptr;

	R2H_TCP_PORT 								__server_port;
	R2H_INT32 									__server_timeout;
	//R2H_INT32									__server_max_work_thread;
	R2H_INT32 									__server_listen_backlog;
	R2H_INT32 									__server_listen_thread_priority;
	R2H_INT32 									__server_work_thread_priority_n;
	R2H_INT32 									__server_work_thread_priority_l;
	R2H_INT32									__server_work_thread_budget_sec;
	R2H_INT32									__server_work_thread_budget_nsec;
	R2H_INT32									__server_work_thread_repl_period_sec;
	R2H_INT32									__server_work_thread_repl_period_nsec;
	R2H_INT32									__server_work_thread_max_repl;

	pthread_t 									__server_listen_thread_id;
	sem_t										__server_worker_sem;
	R2H_SOCKET									__server_listen_socket;


	static void* __server_listen_routine(void *host);
	static void* __server_work_routine(void *param);

	R2H_INT32 									__server_started;
	
	//for VxWorks
	R2H_CHAR									__server_listen_routine_name[R2H_SERVER_THREAD_NAME_LENGTH];
	R2H_CHAR									__server_work_routine_name[R2H_SERVER_THREAD_NAME_LENGTH];
};

}
#endif /* R2H_DLINK_REMOTE_SEVER_H_ */
