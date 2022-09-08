/*
 * r2h_ilink_engine_exception.h
 *
 *  Created on: 2020-5-26
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_EXCEPTION_H_
#define R2H_ILINK_ENGINE_EXCEPTION_H_

#include "../Branch/r2h_ilink_engine_branch.h"
#include "../Event/r2h_ilink_engine_event.h"

namespace R2H_ILINK
{
class ExceptionResponse
{
public:
	ExceptionResponse();
	virtual ~ExceptionResponse();
	void SetResponse(const cJSON* pExceptionObject, const EventStorage &globalEvents, const EventClock& clock, Context& context, R2H_UINT32 stepSlots);
	void ResetResponse();
	bool CheckEventReference(const Event*p) const;
	void ResetAllEvents();
	std::string ToString(R2H_UINT32 tabs = 0) const;
	bool Next(bool updatePostShaders, R2H_UINT32& nextStep);
private:
	ExceptionResponse(ExceptionResponse&);
	void* __exception_context;
	BranchVector __branchs;
	EventStorage __local_events;
	void __clean();
};
}
#endif /* R2H_ILINK_ENGINE_EXCEPTION_H_ */
