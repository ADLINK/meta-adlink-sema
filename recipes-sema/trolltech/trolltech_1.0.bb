SUMMARY = "Include Trolltech.conf to /home/root/.config/"
DESCRIPTION = "Fixed for SEMA GUI display abnormal issue"
AUTHOR = "Owen.Huang"
SECTION = "examples"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

PR = "r0"

SRC_URI = "file://Trolltech.conf"

S = "${WORKDIR}"

do_install() {
	install -d 0755 ${D}/home/root/.config
	install -m 0755 ${S}/Trolltech.conf ${D}/home/root/.config/Trolltech.conf
}

FILES_${PN} += "/home/root/.config/Trolltech.conf"
