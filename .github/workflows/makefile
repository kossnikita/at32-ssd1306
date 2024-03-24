# Tools

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AS=arm-none-eabi-gcc

# Code Paths

LIBROOT=libs
CORE=$(LIBROOT)/cmsis/cm4/core_support
DEVICE=$(LIBROOT)/cmsis/cm4/device_support
PERIPH=$(LIBROOT)/drivers
SSD1306=$(LIBROOT)/ssd1306

SRCS=$(wildcard libs/drivers/src/*.c)
SRCS+=$(wildcard libs/ssd1306/src/*.c)
SRCS+=$(wildcard libs/cmsis/cm4/device_support/system_*.c)
SRCS+=$(wildcard libs/cmsis/cm4/device_support/startup/gcc/startup_*.s)

OBJS=$(patsubst %.c,%.o,$(patsubst %.s,%.o,$(SRCS)))

# Library flags

SSD1306_FLAGS= -D${NAME}
SSD1306_FLAGS+= -DSSD1306_I2C_PORT=I2C1
SSD1306_FLAGS+= -DSSD1306_SPI_PORT=SPI1
SSD1306_FLAGS+= -DSSD1306_INCLUDE_FONT_6x8
SSD1306_FLAGS+= -DSSD1306_INCLUDE_FONT_7x10
SSD1306_FLAGS+= -DSSD1306_INCLUDE_FONT_11x18
SSD1306_FLAGS+= -DSSD1306_INCLUDE_FONT_16x26
SSD1306_FLAGS+= -DSSD1306_INCLUDE_FONT_16x24

# Compilation Flags

LDFLAGS= -T$(shell find libs -name ${LDSCRIPT}) -mthumb -mcpu=cortex-m4 --specs=nosys.specs -flto -Wl,--gc-sections -Wl,--no-warn-rwx-segments -Wall -Werror
CFLAGS= -mcpu=cortex-m4 -mthumb --specs=nosys.specs -Os -Wall -Werror -fdata-sections -ffunction-sections 
CFLAGS+= -I$(DEVICE) -I$(CORE) -I$(PERIPH)/inc -I$(SSD1306)/include -I. 
CFLAGS+= -D${MCU}
CFLAGS+= $(SSD1306_FLAGS)

# Build executable 

.PHONY: i2c
i2c: CFLAGS+= -DSSD1306_USE_I2C
i2c: i2c.elf

.PHONY: spi
spi: CFLAGS+= -DSSD1306_USE_SPI
spi: spi.elf

ssd1306_conf.h:
	touch ssd1306_conf.h

define main
#include <errno.h>
#include "ssd1306_tests.h"
int main(void){ssd1306_TestAll();while (1){}}
int __attribute__((weak)) _close(int fildes) {(void)(fildes);errno = ENOSYS;return -1;}
int __attribute__((weak)) _lseek(int file, int ptr, int dir) {(void)(file);(void)(ptr);(void)(dir);errno = ENOSYS;return -1;}
int __attribute__((weak)) _read(int file, char *ptr, int len) {(void)(file);(void)(ptr);(void)(len);errno = ENOSYS;return -1;}
int __attribute__((weak)) _write(int file, char *ptr, int len) {(void)(file);(void)(ptr);(void)(len);errno = ENOSYS;return -1;}
endef

main.c: ssd1306_conf.h
	$(file > main.c,${main}) 

%.elf : main.o $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $< $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@
