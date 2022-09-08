/*
 * r2h_ilink_condition_statement.h
 *
 *  Created on: 2020-4-20
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_CONDITION_STATEMENT_H_
#define R2H_ILINK_CONDITION_STATEMENT_H_

#include "r2h_ilink_engine_event.h"
#include "r2h_ilink_engine_timer_event.h"

#include "../Expression/r2h_ilink_engine_expression.h"
#include "../../Exception/r2h_ilink_exception.h"

namespace R2H_ILINK
{

typedef enum CONDITION_STATEMENT_FOR_EVENT
{
	CONDITION_EQUAL_TO,
	CONDITION_GREATER_THAN,
	CONDITION_LESS_THAN,
	CONDITION_GREATER_OR_EQUAL,
	CONDITION_LESS_OR_EQUAL,
}CONDITION_STATEMENT_FOR_EVENT_T;

class ConditionStatement: public Event
{
public:
	ConditionStatement(CONDITION_STATEMENT_FOR_EVENT_T condition, Context& context,
			R2H_CONST_STRING comparandA, R2H_CONST_STRING comparandB,
			R2H_ULONG onDelay, R2H_ULONG offDelay,
			R2H_DOUBLE positiveTolerance, R2H_DOUBLE negativeTolerance, 
			bool initValue, const EventClock& clock, EventAccessLock *pLock = 0);
	ConditionStatement(const cJSON* pEventJSON, Context& context, const EventClock& clock, EventAccessLock *pLock = 0);
	virtual ~ConditionStatement();
	virtual std::string ToString(bool escape = false) const;
	virtual void Reset();
	virtual bool Eval();
private:
	CONDITION_STATEMENT_FOR_EVENT_T __condition;
	const Expression* __comparand_a;
	const Expression* __comparand_b;
	TimerEvent* __on_delay;
	TimerEvent* __off_delay;
	R2H_DOUBLE __positive_tolerance,  __negative_tolerance;
	bool __init_value;
	bool __status;
	void __clean();
};

}

#endif /* R2H_ILINK_CONDITION_STATEMENT_H_ */
