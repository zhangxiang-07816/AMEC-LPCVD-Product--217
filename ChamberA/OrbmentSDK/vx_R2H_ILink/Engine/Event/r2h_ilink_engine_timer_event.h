/*
 * r2h_ilink_timer_event.h
 *
 *  Created on: 2020-4-3
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_TIMER_EVENT_H_
#define R2H_ILINK_TIMER_EVENT_H_

#include "r2h_ilink_engine_event.h"

namespace R2H_ILINK
{
class TimerEvent: public Event
{
public:
	TimerEvent(R2H_ULONG timeout, const EventClock& clock, EventAccessLock *pLock = 0);
	TimerEvent(R2H_CONST_STRING timeout, Context& context, const EventClock& clock, EventAccessLock *pLock= 0);
	TimerEvent(const cJSON* pEventJSON, Context& context, const EventClock& clock, EventAccessLock *pLock = 0);
	virtual ~TimerEvent();
	virtual std::string ToString(bool escape = false) const;
	virtual void Reset();
	virtual bool Eval();
	R2H_ULONG TimerCountValue() const;
	bool TimerOverflow() const;
	R2H_ULONG TimeoutValue() const;
	void SetTimeoutValue(R2H_ULONG value);
private:
	R2H_ULONG					__timer_count_value;
	R2H_ULONG					__timeout;
	R2H_ULONG					__reset_ticks;
	Expression*					__timeout_expression;
};


}

#endif /* R2H_ILINK_TIMER_EVENT_H_ */
