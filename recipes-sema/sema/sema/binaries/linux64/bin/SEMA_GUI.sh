#!/bin/sh
export PATH=/usr/local/SEMA/semagui:$PATH
export LD_LIBRARY_PATH=/usr/local/SEMA/lib:/usr/local/SEMA/semagui
export QT_X11_NO_MITSHM=1
chmod 755 /usr/local/SEMA/semagui/SEMAGUI
/usr/local/SEMA/semagui/SEMAGUI > /dev/null 2>&1
