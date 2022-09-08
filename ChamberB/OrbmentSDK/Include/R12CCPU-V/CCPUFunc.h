typedef void (*CCPU_FUNCPTR)(void);
typedef short (*CCPU_REFENDFUNCPTR) (unsigned short usGroupNo);

#ifdef __cplusplus
extern "C" {
#endif

short CCPU_DNTRefreshBufferMemory(unsigned short usIoNo, unsigned long ulTimeout);

short CCPU_ChangeCCIEFBCycPrm( unsigned short usGroupNo, unsigned short usLinkScanTime, unsigned short usTimeout, unsigned short usTimeoutRetryCnt );
short CCPU_ChangeFileSecurity( short sMode, char* pcPass );
short CCPU_ClearError( long* plErrorInfo );
short CCPU_Control( short sCpuNo, short sCode );
short CCPU_DedicatedDInst( char* pcInstName, short sCPUNo, short* psArg1, short sArg1Size, short* psArg2, short sArg2Size, short* psArg3, short sArg3Size, short* psArg4, short sArg4Size, short* psArg5, short sArg5Size, short* psArg6, short sArg6Size, short* psArg7, short sArg7Size, short* psArg8, short sArg8Size, short* psArg9, short sArg9Size);
short CCPU_DedicatedGInst( char* pcInstName, short sIoNo, short* psArg1, short sArg1Size, short* psArg2, short sArg2Size, short* psArg3, short sArg3Size, short* psArg4, short sArg4Size, short* psArg5, short sArg5Size, short* psArg6, short sArg6Size, short* psArg7, short sArg7Size, short* psArg8, short sArg8Size, short* psArg9, short sArg9Size);
short CCPU_DedicatedJInst( char* pcInstName, short sNetNo, short* psArg1, short sArg1Size, short* psArg2, short sArg2Size, short* psArg3, short sArg3Size, short* psArg4, short sArg4Size, short* psArg5, short sArg5Size, short* psArg6, short sArg6Size, short* psArg7, short sArg7Size, short* psArg8, short sArg8Size, short* psArg9, short sArg9Size);
short CCPU_DedicatedMInst( char* pcInstName, short sCPUNo, short* psArg1, short sArg1Size, short* psArg2, short sArg2Size, short* psArg3, short sArg3Size, short* psArg4, short sArg4Size, short* psArg5, short sArg5Size, short* psArg6, short sArg6Size, short* psArg7, short sArg7Size, short* psArg8, short sArg8Size, short* psArg9, short sArg9Size);
short CCPU_DisableInt( short sSINo );
short CCPU_EnableInt( short sSINo );
short CCPU_EndCCIEFBDataAssurance( unsigned short usGroupNo );
short CCPU_EntryCCIEFBRefEndFunc( CCPU_REFENDFUNCPTR pREFENDFuncPtr );
short CCPU_EntryInt( short sSINo, CCPU_FUNCPTR pFuncPtr);
short CCPU_EntryTimerEvent( long* plEvent );
short CCPU_EntryWDTInt( short sType, CCPU_FUNCPTR pFuncPtr );
short CCPU_FromBuf( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_FromBufHG( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_GetCCIEFBDiagnosticInfo( unsigned short usSlave, short* psStatusBuf, unsigned long ulBufSize );
short CCPU_GetCounterMillis( unsigned long* pulMillis );
short CCPU_GetCounterMicros( unsigned long* pulMicros );
short CCPU_GetCpuStatus( long* plStatusBuf, unsigned long ulBufSize );
short CCPU_GetDotMatrixLED( char* pcData, unsigned long ulDataSize );
short CCPU_GetErrInfo( unsigned short* pusErrorInfo, unsigned long ulBufSize );
short CCPU_GetFileSecurity( short* psMode );
static __inline short CCPU_GetIDInfo ( unsigned char *pucGetData, unsigned long ulBufSize);
short CCPU_GetLEDStatus( long lLed, unsigned short* pusLedInfo, unsigned long ulBufSize );
short CCPU_GetOpSelectMode( long lModeInfo, long* plSelectMode );
short CCPU_GetPowerStatus( long* plStatusBuf, unsigned long ulBufSize );
short CCPU_GetConstantProcessStatus( unsigned short* pusStatusBuf, unsigned long ulBufSize );
short CCPU_GetRTC( short* psGetData, unsigned long ulBufSize );
short CCPU_GetSerialNo( char* pcGetData, unsigned long ulDataSize);
short CCPU_GetSwitchStatus( long* plStatusBuf, unsigned long ulBufSize );
short CCPU_GetUnitInfo( unsigned short* pusUnitInfo1, unsigned short* pusUnitInfo2, unsigned short* pusUnitInfo3 );
short CCPU_LockFWUpdate( char* pcPass );
short CCPU_MountMemoryCard( short sDrive );
short CCPU_ReadDevice( short sDevType, unsigned long ulDevNo, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_ReadLinkDevice( unsigned short usIoNo, short sDevType, unsigned long ulDevNo, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
//short CCPU_RegistEventLog (long lEventCode, char* pcEventMsg);
short CCPU_RegistEventLog (long lEventCode, const char* pcEventMsg);
short CCPU_Reset( void );
short CCPU_ResetDevice( short sDevType, unsigned long ulDevNo );
short CCPU_ResetWDT( short sType );
short CCPU_RestoreDefaultCCIEFBCycPrm( void );
short CCPU_SetDevice( short sDevType, unsigned long ulDevNo );
short CCPU_SetDotMatrixLED( unsigned short usLedMode, char* pcData );
short CCPU_SetLEDStatus( long lLed, unsigned short usLedInfo );
short CCPU_SetOpSelectMode( long lModeInfo, long lSelectMode );
short CCPU_SetRTC( short* psSetData );
short CCPU_ShutdownRom( void );
short CCPU_StartCCIEFBDataAssurance( unsigned short usGroupNo, unsigned long ulTimeout );
short CCPU_StartWDT( short sType, short sInterval );
short CCPU_StopWDT( short sType );
short CCPU_SysClkRateGet( short* psTicks );
short CCPU_SysClkRateSet( short sTicks, short* psRestart );
short CCPU_ToBuf( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_ToBufHG( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_UnlockFWUpdate( char* pcPass );
short CCPU_UnmountMemoryCard( short sDrive );
short CCPU_WaitEvent( short* psEvent, unsigned long ulTimeout, short* psSetEventNo );
short CCPU_WaitSwitchEvent( short sSwitch, unsigned long ulTimeout );
short CCPU_WaitTimerEvent( long lEventNo );
short CCPU_WaitUnitEvent( short* psEvent, unsigned long ulTimeout, short* psSetEventNo );
short CCPU_WriteDevice( short sDevType, unsigned long ulDevNo, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_WriteLinkDevice( unsigned short usIoNo, short sDevType, unsigned long ulDevNo, unsigned long ulSize, unsigned short* pusDataBuf, unsigned long ulBufSize );
short CCPU_X_In_BitEx( short sFlg, unsigned short usXNo, unsigned short* pusData );
short CCPU_X_In_WordEx( short sFlg, unsigned short usXNo, unsigned short usSize, unsigned short* pusDataBuf, unsigned short usBufSize );
short CCPU_Y_In_BitEx( short sFlg, unsigned short usYNo, unsigned short* pusData );
short CCPU_Y_In_WordEx( short sFlg, unsigned short usYNo, unsigned short usSize, unsigned short* pusDataBuf, unsigned short usBufSize );
short CCPU_Y_Out_BitEx( short sFlg, unsigned short usYNo, unsigned short usData );
short CCPU_Y_Out_WordEx( short sFlg, unsigned short usYNo, unsigned short usSize, unsigned short* pusDataBuf, unsigned short usBufSize );

short CCPU_DisableInt_ISR( short sSINo );
short CCPU_EnableInt_ISR( short sSINo );
short CCPU_FromBuf_ISR( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf );
short CCPU_FromBufHG_ISR( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf );
short CCPU_GetDotMatrixLED_ISR( char* pcData, unsigned long ulDataSize );
short CCPU_GetCounterMillis_ISR( unsigned long* pulMillis );
short CCPU_GetCounterMicros_ISR( unsigned long* pulMicros );
short CCPU_ReadDevice_ISR( short sDevType, unsigned long ulDevNo, unsigned long ulSize, unsigned short* pusDataBuf );
short CCPU_RegistEventLog_ISR( long lEventCode, char* pcEventMsg );
short CCPU_ResetDevice_ISR( short sDevType, unsigned long ulDevNo );
short CCPU_SetDevice_ISR( short sDevType, unsigned long ulDevNo );
short CCPU_SetDotMatrixLED_ISR( unsigned short usLedMode, char* pcData );
short CCPU_SetLEDStatus_ISR( long lLed, unsigned short usLedInfo );
short CCPU_ToBuf_ISR( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf );
short CCPU_ToBufHG_ISR( unsigned short usIoNo, unsigned long ulOffset, unsigned long ulSize, unsigned short* pusDataBuf );
short CCPU_WriteDevice_ISR( short sDevType, unsigned long ulDevNo, unsigned long ulSize, unsigned short* pusDataBuf );
short CCPU_X_In_Word_ISR( unsigned short usXNo, unsigned short usSize, unsigned short* pusDataBuf );
short CCPU_Y_In_Word_ISR( unsigned short usYNo, unsigned short usSize, unsigned short* pusDataBuf );
short CCPU_Y_Out_Word_ISR( unsigned short usYNo, unsigned short usSize, unsigned short* pusDataBuf );

#ifndef __CCPU_GETIDINFO_FUNCDEF__
#define __CCPU_GETIDINFO_FUNCDEF__
static __inline short CCPU_GetIDInfo ( unsigned char *pucGetData, unsigned long ulBufSize){
	unsigned long i=0;short sRet = 0x0;unsigned long FIX_ulBufMax = 12;unsigned long FIX_ulBufHalf = 12/2;
	if(pucGetData==0){sRet=-264;return(sRet);}
	if(ulBufSize==0){sRet=0;return(sRet);}else if(ulBufSize>FIX_ulBufMax){ulBufSize=FIX_ulBufMax;}
	if(ulBufSize<=FIX_ulBufHalf){for(i=0;i<ulBufSize;i++){pucGetData[i] = *( ((char*)(0xC807F000+0)) + i );}}else{for(i=0;i<FIX_ulBufHalf;i++){pucGetData[i] = *( ((char*)(0xC807F000+0)) + i );}ulBufSize-=FIX_ulBufHalf;pucGetData+=FIX_ulBufHalf;for(i=0;i<ulBufSize;i++){pucGetData[i] = *( ((char*)(0xC807F000+6)) + i );}}
	return( sRet );
}
#endif

#ifdef __cplusplus
}
#endif

#define Dev_LX					1000
#define Dev_LY					2000
#define Dev_LB					23000
#define Dev_LW					24000
#define Dev_LSB					25000
#define Dev_LSW					28000

#define Dev_CCPU_M				4
#define Dev_CCPU_SM				5
#define Dev_CCPU_D				13
#define Dev_CCPU_SD				14
#define Dev_CCPU_B				23
#define Dev_CCPU_W				24
#define Dev_CCPU_ZR				220
