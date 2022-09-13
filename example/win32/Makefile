
########################################
#        编译器全局配置，必填
########################################

# 编译器可执行文件目录, 如果路径不为空，则必须以 '/' 结尾
# 例如：CC_FOLDER = D:/xpack-riscv-none-embed-gcc-8.3.0-2.3/bin/
CC_FOLDER = D:/TDM-GCC-32/bin/

# 编译器前缀
CC_PREFIX = 

# 编译器可执行文件
CC = $(CC_FOLDER)$(CC_PREFIX)gcc
AS = $(CC_FOLDER)$(CC_PREFIX)gcc
LD = $(CC_FOLDER)$(CC_PREFIX)gcc
AR = $(CC_FOLDER)$(CC_PREFIX)gcc

# binutils 可执行文件
SZ = 
HEX = 
BIN = 

# 生成 hex, bin 的命令
HEX_FLAGS = 
HEX_OUT_CMD =
BIN_FLAGS = 
BIN_OUT_CMD =

# static lib flags
AR_FLAGS = 

# 包含命令，宏定义命令的前缀
INC_PREFIX = -I
LIB_PREFIX = -L
DEF_PREFIX = -D

# 编译器输出命令
CC_OUT_CMD = -o
AS_OUT_CMD = -o
LD_OUT_CMD = -o
AR_OUT_CMD = -rcv

# 二进制文件后缀
OBJ_SUFFIX = o
ELF_SUFFIX = exe
AR_SUFFIX = a

################################
#        应用程序生成配置
################################

# 输出根目录
BUILD_ROOT = build

# 可执行文件名称
EXE_NAME := main

# 输出目录
BUILD_DIR := $(BUILD_ROOT)

# 输出二进制类型，默认：elf，可选值：static_lib, elf
OUTPUT_TYPE := elf

# 要生成的可执行文件列表
ifeq ($(OUTPUT_TYPE),static_lib)
ifeq ($(AR_SUFFIX),a)
EXE_NAME := lib$(EXE_NAME)
endif
EXE_FILES += $(BUILD_DIR)/$(EXE_NAME).$(AR_SUFFIX)
else
EXE_FILES += $(BUILD_DIR)/$(EXE_NAME).$(ELF_SUFFIX)
endif

#############################
# 此处添加包含目录，源文件

MESCH_SDK_ROOT = ../..

INCLUDE_FOLDERS += . \
	port \
	$(MESCH_SDK_ROOT)/include \

C_SOURCES += \
	main.c \
	port/machine.c

C_SOURCES += \
	$(MESCH_SDK_ROOT)/src/hsehldr.c \
	$(MESCH_SDK_ROOT)/src/vecop.c \
	$(MESCH_SDK_ROOT)/src/sprow.c \
	$(MESCH_SDK_ROOT)/src/sparse.c \
	$(MESCH_SDK_ROOT)/src/solve.c \
	$(MESCH_SDK_ROOT)/src/pxop.c \
	$(MESCH_SDK_ROOT)/src/core/init.c \
	$(MESCH_SDK_ROOT)/src/core/copy.c \
	$(MESCH_SDK_ROOT)/src/core/submat.c \
	$(MESCH_SDK_ROOT)/src/core/matop.c \
	$(MESCH_SDK_ROOT)/src/factor/ivecop.c \
	$(MESCH_SDK_ROOT)/src/factor/lufactor.c \
	$(MESCH_SDK_ROOT)/src/factor/qrfactor.c \
	$(MESCH_SDK_ROOT)/src/factor/bdfactor.c \
	$(MESCH_SDK_ROOT)/src/mem/meminfo.c \
	$(MESCH_SDK_ROOT)/src/mem/memory.c \
	$(MESCH_SDK_ROOT)/src/mem/memstat.c \
	$(MESCH_SDK_ROOT)/src/iter0.c \
	$(MESCH_SDK_ROOT)/src/io/matrixio.c

###############################
# 此处添加编译参数

# CFLAGS
CFLAGS += -c -MMD -ffunction-sections -fdata-sections

# CXXFLAGS
CXXFLAGS +=

# ASMFLAGS
ASMFLAGS +=

# LDFLAGS
LDFLAGS += -Wl,--gc-sections

# LDLIBS
LDLIBS +=

#############################################################
# Append Args (DON'T MODIFY THE FOLLOWING CONTENTS)
#############################################################

SRC_INC = $(foreach path,$(INCLUDE_FOLDERS),$(INC_PREFIX)$(path))
LIB_INC = $(foreach path,$(LIB_FOLDERS),$(LIB_PREFIX)$(path))
DEFS = $(foreach str,$(DEFINES),$(DEF_PREFIX)$(str))
CFLAGS += $(SRC_INC) $(DEFS)
CXXFLAGS += $(SRC_INC) $(DEFS)
LDFLAGS += $(LIB_INC)

C_FILTER := %.c
CPP_FILTER := %.cpp %c++ %cxx %cc
ASM_FILTER := %.asm %.s %.a51
OBJ_FILTER := %.o %.lib %.a %.obj

# C sources
C_SRC = $(foreach path,$(filter $(C_FILTER),$(C_SOURCES)),$(path))

