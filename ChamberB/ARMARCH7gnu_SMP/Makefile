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
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/ChamberB



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

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/Include/R12CCPU-V -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_Task/Startup -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_Task/IOControl -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/SlavePDOProfile 

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
DEBUGFLAGS_C++-Compiler =  -O2  -fno-builtin -fsigned-char
DEBUGFLAGS_Linker =  -O2  -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = ChamberB/$(MODE_DIR)/ChamberB.out \
	 ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage.o


#Rules

# ChamberB
ifeq ($(DEBUG_MODE),1)
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin -fsigned-char
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-builtin -fsigned-char
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2  -fno-builtin
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberB/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif
ChamberB/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/Include/R12CCPU-V -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_Task/Startup -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_Task/IOControl -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/SlavePDOProfile 
ChamberB/$(MODE_DIR)/% : IDE_LIBRARIES = 
ChamberB/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
ChamberB/$(MODE_DIR)/% : PROJECT_TYPE = DKM
ChamberB/$(MODE_DIR)/% : DEFINES = 
ChamberB/$(MODE_DIR)/% : EXPAND_DBG = 0
ChamberB/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
ChamberB/$(MODE_DIR)/% : CPU = ARMARCH7
ChamberB/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ChamberB/$(MODE_DIR)/% : TOOL = gnu
ChamberB/$(MODE_DIR)/% : TOOL_PATH = 
ChamberB/$(MODE_DIR)/% : CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp -mlong-calls
ChamberB/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib_smp
ChamberB/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
ChamberB/$(MODE_DIR)/% : LIBPATH = 
ChamberB/$(MODE_DIR)/% : LIBS = 
ChamberB/$(MODE_DIR)/% : OBJ_DIR := ChamberB/$(MODE_DIR)

OBJECTS_ChamberB = ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage.o

ifeq ($(TARGET_JOBS),1)
ChamberB/$(MODE_DIR)/ChamberB.out : $(OBJECTS_ChamberB)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmarm $(OBJECTS_ChamberB) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c arm -tags $(VSB_DIR)/tags/arm/ARMARCH7/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccarm $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall   $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccarm -r -nostdlib -Wl,-X -Wl,-EL -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_ChamberB) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
ChamberB/$(MODE_DIR)/ChamberB.out : ChamberB/$(MODE_DIR)/ChamberB.out_jobs

endif
ChamberB/$(MODE_DIR)/ChamberB_compile_file : $(FILE) ;

_clean :: ChamberB/$(MODE_DIR)/ChamberB_clean

ChamberB/$(MODE_DIR)/ChamberB_clean : 
	$(TRACE_FLAG)if [ -d "ChamberB" ]; then cd "ChamberB"; rm -rf $(MODE_DIR); fi


# ChamberB_partialImage
ifeq ($(DEBUG_MODE),1)
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g -fsigned-char -D_R2H_DEBUG
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-builtin -fsigned-char
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-builtin -fsigned-char
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2  -fno-builtin
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ChamberB_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-builtin
endif
ChamberB_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/Include/R12CCPU-V -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_Task/Startup -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_Task/IOControl -I$(WS_ROOT_DIR)/ChamberB/OrbmentSDK/vx_R2H_ExtModule/NetworkDevice/SMART-ECAT/SlavePDOProfile 
ChamberB_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
ChamberB_partialImage/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
ChamberB_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
ChamberB_partialImage/$(MODE_DIR)/% : DEFINES = 
ChamberB_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
ChamberB_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
ChamberB_partialImage/$(MODE_DIR)/% : CPU = ARMARCH7
ChamberB_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ChamberB_partialImage/$(MODE_DIR)/% : TOOL = gnu
ChamberB_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
ChamberB_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -t7 -mfpu=vfp -mfloat-abi=softfp -mlong-calls
ChamberB_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib_smp
ChamberB_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
ChamberB_partialImage/$(MODE_DIR)/% : LIBPATH = 
ChamberB_partialImage/$(MODE_DIR)/% : LIBS = 
ChamberB_partialImage/$(MODE_DIR)/% : OBJ_DIR := ChamberB_partialImage/$(MODE_DIR)

ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/DataCopy/data_copy.o : $(PRJ_ROOT_DIR)/Product/Lib/DataCopy/data_copy.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/DummyDOPulse/dummy_do_pulse.o : $(PRJ_ROOT_DIR)/Product/Lib/DummyDOPulse/dummy_do_pulse.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Heartbeat/heartbeat_generator.o : $(PRJ_ROOT_DIR)/Product/Lib/Heartbeat/heartbeat_generator.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/LiftMotor/simple_ecat_positioning_motor.o : $(PRJ_ROOT_DIR)/Product/Lib/LiftMotor/simple_ecat_positioning_motor.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Tricker/tricker.o : $(PRJ_ROOT_DIR)/Product/Lib/Tricker/tricker.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Version/version.o : $(PRJ_ROOT_DIR)/Product/Lib/Version/version.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/utiltiy.o : $(PRJ_ROOT_DIR)/Product/Lib/utiltiy.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/lpcvd_alpha_init.o : $(PRJ_ROOT_DIR)/Product/lpcvd_alpha_init.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/lpcvd_alpha_process.o : $(PRJ_ROOT_DIR)/Product/lpcvd_alpha_process.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Startup/lpcvd_alpha_startup.o : $(PRJ_ROOT_DIR)/Startup/lpcvd_alpha_startup.cc $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP -mlong-calls $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_ChamberB_partialImage = ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/DataCopy/data_copy.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/DummyDOPulse/dummy_do_pulse.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Heartbeat/heartbeat_generator.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/LiftMotor/simple_ecat_positioning_motor.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Tricker/tricker.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Version/version.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/utiltiy.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/lpcvd_alpha_init.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/lpcvd_alpha_process.o \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Startup/lpcvd_alpha_startup.o

ifeq ($(TARGET_JOBS),1)
ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage.o : $(OBJECTS_ChamberB_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccarm -r -nostdlib -Wl,-X -Wl,-EL  -o "$@" $(OBJECTS_ChamberB_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage.o : ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage.o_jobs

endif
ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage_compile_file : $(FILE) ;

_clean :: ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage_clean

ChamberB_partialImage/$(MODE_DIR)/ChamberB_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "ChamberB_partialImage" ]; then cd "ChamberB_partialImage"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/DataCopy/data_copy.d ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/DummyDOPulse/dummy_do_pulse.d ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Heartbeat/heartbeat_generator.d \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/LiftMotor/simple_ecat_positioning_motor.d ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Tricker/tricker.d ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/Version/version.d \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/Lib/utiltiy.d ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/lpcvd_alpha_init.d ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Product/lpcvd_alpha_process.d \
	 ChamberB_partialImage/$(MODE_DIR)/Objects/ChamberB/Startup/lpcvd_alpha_startup.d
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
