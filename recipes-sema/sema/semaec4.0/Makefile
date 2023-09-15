SEMA_OBJS = $(patsubst %.c,%.o,$(wildcard lib/*.c))
APP_OBJS = $(patsubst %.c,%.o,$(wildcard app/*.c))
obj-m := driver/adl-ec.o \
         driver/adl-ec-bklight.o \
         driver/adl-ec-wdt.o \
         driver/adl-ec-i2c.o \
         driver/adl-ec-boardinfo.o \
         adl-ec-nvmem-sec.o \
         adl-ec-nvmem.o \
         driver/adl-ec-vm.o \
         driver/adl-ec-hwmon.o \
         driver/adl-ec-i2c.o \
         driver/adl-ec-gpio.o

adl-ec-nvmem-sec-m := driver/adl-ec-nvmem-sec.o driver/nvmem-common.o	 
adl-ec-nvmem-m := driver/adl-ec-nvmem.o driver/nvmem-common.o	


all: modules

driver: modules


modules:
	$(MAKE) -C $(KERNEL_SRC) M=`pwd` $@


modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=`pwd` modules_install


clean:
	rm -rf *.o *.ko *.mod.c

