cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_SOURCE_DIR}/common/include)

if(WIN32)
	# add_definitions("-c -MD -MP2 -W0 -nologo")
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	include_directories(${PROJECT_SOURCE_DIR}/SEMA_Lib/EAPI/libsema)
	include_directories(${PROJECT_SOURCE_DIR}/SEMA_Lib/EAPI/eapi/include)
	include_directories(${PROJECT_SOURCE_DIR}/SEMA_Lib/EAPI/eapi/include/winnt)
	add_library(EApi_1 SHARED eapi.c eapi.rc eapi.def)
	target_link_libraries(EApi_1 libsema)
endif(WIN32)

if(UNIX)
	add_definitions("-O2 -Wall -s -W  ")
	add_definitions("-U SEMAADMIN")
	include_directories(${PROJECT_SOURCE_DIR}/SEMA_Lib/EAPI/libsema)
	include_directories(${PROJECT_SOURCE_DIR}/SEMA_Lib/EAPI/eapi/include)
	add_library(EApi_1 SHARED eapi.c libinfo.c)
	set_target_properties(EApi_1
   	 PROPERTIES
	 PREFIX        "lib"
  	 PUBLIC_HEADER "EApi.h"
	)
	target_link_libraries(EApi_1 libsema)	
endif(UNIX)


add_executable(EApi_demo demo.c)
target_link_libraries(EApi_demo EApi_1)
