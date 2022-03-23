SEMA_OBJS = $(patsubst %.c,%.o,$(wildcard lib/*.c))
APP_OBJS = $(patsubst %.c,%.o,$(wildcard app/*.c))
obj-m := driver/adl-bmc.o \
         driver/adl-bmc-bklight.o \
         driver/adl-bmc-wdt.o \
         driver/adl-bmc-i2c.o \
         driver/adl-bmc-boardinfo.o \
         adl-bmc-nvmem-sec.o \
         adl-bmc-nvmem.o \
         driver/adl-bmc-vm.o \
         driver/adl-bmc-hwmon.o \
         driver/adl-bmc-i2c.o \
         driver/adl-bmc-gpio.o

adl-bmc-nvmem-sec-m := driver/adl-bmc-nvmem-sec.o driver/nvmem-common.o	 
adl-bmc-nvmem-m := driver/adl-bmc-nvmem.o driver/nvmem-common.o	


all: modules

driver: modules


modules:
	$(MAKE) -C $(KERNEL_SRC) M=`pwd` $@


modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=`pwd` modules_install


clean:
	rm -rf *.o *.ko *.mod.c

