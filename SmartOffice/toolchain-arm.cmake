cmake_minimum_required(VERSION 3.10)

# 1. Target System Configuration
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 2. Check for the Yocto Environment
if(NOT DEFINED ENV{OECORE_TARGET_SYSROOT})
    message(FATAL_ERROR "OECORE_TARGET_SYSROOT not set. Please source your SDK environment script first!")
endif()

# 3. Sysroot Setup
set(CMAKE_SYSROOT $ENV{OECORE_TARGET_SYSROOT})
set(CMAKE_STAGING_PREFIX $ENV{OECORE_TARGET_SYSROOT}/usr)

# 4. Search Behavior - MODIFIED for Qt Tools
set(CMAKE_FIND_ROOT_PATH $ENV{OECORE_TARGET_SYSROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# CRITICAL CHANGE: Allow Qt *Tools packages to be found on host system
# This lets CMake find all Qt6*Tools packages from Debian automatically
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

# 5. Compilers
set(CMAKE_C_COMPILER aarch64-poky-linux-gcc)
set(CMAKE_CXX_COMPILER aarch64-poky-linux-g++)

# 6. Qt Specifics
# Target Qt libraries
set(CMAKE_PREFIX_PATH ${CMAKE_SYSROOT}/usr/lib/cmake)

# 7. Host Qt Configuration
set(QT_HOST_PATH "/lib/qt6" CACHE PATH "Path to host Qt installation" FORCE)

# Add Debian's Qt CMake path so all *Tools packages can be found
list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

set(CMAKE_PREFIX_PATH 
   # "/opt/qskinny-arm"
    ${CMAKE_SYSROOT}/usr/lib/cmake
    ${CMAKE_SYSROOT}/usr/lib
)