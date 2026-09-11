FILESEXTRAPATHS:prepend := "${THISDIR}/sema4.0:"

SUMMARY = "SEMA Application"
DESCRIPTION = "At the heart of SEMA is the Board Management Controller (BMC) supporting SEMA functions. The SEMA Extended EAPI provides access to all functions and can be integrated into the user's own applications. The SEMA GUI and SEMA Command Line Interface allow monitoring, control and use of the SEMA parameters and functions directly on your device for test and demonstration purpose"
HOMEPAGE = "https://www.adlinktech.com/en/SEMA.aspx"
SECTION = "Applications"

LICENSE = "CLOSED"

inherit module
DEPENDS += "util-linux util-linux-libuuid"

SRCREV = "81d391725d072fa72a8b2e63b23e4f103c13945e"
SRC_URI = "git://github.com/ADLINK/sema-linux-bmc.git;branch=main;protocol=http \
           file://Makefile \
"


CFLAGS:prepend = "-I${S}/lib "

do_compile:prepend() {
	rm -f ${S}/Makefile
	cp ${UNPACKDIR}/Makefile ${S}/Makefile
}

do_compile:append() {
	cd ${S}
	${CC} ${CFLAGS} ${LDFLAGS} -shared -fPIC -Wl,-soname,libsema.so \
		${S}/lib/backlight.c \
		${S}/lib/common.c \
		${S}/lib/boardinfo.c \
		${S}/lib/conv.c \
		${S}/lib/fan.c \
		${S}/lib/gpio.c \
		${S}/lib/i2c.c \
		${S}/lib/init.c \
		${S}/lib/storage.c \
		${S}/lib/watchdog.c -o ${S}/lib/libsema.so
	${CC} ${CFLAGS} -Wall -L${S}/lib/ ${S}/app/main.c -lsema -luuid -o ${S}/semautil
}

do_install:append() {
	install -d -m 0755 ${D}${base_libdir}
	install -d -m 0755 ${D}${base_bindir}
	install -m 0755 ${S}/semautil ${D}${base_bindir}/
	install -m 0755 ${S}/lib/libsema.so ${D}${base_libdir}/
}

FILES:${PN} += "/etc ${base_bindir}/semautil ${base_libdir}/*.so"
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
