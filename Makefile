TARGET = stm8
DEBUG = 1

C_SOURCES = $(wildcard src/*.c)
INCLUDES = -Isrc

# no trailing slash
BUILD_DIR = build

# opt-code-speed is also possible if preferred
CFLAGS = -mstm8 --stack-auto --out-fmt-elf --opt-code-size
CFLAGS += $(INCLUDES)

ifeq ($(DEBUG), 1)
CFLAGS += --debug
else
endif

ifdef SDCC_PATH
CC = $(SDCC_PATH)/sdcc
SZ = $(SDCC_PATH)/size
PP = $(SDCC_PATH)/sdcpp
else
CC = sdcc
SZ = size
PP = sdcpp
endif


objects = $(addprefix $(BUILD_DIR)/, $(notdir $(C_SOURCES:.c=.rel)))
vpath %.c $(sort $(dir $(C_SOURCES)))

$(TARGET): $(objects) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET).elf $(objects)
	$(SZ) $(BUILD_DIR)/$(TARGET).elf

$(BUILD_DIR)/%.rel: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.d: %.c Makefile | $(BUILD_DIR)
	$(PP) -MM -MP -MT "$(@:.d=.rel) $@" -MF $@ $< 

$(BUILD_DIR):
	mkdir $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: debug
	openocd -f stlink.cfg -f stm32l1.cfg -c "init" -c "reset halt" & stm8-gdb  $(BUILD_DIR)/$(TARGET).elf --tui

include $(objects:.rel=.d)