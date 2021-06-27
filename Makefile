#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
PLATFORM        = HOST
include sources.mk

# Platform Overrides
FUNCTION        = COURSE1
OTHER_FLAGS = -g -Wall -Werror -std=c99 -O0 -D$(FUNCTION)
TARGET = c1m2


ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = -DHOST $(GENERAL_FLAGS)
  CPPFLAGS = -I ./include/common -MD -v $(OTHER_FLAGS)
else
  #Architectures Specific Flags
  LINKER_FILE = msp432p401r.lds
  PLATFORM = MSP432
  CPU = cortex-m4
  ARCH = thumb
  SPECS = nosys.specs
  MARCH = armv7e-m
  MFLOAT = hard
  MFPU = fpv4-sp-d16
  # Compiler Flags and Defines
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(MARCH) -mfloat-abi=$(MFLOAT) -mfpu=$(MFPU) --specs=$(SPECS) -DMSP432 $(OTHER_FLAGS)
  CPPFLAGS = -I ./include/CMSIS -I ./include/msp432 -MD
  LDFLAGS = -T $(LINKER_FILE)
endif


%.i : $(SOURCES)
	$(CC) -E $(CPPFLAGS) $(CFLAGS) -o $@ $(INCLUDES) -D$(PLATFORM) $<

%.o : $(SOURCES)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $(INCLUDES) -D$(PLATFORM) $<

%.asm : $(SOURCES)
	$(CC) -S $(CPPFLAGS) $(CFLAGS) -o $@ $(INCLUDES) -D$(PLATFORM) $<

.PHONY: build
build: $(TARGET).out

.PHONY: compile_all
compile-all:
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -D$(PLATFORM) $(SOURCES)

.PHONY: clean
clean:
	rm -f *.out *.map *.i *.asm *.o *.d


$(TARGET).out: compile-all
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out $(INCLUDES) -D$(PLATFORM) $(SOURCES)




