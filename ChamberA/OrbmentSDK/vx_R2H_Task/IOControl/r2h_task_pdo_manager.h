/*
 * r2h_task_pdo_manager.h
 *
 *  Created on: 2019-8-13
 *      Author: CrazyHein
 */

#ifndef R2H_TASK_PDO_MANAGER_H_
#define R2H_TASK_PDO_MANAGER_H_

#include "r2h_task_pdo_manager_def.h"
#include "r2h_task_pdo_interlock.h"
#include "../pugixml/pugixml.hpp"
#include "../r2h_task_data_type.h"
#include "r2h_task_io_control_def.h"
#include "r2h_task_exception.h"
#include "Encryption/MD5.h"
#include "../../vx_R2H_ILink/Startup/r2h_ilink_startup.h"
#include <vector>

using namespace pugi;

class R2H_Task_ProcessDataObjectManager
{
public:
	R2H_Task_ProcessDataObjectManager();
	R2H_Task_ProcessDataObjectManager(R2H_CONST_STRING variableCatalogue, R2H_CONST_STRING ioList);
	virtual ~R2H_Task_ProcessDataObjectManager();
	bool IsPDOLoaded();
	void FileMD5Hash(MD5_HASH* variableCatalogue, MD5_HASH* ioList);
	
	void Init(R2H_CONST_STRING variableCatalogue, R2H_CONST_STRING ioList);
	
	void BindToDeviceIOHelper(const std::vector<P_R2H_ExtModule_BaseDevice> *pExtDevices, 
			const std::vector<P_R2H_EthModule_SocketDevice> *pEthDevices,
			std::vector<P_R2H_Task_DLinkDeviceIOHelper> *pDeviceIOHelpers);

	void ImportRxPDO(R2H_ULONG counterMicros, R2H_ILINK::Engine &engine);
	void ExportRxPDO(R2H_ULONG counterMicros);
	void ExportTxPDO(R2H_ULONG counterMicros, R2H_ILINK::Engine &engine);
	
	void WriteReservedPDO(R2H_TASK_MANAGER_RESERVED_PDO_KEY_T key, const void* pData, R2H_INT32* pWriteLengthInByte);
	void ReadReservedPDO(R2H_TASK_MANAGER_RESERVED_PDO_KEY_T key, void* pData, R2H_INT32* pReadLengthInByte);
	
	R2H_INT32 WritePDO(R2H_TASK_PDO_AREA_T area, R2H_UINT32 offsetInByte, R2H_UINT32 sizeInByte, R2H_BYTE* pData, R2H_INT32 *pInterlock);
	R2H_INT32 ReadPDO(R2H_TASK_PDO_AREA_T area, R2H_UINT32 offsetInByte, R2H_UINT32 sizeInByte, R2H_BYTE* pData);
	R2H_INT32 ApplyInterlockLogic();
	
	void SearchPDO(R2H_TASK_PDO_AREA_T area, R2H_UINT32 objectIndex, R2H_TASK_PDO_INDEX_T *pIndex);
	void SearchPDO(R2H_TASK_PDO_AREA_T area, R2H_CONST_STRING name, R2H_UINT32 *pObjectIndexArray, R2H_INT32* pQuantityOfObjectIndex);
	void UnsafeMemoryPointer(R2H_TASK_PDO_AREA_T area, R2H_UINT32 objectIndex, R2H_TASK_PDO_INDEX_T *pIndex, R2H_BYTE** ptr);
	
	R2H_INT32 QuantityOfObject(R2H_TASK_PDO_AREA_T area);
	
	static bool SEARCH_OBJECT(void* pObjectManager, R2H_UINT32 objectIndex, R2H_TASK_PDO_AREA_T* pArea, R2H_TASK_PDO_INDEX_T *pIndex, R2H_BYTE** ptr);
	static void* ALIGNED_MALLOC(R2H_UINT32 required_bytes, R2H_UINT32 alignment);
	static void ALIGNED_FREE(void *p);
private:
	xml_document __variable_catalogue_doc;
	xml_document __io_list_doc;
	
	xpath_variable_set __object_index_set;
	xpath_variable_set __variable_name_set;
	xpath_variable_set __module_reference_set;
			
	xpath_query *__variable_name_query;
	xpath_query *__variable_data_type_query;
	xpath_query *__object_binding_module_query;
	xpath_query *__object_converter_up_scale_query;
	xpath_query *__object_converter_down_scale_query;
	xpath_query *__ext_module_id_query;
	xpath_query *__ext_module_sw_query;
	xpath_query *__ext_module_address_query;
	xpath_query *__eth_module_id_query;
	xpath_query *__eth_module_sw_query;
	xpath_query *__eth_module_ip_query;
	xpath_query *__eth_module_port_query;
	
