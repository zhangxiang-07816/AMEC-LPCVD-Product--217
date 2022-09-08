/*
 * r2h_ilink_event_trigger.h
 *
 *  Created on: 2020-4-7
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_EVENT_TRIGGER_H_
#define R2H_ILINK_EVENT_TRIGGER_H_

#include <map>
#include <iostream>
#include <string>
#include "r2h_ilink_engine_event.h"

namespace R2H_ILINK
{

class EventTriggerLogicTree;

class EventTriggerLogicElement
{
public:
	EventTriggerLogicElement(EVENT_TRIGGER_ELEMENT_TYPE_T type, EventTriggerLogicTree *pRoot);
	EventTriggerLogicElement(const EventTriggerLogicElement&);
	EventTriggerLogicElement& operator=(const EventTriggerLogicElement&);
	virtual ~EventTriggerLogicElement();
	inline EVENT_TRIGGER_ELEMENT_TYPE_T Type() const;
	inline R2H_INT32 Layer() const;
	virtual std::string ToString(R2H_UINT32 tabs = 0) const = 0;
	virtual bool Eval() = 0;
	virtual bool Search(const Event*) const = 0;
private:
	const EVENT_TRIGGER_ELEMENT_TYPE_T __type;
	EventTriggerLogicTree* __root_ptr;
	const R2H_INT32 __layer;
};
EVENT_TRIGGER_ELEMENT_TYPE_T EventTriggerLogicElement::Type() const {return __type;}
R2H_INT32 EventTriggerLogicElement::Layer() const {return __layer;}

class EventTriggerLogicOperand : public EventTriggerLogicElement
{
public:
	EventTriggerLogicOperand(Event& event, R2H_UINT32 index, bool region, EventTriggerLogicTree *pRoot);
	virtual ~EventTriggerLogicOperand();
	virtual std::string ToString(R2H_UINT32 tabs = 0) const;
	virtual bool Eval();
	virtual bool Search(const Event*) const;
private:
	Event& __internal_event;
	R2H_UINT32 __index;
	bool __global_region;
};

class EventTriggerLogicTree : public EventTriggerLogicElement
{
public:
	EventTriggerLogicTree(EVENT_TRIGGER_LOGIC_OPERATOR_T op, EventTriggerLogicTree *pRoot);
	virtual ~EventTriggerLogicTree();
	virtual std::string ToString(R2H_UINT32 tabs = 0) const;
	virtual bool Eval();
	inline EVENT_TRIGGER_LOGIC_OPERATOR_T LogicOperator() const;
	void AppendLogicElement(EventTriggerLogicElement*);
	R2H_UINT32 ElementCount() const;
	virtual bool Search(const Event*) const;
private:
	const EVENT_TRIGGER_LOGIC_OPERATOR_T __logic_operator;
	vector<EventTriggerLogicElement*> __logic_elements;
};

EVENT_TRIGGER_LOGIC_OPERATOR_T EventTriggerLogicTree::LogicOperator() const {return __logic_operator;}

typedef struct __EVENT_TRIGGER_LOGIC_STATEMENT
{
	R2H_INT32						tabs;
	Event*							event_ptr;
	R2H_UINT32						index;
	bool							global_region;
	EVENT_TRIGGER_LOGIC_OPERATOR_T	op;
	__EVENT_TRIGGER_LOGIC_STATEMENT()
	{
		tabs = 0;
		event_ptr = 0;
		index = 0;
		global_region = false;
		op = EVENT_TRIGGER_LOGIC_NONE;
	}
}__EVENT_TRIGGER_LOGIC_STATEMENT_T;

typedef std::map<R2H_UINT32, Event*> EventStorage;
typedef std::map<Event*, R2H_UINT32> EventReference;

class EventTrigger
{
public:
	EventTrigger(const std::string statement, const EventStorage &globalEvents, EventStorage &localEvents, const EventClock& localClock, Context& context);
	EventTrigger(const cJSON* pStatement, const EventStorage &globalEvents, EventStorage &localEvents, const EventClock& localClock, Context& context);
	EventTrigger(const EventTrigger&);
	EventTrigger& operator=(const EventTrigger&);
	virtual ~EventTrigger();
	std::string ToString(R2H_UINT32 tabs = 0) const;
	bool Eval();
	bool Search(const Event*) const;
private:
	EventTriggerLogicElement *__logic_tree;
	const static R2H_CONST_STRING  __GLOBAL_EVENT_PATTERN;
	const static R2H_CONST_STRING  __LOCAL_EVENT_PATTERN;
	const static R2H_CONST_STRING  __LOCAL_EVENT_OBJECT_PATTERN;
	void __converter(const std::string &str, vector<__EVENT_TRIGGER_LOGIC_STATEMENT_T> &buffer, const EventStorage &globalEvents, EventStorage &localEvents, const EventClock& localClock, Context& context);
	void __converter(const cJSON *pStatement, vector<__EVENT_TRIGGER_LOGIC_STATEMENT_T> &buffer, const EventStorage &globalEvents,  EventStorage &localEvents, const EventClock& localClock, Context& context);
	EventTriggerLogicElement* __search_logic_element(vector<__EVENT_TRIGGER_LOGIC_STATEMENT_T> &buffer, size_t *pStart, EventTriggerLogicTree *pRoot);
};


}
#endif /* R2H_ILINK_EVENT_TRIGGER_H_ */
