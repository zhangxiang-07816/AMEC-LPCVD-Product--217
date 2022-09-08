/*
 * r2h_extmodule_analog_in_device_static.h
 *
 *  Created on: 2018-6-29
 *      Author: CrazyHein
 */

#ifndef R2H_EXTMODULE_ANALOG_IN_DEVICE_STATIC_H_
#define R2H_EXTMODULE_ANALOG_IN_DEVICE_STATIC_H_

#include <vxWorks.h>
#include <msgQLib.h>
#include <taskLib.h>
#include <string.h>
#include "r2h_extmodule_analog_in_device.h"
#include "r2h_extmodule_analog_in_device_def.h"
#include "r2h_extmodule_analog_in_device_buffer_address.h"

#define R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_SIZE_IN_WORD					R2H_AD_DEVICE_CH_LOGGING_SIZE_IN_WORD

#pragma pack(2)
typedef struct R2H_AD_DEVICE_LOGGING_HOLD_ISR_MSG
{
	R2H_INT32					id;
	R2H_UINT16					device_base_address;
	R2H_INT32					channel_index;
	struct
	{
		R2H_INT16				oldest_data_offset;
		R2H_INT16				latest_data_offset;
		R2H_INT16				num_of_logging_data;
		R2H_INT16				trigger_data_offset;
	}holding_data_info;
	struct
	{
		R2H_UINT16				time_of_year;
		R2H_BYTE				time_of_day;
		R2H_BYTE				time_of_month;
		R2H_BYTE				time_of_minute;
		R2H_BYTE				time_of_hour;
		R2H_BYTE				time_of_day_of_week;
		R2H_BYTE				time_of_second;
		R2H_UINT16				time_of_millisecond;
	}trigger_generation_time;
}R2H_AD_DEVICE_LOGGING_HOLD_ISR_MSG_T;


typedef struct R2H_AD_DEVICE_LOGGING_READ_ISR_MSG
{
	R2H_INT32				id;
	R2H_UINT16				device_base_address;
	R2H_INT32				channel_index;
	R2H_INT16				current_read_offset;
	R2H_INT16				previous_read_offset;
	R2H_INT16				logging_read_points;
}R2H_AD_DEVICE_LOGGING_READ_ISR_MSG_T;


#pragma pack()



typedef struct R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER
{
	R2H_INT32			id;
	R2H_INT32			unread_data_offset;
	R2H_INT32			unread_data_size_in_word;
	R2H_UINT16			data[R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_SIZE_IN_WORD];
}R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_T;

int	__r2h_ad_device_logging_read_func_ist(R2H_INT32 index, MSG_Q_ID loggingReadMessages, 
											SEM_ID* mutexLocks, R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_T* loggingReadData);
void __r2h_ad_device_initialize_ch_logging_read_ring_buffer(R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_T* data);

#define __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER(index) \
		R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_T __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL];
#define __INIT_R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER(index) \
		__r2h_ad_device_initialize_ch_logging_read_ring_buffer(__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index);

