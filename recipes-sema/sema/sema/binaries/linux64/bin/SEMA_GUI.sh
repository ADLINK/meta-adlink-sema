#!/bin/sh
export PATH=$(pwd)/../semagui:$PATH
export LD_LIBRARY_PATH=$(pwd)/../semagui
chmod 755 /usr/local/SEMA/bin/../semagui/SEMAGUI 
/usr/local/SEMA/bin/../semagui/SEMAGUI > /dev/null 2>&1
