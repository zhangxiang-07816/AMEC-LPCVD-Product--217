/*
 * r2h_ilink_engine.h
 *
 *  Created on: 2020-4-20
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_H_
#define R2H_ILINK_ENGINE_H_

#include "r2h_ilink_engine_def.h"
#include "Branch/r2h_ilink_engine_branch.h"
#include "Shader/r2h_ilink_engine_shader.h"
#include "Step/r2h_ilink_engine_step.h"
#include "Scroll/r2h_ilink_engine_scroll.h"
#include "Event/r2h_ilink_engine_event.h"
#include "Exception/r2h_ilink_engine_exception.h"
#include "../r2h_ilink_env.h"

namespace R2H_ILINK
{

class EngineAccessLock
{
public:
	EngineAccessLock();
	EngineAccessLock(const EngineAccessLock&);
	virtual ~EngineAccessLock();
#ifdef _WRS_VX_SMP
	inline STATUS			WriteLock(R2H_UINT32 timeout = WAIT_FOREVER) const;
	inline STATUS			ReadLock(R2H_UINT32 timeout = WAIT_FOREVER) const;
	inline void				Unlock() const;
#elif WIN32
	inline DWORD			WriteLock(R2H_UINT32 timeout = INFINITE) const;
	inline DWORD			ReadLock(R2H_UINT32 timeout = INFINITE) const;
	inline void				Unlock() const;
#endif
private:
#ifdef _WRS_VX_SMP
	SEM_ID					__sync_access_mutex;
#elif WIN32	
	HANDLE					__sync_access_mutex;
#endif
};

#ifdef _WRS_VX_SMP
STATUS EngineAccessLock::WriteLock(R2H_UINT32 timeout) const
{
	return semWTake(__sync_access_mutex, timeout);
}
STATUS EngineAccessLock::ReadLock(R2H_UINT32 timeout) const
{
	return semRTake(__sync_access_mutex, timeout);
}
void EngineAccessLock::Unlock() const
{
	semGive(__sync_access_mutex);
}
#elif WIN32
DWORD EngineAccessLock::WriteLock(R2H_UINT32 timeout) const
{
	return WaitForSingleObject(__sync_access_mutex, timeout);
}
DWORD EngineAccessLock::ReadLock(R2H_UINT32 timeout) const
{
	return WaitForSingleObject(__sync_access_mutex, timeout);
}
void EngineAccessLock::Unlock() const
{
	ReleaseMutex(__sync_access_mutex);
}
#endif

class Engine
{
public:
	Engine(R2H_UINT32 maxStepIndex = 1024*4, R2H_UINT32 throughput = 16, EngineAccessLock* pLock = 0);
	virtual ~Engine();

	void AddEvent(R2H_UINT32 index, const cJSON* pEventObject);
	void AddEvent(const cJSON* pEventOrEventArrayObject);
	void RemoveEvent(R2H_UINT32 index);
	void ClearEventStorage();
	void RemoveEvent(R2H_UINT32 startIndex, R2H_UINT32 endIndex);
	std::string EventsEcho(R2H_UINT32 index) const;
	std::string EventsEcho(R2H_UINT32 startIndex, R2H_UINT32 endIndex) const;
	std::string EventsEcho() const;

	void SetStepSlot(const cJSON* pStepOrStepArrayObject);
	void ResetStepSlot(R2H_UINT32 index);
	void ResetStepStorage();
	void ResetStepSlot(R2H_UINT32 startIndex, R2H_UINT32 endIndex);
	std::string StepsEcho(R2H_UINT32 index) const;
	std::string StepsEcho(R2H_UINT32 startIndex, R2H_UINT32 endIndex) const;
	std::string StepsEcho() const;

	void AddScroll(const cJSON* pScrollOrScrollArrayObject);
	void RemoveScroll(R2H_UINT32 index);
	void ClearScrollStorage();
	void RemoveScroll(R2H_UINT32 startIndex, R2H_UINT32 endIndex);
	std::string ScrollsEcho(R2H_UINT32 index) const;
	std::string ScrollsEcho(R2H_UINT32 startIndex, R2H_UINT32 endIndex) const;
	std::string ScrollsEcho() const;
	
	void SetExceptionResponse(const cJSON* pExceptionObject);
	void ResetExceptionResponse();
	std::string ExceptionResponseEcho() const;
	
	ENGINE_STATE_T State() const;
	R2H_UINT32 StepPos() const;
	R2H_ULONG MilliCounter() const;
	R2H_INT32 ReturnCode() const;
	
	R2H_INT32 CState(ENGINE_STATE_T&) const;
	R2H_INT32 CStepPos(R2H_UINT32&) const;
	R2H_INT32 CMilliCounter(R2H_ULONG&) const;
	R2H_INT32 CMilliCounter(R2H_UINT32&) const;
	R2H_INT32 CReturnCode(R2H_INT32&) const;

	void Activate(R2H_ULONG owner, R2H_UINT32 stepIndex, R2H_ULONG tickMillis);
	void Shutdown(R2H_ULONG owner, R2H_ULONG tickMillis);
	void Reset(R2H_UINT32 stepIndex, R2H_ULONG tickMillis);
	void DirectPDOManagerAccess(R2H_UINT32 mode, R2H_ULONG tickMillis);
	R2H_INT32 CActivate(R2H_ULONG owner, R2H_UINT32 stepIndex, R2H_ULONG tickMillis);
	R2H_INT32 CShutdown(R2H_ULONG owner, R2H_ULONG tickMillis);
	R2H_INT32 CReset(R2H_UINT32 stepIndex, R2H_ULONG tickMillis);
	R2H_INT32 CDirectPDOManagerAccess(R2H_UINT32 mode, R2H_ULONG tickMillis);

protected:
	void _AcquireOwnership(R2H_ULONG owner, R2H_UINT32 timeout);
	void _ReleaseOwnership(R2H_ULONG owner, R2H_UINT32 timeout);
	R2H_INT32 _CAcquireOwnership(R2H_ULONG owner, R2H_UINT32 timeout);
	R2H_INT32 _CReleaseOwnership(R2H_ULONG owner, R2H_UINT32 timeout);
	
private:
	Engine(Engine&);
	EventClock __global_clock;
	EventStorage __global_events;
	StepVector __steps;
	R2H_UINT32 __throughput;
	ScrollStorage __scrolls;
	ExceptionResponse __exception_response;
	EngineAccessLock* __sync_access_lock;
	R2H_ULONG __owner;
	void __reset(R2H_UINT32 stepIndex, R2H_ULONG tickMillis);
	void __direct_pdo_memory_access(R2H_UINT32 mode, R2H_ULONG tickMillis);
	void __clean();
	void __clear_global_events();
	void __reset_steps();
	void __clear_scrolls();
	void __add_event_array_object(const cJSON* pEventArrayObject);
	void __add_event_object(const cJSON* pEventObject);
	void __set_step_array_object(const cJSON* pStepArrayObject);
	void __set_step_object(const cJSON* pStepObject);
	void __check_event_reference(const Event*) const;
	bool __check_event_step_reference(const Event*) const;
	bool __check_event_scroll_reference(const Event*) const;
	bool __check_event_exception_reference(const Event*) const;
	void __add_scroll_array_object(const cJSON* pScrollArrayObject);
	void __add_scroll_object(const cJSON* pScrollObject);

	Context __context;
};
}



#endif /* R2H_ILINK_ENGINE_H_ */
