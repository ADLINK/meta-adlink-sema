SUMMARY = "SEMA Application"
DESCRIPTION = "At the heart of SEMA is the Board Management Controller (BMC) supporting SEMA functions. The SEMA Extended EAPI  provides access to all functions and can be integrated into the user’s own applications. The SEMA GUI and SEMA Command Line Interface  allow monitoring, control and use of the SEMA parameters and functions directly on your device for test and  demonstration  purpose "
HOMEPAGE = "https://www.adlinktech.com/en/SEMA.aspx"
SECTION = "Applications"

LICENSE = "CLOSED"

inherit module

SRCREV = "c094066cc6f69bdc21ec5b2bb8bdae805586c16f"
SRC_URI = "git://github.com/ADLINK/sema-linux.git;protocol=http \
           "

SRC_URI[md5sum] = "f3add5725dfc38e3c30357fecb43ff54"
SRC_URI[sha256sum] = "1225bcf4b6d7f89e7fc9b26b70a81a47e843f8f22c1b9fd407352f5c92dc6306"

SRC_URI_append ="file://Makefile"

S = "${WORKDIR}/git"

do_compile_prepend() {
	rm -r ${WORKDIR}/git/Makefile
	cp ${WORKDIR}/Makefile ${WORKDIR}/git/Makefile
}

do_compile_append() {
	cd ${WORKDIR}/git
	make semautil
	make libsema.so
}
do_install_append() {
	install -d -m 0755 ${D}/lib64
	ln -s -r ${D}/lib64/ld-linux-x86-64.so.2  ${D}/lib64/ld-linux-x86-64.so.2 
	install -d -m 0755 ${D}/usr${base_libdir}
	install -d -m 0755 ${D}/usr${base_bindir}
	    install -m 0755 ${WORKDIR}/git/semautil ${D}/usr${base_bindir}/
	    install -m 0755 ${WORKDIR}/git/lib/libsema.so ${D}/usr${base_libdir}/
}


FILES_${PN} += " ${D}/lib64 /usr${base_bindir}/semautil /usr${base_libdir}/*.so"
FILES_SOLIBSDEV = ""
do_package_qa() {
}

INSANE_SKIP_${PN} = "already-stripped"
