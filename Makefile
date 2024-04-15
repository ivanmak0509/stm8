TARGET = stm8
DEBUG = 1

OS := $(shell uname)

C_SOURCES = $(wildcard src/*.c)
INCLUDES = \
-Isrc

ifeq ($(OS),Darwin)
INCLUDES += -I/opt/homebrew/share/sdcc/include
else
INCLUDES += -I/usr/share/sdcc/include
endif

BUILD_DIR = build

# --opt-code-speed is also possible if preferred
MCU = -mstm8 --stack-auto --opt-code-size

CFLAGS =  $(MCU) $(INCLUDES)
LDFLAGS = $(MCU)

ifeq ($(DEBUG), 1)
CFLAGS += --debug
else
endif

ifdef SDCC_PATH
CC = $(SDCC_PATH)/sdcc
SZ = $(SDCC_PATH)/size
PP = $(SDCC_PATH)/sdcpp
CP = $(SDCC_PATH)/sdobjcopy
else
CC = sdcc
SZ = size
PP = sdcpp
CP = sdobjcopy
endif


objects = $(addprefix $(BUILD_DIR)/, $(notdir $(C_SOURCES:.c=.rel)))
vpath %.c $(sort $(dir $(C_SOURCES)))

$(BUILD_DIR)/$(TARGET).ihx: $(objects) Makefile | $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $(objects)
	$(SZ) $@

$(BUILD_DIR)/%.rel: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.d: %.c Makefile | $(BUILD_DIR)
	$(PP) $(INCLUDES) -MM -MP -MT "$(@:.d=.rel) $@" -MF $@ $< 

$(BUILD_DIR):
	mkdir $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# .PHONY: unlock
# unlock:
# 	stm8flash -c stlinkv2 -p stm8l101f2 -u

# execute twice because stm8flash reports 'device locked' every once in a while
.PHONY: flash
flash: $(BUILD_DIR)/$(TARGET).ihx
	-stm8flash -c stlinkv2 -p stm8l101f2 -s flash -w $<
	-stm8flash -c stlinkv2 -p stm8l101f2 -s flash -w $<

# doesnt work well, atleast for stm8l101f2p6
# .PHONY: debug
# debug:
# 	openocd -f openocd.cfg


include $(objects:.rel=.d)
