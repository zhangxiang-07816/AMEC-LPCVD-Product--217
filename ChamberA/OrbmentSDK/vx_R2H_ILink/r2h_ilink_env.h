/*
 * r2h_ilink_env.h
 *
 *  Created on: 2020-4-16
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_ENV_H_
#define R2H_ILINK_ENV_H_

#include "r2h_ilink_data_type.h"

namespace R2H_ILINK
{
	extern void*								__ILINK_ENV_PDO_OBJECT_MANAGER;

	class Context
	{
	public:
		Context();
		void ResetAll();
		R2H_ULONG								VariableTick;
		R2H_UINT32								VariableStep;
		R2H_DOUBLE								VariableDebug;
		R2H_DOUBLE								VariableUserDataArray[16];
		R2H_INT32								VariableReturnCode;
	};
}



#endif /* R2H_ILINK_ENV_H_ */
