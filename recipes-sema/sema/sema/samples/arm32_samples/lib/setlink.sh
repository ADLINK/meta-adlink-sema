#!/bin/sh
SEMAEAPI_LINK_NAME=""
LIBSEMA_LINK_NAME=""
EAPI_1_LINK_NAME=""
definelinkname()
{
	minor="`echo libsemaeapi.so.* | awk -F '.' '{print $NF}'`"
        temp_filename="`echo libsemaeapi.so.* | sed -e s/\.${minor}$//`"
	major="`echo $temp_filename | awk -F '.' '{print $NF}'`"
	SEMAEAPI_LINK_NAME="`echo $temp_filename | sed -e s/\.${major}$//`"
	#echo $SEMAEAPI_LINK_NAME

	minor="`echo libsema.so.*.* | awk -F '.' '{print $NF}'`"	
	LIBSEMA_LINK_NAME="`echo libsema.so.*.* | sed -e s/\.${minor}$//`"
	#echo $LIBSEMA_LINK_NAME

	minor="`echo libEApi_1.so.*.* | awk -F '.' '{print $NF}'`"	
    EAPI_1_LINK_NAME="`echo libEApi_1.so.*.* | sed -e s/\.${minor}$//`"
	#echo $EAPI_1_LINK_NAME
}
main()
{
	definelinkname

	if [ ! -f $SEMAEAPI_LINK_NAME ]; then
		sudo ln -s libsemaeapi.so.*.* $SEMAEAPI_LINK_NAME
	fi
	if [ ! -f $LIBSEMA_LINK_NAME ]; then
		sudo ln -s libsema.so.*.* $LIBSEMA_LINK_NAME
	fi
	if [ ! -f $EAPI_1_LINK_NAME ]; then
		sudo ln -s libEApi_1.so.*.* $EAPI_1_LINK_NAME
	fi
}

main
