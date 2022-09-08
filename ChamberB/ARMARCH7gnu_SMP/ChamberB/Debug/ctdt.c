/* ctors and dtors arrays -- to be used by runtime system */
/*   to call static constructors and destructors          */
/*                                                        */
/* NOTE: Use a C compiler to compile this file. If you    */
/*       are using GNU C++, be sure to use compile this   */
/*       file using a GNU compiler with the               */
/*       -fdollars-in-identifiers flag.                   */


#if defined(__GNUC__)

extern void __register_frame_info (const void *, void *);
extern void *__deregister_frame_info (const void *);
extern const unsigned __EH_FRAME_BEGIN__[];
static void _STI__15_ctors ()
{
  /* This structure must approximately match that in unwind-dw2-fde.h.
     In particular it must be no smaller, and no less aligned.  */
  static struct object {
    void *pc_begin; void *tbase; void *dbase; void *u;
    unsigned long b; void *fde_end; struct object *next;
  } object;
  __register_frame_info (__EH_FRAME_BEGIN__, &object);
}

static void _STD__15_dtors ()
{
  __deregister_frame_info (__EH_FRAME_BEGIN__);
}
#else
static void _STI__15_ctors ()
{
}

static void _STD__15_dtors ()
{
}
#endif

char __dso_handle = 0;
extern void __cxa_finalize(void *);
static void _STD__cxa_finalize()
{
	__cxa_finalize(&__dso_handle);
}


void _GLOBAL__I_65535_0_INITIALIZE_PTR();

void _GLOBAL__I_65535_0__GLB_VERSION();

void _GLOBAL__I_65535_0__Z25vx_LPCVD_Alpha_Startup_ExPKcS0_();

void _GLOBAL__I_65535_0__Z33__user_process_control_routine_exPSt6vectorIP24R2H_ExtModule_BaseDeviceSaIS1_EEPS_IP26R2H_EthModule_SocketDeviceSaIS6_EEP23R2H_DLink_MemorySysInfoP24R2H_DLink_MemoryTaskInfoP24R2H_DLink_MemoryDeviceIOP22R2H_DLink_MemoryUserIOPS_I38R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATASaISI_EEP33R2H_Task_ProcessDataObjectManagerm();

void _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT10Tricker617C2Ev();

void _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT12DummyDOPulseC2Ev();

void _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT18HeartbeatGeneratorC2Ev();

void _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT18SimpleECATPosMotorC2Ev();

void _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT7VersionC2Ev();

void _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT8DataCopyC2Ev();

extern void (*_ctors[])();
void (*_ctors[])() =
    {
    _STI__15_ctors,
    _GLOBAL__I_65535_0_INITIALIZE_PTR,
    _GLOBAL__I_65535_0__GLB_VERSION,
    _GLOBAL__I_65535_0__Z25vx_LPCVD_Alpha_Startup_ExPKcS0_,
    _GLOBAL__I_65535_0__Z33__user_process_control_routine_exPSt6vectorIP24R2H_ExtModule_BaseDeviceSaIS1_EEPS_IP26R2H_EthModule_SocketDeviceSaIS6_EEP23R2H_DLink_MemorySysInfoP24R2H_DLink_MemoryTaskInfoP24R2H_DLink_MemoryDeviceIOP22R2H_DLink_MemoryUserIOPS_I38R2H_TASK_DEVICE_LOCAL_PROCESS_OUT_DATASaISI_EEP33R2H_Task_ProcessDataObjectManagerm,
    _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT10Tricker617C2Ev,
    _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT12DummyDOPulseC2Ev,
    _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT18HeartbeatGeneratorC2Ev,
    _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT18SimpleECATPosMotorC2Ev,
    _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT7VersionC2Ev,
    _GLOBAL__I_65535_0__ZN16R2H_AMEC_PRODUCT8DataCopyC2Ev,
    0
    };

void _STD__15_dtors();

extern void (*_dtors[])();
void (*_dtors[])() =
    {
    _STD__15_dtors,
    _STD__cxa_finalize,
    0
    };

/* build variables */
#ifdef __GNUC__
__asm("	.section \".wrs_build_vars\",\"a\"");
#endif
#ifdef __DCC__
__asm("	.section \".wrs_build_vars\",\"r\"");
#endif
__asm(" .ascii \"tag SMP 1\"");
__asm(" .byte 0");
__asm("	.ascii \"end\"");
__asm("	.byte 0");
__asm("	.previous");
