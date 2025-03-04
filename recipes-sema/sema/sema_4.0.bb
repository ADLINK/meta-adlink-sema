FILESEXTRAPATHS:prepend := "${THISDIR}/sema4.0:"

SUMMARY = "SEMA Application"
DESCRIPTION = "At the heart of SEMA is the Board Management Controller (BMC) supporting SEMA functions. The SEMA Extended EAPI  provides access to all functions and can be integrated into the user’s own applications. The SEMA GUI and SEMA Command Line Interface  allow monitoring, control and use of the SEMA parameters and functions directly on your device for test and  demonstration  purpose "
HOMEPAGE = "https://www.adlinktech.com/en/SEMA.aspx"
SECTION = "Applications"

LICENSE = "CLOSED"

inherit module
DEPENDS += "  util-linux util-linux-libuuid"

SRCREV = "56c8107db0575987eaf9e2f03097fcd7937c79c0"
SRC_URI = "git://github.com/ADLINK/sema-linux-bmc.git;branch=main;protocol=http \
           "

SRC_URI:append ="file://Makefile \
"

S = "${WORKDIR}/git"

CFLAGS:prepend = "-I${WORKDIR}/git/lib"

do_compile:prepend() {
	rm -r ${WORKDIR}/git/Makefile
	cp ${WORKDIR}/Makefile ${WORKDIR}/git/Makefile
}

do_compile:append() {
	cd ${WORKDIR}/git
	${CC} ${CFLAGS} ${LDFLAGS} -shared -fPIC -Wl,-soname,libsema.so ${WORKDIR}/git/lib/backlight.c \
	${WORKDIR}/git/lib/common.c \
	${WORKDIR}/git/lib/boardinfo.c \
	${WORKDIR}/git/lib/conv.c \
	${WORKDIR}/git/lib/fan.c \
	${WORKDIR}/git/lib/gpio.c \
	${WORKDIR}/git/lib/i2c.c \
	${WORKDIR}/git/lib/init.c \
	${WORKDIR}/git/lib/storage.c \
	${WORKDIR}/git/lib/watchdog.c -o ${WORKDIR}/git/lib/libsema.so
  	${CC} ${CFLAGS} -Wall -L${WORKDIR}/git/lib/ ${WORKDIR}/git/app/main.c -lsema -luuid -o ${WORKDIR}/git/semautil 
}

do_install:append() {
	install -d -m 0755 ${D}/lib64
	ln -s -r ${D}/lib/ld-linux-x86-64.so.2  ${D}/lib64/ld-linux-x86-64.so.2 
	install -d -m 0755 ${D}${base_libdir}
	install -d -m 0755 ${D}${base_bindir}
	install -m 0755 ${WORKDIR}/git/semautil ${D}${base_bindir}/
	install -m 0755 ${WORKDIR}/git/lib/libsema.so ${D}${base_libdir}/
}


FILES:${PN} += "/etc /lib64 ${base_bindir}/semautil ${base_libdir}/*.so"
FILES_SOLIBSDEV = ""
do_package_qa() {
}

INSANE_SKIP:${PN} = "already-stripped"

KERNEL_MODULE_AUTOLOAD += "\
adl-bmc \
adl-bmc-bklight \
adl-bmc-boardinfo \
adl-bmc-i2c \
adl-bmc-nvmem \
adl-bmc-wdt \
adl-bmc-hwmon \
adl-bmc-vm \
"

