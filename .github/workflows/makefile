# Tools

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AS=arm-none-eabi-gcc

# Code Paths

LIBROOT=libs
CORE=$(LIBROOT)/cmsis/cm4/core_support
DEVICE=$(LIBROOT)/cmsis/cm4/device_support
PERIPH=$(LIBROOT)/drivers

#  Processor specific

LDSCRIPT = $(shell find libs -name ${LDSCRIPT})
STARTUP= startup_stm32f10x.o system_stm32f10x.o 

# Compilation Flags

FULLASSERT = -DUSE_FULL_ASSERT 

LDFLAGS+= -T$(LDSCRIPT) -mthumb -mcpu=cortex-m4
CFLAGS+= -mcpu=cortex-m4 -mthumb 
CFLAGS+= -I$(DEVICE) -I$(CORE) -I$(PERIPH)/inc -I.
CFLAGS+= -D$(MCU)

# Build executable 

i2c: i2c.elf

spi: spi.elf

$(ELF) : $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@
