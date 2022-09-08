/*
 * r2h_ilink_event.h
 *
 *  Created on: 2020-3-31
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_EVENT_H_
#define R2H_ILINK_EVENT_H_

#ifdef _WRS_VX_SMP
#include <pthread.h>
#include <vxWorks.h>
#elif WIN32
#include <windows.h>
#endif
#include <assert.h>
#include "r2h_ilink_engine_event_def.h"

#include "../Expression/r2h_ilink_engine_expression.h"
#include "../../Exception/r2h_ilink_exception.h"
#include "../../Utility/cJSON/cJSON.h"
#include "../../Utility/cJSON/cJSON_Utils.h"

using namespace std;

namespace R2H_ILINK
{

class EventAccessLock
{
public:
	EventAccessLock();
	EventAccessLock(const EventAccessLock&);
	EventAccessLock& operator=(const EventAccessLock&);
	virtual ~EventAccessLock();
	inline void				WriteLock() const;
	inline void				ReadLock() const;
	inline void				Unlock() const;
private:
#ifdef _WRS_VX_SMP
	SEM_ID					__sync_access_mutex;
#elif WIN32	
	HANDLE					__sync_access_mutex;
#endif
};

#ifdef _WRS_VX_SMP
void EventAccessLock::WriteLock() const
{
	semWTake(__sync_access_mutex, WAIT_FOREVER);	
}
void EventAccessLock::ReadLock() const
{
	semRTake(__sync_access_mutex, WAIT_FOREVER);
}
void EventAccessLock::Unlock() const
{
	semGive(__sync_access_mutex);
}
#elif WIN32
void EventAccessLock::WriteLock() const
{
	WaitForSingleObject(__sync_access_mutex, INFINITE);
}
void EventAccessLock::ReadLock() const
{
	WaitForSingleObject(__sync_access_mutex, INFINITE);
}
void EventAccessLock::Unlock() const
{
	ReleaseMutex(__sync_access_mutex);
}
#endif

class EventClock
{
public:
	EventClock(R2H_ULONG initialTicks = 0, EventAccessLock *pLock = 0);
	inline void SetLock(EventAccessLock *pLock);
	inline void SetInitialTicks(R2H_ULONG ticks);
	inline void Update(R2H_ULONG ticks);
	inline R2H_ULONG Ticks() const;
	inline R2H_ULONG InitialTicks() const;
	inline R2H_ULONG Duration() const;
private:
	R2H_ULONG						__initial_ticks;
	EventAccessLock*				__sync_access_mutex;
	R2H_ULONG						__ticks;
};

inline void EventClock::SetLock(EventAccessLock *pLock)
{
	__sync_access_mutex = pLock;
}

void EventClock::SetInitialTicks(R2H_ULONG ticks)
{
	if (__sync_access_mutex) __sync_access_mutex->WriteLock();
	__initial_ticks = ticks;
	__ticks = ticks;
	if (__sync_access_mutex) __sync_access_mutex->Unlock();
}

void EventClock::Update(R2H_ULONG ticks)
{
	if (__sync_access_mutex) __sync_access_mutex->WriteLock();
	__ticks = ticks;
	if (__sync_access_mutex) __sync_access_mutex->Unlock();
}

R2H_ULONG EventClock::Ticks() const
{
	if (__sync_access_mutex) __sync_access_mutex->ReadLock();
	R2H_ULONG res = __ticks;
	if (__sync_access_mutex) __sync_access_mutex->Unlock();
	return res;
}

R2H_ULONG EventClock::InitialTicks() const
{
	if (__sync_access_mutex) __sync_access_mutex->ReadLock();
	R2H_ULONG res = __initial_ticks;
	if (__sync_access_mutex) __sync_access_mutex->Unlock();
	return res;
}

R2H_ULONG EventClock::Duration() const
{
	if (__sync_access_mutex) __sync_access_mutex->ReadLock();
	R2H_ULONG res = __ticks - __initial_ticks;
	if (__sync_access_mutex) __sync_access_mutex->Unlock();
	return res;
}

class Event
{
public:
	Event(const EventClock &clock, EventAccessLock *pLock);
	Event(const Event&);
	Event& operator=(const Event&);
	virtual std::string ToString(bool escape = false) const = 0;
	virtual ~Event();
	virtual void Reset() = 0;
	virtual bool Eval() = 0;
	inline const EventClock& Clock() const;
protected:
	const EventClock&				_clock;
	inline void 					_wlock() const;
	inline void 					_rlock() const;
	inline void 					_unlock() const;
	inline void						_set_lock(EventAccessLock *pLock);
private:
	EventAccessLock*				__sync_access_mutex;
};

const EventClock& Event::Clock() const
{
	return _clock;
}

void Event::_rlock() const
{
	if(__sync_access_mutex)
		__sync_access_mutex->ReadLock();
}

void Event::_wlock() const
{
	if(__sync_access_mutex)
		__sync_access_mutex->WriteLock();
}

void Event::_unlock() const
{
	if(__sync_access_mutex)
		__sync_access_mutex->Unlock();
}

void Event::_set_lock(EventAccessLock *pLock)
{
	__sync_access_mutex = pLock;
}

}

#endif /* R2H_ILINK_EVENT_H_ */
