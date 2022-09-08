/*
 * version.h
 *
 *  Created on: Nov 8, 2021
 *      Author: haihangren
 */

#ifndef VERSION_H_
#define VERSION_H_

#include "../IOControl/r2h_task_io_control.h"
#include "../common_def.h"

namespace R2H_AMEC_PRODUCT
{
class Version
{
public:
	Version();
	void Init(R2H_Task_ProcessDataObjectManager *pObjectManager, R2H_CONST_STRING name);
	void WriteVersion(R2H_UINT32 v);
	R2H_UINT32 ReadVersion();
private:
	R2H_UINT32* __version_unsafe_ptr;
};
}



#endif /* VERSION_H_ */