# Cpp sources
CPP_SRC = $(foreach path,$(filter $(CPP_FILTER),$(CPP_SOURCES)),$(path))

# ASM sources
ASM_SRC = $(foreach path,$(filter $(ASM_FILTER),$(ASM_SOURCES)),$(path))

# Obj sources
OBJ_SRC = $(foreach path,$(filter $(OBJ_FILTER),$(OBJ_SOURCES)),$(path))

############################################################################
# START BUILD THE APPLICATION (DON'T MODIFY THE FOLLOWING CONTENTS !!!)
############################################################################

all: $(EXE_FILES)

# print color
COLOR_END = "\e[0m"
COLOR_WARN = "\e[33;1m"
COLOR_DONE = "\e[32;1m"
COLOR_ERR = "\e[31;1m"

# merge all objs
OBJS += $(addprefix $(BUILD_DIR)/,$(notdir $(addsuffix .$(OBJ_SUFFIX),$(basename $(C_SRC))))) \
		$(addprefix $(BUILD_DIR)/,$(notdir $(addsuffix .$(OBJ_SUFFIX),$(basename $(CPP_SRC))))) \
		$(addprefix $(BUILD_DIR)/,$(notdir $(addsuffix .$(OBJ_SUFFIX),$(basename $(ASM_SRC))))) \
		$(OBJ_SRC)

# add source search folder
vpath %.c $(sort $(dir $(C_SRC)))
vpath %.cpp $(sort $(dir $(CPP_SRC)))
vpath %.cc $(sort $(dir $(CPP_SRC)))
vpath %.cxx $(sort $(dir $(CPP_SRC)))
vpath %.c++ $(sort $(dir $(CPP_SRC)))
vpath %.s $(sort $(dir $(ASM_SRC)))
vpath %.asm $(sort $(dir $(ASM_SRC)))
vpath %.a51 $(sort $(dir $(ASM_SRC)))

# compile C source file
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.c Makefile | $(BUILD_DIR) 
	@echo CC '$<' ...
	@$(CC) $(CFLAGS) $< $(CC_OUT_CMD) $@

# compile CPP source file
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.cpp Makefile | $(BUILD_DIR) 
	@echo CC '$<' ...
	@$(CC) $(CXXFLAGS) $< $(CC_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.cc Makefile | $(BUILD_DIR) 
	@echo CC '$<' ...
	@$(CC) $(CXXFLAGS) $< $(CC_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.cxx Makefile | $(BUILD_DIR) 
	@echo CC '$<' ...
	@$(CC) $(CXXFLAGS) $< $(CC_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.c++ Makefile | $(BUILD_DIR) 
	@echo CC '$<' ...
	@$(CC) $(CXXFLAGS) $< $(CC_OUT_CMD) $@

# compile ASM program objects
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.s Makefile | $(BUILD_DIR)
	@echo AS '$<' ...
	@$(AS) $(ASMFLAGS) $< $(AS_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.asm Makefile | $(BUILD_DIR)
	@echo AS '$<' ...
	@$(AS) $(ASMFLAGS) $< $(AS_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.a51 Makefile | $(BUILD_DIR)
	@echo AS '$<' ...
	@$(AS) $(ASMFLAGS) $< $(AS_OUT_CMD) $@

# link executable file
$(BUILD_DIR)/$(EXE_NAME).$(ELF_SUFFIX): $(OBJS) Makefile | $(BUILD_DIR)
	@echo LINK '$@' ...
	$(LD) $(OBJS) $(LDFLAGS) $(LD_OUT_CMD) $@ $(LDLIBS)
ifdef SZ
	@$(SZ) $@
endif
	@echo -e $(COLOR_DONE)"#################### Build successfully ! ####################"$(COLOR_END)

# static lib
$(BUILD_DIR)/$(EXE_NAME).$(AR_SUFFIX): $(OBJS) Makefile | $(BUILD_DIR)
	@echo AR '$@' ...
	@$(AR) $(AR_OUT_CMD) $@ $(AR_FLAGS) $(OBJS) 
	@echo -e $(COLOR_DONE)"#################### Archive lib successfully ! ####################"$(COLOR_END)

# generate hex
$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.$(ELF_SUFFIX) | $(BUILD_DIR)
ifdef HEX
	@$(HEX) $(HEX_FLAGS) $< $(HEX_OUT_CMD) $@
else
	@echo -e $(COLOR_WARN)"Not found hex command. Skip output hex file !"$(COLOR_END)
endif

# generate bin
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.$(ELF_SUFFIX) | $(BUILD_DIR)
ifdef BIN
	@$(BIN) $(BIN_FLAGS) $< $(BIN_OUT_CMD) $@
else
	@echo -e $(COLOR_WARN)"Not found bin command. Skip output bin file !"$(COLOR_END)
endif
	
$(BUILD_DIR):
	mkdir $@		

#####################
# CLEAN ALL OBJECTS
#####################
.PHONY : clean
clean:
	-rm -fR $(BUILD_DIR)/*.$(OBJ_SUFFIX)
	-rm -fR $(BUILD_DIR)/*.$(ELF_SUFFIX)
	-rm -fR $(BUILD_DIR)/*.$(AR_SUFFIX) 
	-rm -fR $(BUILD_DIR)/*.hex $(BUILD_DIR)/*.bin