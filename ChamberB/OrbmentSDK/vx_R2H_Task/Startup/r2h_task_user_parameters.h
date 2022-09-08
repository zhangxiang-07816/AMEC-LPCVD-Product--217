/*
 * r2h_startup_user_parameters.h
 *
 *  Created on: 2018-8-21
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_USER_PARAMETERS_H_
#define R2H_TASK_USER_PARAMETERS_H_

#include "../pugixml/pugixml.hpp"
#include "../r2h_task_data_type.h"
#include "../IOControl/Encryption/MD5.h"
#include "r2h_task_user_parameters_def.h"
#include <vector>

using namespace pugi;
using namespace std;

class R2H_Task_UserParameters
{
public:
	R2H_Task_UserParameters();
	R2H_Task_UserParameters(R2H_CONST_STRING filePath);
	virtual ~R2H_Task_UserParameters();
	
	void LoadParametersFromFile(R2H_CONST_STRING filePath);
	void LoadParametersFromFile();
	
	R2H_TASK_PARAM_EVENT_LOGGER_T					DefaultLogger;
	R2H_UINT16										HostCPUAddress;
	vector<R2H_TASK_PARAM_EXTENSION_MODULE_T>		ExtensionModules;
	vector<R2H_TASK_PARAM_ETHERNET_MODULE_T>		EthernetModules;
	R2H_UINT32										UserIOSizeInByte;
	R2H_TASK_PARAM_R2H_DLINK_SERVER_T				R2H_DLinkServerSettings;
	R2H_TASK_PARAM_R2H_ILINK_SERVER_T				R2H_ILinkServerSettings;
	R2H_TASK_PARAM_DEVICE_IO_SCAN_T					DeviceIOScanTaskSettings;
	R2H_TASK_PARAM_DEVICE_CONTROL_T					DeviceControlTaskSettings;
	R2H_TASK_PARAM_RECIPE_PARSER_T					RecipeParserTaskSettings;
	MD5_HASH										ParametersFileMD5Hash;
	bool 											HashAvailable;
	R2H_UINT32										EngineStepCapacity;
private:
	xml_document 									__user_parameters_doc;
	xml_parse_result 								__parse_result;
	Md5Context 										__file_md5_context;
	void 											__clear();
	vector<R2H_TASK_PARAM_SUB_MODULE_T>*			__load_eni_file(R2H_CONST_STRING filePath);
	vector<R2H_TASK_PARAM_SUB_MODULE_T>*			__load_port_server_slaves(R2H_CONST_STRING filePath);
};


#endif /* R2H_STARTUP_USER_PARAMETERS_H_ */
