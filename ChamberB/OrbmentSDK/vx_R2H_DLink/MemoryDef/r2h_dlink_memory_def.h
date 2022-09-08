/*
 * r2h_dlink_remote_memory_def.h
 *
 *  Created on: 2017-7-22
 *      Author: CrazyHein
 */

#ifndef R2H_DLINK_MEMORY_DEF_H_
#define R2H_DLINK_MEMORY_DEF_H_

#include "../r2h_dlink_data_type.h"
//#define R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH			(64)
#define R2H_RINFO_SYSTEM_NAME_LENGTH 					(128)
//#define R2H_RINFO_IS_LAST_DEVICE_IO_INDEX(i)			(i&0x8000)
//#define R2H_RINFO_REAL_DEVICE_IO_INDEX(i)				(i&0x7FFF)
//#define R2H_RINFO_IS_LAST_TASK_INDEX(i)					(i&0x8000)
//#define R2H_RINFO_REAL_TASK_INDEX(i)					(i&0x7FFF)
#define R2H_RINFO_SYS_CONTROL_IN_SIZE					(256)
#define R2H_RINFO_SYS_CONTROL_OUT_SIZE					(256)
#define R2H_RINFO_TASK_CONTROL_IN_SIZE					(256)
#define R2H_RINFO_TASK_CONTROL_OUT_SIZE					(256)
#define R2H_RINFO_NOT_A_HANDSHAKE_VALUE					(0)
#define R2H_RINFO_TASK_NAME_LENGTH 						(64)

typedef enum R2H_RINFO_MEMORY_SEGMENT
{
	R2H_R_MEMORY_SYS_INFO = 0,
	R2H_R_MEMORY_DEVICE_IO = 1,
	R2H_R_MEMORY_USER_IO = 2,
	R2H_R_MEMORY_TASK_INFO = 3,

	R2H_R_MEMORY_SYS_CONTROL = 4,
	R2H_R_MEMORY_TASK_CONTROL = 5,

	R2H_R_MEMORY_SEGMENT_COUNT = 6
}R2H_RINFO_MEMORY_SEGMENT_T;

typedef enum R2H_RINFO_TASK_TYPE
{
	R2H_R_TASK_R2H_SERVICE = 1,
	R2H_R_TASK_COMMON_SERVICE = 2,
	R2H_R_TASK_PERIODIC = 3,
	R2H_R_TASK_SCAN = 4
}R2H_RINFO_TASK_TYPE_T;

typedef enum R2H_RINFO_TASK_SCHED_POLICY
{
	R2H_R_TASK_SCHED_FIFO = 1,
	R2H_R_TASK_SCHED_RR = 2,
	R2H_R_TASK_SCHED_SPORADIC = 3,
	R2H_R_TASK_SCHED_OTHER = 4
}R2H_RINFO_TASK_SCHED_POLICY_T;


//#pragma pack(push, 1)
#pragma pack(1)