	R2H_TASK_PDO_MAPPING_T __pdo_areas[6];
	R2H_TASK_PDO_MAPPING_T* __tx_diagnostic_area;
	R2H_TASK_PDO_MAPPING_T* __tx_bit_area;
	R2H_TASK_PDO_MAPPING_T* __tx_block_area;
	R2H_TASK_PDO_MAPPING_T* __rx_control_area;
	R2H_TASK_PDO_MAPPING_T* __rx_bit_area;
	R2H_TASK_PDO_MAPPING_T* __rx_block_area;
	
	std::map<R2H_UINT32, R2H_TASK_PDO_INDEX_T> 	__manager_reserved_pdo_indexs;
	
	vector<R2H_Task_PDOInterlockLogic*> __interlock_logics;
	
	SEM_ID __pdo_locks[6];
	SEM_ID __tx_diag_pdo_rwlock;
	SEM_ID __tx_bit_pdo_rwlock;
	SEM_ID __tx_block_pdo_rwlock;
	SEM_ID __rx_ctl_pdo_rwlock;
	SEM_ID __rx_bit_pdo_rwlock;
	SEM_ID __rx_block_pdo_rwlock;
	SEM_ID __pdo_index_rwlock;
	
	void __find_object_index_by_name(const xml_node &node, R2H_CONST_STRING name, R2H_UINT32 *pObjectIndexArray, R2H_INT32* pQuantityOfObjectIndex);
	void __init_bit_area(const xml_node &node, R2H_TASK_PDO_AREA_T area);
	void __init_block_area(const xml_node &node, R2H_TASK_PDO_AREA_T area);
	void __calculate_file_md5_hash(R2H_CONST_STRING variableCatalogue, R2H_CONST_STRING ioList);
	void __initialize_manager_reserved_pdo();
	void __clear();
	void __reset();
	void __reset(R2H_TASK_PDO_AREA_T area);
	void __reset(R2H_TASK_PDO_MAPPING_T* pArea);
	void __io_object_info(R2H_TASK_PDO_AREA_T area, const xml_node &node, R2H_UINT32 *pObjectIndex, R2H_UINT32 *pSizeInBit, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T *pDataType, R2H_TASK_MANAGER_RESERVED_PDO_KEY_T *pKey);
	static void __data_type_size_in_bit(R2H_CONST_STRING name, R2H_UINT32 *dataSizeInBit, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T *dataType);
	R2H_TASK_MANAGER_RESERVED_PDO_KEY_T __identify_manager_reserved_pdo(R2H_CONST_STRING name, R2H_TASK_PDO_AREA_T area, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T dataType, R2H_UINT32 dataSizeInBit);
	void __manager_reserved_pdo_info(R2H_TASK_MANAGER_RESERVED_PDO_KEY_T key, R2H_TASK_PDO_AREA_T *pArea, R2H_UINT32* dataSizeInBit, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T *dataType);
	void __binding_area_to_device_io_helper(const xml_node &pdoNode, R2H_TASK_PDO_AREA_T area,
				const std::vector<P_R2H_ExtModule_BaseDevice> *pExtDevices, const std::vector<P_R2H_EthModule_SocketDevice> *pEthDevices,
				std::vector<P_R2H_Task_DLinkDeviceIOHelper> *pDeviceIOHelpers);
	void __init_interlock_logics(const xml_node &node);
	void __init_interlock_target(const xml_node &node, R2H_Task_PDOInterlockTarget *pTarget);
	R2H_Task_PDOInterlockElement* __init_interlock_statement(const xml_node &node, R2H_Task_PDOInterlockExpression *pRootExpression);
	
	static const int __max_layer_of_nested_logic = 5;
	
	bool __pdo_loaded;
	
	MD5_HASH __io_list_file_md5_hash;
	MD5_HASH __variable_catalogue_file_md5_hash;
	Md5Context __file_md5_context;
	
	R2H_UINT32* __controller_heartbeat_counter_unsafe_ptr;
	R2H_UINT32* __host_heartbeat_counter_unsafe_ptr;
	
	//R2H_TASK_PDO_INDEX_T __tx_handshake_word_for_host_index;
	//R2H_TASK_PDO_INDEX_T __rx_handshake_word_for_host_index;
	//R2H_TASK_PDO_INDEX_T __tx_handshake_word_for_controller_index;
	//R2H_TASK_PDO_INDEX_T __rx_handshake_word_for_controller_index;
	
	R2H_UINT32 __rx_host_handshake_offset;
	R2H_UINT32 __rx_controller_handshake_offset;
	R2H_UINT16* __rx_host_handshake_unsafe_ptr;
	R2H_UINT16* __rx_controller_handshake_unsafe_ptr;
	R2H_UINT32 __tx_host_handshake_offset;
	R2H_UINT32 __tx_controller_handshake_offset;
	R2H_UINT16* __tx_host_handshake_unsafe_ptr;
	R2H_UINT16* __tx_controller_handshake_unsafe_ptr;
	
