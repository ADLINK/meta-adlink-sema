SUMMARY = "SEMA Application"
DESCRIPTION = "At the heart of SEMA is the Board Management Controller (BMC) supporting SEMA functions. The SEMA Extended EAPI  provides access to all functions and can be integrated into the user’s own applications. The SEMA GUI and SEMA Command Line Interface  allow monitoring, control and use of the SEMA parameters and functions directly on your device for test and  demonstration  purpose "
HOMEPAGE = "https://www.adlinktech.com/en/SEMA.aspx"
SECTION = "Applications"

LICENSE = "CLOSED"

inherit module

SRCREV = "302ea74a83789c5464d396c8dadc6eee7152e836"
SRC_URI = "git://github.com/ADLINK/sema-linux.git;protocol=http \
           "

SRC_URI_append ="file://Makefile"

S = "${WORKDIR}/git"

CFLAGS_prepend += "-I${WORKDIR}/git/lib"

do_compile_prepend() {
	rm -r ${WORKDIR}/git/Makefile
	cp ${WORKDIR}/Makefile ${WORKDIR}/git/Makefile
}

do_compile_append() {
	cd ${WORKDIR}/git
	${CC}${CFLAGS}${LDFLAGS} -shared -fPIC -Wl,-soname,libsema.so ${WORKDIR}/git/lib/backlight.c \
	${WORKDIR}/git/lib/common.c \
	${WORKDIR}/git/lib/boardinfo.c \
	${WORKDIR}/git/lib/conv.c \
	${WORKDIR}/git/lib/fan.c \
	${WORKDIR}/git/lib/gpio.c \
	${WORKDIR}/git/lib/i2c.c \
	${WORKDIR}/git/lib/init.c \
	${WORKDIR}/git/lib/storage.c \
	${WORKDIR}/git/lib/watchdog.c -o ${WORKDIR}/git/lib/libsema.so
  	${CC} ${CFLAGS} -Wall -L${WORKDIR}/git/lib/ ${WORKDIR}/git/app/main.c -lsema -o ${WORKDIR}/git/semautil 
}

do_install_append() {
	install -d -m 0755 ${D}/lib64
	ln -s -r ${D}/lib/ld-linux-x86-64.so.2  ${D}/lib64/ld-linux-x86-64.so.2 
	install -d -m 0755 ${D}/usr${base_libdir}
	install -d -m 0755 ${D}/usr${base_bindir}
	install -m 0755 ${WORKDIR}/git/semautil ${D}/usr${base_bindir}/
	install -m 0755 ${WORKDIR}/git/lib/libsema.so ${D}/usr${base_libdir}/
}


FILES_${PN} += " /lib64 /usr${base_bindir}/semautil /usr${base_libdir}/*.so"
FILES_SOLIBSDEV = ""
do_package_qa() {
}

INSANE_SKIP_${PN} = "already-stripped"
