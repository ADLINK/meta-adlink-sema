cmake_minimum_required(VERSION 2.6)

project(SEMA_EAPI_Sample)

#set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_BUILD_TYPE Debug)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set link directories
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add debug definitions
if(UNIX)
    add_definitions("-DLINUX -O2 -s -Wall ")
endif(UNIX)

if(WIN32)
    if(MSVC_VERSION EQUAL 1700)
      add_definitions(-D_VARIADIC_MAX=10)
    endif()

    add_definitions("-D_SCL_SECURE_NO_WARNINGS")
    if (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 16.0)
        include_directories(${CMAKE_SOURCE_DIR}/include/winnt)
        #set this flag, otherwise the boost uintXX define will conflicate with VC stdint.h
        add_definitions(-DBOOST_HAS_STDINT_H)
    endif (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 16.0)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0501")
endif(WIN32)



##
#  Executable   : sample_board_info
#  Details      : sample_board_info exe file
add_executable(sample_board_info 
    src/BoardInformation/sample_board_info.cpp
)

target_link_libraries(sample_board_info semaeapi)


##
#  Executable   : sample_hdd_smart
#  Details      : sample_hdd_smart exe file
add_executable(sample_hdd_smart
    src/HDD_SMART/sample_hdd_smart.cpp
)

target_link_libraries(sample_hdd_smart semaeapi)


##
#  Executable   : sample_watchdog
#  Details      : sample_watchdog exe file
add_executable(sample_watchdog
    src/WatchDog/sample_watchdog.cpp
)

target_link_libraries(sample_watchdog semaeapi)

##
#  Executable   : gpio_1pin
#  Details      : gpio_1pin exe file
add_executable(gpio_1pin
    src/GPIO_1PIN/gpio_1pin.cpp
)

target_link_libraries(gpio_1pin semaeapi)

##
#  Executable   : i2c
#  Details      : i2c exe file
add_executable(i2c
    src/I2C/i2c.cpp
)

target_link_libraries(i2c semaeapi)