	bool __tx_pdo_export_sync;
	bool __rx_pdo_import_sync;
	
	void __import_rx_pdo(R2H_TASK_PDO_AREA_MASK_T mask, R2H_ULONG counterMicros);
	void __export_rx_pdo(R2H_TASK_PDO_AREA_MASK_T mask, R2H_ULONG counterMicros);
	void __export_tx_pdo(R2H_TASK_PDO_AREA_MASK_T mask, R2H_ULONG counterMicros);
	
	R2H_UINT32* __rx_recipe_engine_control_request_unsafe_ptr;
	R2H_UINT32* __rx_recipe_engine_initial_step_unsafe_ptr;
	R2H_UINT32* __tx_recipe_engine_control_response_unsafe_ptr;
	R2H_INT32* __tx_recipe_engine_control_result_unsafe_ptr;
	R2H_UINT32* __tx_recipe_engine_millisecond_counter_unsafe_ptr;
	R2H_UINT32* __tx_recipe_engine_step_counter_unsafe_ptr;
	R2H_UINT32* __tx_recipe_engine_state_unsafe_ptr;
	R2H_INT32* __tx_recipe_engine_user_return_unsafe_ptr;
	
	bool __recipe_engine_ready;
	bool __recipe_engine_activated;
};

inline bool R2H_Task_ProcessDataObjectManager::IsPDOLoaded()
{
	semRTake(__pdo_index_rwlock, WAIT_FOREVER);
	bool loaded = __pdo_loaded;
	semRWGive(__pdo_index_rwlock);
	return loaded;
}

inline void R2H_Task_ProcessDataObjectManager::__data_type_size_in_bit(
		R2H_CONST_STRING name, R2H_UINT32 *dataSizeInBit, R2H_TASK_DLINK_DEVICE_SIDE_DATA_TYPE_T *dataType)
{
	if (strcmp(name, "BIT") == 0){*dataType = SIDE_DATA_TYPE_BIT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "BYTE") == 0){*dataType = SIDE_DATA_TYPE_BYTE; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "SBYTE") == 0){*dataType = SIDE_DATA_TYPE_SBYTE; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "SHORT") == 0){*dataType = SIDE_DATA_TYPE_SHORT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "USHORT") == 0){*dataType = SIDE_DATA_TYPE_USHORT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "INT") == 0){*dataType = SIDE_DATA_TYPE_INT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "UINT") == 0){*dataType = SIDE_DATA_TYPE_UINT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "FLOAT") == 0){*dataType = SIDE_DATA_TYPE_FLOAT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DOUBLE") == 0){*dataType = SIDE_DATA_TYPE_DOUBLE; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	
	else if (strcmp(name, "FIXEDPOINT3201") == 0){*dataType = SIDE_DATA_TYPE_FP3201; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "FIXEDPOINT3202") == 0){*dataType = SIDE_DATA_TYPE_FP3202; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "FIXEDPOINT6401") == 0){*dataType = SIDE_DATA_TYPE_FP6401; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "FIXEDPOINT6402") == 0){*dataType = SIDE_DATA_TYPE_FP6402; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "FIXEDPOINT6404") == 0){*dataType = SIDE_DATA_TYPE_FP6404; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	
	else if (strcmp(name, "FINGERPRINT") == 0){*dataType = SIDE_DATA_TYPE_FINGERPRINT; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "ECAT_CIA402_DEFAULT_TX") == 0){*dataType = SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_TX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "ECAT_CIA402_DEFAULT_RX") == 0){*dataType = SIDE_DATA_TYPE_ECT_CIA402_DEFAULT_RX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DEVICENET_MFC_DEFAULT_TX") == 0){*dataType = SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_TX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DEVICENET_MFC_DEFAULT_RX") == 0){*dataType = SIDE_DATA_TYPE_DN_DEVICENET_MFC_DEFAULT_RX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DEVICENET_UPC_DEFAULT_TX") == 0){*dataType = SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_TX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DEVICENET_UPC_DEFAULT_RX") == 0){*dataType = SIDE_DATA_TYPE_DN_DEVICENET_UPC_DEFAULT_RX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DEVICENET_FRC_DEFAULT_TX") == 0){*dataType = SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_TX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else if (strcmp(name, "DEVICENET_FRC_DEFAULT_RX") == 0){*dataType = SIDE_DATA_TYPE_DN_DEVICENET_FRC_DEFAULT_RX; *dataSizeInBit = R2H_Task_DLinkDeviceIOHelper::DATA_SIZE_IN_BIT(*dataType);}
	else{*dataSizeInBit = 0, *dataType = SIDE_DATA_TYPE_NONE;}
}

#endif /* R2H_TASK_PDO_MANAGER_H_ */
