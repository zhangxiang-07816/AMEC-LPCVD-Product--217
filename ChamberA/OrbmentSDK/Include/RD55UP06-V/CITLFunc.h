#ifndef __CITLFUNC_H__
#define __CITLFUNC_H__

typedef void (*CITL_FUNCPTR)(void);
typedef void (*CITL_CEXECUTEFUNCPTR)(unsigned short*, unsigned short*, unsigned short*, unsigned short*);

#ifdef __cplusplus
extern "C" {
#endif

short CITL_ChangeFileSecurity(short, char*);
short CITL_ClearError(long*);
short CITL_DisableYInt(short);
short CITL_EnableYInt(short);
short CITL_EntryDedicatedInstFunc(CITL_CEXECUTEFUNCPTR);
short CITL_EntryYInt(short, CITL_FUNCPTR);
short CITL_EntryTimerEvent(long*);
short CITL_EntryWDTInt(short, CITL_FUNCPTR);
short CITL_FromBuf(unsigned long, unsigned long, unsigned short*, unsigned long);
short CITL_GetCollectData(short*, unsigned long, unsigned long*);
short CITL_GetCounterMicros(unsigned long*);
short CITL_GetCounterMillis(unsigned long*);
short CITL_GetErrInfo(unsigned short*, unsigned long);
short CITL_GetFileSecurity(short*);
static __inline short CITL_GetIDInfo(unsigned char*, unsigned long);
short CITL_GetLEDStatus(long, unsigned short*, unsigned long);
short CITL_GetSerialNo(char*, unsigned long);
short CITL_GetSwitchStatus(long*, unsigned long);
short CITL_GetTime(short*, unsigned long);
short CITL_GetUnitStatus(long*, unsigned long);
short CITL_MountMemoryCard(short);
short CITL_RegistEventLog(long, char*);
short CITL_ResetWDT(short);
short CITL_SetCollectData(long*, unsigned short, unsigned short, unsigned long*);
short CITL_SetLEDStatus(long, unsigned short);
short CITL_SetSyncTimeStatus(unsigned short);
short CITL_ShutdownRom(void);
short CITL_StartCollectData(void);
short CITL_StartWDT(short, short);
short CITL_StopCollectData(void);
short CITL_StopWDT(short);
short CITL_SyncTime(void);
short CITL_SysClkRateGet(short*);
short CITL_SysClkRateSet(short, short*);
short CITL_ToBuf(unsigned long, unsigned long, unsigned short*, unsigned long);
short CITL_UnmountMemoryCard(short);
short CITL_WaitCollectDataRecvEvent(unsigned short, unsigned long);
short CITL_WaitSwitchEvent(short, unsigned long);
short CITL_WaitTimerEvent(long);
short CITL_WaitYEvent(short*, unsigned long, unsigned short*);
short CITL_X_In_Bit(unsigned short, unsigned short*);
short CITL_X_In_Word(unsigned short, unsigned short, unsigned short*, unsigned short);
short CITL_X_Out_Bit(unsigned short, unsigned short);
short CITL_X_Out_Word(unsigned short, unsigned short, unsigned short*, unsigned short);
short CITL_Y_In_Bit(unsigned short, unsigned short*);
short CITL_Y_In_Word(unsigned short, unsigned short, unsigned short*, unsigned short);

short CITL_DisableYInt_ISR(short);
short CITL_EnableYInt_ISR(short);
short CITL_FromBuf_ISR(unsigned long, unsigned long, unsigned short*);
short CITL_GetCounterMicros_ISR(unsigned long*);
short CITL_GetCounterMillis_ISR(unsigned long*);
short CITL_RegistEventLog_ISR(long, char*);
short CITL_SetLEDStatus_ISR(long, unsigned short);
short CITL_ToBuf_ISR(unsigned long, unsigned long, unsigned short*);
short CITL_X_In_Word_ISR(unsigned short, unsigned short, unsigned short*);
short CITL_X_Out_Word_ISR(unsigned short, unsigned short, unsigned short*);
short CITL_Y_In_Word_ISR(unsigned short, unsigned short, unsigned short*);

static __inline short CITL_GetIDInfo(unsigned char* pucGetData, unsigned long ulBufSize){
	unsigned long i = 0; unsigned long FIX_ulBufMax = 6;
	if(pucGetData == 0){return(-264);}
	if(ulBufSize == 0){return(0);}else if(ulBufSize > FIX_ulBufMax){ulBufSize = FIX_ulBufMax;}
	for(i=0; i<ulBufSize; i++){pucGetData[i] = *(((char*)0xF106E000)+i);}
	return(0);
}

#define REMOVE_INDEX      (0x0001)
#define REMOVE_DATE       (0x0002)
#define REMOVE_DATA_MISS  (0x0004)

#define SYNCTIME_AUTO     (0)
#define SYNCTIME_STOP     (1)

#ifdef __cplusplus
}
#endif

#endif
