cmake_minimum_required(VERSION 3.10)

# 1. System Name and Processor
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 2. Sysroots
# Target Sysroot: Where the ARM libraries are (libQt6Core.so, etc.)
set(CMAKE_SYSROOT $ENV{OECORE_TARGET_SYSROOT})

# Host Sysroot: Where your x86_64 tools are (moc, rcc, uic)
set(OECORE_NATIVE_SYSROOT "/opt/fsl-imx-wayland/6.12-walnascar/sysroots/x86_64-pokysdk-linux")

# 3. Compilers
# Use the environment variables set by the Yocto SDK script
set(CMAKE_C_COMPILER aarch64-poky-linux-gcc)
set(CMAKE_CXX_COMPILER aarch64-poky-linux-g++)
set(CMAKE_CXX_FLAGS $ENV{CXXFLAGS})
set(CMAKE_C_FLAGS $ENV{CFLAGS})
set(CMAKE_EXE_LINKER_FLAGS $ENV{LDFLAGS})

# 4. Search Behavior
# Never search for programs in the target sysroot (we can't run ARM binaries on laptop)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Only search for libraries/headers in the target sysroot
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# 5. Search Paths
set(CMAKE_FIND_ROOT_PATH 
    ${CMAKE_SYSROOT}
    ${OECORE_NATIVE_SYSROOT} 
    "/opt/qskinny-arm"
)

# --- 6. Qt Specifics (UPDATED) ---

# Define where the Host Tools (moc, rcc, uic) are located
# You found them in libexec, so we explicitly set that here.
set(OE_QMAKE_PATH_HOST_BINS "${OECORE_NATIVE_SYSROOT}/usr/libexec" CACHE PATH "Path to Qt Host Tools" FORCE)

# Define the base of the Host Qt installation
set(QT_HOST_PATH "${OECORE_NATIVE_SYSROOT}/usr" CACHE PATH "Path to Host Qt Root" FORCE)

# Skip standard compiler checks to save time/errors
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)