#define __R2H_AD_DEVICE_LOGGING_READ_ISR_MESSAGE_QUEUE(index, queueLength) \
		VX_MSG_Q(__r2h_ad_device_logging_read_isr_message_queue##index,queueLength,sizeof(R2H_AD_DEVICE_LOGGING_READ_ISR_MSG_T));\
		MSG_Q_ID __R2H_AD_DEVICE_LOGGING_READ_ISR_MESSAGE_QUEUE##index = 0;
#define __INIT_R2H_AD_DEVICE_LOGGING_READ_ISR_MESSAGE_QUEUE(index, queueLength) \
		__R2H_AD_DEVICE_LOGGING_READ_ISR_MESSAGE_QUEUE##index = msgQInitialize(__r2h_ad_device_logging_read_isr_message_queue##index, queueLength, sizeof(R2H_AD_DEVICE_LOGGING_READ_ISR_MSG_T),MSG_Q_FIFO );

#define __R2H_AD_DEVICE_LOGGING_HOLD_ISR_MESSAGE_QUEUE(index, queueLength) \
		VX_MSG_Q(__r2h_ad_device_logging_hold_isr_message_queue##index,queueLength,sizeof(R2H_AD_DEVICE_LOGGING_HOLD_ISR_MSG_T));\
		MSG_Q_ID __R2H_AD_DEVICE_LOGGING_HOLD_ISR_MESSAGE_QUEUE##index = 0;
#define __INIT_R2H_AD_DEVICE_LOGGING_HOLD_ISR_MESSAGE_QUEUE(index, queueLength) \
		__R2H_AD_DEVICE_LOGGING_HOLD_ISR_MESSAGE_QUEUE##index = msgQInitialize(__r2h_ad_device_logging_hold_isr_message_queue##index, queueLength, sizeof(R2H_AD_DEVICE_LOGGING_HOLD_ISR_MSG_T),MSG_Q_FIFO );

#define __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX(index) \
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch0##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch1##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch2##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch3##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch4##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch5##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch6##index);\
		VX_MUTEX_SEMAPHORE(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch7##index);\
		SEM_ID __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[R2H_AD_DEVICE_MAX_NUM_OF_CHANNEL];
#define __INIT_R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX(index) \
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[0] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch0##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[1] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch1##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[2] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch2##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[3] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch3##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[4] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch4##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[5] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch5##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[6] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch6##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\
		__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[7] = semMInitialize(__r2h_ad_channel_logging_read_ring_buffer_mutex_ch7##index,SEM_Q_PRIORITY | SEM_INVERSION_SAFE);\

#define __R2H_AD_DEVICE_LOGGING_READ_IST(index, taskPriority, stackSize) \
		VX_TASK(__r2h_ad_device_logging_read_ist##index,stackSize);\
		TASK_ID __R2H_AD_DEVICE_LOGGING_READ_IST##index = 0;
#define __INIT_R2H_AD_DEVICE_LOGGING_READ_IST(index, taskPriority, stackSize) \
		__R2H_AD_DEVICE_LOGGING_READ_IST##index = VX_TASK_INSTANTIATE(__r2h_ad_device_logging_read_ist##index, taskPriority, 0, stackSize, __r2h_ad_device_logging_read_func_ist,index, (int)__R2H_AD_DEVICE_LOGGING_READ_ISR_MESSAGE_QUEUE##index,(int)__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index,(int)__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index,0,0,0,0,0,0);

#define __R2H_AD_DEVICE_MODULE_ISR(index,factor, base) \
		void __R2H_AD_DEVICE_MODULE_ISR##index##factor() \
		{\
			/*R2H_UINT16 temps[R2H_AD_DEVICE_MAX_NUM_OF_INTERRUPT]; \*/\
			R2H_UINT16 temp;\
			R2H_UINT16 rst = R2H_AD_DEVICE_INTERRUPT_FACTOR_RST_RSQ ; \
			R2H_AD_DEVICE_LOGGING_HOLD_ISR_MSG_T logging_hold_message;\
			R2H_AD_DEVICE_LOGGING_READ_ISR_MSG_T logging_read_message;\
			logging_hold_message.device_base_address = base;\
			logging_read_message.device_base_address = base;\
			CCPU_FromBuf_ISR(base/16, R2H_AD_DEVICE_BUFM_INTERRUPT_FACTOR_DETECTION_FLAG0+factor,1,&temp);\
			if(temp == R2H_AD_DEVICE_INTERRPUT_FACTOR_ON) \
			{\
				if(factor%2 == 0)\
				{\
					logging_hold_message.id = 0;\
					logging_hold_message.channel_index = (factor/2);\
					CCPU_FromBuf_ISR(base/16, R2H_ExtModule_AnalogInDevice::R2H_AD_DEVICE_BUFM_CH_OLDEST_LOGGING_OFFSET[factor/2], 4,(R2H_UINT16*)&(logging_hold_message.holding_data_info));\
					CCPU_FromBuf_ISR(base/16, R2H_ExtModule_AnalogInDevice::R2H_AD_DEVICE_BUFM_CH_LOGGING_HOLD_TRIGGER_TIME0[(factor/2)], 5,(R2H_UINT16*)&(logging_hold_message.trigger_generation_time));\
					msgQSend(__R2H_AD_DEVICE_LOGGING_HOLD_ISR_MESSAGE_QUEUE##index, (char*)&logging_hold_message, sizeof(R2H_AD_DEVICE_LOGGING_HOLD_ISR_MSG_T), NO_WAIT, MSG_PRI_NORMAL);\
				}\
				else\
				{\
					logging_read_message.id = 0;\
					logging_read_message.channel_index = (factor/2);\
					CCPU_FromBuf_ISR(base/16, R2H_ExtModule_AnalogInDevice::R2H_AD_DEVICE_BUFM_CH_LOGGING_CUR_READ_OFFSET[factor/2], 3,(R2H_UINT16*)&(logging_read_message.current_read_offset));\
					msgQSend(__R2H_AD_DEVICE_LOGGING_READ_ISR_MESSAGE_QUEUE##index, (char*)&logging_read_message, sizeof(R2H_AD_DEVICE_LOGGING_READ_ISR_MSG_T), NO_WAIT, MSG_PRI_NORMAL);\
				}\
				CCPU_ToBuf_ISR(base/16, R2H_AD_DEVICE_BUFC_INTERRUPT_FACTOR_RESET0+(factor),1,&rst);\
			}\
		}\

#define __R2H_AD_DEVICE_BIND_MODULE_ISR(index,factor, irq) \
		CCPU_DisableInt(irq);\
		CCPU_EntryInt(irq, __R2H_AD_DEVICE_MODULE_ISR##index##factor);\
		CCPU_EnableInt(irq);

#define __R2H_AD_DEVICE_UNBIND_MODULE_ISR(irq) \
		CCPU_EntryInt(irq, 0);\
		CCPU_DisableInt(irq);
		

#define __READ_R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER(index) \
		void __READ_R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index(R2H_INT32 channelIndex, R2H_INT32 readLengthInWord, R2H_INT16* pDataBuffer, R2H_INT32* pActualReadLengthInWord)\
		{\
			*pActualReadLengthInWord = 0;\
			if(__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[channelIndex] != NULL )\
			{\
				semTake(__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[channelIndex],WAIT_FOREVER);\
				if(readLengthInWord < __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_size_in_word)\
					*pActualReadLengthInWord = readLengthInWord;\
				else\
					*pActualReadLengthInWord = __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_size_in_word;\
				if(*pActualReadLengthInWord > 0)\
				{\
					R2H_INT32 bulkReadSizeInWord = R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_SIZE_IN_WORD - __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_offset;\
					if(bulkReadSizeInWord < *pActualReadLengthInWord)\
					{\
						memcpy(pDataBuffer,__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].data +  __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_offset, 2*bulkReadSizeInWord);\
						memcpy(pDataBuffer + bulkReadSizeInWord,__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].data, 2*(*pActualReadLengthInWord - bulkReadSizeInWord));\
					}\
					else\
						memcpy(pDataBuffer,__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].data +  __R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_offset, 2*(*pActualReadLengthInWord));\
					__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_offset += (*pActualReadLengthInWord);\
					__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_offset %= R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_SIZE_IN_WORD;\
					__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER##index[channelIndex].unread_data_size_in_word -= (*pActualReadLengthInWord);\
				}\
				semGive(__R2H_AD_CHANNEL_LOGGING_READ_RING_BUFFER_MUTEX##index[channelIndex]);\
			}\
			else\
				*pActualReadLengthInWord = 0;\
		}\

#endif /* R2H_EXTMODULE_ANALOG_IN_DEVICE_STATIC_H_ */
