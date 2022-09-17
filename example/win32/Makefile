################################
#        应用程序生成配置
################################

# 输出根目录
BUILD_ROOT := build

# 可执行文件名称
EXE_NAME := main

# 输出二进制类型，默认：elf
# 可选值：static_lib, elf
OUTPUT_TYPE := elf

# 输出目录
ifeq ($(CWD),)
	BUILD_DIR = $(BUILD_ROOT)
else
	BUILD_DIR = $(BUILD_ROOT)/$(CWD)
endif

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

MESCH_SDK_ROOT := ../..

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

CPP_SOURCES +=

ASM_SOURCES +=

OBJ_SOURCES +=

SUB_DIRS +=

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
LDLIBS += -lm

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
SZ = $(CC_FOLDER)$(CC_PREFIX)size
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
ASM_FILTER := %.asm %.s %.S
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

# print color
COLOR_END = "\e[0m"
COLOR_WARN = "\e[33;1m"
COLOR_DONE = "\e[32;1m"
COLOR_ERR = "\e[31;1m"

# add source dep search folder
vpath %.c $(dir $(C_SRC))
vpath %.cpp $(dir $(CPP_SRC))
vpath %.cc $(dir $(CPP_SRC))
vpath %.cxx $(dir $(CPP_SRC))
vpath %.c++ $(dir $(CPP_SRC))
vpath %.s $(dir $(ASM_SRC))
vpath %.asm $(dir $(ASM_SRC))
vpath %.S $(dir $(ASM_SRC))
vpath %.h $(dir $(INCLUDE_FOLDERS))
vpath %.hpp $(dir $(INCLUDE_FOLDERS))
vpath %.hxx $(dir $(INCLUDE_FOLDERS))
vpath %.h++ $(dir $(INCLUDE_FOLDERS))

# merge all objs
OBJS += $(addprefix $(BUILD_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(subst ..,__,$(C_SRC))))) \
		$(addprefix $(BUILD_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(subst ..,__,$(CPP_SRC))))) \
		$(addprefix $(BUILD_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(subst ..,__,$(ASM_SRC))))) \
		$(OBJ_SRC)

DEPS = $(OBJS:.$(OBJ_SUFFIX)=.d)

#################
# rules

all: $(SUB_DIRS) $(EXE_FILES)
	@echo -e $(COLOR_DONE)"#################### All Done ! ####################"$(COLOR_END)

$(BUILD_DIR):
	@mkdir -p $@

$(SUB_DIRS):
	@make -C $@ CWD=$@

# link executable file
$(BUILD_DIR)/$(EXE_NAME).$(ELF_SUFFIX): $(OBJS) Makefile | $(BUILD_DIR)
	@echo LINK '$@' ...
	$(LD) $(OBJS) $(LDFLAGS) $(LD_OUT_CMD) $@ $(LDLIBS)
ifdef SZ
	@$(SZ) $@
endif

# static lib
$(BUILD_DIR)/$(EXE_NAME).$(AR_SUFFIX): $(OBJS) Makefile | $(BUILD_DIR)
	@echo AR '$@' ...
	@$(AR) $(AR_OUT_CMD) $@ $(AR_FLAGS) $(OBJS)

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

# compile c source
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.c Makefile | $(BUILD_DIR) 
	@echo CC '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(CC) $(CFLAGS) $(subst __,..,$<) $(CC_OUT_CMD) $@

# compile c++ source
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.cpp Makefile | $(BUILD_DIR) 
	@echo CXX '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(CC) $(CXXFLAGS) $(subst __,..,$<) $(CC_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.c++ Makefile | $(BUILD_DIR) 
	@echo CXX '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(CC) $(CXXFLAGS) $(subst __,..,$<) $(CC_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.cxx Makefile | $(BUILD_DIR) 
	@echo CXX '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(CC) $(CXXFLAGS) $(subst __,..,$<) $(CC_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.cc Makefile | $(BUILD_DIR) 
	@echo CXX '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(CC) $(CXXFLAGS) $(subst __,..,$<) $(CC_OUT_CMD) $@

# compile asm source
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.s Makefile | $(BUILD_DIR) 
	@echo AS '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(AS) $(ASMFLAGS) $(subst __,..,$<) $(AS_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.S Makefile | $(BUILD_DIR) 
	@echo AS '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(AS) $(ASMFLAGS) $(subst __,..,$<) $(AS_OUT_CMD) $@
$(BUILD_DIR)/%.$(OBJ_SUFFIX): %.asm Makefile | $(BUILD_DIR) 
	@echo AS '$(subst __,..,$<)' ...
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	@$(AS) $(ASMFLAGS) $(subst __,..,$<) $(AS_OUT_CMD) $@

# include deps
-include $(DEPS)

# check source files
%.c %.cc %.cpp %.cxx %.c++:
	@ls -l $(subst __,..,$@) >/dev/null

%.s %.S %.asm:
	@ls -l $(subst __,..,$@) >/dev/null

# override default rules
%.d:
	@echo >/dev/null

#####################
# CLEAN ALL OBJECTS
clean:
	-rm -fR $(BUILD_DIR)/*

.PHONY : all clean $(SUB_DIRS)