typedef struct R2H_RINFO_MEMORY_SEGMENT_SYS_INFO
{
	//R2H_CHAR						memory_segment_name[R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH];
	struct
	{
		R2H_CHAR 					name[R2H_RINFO_SYSTEM_NAME_LENGTH];
		R2H_BYTE					sys_main_version;
		R2H_BYTE					sys_sub_version;
		R2H_UINT32					sys_build_data;	//0x07222017
		R2H_UINT32					user_io_size_in_byte;
	}remote_system_info;
	struct
	{
		R2H_UINT32					status_code;
	}remote_system_status;

}R2H_RINFO_MEMORY_SEGMENT_SYS_INFO_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_HEAD
{
	//R2H_CHAR						memory_segment_name[R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH];
	R2H_UINT32						quantity_of_device;
}R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_HEAD_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_ATTR
{
	R2H_UINT16						device_id;
	R2H_UINT16						device_type;
	//R2H_INT32						device_error_code;
	//R2H_UINT32						io_refresh_sec;
	//R2H_UINT32						io_refresh_nsec;
	R2H_UINT32						device_io_address;
	R2H_UINT32						device_memory_address;
	R2H_UINT32						device_process_in_size;
	R2H_UINT32						device_control_out_size;
	R2H_UINT32						device_process_out_size;
	R2H_UINT32						device_control_in_size;
}R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_ATTR_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS
{
	R2H_INT32						device_error_code;
	R2H_INT64						i_refresh_sec;
	R2H_INT32						i_refresh_nsec;
	R2H_INT64						o_refresh_sec;
	R2H_INT32						o_refresh_nsec;
}R2H_RINFO_MEMORY_SEGMENT_DEVICE_IO_STATUS_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_USER_IO_HEAD
{
	//R2H_CHAR						memory_segment_name[R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH];
	R2H_UINT32						user_memory_size_in_byte;
}R2H_RINFO_MEMORY_SEGMENT_USER_IO_HEAD_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_HEAD
{
	//R2H_CHAR						memory_segment_name[R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH];
	R2H_UINT32						quantity_of_task;
}R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_HEAD_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM
{
	R2H_UINT16						task_index;
	R2H_UINT16						task_type;
	R2H_INT32						task_error_code;
	R2H_CHAR						task_name[R2H_RINFO_TASK_NAME_LENGTH];
	union
	{
		struct
		{
			R2H_UINT32						priority_n;
			R2H_UINT32						priority_l;
			R2H_UINT32						max_repl;
			R2H_UINT32						repl_period_sec;
			R2H_UINT32						repl_period_nsec;
			R2H_UINT32						init_budget_sec;
			R2H_UINT32						init_budget_nsec;
		}task_r2h_service_param;
		struct
		{
			R2H_UINT32						policy;
			R2H_UINT32						priority;
		}task_common_service_param;
		struct
		{
			R2H_UINT32						policy;
			R2H_UINT32						priority;
			R2H_UINT32						period_time_sec;
			R2H_UINT32						period_time_nsec;
			R2H_UINT32						monitoring_time_sec;
			R2H_UINT32						monitoring_time_nsec;
			R2H_UINT32						max_monitoring_time_sec;
			R2H_UINT32						max_monitoring_time_nsec;
			R2H_UINT32						min_monitoring_time_sec;
			R2H_UINT32						min_monitoring_time_nsec;
		}task_periodic_param;
		struct
		{
			R2H_UINT32						policy;
			R2H_UINT32						priority;
			R2H_UINT32						constant_scan_time_sec;
			R2H_UINT32						constant_scan_time_nsec;
			R2H_UINT32						monitoring_scan_time_sec;
			R2H_UINT32						monitoring_scan_time_nsec;
			R2H_UINT32						max_monitoring_scan_time_sec;
			R2H_UINT32						max_monitoring_scan_time_nsec;
			R2H_UINT32						min_monitoring_scan_time_sec;
			R2H_UINT32						min_monitoring_scan_time_nsec;
		}task_scan_param;
	};
}R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM_T,*R2H_RINFO_MEMORY_SEGMENT_TASK_INFO_ITEM_P;


typedef struct R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_IN
{
	R2H_BYTE 								host_handshake_byte;
	R2H_UINT32								command;
	R2H_BYTE								param[R2H_RINFO_SYS_CONTROL_IN_SIZE];
}R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_IN_T;

typedef struct R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_OUT
{
	R2H_BYTE 								device_handshake_byte;
	R2H_INT32								result;
	R2H_BYTE								data[R2H_RINFO_SYS_CONTROL_OUT_SIZE];
}R2H_RINFO_MEMORY_SEGMENT_SYS_CONTROL_OUT_T;
	//R2H_CHAR									memory_segment_name[R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH];


typedef struct R2H_RINFO_MEMORY_SEGMENT_TASK_CONTROL_IN
{
	R2H_BYTE 								host_handshake_byte;
	R2H_UINT32								command;
	R2H_BYTE								param[R2H_RINFO_TASK_CONTROL_IN_SIZE];
}R2H_RINFO_MEMORY_SEGMENT_TASK_CONTROL_IN_T;
//R2H_CHAR									memory_segment_name[R2H_RINFO_MEMORY_SEGMENT_NAME_LENGTH];

typedef struct R2H_RINFO_MEMORY_SEGMENT_TASK_CONTROL_OUT
{
	R2H_BYTE 								device_handshake_byte;
	R2H_INT32								result;
	R2H_BYTE								data[R2H_RINFO_TASK_CONTROL_OUT_SIZE];
}R2H_RINFO_MEMORY_SEGMENT_TASK_CONTROL_OUT_T;


#pragma pack()
//#pragma pack(pop)


#endif /* R2H_DLINK_REMOTE_MEMORY_DEF_H_ */
