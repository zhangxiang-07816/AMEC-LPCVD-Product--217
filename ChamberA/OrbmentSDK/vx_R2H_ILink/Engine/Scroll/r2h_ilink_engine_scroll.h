/*
 * r2h_ilink_engine_scroll.h
 *
 *  Created on: 2020-5-3
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_SCROLL_H_
#define R2H_ILINK_ENGINE_SCROLL_H_

#include "r2h_ilink_engine_scroll_def.h"
#include "../Shader/r2h_ilink_engine_shader.h"
#include "../Event/r2h_ilink_engine_event_trigger.h"
#include <map>

namespace R2H_ILINK
{
class Scroll
{
public:
	Scroll(const cJSON* pScrollObject, const EventStorage &globalEvents, const EventClock &clock, Context& context);
	virtual ~Scroll();
	std::string ToString(R2H_UINT32 tabs = 0) const;
	void Render();
	R2H_UINT32 Index() const;
	void ResetAllEvents();
	static R2H_UINT32 SCROLL_INDEX(const cJSON * pScrollObject);
	inline bool CheckEventReference(const Event*p) const;
private:
	Scroll(const Scroll&);
	R2H_UINT32 __index;
	EventTrigger* __event_trigger;
	ShaderVector __on_shaders;
	ShaderVector __off_shaders;
	EventStorage __local_events;
	void __clean();
};

inline R2H_UINT32 Scroll::Index() const
{
	return __index;
}

inline bool Scroll:: CheckEventReference(const Event* p) const
{
	return __event_trigger == 0 ? false : __event_trigger->Search(p);
}

typedef std::map<R2H_UINT32, Scroll*> ScrollStorage;
}

#endif /* R2H_ILINK_ENGINE_SCROLL_H_ */
