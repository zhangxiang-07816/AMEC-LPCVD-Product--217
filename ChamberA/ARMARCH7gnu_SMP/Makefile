# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = ARMARCH7gnu_SMP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := D:/AMEC_Projects/LPCVD/Firmware/T217
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/ChamberA



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = arm
CPU = ARMARCH7
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp -mlong-calls
VSB_DIR = $(WIND_BASE)/target/lib_smp
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/Include/R12CCPU-V -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_Task/Startup -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_Task/IOControl -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/SlavePDOProfile 

IDE_LIBRARIES = 

IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g -fsigned-char -D_R2H_DEBUG
DEBUGFLAGS_C++-Compiler = -g -fsigned-char -D_R2H_DEBUG
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin -fsigned-char
DEBUGFLAGS_C++-Compiler = -O2  -fno-builtin -fsigned-char
DEBUGFLAGS_Linker =  -O2  -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = ChamberA/$(MODE_DIR)/ChamberA.out \
	 ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage.o


#Rules

# ChamberA
ifeq ($(DEBUG_MODE),1)
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin -fsigned-char
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2  -fno-builtin -fsigned-char
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2  -fno-builtin
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberA/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif
ChamberA/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/Include/R12CCPU-V -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_Task/Startup -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_Task/IOControl -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/SlavePDOProfile 
ChamberA/$(MODE_DIR)/% : IDE_LIBRARIES = 
ChamberA/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
ChamberA/$(MODE_DIR)/% : PROJECT_TYPE = DKM
ChamberA/$(MODE_DIR)/% : DEFINES = 
ChamberA/$(MODE_DIR)/% : EXPAND_DBG = 0
ChamberA/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
ChamberA/$(MODE_DIR)/% : CPU = ARMARCH7
ChamberA/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ChamberA/$(MODE_DIR)/% : TOOL = gnu
ChamberA/$(MODE_DIR)/% : TOOL_PATH = 
ChamberA/$(MODE_DIR)/% : CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp -mlong-calls
ChamberA/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib_smp
ChamberA/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
ChamberA/$(MODE_DIR)/% : LIBPATH = 
ChamberA/$(MODE_DIR)/% : LIBS = 
ChamberA/$(MODE_DIR)/% : OBJ_DIR := ChamberA/$(MODE_DIR)

OBJECTS_ChamberA = ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage.o

ifeq ($(TARGET_JOBS),1)
ChamberA/$(MODE_DIR)/ChamberA.out : $(OBJECTS_ChamberA)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmarm $(OBJECTS_ChamberA) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c arm -tags $(VSB_DIR)/tags/arm/ARMARCH7/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccarm $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall   $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccarm -r -nostdlib -Wl,-X -Wl,-EL -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_ChamberA) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
ChamberA/$(MODE_DIR)/ChamberA.out : ChamberA/$(MODE_DIR)/ChamberA.out_jobs

endif
ChamberA/$(MODE_DIR)/ChamberA_compile_file : $(FILE) ;

_clean :: ChamberA/$(MODE_DIR)/ChamberA_clean

ChamberA/$(MODE_DIR)/ChamberA_clean : 
	$(TRACE_FLAG)if [ -d "ChamberA" ]; then cd "ChamberA"; rm -rf $(MODE_DIR); fi


# ChamberA_partialImage
ifeq ($(DEBUG_MODE),1)
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin -fsigned-char
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2  -fno-builtin -fsigned-char
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2  -fno-builtin
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberA_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif
ChamberA_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/Include/R12CCPU-V -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_Task/Startup -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_Task/IOControl -I$(WS_ROOT_DIR)/ChamberA/OrbmentSDK/vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/SlavePDOProfile 
ChamberA_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
ChamberA_partialImage/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
ChamberA_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
ChamberA_partialImage/$(MODE_DIR)/% : DEFINES = 
ChamberA_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
ChamberA_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
ChamberA_partialImage/$(MODE_DIR)/% : CPU = ARMARCH7
ChamberA_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ChamberA_partialImage/$(MODE_DIR)/% : TOOL = gnu
ChamberA_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
ChamberA_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp -mlong-calls
ChamberA_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib_smp
ChamberA_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
ChamberA_partialImage/$(MODE_DIR)/% : LIBPATH = 
ChamberA_partialImage/$(MODE_DIR)/% : LIBS = 
ChamberA_partialImage/$(MODE_DIR)/% : OBJ_DIR := ChamberA_partialImage/$(MODE_DIR)

ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/DataCopy/data_copy.o : $(PRJ_ROOT_DIR)/Product/Lib/DataCopy/data_copy.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/DummyDOPulse/dummy_do_pulse.o : $(PRJ_ROOT_DIR)/Product/Lib/DummyDOPulse/dummy_do_pulse.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Heartbeat/heartbeat_generator.o : $(PRJ_ROOT_DIR)/Product/Lib/Heartbeat/heartbeat_generator.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/LiftMotor/simple_ecat_positioning_motor.o : $(PRJ_ROOT_DIR)/Product/Lib/LiftMotor/simple_ecat_positioning_motor.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Tricker/tricker.o : $(PRJ_ROOT_DIR)/Product/Lib/Tricker/tricker.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Version/version.o : $(PRJ_ROOT_DIR)/Product/Lib/Version/version.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/utiltiy.o : $(PRJ_ROOT_DIR)/Product/Lib/utiltiy.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/lpcvd_alpha_init.o : $(PRJ_ROOT_DIR)/Product/lpcvd_alpha_init.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/lpcvd_alpha_process.o : $(PRJ_ROOT_DIR)/Product/lpcvd_alpha_process.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Startup/lpcvd_alpha_startup.o : $(PRJ_ROOT_DIR)/Startup/lpcvd_alpha_startup.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_ChamberA_partialImage = ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/DataCopy/data_copy.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/DummyDOPulse/dummy_do_pulse.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Heartbeat/heartbeat_generator.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/LiftMotor/simple_ecat_positioning_motor.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Tricker/tricker.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Version/version.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/utiltiy.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/lpcvd_alpha_init.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/lpcvd_alpha_process.o \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Startup/lpcvd_alpha_startup.o

ifeq ($(TARGET_JOBS),1)
ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage.o : $(OBJECTS_ChamberA_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm -r -nostdlib -Wl,-X -Wl,-EL  -o "$@" $(OBJECTS_ChamberA_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage.o : ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage.o_jobs

endif
ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage_compile_file : $(FILE) ;

_clean :: ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage_clean

ChamberA_partialImage/$(MODE_DIR)/ChamberA_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "ChamberA_partialImage" ]; then cd "ChamberA_partialImage"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/DataCopy/data_copy.d ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/DummyDOPulse/dummy_do_pulse.d ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Heartbeat/heartbeat_generator.d \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/LiftMotor/simple_ecat_positioning_motor.d ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Tricker/tricker.d ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/Version/version.d \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/Lib/utiltiy.d ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/lpcvd_alpha_init.d ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Product/lpcvd_alpha_process.d \
	 ChamberA_partialImage/$(MODE_DIR)/Objects/ChamberA/Startup/lpcvd_alpha_startup.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1 &&\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
