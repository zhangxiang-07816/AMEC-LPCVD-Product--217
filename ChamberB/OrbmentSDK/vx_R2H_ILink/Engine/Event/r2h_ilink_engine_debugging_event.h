/*
 * r2h_ilink_debugging_event.h
 *
 *  Created on: 2020-4-8
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_DEBUGGING_EVENT_H_
#define R2H_ILINK_DEBUGGING_EVENT_H_

#include "r2h_ilink_engine_event.h"

namespace R2H_ILINK
{
class ConstantEvent: public Event
{
public:
	ConstantEvent(bool alert, const EventClock& clock, EventAccessLock *pLock = 0);
	ConstantEvent(const cJSON * pEventJSON, const EventClock& clock, EventAccessLock * pLock = 0);
	virtual ~ConstantEvent();
	virtual std::string ToString(bool escape = false) const;
	virtual void Reset();
	virtual bool Eval();
private:
	bool __alert;
};
}

#endif /* R2H_ILINK_DEBUGGING_EVENT_H_ */
