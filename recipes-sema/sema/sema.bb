SUMMARY = "SEMA Application"
DESCRIPTION = "At the heart of SEMA is the Board Management Controller (BMC) supporting SEMA functions. The SEMA Extended EAPI  provides access to all functions and can be integrated into the user’s own applications. The SEMA GUI and SEMA Command Line Interface  allow monitoring, control and use of the SEMA parameters and functions directly on your device for test and  demonstration  purpose "
HOMEPAGE = "https://www.adlinktech.com/en/SEMA.aspx"
SECTION = "Applications"

LICENSE = "CLOSED"

SRC_URI+="file://docs"
SRC_URI+="file://include"
SRC_URI+="file://configs"
SRC_URI+="file://samples"

#==============================================================================
#     ARM x64
#==============================================================================
SRC_URI+="file://binaries/arm64/lib"
SRC_URI+="file://binaries/arm64/bin"
SRC_URI+="file://binaries/arm64/semagui"

#==============================================================================
#     ARM x32
#==============================================================================
SRC_URI+="file://binaries/arm32/lib"
SRC_URI+="file://binaries/arm32/bin"
SRC_URI+="file://binaries/arm32/semagui"

#==============================================================================
#     Linux x32
#==============================================================================
SRC_URI+="file://binaries/linux32/lib"
SRC_URI+="file://binaries/linux32/bin"
SRC_URI+="file://binaries/linux32/semagui"

#==============================================================================
#     Linux x64
#==============================================================================
SRC_URI+="file://binaries/linux64/lib"
SRC_URI+="file://binaries/linux64/bin"
SRC_URI+="file://binaries/linux64/semagui"

S = "${WORKDIR}"

#--------------------------------------------------------------------------------------------------------------------------------
# To exclude shared libraries installed within a recipe that should be ignored by the OpenEmbedded build system's shared library
#   resolver.

PRIVATE_LIBS = "libstdc++.so.6 \
		libEApi_1.so.3 \
		libgcc_s.so.1 \
		libsema.so.3 \
		libsemaeapi.so.3 \
		libsema_hwlinux.so.1.7 \
	       "
#---------------------------------------------------------------------------------------------------------------------------------

# Tasks
do_install() {

	install -d -m 0755 ${D}${base_libdir}
	install -d -m 0755 ${D}/usr/local/SEMA
	install -d -m 0755 ${D}/etc/SEMA

	if ${@bb.utils.contains('TARGET_ARCH', 'x86_64', 'true', 'false', d)}; then # Intel/AMD x64
		cp -a ${WORKDIR}/binaries/linux64/bin ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/linux64/lib ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/linux64/semagui ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/docs ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/include ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/samples/linux64_samples ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/configs/config ${D}/etc/SEMA
		cp -a ${WORKDIR}/configs/cert ${D}/etc/SEMA

		install -m 0755 ${WORKDIR}/binaries/linux64/lib/libEApi_1.so.3.6 ${D}${base_libdir}/libEApi_1.so.3
		install -m 0755 ${WORKDIR}/binaries/linux64/lib/libsemaeapi.so.3.6 ${D}${base_libdir}/libsemaeapi.so
		install -m 0755 ${WORKDIR}/binaries/linux64/lib/libsema_hwlinux.so.1.7 ${D}${base_libdir}/
		install -m 0755 ${WORKDIR}/binaries/linux64/lib/libsema.so.3.6 ${D}${base_libdir}/libsema.so.3
	fi

	if ${@bb.utils.contains('${TARGET_ARCH}', 'i586', 'true', 'false', d)}; then # Intel/AMD x32
		cp -a ${WORKDIR}/binaries/linux32/bin ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/linux32/lib ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/linux32/semagui ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/docs ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/include ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/samples/linux32_samples ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/configs/config ${D}/etc/SEMA
		cp -a ${WORKDIR}/configs/cert ${D}/etc/SEMA

		install -m 0755 ${WORKDIR}/binaries/linux32/lib/libEApi_1.so.3.6 ${D}${base_libdir}/libEApi_1.so.3
		install -m 0755 ${WORKDIR}/binaries/linux32/lib/libsemaeapi.so.3.6 ${D}${base_libdir}/libsemaeapi.so
		install -m 0755 ${WORKDIR}/binaries/linux32/lib/libsema_hwlinux.so.1.7 ${D}${base_libdir}/
		install -m 0755 ${WORKDIR}/binaries/linux32/lib/libsema.so.3.6 ${D}${base_libdir}/libsema.so.3
	fi

	if ${@bb.utils.contains('TARGET_ARCH', 'arm', 'true', 'false', d)}; then # ARM x32
		cp -a ${WORKDIR}/binaries/arm32/bin ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/arm32/lib ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/arm32/semagui ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/docs ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/include ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/samples/arm32_samples ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/configs/config ${D}/etc/SEMA
		cp -a ${WORKDIR}/configs/cert ${D}/etc/SEMA

		install -m 0755 ${WORKDIR}/binaries/arm32/lib/libEApi_1.so.3.6 ${D}${base_libdir}/
		install -m 0755 ${WORKDIR}/binaries/arm32/lib/libsemaeapi.so.3.6 ${D}${base_libdir}/
		install -m 0755 ${WORKDIR}/binaries/arm32/lib/libsema_hwlinux.so.1.7 ${D}${base_libdir}/
		install -m 0755 ${WORKDIR}/binaries/arm32/lib/libsema.so.3.6 ${D}${base_libdir}/
	fi

	if ${@bb.utils.contains('${TARGET_ARCH}', 'aarch', 'true', 'false', d)}; then # ARM x64
		cp -a ${WORKDIR}/binaries/arm64/bin ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/binaries/arm64/lib ${D}/usr/local/SEMA
	    cp -a ${WORKDIR}/binaries/arm64/semagui ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/docs ${D}/usr/local/SEMA
	    cp -a ${WORKDIR}/include ${D}/usr/local/SEMA
		cp -a ${WORKDIR}/samples/arm64_samples ${D}/usr/local/SEMA
	    cp -a ${WORKDIR}/configs/config ${D}/etc/SEMA
		cp -a ${WORKDIR}/configs/cert ${D}/etc/SEMA

	    install -m 0755 ${WORKDIR}/binaries/arm64/lib/libEApi_1.so.3.6 ${D}${base_libdir}/
	    install -m 0755 ${WORKDIR}/binaries/arm64/lib/libsemaeapi.so.3.6 ${D}${base_libdir}/
		install -m 0755 ${WORKDIR}/binaries/arm64/lib/libsema_hwlinux.so.1.7 ${D}${base_libdir}/
	    install -m 0755 ${WORKDIR}/binaries/arm64/lib/libsema.so.3.6 ${D}${base_libdir}/
	fi
}

FILES_${PN} += " /usr/local/ /usr/local/SEMA /etc/SEMA/ ${base_libdir}/*.so"
FILES_SOLIBSDEV = ""

do_package_qa() {
}

INSANE_SKIP_${PN} = "already-stripped"
