/*
 * r2h_ilink_engine_def.h
 *
 *  Created on: 2020-4-20
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENGINE_DEF_H_
#define R2H_ILINK_ENGINE_DEF_H_
#include "../r2h_ilink_data_type.h"

namespace R2H_ILINK
{
#ifdef _WRS_VX_SMP
	#define MAKE_ENGINE_TIMEOUT(milliseconds)			(milliseconds*60/1000)
	#define WAIT_ENGINE_WLOCK(lock, timeout)			(lock->WriteLock(MAKE_ENGINE_TIMEOUT(timeout)) == OK)
	#define WAIT_ENGINE_RLOCK(lock, timeout)			(lock->ReadLock(MAKE_ENGINE_TIMEOUT(timeout)) == OK)
#elif WIN32
	#define MAKE_ENGINE_TIMEOUT(milliseconds)			(milliseconds)
	#define WAIT_ENGINE_WLOCK(lock, timeout)			(lock->WriteLock(MAKE_ENGINE_TIMEOUT(timeout)) == WAIT_OBJECT_0)
	#define WAIT_ENGINE_RLOCK(lock, timeout)			(lock->ReadLock(MAKE_ENGINE_TIMEOUT(timeout)) == WAIT_OBJECT_0)
#endif

typedef enum ENGINE_PDO_MANAGER_ACCESS_MODE
{
	PDO_ACCESS_SCROLL_RENDER							= 0x00000001,
	PDO_ACCESS_STEP_EVALUATE							= 0x00000002,
	PDO_ACCESS_UPDATE_CLOCK								= 0x00000004,
	
	PDO_ACCESS_FULL										= 0xFFFFFFFF
}ENGINE_PDO_MANAGER_ACCESS_MODE_T;


typedef struct ENGINE_STATE
{
	union
	{
		struct
		{
			R2H_UINT32			active 						: 1;
			R2H_UINT32			idle				 		: 1;
		};
		R2H_UINT32				raw_state_dword;
	};
	ENGINE_STATE()
	{
		raw_state_dword = 0;
		idle = 1;
	}
}ENGINE_STATE_T;

}
#endif /* R2H_ILINK_ENGINE_DEF_H_ */
