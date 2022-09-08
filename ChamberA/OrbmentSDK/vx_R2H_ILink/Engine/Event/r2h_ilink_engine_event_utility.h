/*
 * r2h_ilink_event_utility.h
 *
 *  Created on: 2020-4-3
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_EVENT_UTILITY_H_
#define R2H_ILINK_EVENT_UTILITY_H_

#include "r2h_ilink_engine_event.h"
#include "r2h_ilink_engine_debugging_event.h"
#include "r2h_ilink_engine_timer_event.h"
#include "r2h_ilink_engine_alert_event.h"
#include "r2h_ilink_engine_condition_statement.h"
#include "../../Utility/cJSON/cJSON.h"

namespace R2H_ILINK
{
	/*
	static Event* CreateNewEvent(const cJSON *pObject, const EventClock &clock, EventAccessLock *pLock = 0)
	{
		Event* pEvent = 0;
		R2H_INT32 select = 0;
		while (select >=0 && pEvent == 0)
		{
			try
			{
				switch (select)
				{
				case 0:
					pEvent = new InputLevelAlertEvent(pObject, clock, pLock);
					break;
				case 1:
					pEvent = new InputLimitAlertEvent(pObject, clock, pLock);
					break;
				case 2:
					pEvent = new FollowingErrorEvent(pObject, clock, pLock);
					break;
				case 3:
					pEvent = new TimerEvent(pObject, clock, pLock);
					break;
				case 4:
					pEvent = new FollowingErrorEvent(pObject, clock, pLock);
					break;
				case 5:
					pEvent = new ConditionStatement(pObject, clock, pLock);
					break;
				case 6:
					pEvent = new ConstantEvent(pObject, clock, pLock);
					break;
				default:
					select = -100;
					break;
				}
			}
			catch (std::exception&)
			{
				if (pEvent) delete pEvent; pEvent = 0;
			}
			select++;
		}	
		return pEvent;
	}
	*/
	
	static Event* CreateNewEvent(const cJSON *pObject, Context& context,const EventClock &clock, EventAccessLock *pLock = 0)
	{
		Event* pEvent = 0;
		cJSON* type = cJSON_GetObjectItemCaseSensitive(pObject, "TYPE");
		if (cJSON_IsObject(pObject))
		{
			if (cJSON_IsString(type))
			{			
				if(strcmp(INPUT_LEVEL_ALERT_EVENT_TYPE_NAME, type->valuestring) == 0)
					pEvent = new InputLevelAlertEvent(pObject, context, clock, pLock);
				else if(strcmp(INPUT_LIMIT_ALERT_EVENT_TYPE_NAME, type->valuestring) == 0)
					pEvent = new InputLimitAlertEvent(pObject, context, clock, pLock);
				else if(strcmp(FOLLOWING_ERROR_EVENT_TYPE_NAME, type->valuestring) == 0)
					pEvent = new FollowingErrorEvent(pObject, context, clock, pLock);
				else if(strcmp(TIMER_EVENT_TYPE_NAME, type->valuestring) == 0)
					pEvent = new TimerEvent(pObject, context, clock, pLock);
				else if(strcmp(CONSTENT_EVENT_TYPE_NAME, type->valuestring) == 0)
					pEvent = new ConstantEvent(pObject, clock, pLock);
				
				else if(strcmp(CONDITION_EQUAL_TO_TYPE_NAME, type->valuestring) == 0)
					pEvent = new ConditionStatement(pObject, context, clock, pLock);
				else if(strcmp(CONDITION_GREATER_THAN_TYPE_NAME, type->valuestring) == 0)
					pEvent = new ConditionStatement(pObject, context, clock, pLock);
				else if(strcmp(CONDITION_GREATER_OR_EQUAL_TYPE_NAME, type->valuestring) == 0)
					pEvent = new ConditionStatement(pObject, context, clock, pLock);
				else if(strcmp(CONDITION_LESS_THAN_TYPE_NAME, type->valuestring) == 0)
					pEvent = new ConditionStatement(pObject, context, clock, pLock);
				else if(strcmp(CONDITION_LESS_OR_EQUAL_TYPE_NAME, type->valuestring) == 0)
					pEvent = new ConditionStatement(pObject, context, clock, pLock);
				else
					throw Exception(R2H_ILINK_EVENT_UNKNOWN_EVENT_TYPE);
			}
			else
				throw Exception(R2H_ILINK_EVENT_INVALID_OBJECT_ATTRIBUTE);
		}
		else
			throw Exception(R2H_ILINK_EVENT_INVALID_JSON_OBJECT);
		
		return pEvent;
	}
}


#endif
