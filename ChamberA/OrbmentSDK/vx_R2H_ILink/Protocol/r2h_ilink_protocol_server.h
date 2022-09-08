/*
 * r2h_ilink_protocol_server.h
 *
 *  Created on: 2020-4-26
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_PROTOCOL_SERVER_H_
#define R2H_ILINK_PROTOCOL_SERVER_H_

#include "../DataPackager/r2h_ilink_data_packager.h"
#include "r2h_ilink_protocol_comm.h"
#include "../Engine/r2h_ilink_engine.h"

#ifdef _WRS_VX_SMP
#include <vxworks.h>
#include <pthread.h>
#include <semaphore.h>

#elif WIN32

#endif


namespace R2H_ILINK
{
#ifdef _WRS_VX_SMP
	typedef pthread_t TASK_HANDLE;
	typedef sem_t SEMAPHORE_HANDLE;
	typedef pthread_mutex_t MUTEX_HANDLE;
	typedef void* (*PTASK_SERVER_ROUTINE)(void* lpThreadParameter);
	typedef void* TASK_PARAM;
#elif WIN32
	typedef HANDLE TASK_HANDLE;
	typedef HANDLE SEMAPHORE_HANDLE;
	typedef HANDLE MUTEX_HANDLE;
	typedef DWORD(WINAPI *PTASK_SERVER_ROUTINE)(LPVOID lpThreadParameter);
	typedef LPVOID TASK_PARAM;
#endif
	class ProtocolServer : public DataPackager
	{
	public:
		ProtocolServer(Engine &engine, ILinkPackagerAccessLock *pLock = 0);
		virtual ~ProtocolServer();

		void Start(R2H_TCP_PORT port, R2H_INT32 timeout, R2H_INT32 listenBacklog, R2H_INT32 listenPriority, R2H_INT32 workerPriority);
		void Stop();

		static inline R2H_INT32						SERVER_BUFFER_SIZE_IN_BYTE();
		inline static R2H_INT32						MAX_DOWNLOAD_DATA_SIZE_IN_BYTE();
		inline static R2H_INT32						MAX_ECHO_DATA_SIZE_IN_BYTE();
		inline static R2H_INT32						MAX_DOWNLOAD_STR_LENGTH_IN_BYTE();
		inline static R2H_INT32						MAX_ECHO_STR_LENGTH_IN_BYTE();
	private:
		static inline void							__initialize_server_worker_semaphore(SEMAPHORE_HANDLE &sem);
		static inline void							__create_server_worker_semaphore(SEMAPHORE_HANDLE &sem);
		static inline void							__wait_server_worker_semaphore(SEMAPHORE_HANDLE &sem);
		static inline void							__post_server_worker_semaphore(SEMAPHORE_HANDLE &sem);
		static inline void							__destroy_server_worker_semaphore(SEMAPHORE_HANDLE &sem);
		
		static inline void							__initialize_server_access_mutex(MUTEX_HANDLE &mutex);
		static inline void							__create_server_access_mutex(MUTEX_HANDLE &mutex);
		static inline void							__lock_server_access_mutex(MUTEX_HANDLE &mutex);
		static inline void							__unlock_server_access_mutex(MUTEX_HANDLE &mutex);
		static inline void							__destroy_server_access_mutex(MUTEX_HANDLE &mutex);

		static inline void							__create_server_task(R2H_STRING name, PTASK_SERVER_ROUTINE routine, R2H_INT32 priority, TASK_HANDLE &task, TASK_PARAM param);
		static inline void							__join_server_task(TASK_HANDLE task);

		R2H_INT32									__dispatch_host_request(R2H_INT32 timeout);

		Engine&										__engine;
		R2H_BYTE*									__server_buffer_ptr;
		static R2H_INT32							__SERVER_BUFFER_SIZE_IN_BYTE;
		static R2H_INT32							__MAX_DOWNLOAD_DATA_SIZE_IN_BYTE;
		static R2H_INT32							__MAX_ECHO_DATA_SIZE_IN_BYTE;
		static R2H_INT32							__MAX_DOWNLOAD_STR_LENGTH_IN_BYTE;
		static R2H_INT32							__MAX_ECHO_STR_LENGTH_IN_BYTE;
		R2H_INT32 									__server_started;
		R2H_INT32 									__worker_priority;
		R2H_INT32									__connection_timeout;

		TASK_HANDLE 								__server_listen_thread_id;
		//SEMAPHORE_HANDLE							__server_worker_semaphore;
		MUTEX_HANDLE								__sync_access_mutex;
		ILinkPackagerAccessLock*					__packager_sync_access_lock;

#ifdef _WRS_VX_SMP		
		static void*								__server_listen_routine(void *host);
		static void*								__server_worker_routine(void *param);
#elif WIN32
		static DWORD WINAPI 						__server_listen_routine(LPVOID host);
		static DWORD WINAPI 						__server_worker_routine(LPVOID param);
#endif
		R2H_CHAR									__server_listen_routine_name[R2H_ILINK_SERVER_THREAD_NAME_LENGTH];
		R2H_CHAR									__server_worker_routine_name[R2H_ILINK_SERVER_THREAD_NAME_LENGTH];
		R2H_SOCKET									__server_listen_socket;

		void 										__clean();
	};

	inline R2H_INT32 ProtocolServer::SERVER_BUFFER_SIZE_IN_BYTE()
	{
		return __SERVER_BUFFER_SIZE_IN_BYTE;
	}
	inline R2H_INT32 ProtocolServer::MAX_DOWNLOAD_DATA_SIZE_IN_BYTE()
	{
		return __MAX_DOWNLOAD_DATA_SIZE_IN_BYTE;
	}
	inline R2H_INT32 ProtocolServer::MAX_ECHO_DATA_SIZE_IN_BYTE()
	{
		return __MAX_ECHO_DATA_SIZE_IN_BYTE;
	}
	inline R2H_INT32 ProtocolServer::MAX_DOWNLOAD_STR_LENGTH_IN_BYTE()
	{
		return __MAX_DOWNLOAD_STR_LENGTH_IN_BYTE;
	}
	inline R2H_INT32 ProtocolServer::MAX_ECHO_STR_LENGTH_IN_BYTE()
	{
		return __MAX_ECHO_STR_LENGTH_IN_BYTE;
	}
	
	inline void ProtocolServer::__initialize_server_worker_semaphore(SEMAPHORE_HANDLE &sem)
	{
#ifdef _WRS_VX_SMP
		sem = 0;
#elif WIN32
		sem = NULL;
#endif
	}

	void ProtocolServer::__create_server_worker_semaphore(SEMAPHORE_HANDLE &sem)
	{
#ifdef _WRS_VX_SMP
		if(sem_init(&sem, 0, 3) != OK)
			throw Exception(R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE);
#elif WIN32
		sem = CreateSemaphore(0, 3, 3, 0);
		if (sem == NULL)
			throw Exception(R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE);
#endif
	}

	void ProtocolServer::__wait_server_worker_semaphore(SEMAPHORE_HANDLE &sem)
	{
#ifdef _WRS_VX_SMP
		sem_wait(&sem);
#elif WIN32
		WaitForSingleObject(sem, INFINITE);
#endif
	}

	void ProtocolServer::__post_server_worker_semaphore(SEMAPHORE_HANDLE &sem)
	{
#ifdef _WRS_VX_SMP
		sem_post(&sem);
#elif WIN32
		ReleaseSemaphore(sem, 1, NULL);
#endif
	}

	void ProtocolServer::__destroy_server_worker_semaphore(SEMAPHORE_HANDLE &sem)
	{
#ifdef _WRS_VX_SMP
		sem_destroy(&sem);
#elif WIN32
		CloseHandle(sem);
#endif
	}
	
	void ProtocolServer::__initialize_server_access_mutex(MUTEX_HANDLE &mutex)
	{
#ifdef _WRS_VX_SMP
		memset(&mutex, 0, sizeof(pthread_mutex_t));
#elif WIN32
		mutex = NULL;
#endif		
	}
	
	void ProtocolServer::__create_server_access_mutex(MUTEX_HANDLE &mutex)
	{
#ifdef _WRS_VX_SMP
		if(pthread_mutex_init(&mutex, NULL) != 0)
			throw Exception(R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE);
#elif WIN32
		mutex = CreateMutex(NULL, FALSE, NULL);
		if(mutex == NULL)
			throw Exception(R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE);
#endif		
	}
	
	void ProtocolServer::__lock_server_access_mutex(MUTEX_HANDLE &mutex)
	{
#ifdef _WRS_VX_SMP
		pthread_mutex_lock(&mutex);
#elif WIN32
		WaitForSingleObject(mutex, INFINITE);
#endif		
	}
	
	void ProtocolServer::__unlock_server_access_mutex(MUTEX_HANDLE &mutex)
	{
#ifdef _WRS_VX_SMP
		pthread_mutex_unlock(&mutex);
#elif WIN32
		ReleaseMutex(mutex);
#endif		
	}
	
	void ProtocolServer::__destroy_server_access_mutex(MUTEX_HANDLE &mutex)
	{
#ifdef _WRS_VX_SMP
		pthread_mutex_destroy(&mutex);
#elif WIN32
		CloseHandle(mutex);
#endif
	}
	void ProtocolServer::__create_server_task(R2H_STRING name, PTASK_SERVER_ROUTINE routine, R2H_INT32 priority, TASK_HANDLE &handle, TASK_PARAM param)
	{
#ifdef _WRS_VX_SMP		
		pthread_attr_t attr;
		pthread_attr_init(&attr); pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
		pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
		sched_param schedparam;
		schedparam.sched_priority = priority;
		pthread_attr_setschedparam(&attr, &schedparam);
		//for VxWorks
		pthread_attr_setopt(&attr, VX_FP_TASK);
		pthread_attr_setname(&attr, name);
		R2H_INT32 res = pthread_create(&handle, &attr, routine, param);
		pthread_attr_destroy(&attr);
		if (res != EOK)
			throw Exception(R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE);
#elif WIN32
		handle = CreateThread(NULL, 0, routine, param, 0, NULL);
		if (handle == NULL)
			throw Exception(R2H_ILINK_SERVER_OUT_OF_OS_RESOURCE);
#endif
	}

	void ProtocolServer::__join_server_task(TASK_HANDLE task)
	{
#ifdef _WRS_VX_SMP	
		pthread_join(task, 0);
#elif WIN32
		WaitForSingleObject(task, INFINITE);
#endif
	}
}


#endif /* R2H_ILINK_PROTOCOL_SERVER_H_ */
