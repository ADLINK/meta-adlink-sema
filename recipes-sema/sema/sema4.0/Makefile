SEMA_OBJS = $(patsubst %.c,%.o,$(wildcard lib/*.c))
APP_OBJS = $(patsubst %.c,%.o,$(wildcard app/*.c))
obj-m := driver/adl-bmc.o \
	 driver/adl-bmc-bklight.o \
 	 driver/adl-bmc-wdt.o \
 	 driver/adl-bmc-boardinfo.o \
 	 driver/adl-bmc-vm.o \
 	 driver/adl-bmc-nvmem.o \
 	 driver/adl-bmc-hwmon.o 
	 

all: libsema.so semautil modules

driver: modules

libsema.so: 	$(SEMA_OBJS) 
		gcc -shared -fPIC -g -o lib/$@ $^

modules:
	$(MAKE) -C $(KERNEL_SRC) M=`pwd` $@


modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=`pwd` modules_install

semautil: $(APP_OBJS)
	gcc -g -o $@ $^ -Llib -lsema


%.o: %.c
	gcc -Wall -I lib -g -fPIC -c $^ -o $@
clean:
	rm -rf *.o *.ko *.mod.c  
