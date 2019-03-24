SUMMARY = "Provides an icon to execute ADLINK SMEA GUI"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = "file://semagui.desktop"
SRC_URI += "file://sema.png"

PR = "r1"

S = "${WORKDIR}"

do_install() {
	install -d ${D}${datadir}/applications
	install -d ${D}${datadir}/icons
	install -d ${D}/home/root/Desktop/

	install -m 0644 semagui.desktop ${D}${datadir}/applications/
	install -m 0644 sema.png ${D}${datadir}/icons/
	install -m 0644 semagui.desktop ${D}/home/root/Desktop/

}

#pkg_postinst_${PN} () {
#    grep -q qemuarm $D${sysconfdir}/hostname && \
#        sed -i $D${datadir}/applications/shutdown.desktop -e 's#^Exec=\(.*\)/halt#Exec=\1/reboot#' \
#        || true
#}

FILES_${PN} += "${datadir}/icons/sema.png"
FILES_${PN} += "/home/root/Desktop/semagui.desktop"

inherit allarch
