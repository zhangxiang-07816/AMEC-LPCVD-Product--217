/*
 * r2h_ilink_alert_event.h
 *
 *  Created on: 2020-4-3
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ALERT_EVENT_H_
#define R2H_ILINK_ALERT_EVENT_H_

#include "r2h_ilink_engine_event.h"
#include "r2h_ilink_engine_timer_event.h"

#include "../Expression/r2h_ilink_engine_expression.h"
#include "../../Exception/r2h_ilink_exception.h"

namespace R2H_ILINK
{

typedef enum INPUT_LEVEL_ALERT_PATTERN
{
	ABOVE_LEVEL_ALERT_PATTERN,
	BELOW_LEVEL_ALERT_PATTERN
}INPUT_LEVEL_ALERT_PATTERN_T;

class InputLevelAlertEvent: public Event
{
public:
	InputLevelAlertEvent(R2H_CONST_STRING exp, Context& context, R2H_DOUBLE lowerLevel, R2H_DOUBLE upperLevel, INPUT_LEVEL_ALERT_PATTERN_T pattern, bool initAlert, const EventClock& clock, EventAccessLock *pLock = 0);
	InputLevelAlertEvent(const cJSON* pEventJSON, Context& context, const EventClock& clock, EventAccessLock *pLock = 0);
	virtual ~InputLevelAlertEvent();
	virtual std::string ToString(bool escape = false) const;
	virtual void Reset();
	virtual bool Eval();
private:
	R2H_DOUBLE __lower_level, __upper_level;
	INPUT_LEVEL_ALERT_PATTERN_T __pattern;
	const Expression* __expression;
	bool __init_alert;
	bool __alert;
};

class InputLimitAlertEvent: public Event
{
public:
	InputLimitAlertEvent(R2H_CONST_STRING exp, Context& context, R2H_DOUBLE lower, R2H_DOUBLE upper, bool reversed, const EventClock& clock, EventAccessLock *pLock = 0);
	InputLimitAlertEvent(const cJSON* pEventJSON, Context& context, const EventClock& clock, EventAccessLock *pLock = 0);
	virtual ~InputLimitAlertEvent();
	virtual std::string ToString(bool escape = false) const;
	virtual void Reset();
	virtual bool Eval();
private:
	R2H_DOUBLE __lower_limit, __upper_limit;
	const Expression* __expression;
	bool __reversed;
};

class InputRateAlertEvent: public Event 
{
	
};

class FollowingErrorEvent: public Event
{
public:
	FollowingErrorEvent(R2H_CONST_STRING setpoint, R2H_CONST_STRING feedback, Context& context,
			R2H_ULONG onDelay, R2H_ULONG offDelay,
			R2H_DOUBLE positiveTolerance, R2H_DOUBLE negativeTolerance, bool initAlert, 
			const EventClock& clock, EventAccessLock *pLock = 0);
	FollowingErrorEvent(const cJSON* pEventJSON, Context& context, const EventClock& clock, EventAccessLock *pLock = 0);
	virtual ~FollowingErrorEvent();
	virtual std::string ToString(bool escape = false) const;
	virtual void Reset();
	virtual bool Eval();
private:
	TimerEvent* __on_delay;
	TimerEvent* __off_delay;
	const Expression* __setpoint;
	const Expression* __feedback;
	R2H_DOUBLE __positive_tolerance,  __negative_tolerance;
	bool __init_alert;
	bool __alert;
	void __clean();
};

}



#endif /* R2H_ILINK_ALERT_EVENT_H_ */
