# toolchain-qskinny-arm.cmake
# Cross-compilation toolchain for QSkinny targeting iMX8M Nano (aarch64)

cmake_minimum_required(VERSION 3.16)

# =============================================================================
# 1. Target System Configuration
# =============================================================================
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# =============================================================================
# 2. Yocto SDK Environment Validation
# =============================================================================
if(NOT DEFINED ENV{OECORE_TARGET_SYSROOT})
    message(FATAL_ERROR 
        "OECORE_TARGET_SYSROOT not set!\n"
        "Please source your SDK environment script first:\n"
        "  source /opt/fsl-imx-wayland/6.12-walnascar/environment-setup-aarch64-poky-linux"
    )
endif()

if(NOT DEFINED ENV{OECORE_NATIVE_SYSROOT})
    message(FATAL_ERROR 
        "OECORE_NATIVE_SYSROOT not set!\n"
        "Please source your SDK environment script first."
    )
endif()

# =============================================================================
# 3. Sysroot Configuration
# =============================================================================
set(CMAKE_SYSROOT $ENV{OECORE_TARGET_SYSROOT})
set(CMAKE_STAGING_PREFIX $ENV{OECORE_TARGET_SYSROOT}/usr)

# Define Native Sysroot (Host tools location)
set(OECORE_NATIVE_SYSROOT $ENV{OECORE_NATIVE_SYSROOT})

message(STATUS "Target Sysroot: ${CMAKE_SYSROOT}")
message(STATUS "Native Sysroot: ${OECORE_NATIVE_SYSROOT}")

# =============================================================================
# 4. Cross-Compilation Search Rules
# =============================================================================
set(CMAKE_FIND_ROOT_PATH 
    ${CMAKE_SYSROOT}
    ${OECORE_NATIVE_SYSROOT}
    "/opt/qskinny-arm"
)

# Programs (compilers, tools): Only on host, never in sysroot
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Libraries and headers: Only in sysroot
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# =============================================================================
# 5. Compiler Configuration
# =============================================================================
# Use environment variables set by the SDK script. 
# This ensures strict architecture flags (march, mcpu) are included.
set(CMAKE_C_COMPILER aarch64-poky-linux-gcc)
set(CMAKE_CXX_COMPILER aarch64-poky-linux-g++)

# Skip compiler tests (already validated by SDK) to speed up configure
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# =============================================================================
# 6. Compiler and Linker Flags (from SDK)
# =============================================================================
set(CMAKE_C_FLAGS "$ENV{CFLAGS}" CACHE STRING "C flags" FORCE)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS}" CACHE STRING "CXX flags" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "$ENV{LDFLAGS}" CACHE STRING "Linker flags" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS "$ENV{LDFLAGS}" CACHE STRING "Shared linker flags" FORCE)

# =============================================================================
# 7. OpenGL/GLES Configuration for iMX8M Nano
# =============================================================================
# iMX8M uses OpenGL ES (not desktop OpenGL)
set(OpenGL_GL_PREFERENCE "GLVND")

# Point to the sysroot's OpenGL ES libraries
set(OPENGL_INCLUDE_DIR "${CMAKE_SYSROOT}/usr/include" CACHE PATH "OpenGL include directory" FORCE)
set(OPENGL_opengl_LIBRARY "${CMAKE_SYSROOT}/usr/lib/libOpenGL.so" CACHE FILEPATH "OpenGL library" FORCE)
set(OPENGL_egl_LIBRARY "${CMAKE_SYSROOT}/usr/lib/libEGL.so" CACHE FILEPATH "EGL library" FORCE)
set(OPENGL_gles2_LIBRARY "${CMAKE_SYSROOT}/usr/lib/libGLESv2.so" CACHE FILEPATH "GLES2 library" FORCE)

# Some CMake modules look for GLX (X11 OpenGL), but iMX8M uses EGL (Wayland)
set(OPENGL_glx_LIBRARY "" CACHE FILEPATH "GLX library (not used on Wayland)" FORCE)

# Tell CMake we have OpenGL (via GLES)
set(OpenGL_FOUND TRUE CACHE BOOL "OpenGL found" FORCE)
set(OPENGL_FOUND TRUE CACHE BOOL "OpenGL found" FORCE)

# =============================================================================
# 8. Qt6 Configuration for Cross-Compilation (UPDATED)
# =============================================================================

# 1. Host Tools Location (moc, rcc, uic)
# Based on your finding: /opt/.../sysroots/x86_64-pokysdk-linux/usr/libexec
set(OE_QMAKE_PATH_HOST_BINS "${OECORE_NATIVE_SYSROOT}/usr/libexec" CACHE PATH "Path to Qt Host Tools" FORCE)

# 2. Host Qt Root
set(QT_HOST_PATH "${OECORE_NATIVE_SYSROOT}/usr" CACHE PATH "Path to Host Qt Root" FORCE)

# 3. Target Qt Packages
# Tell CMake to look inside the Target Sysroot for QtConfig files
list(APPEND CMAKE_PREFIX_PATH 
    "${CMAKE_SYSROOT}/usr/lib/cmake"
    "${CMAKE_SYSROOT}/usr/lib"
)

# Note: We purposely REMOVED the search paths for /usr/lib/x86_64-linux-gnu.
# We must strictly use the SDK tools, not the Laptop's OS tools.

# =============================================================================
# 9. QSkinny-Specific Configuration
# =============================================================================

# Enable position-independent code (required for shared libraries)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# C++ Standard for QSkinny
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Qt's meta-object compiler automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# =============================================================================
# 10. Build Type Default
# =============================================================================
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING 
        "Choose: Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# =============================================================================
# 11. Installation Configuration
# =============================================================================
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "/opt/qskinny-arm" CACHE PATH 
        "Installation prefix" FORCE)
endif()

# Prevent accidental sysroot installation
if(CMAKE_INSTALL_PREFIX MATCHES "${CMAKE_SYSROOT}")
    message(FATAL_ERROR 
        "ERROR: CMAKE_INSTALL_PREFIX points to sysroot!\n"
        "This would pollute the SDK. Use /opt/qskinny-arm instead.\n"
        "Current: ${CMAKE_INSTALL_PREFIX}\n"
        "Sysroot: ${CMAKE_SYSROOT}")
endif()

message(STATUS "Install Prefix: ${CMAKE_INSTALL_PREFIX}")

# =============================================================================
# 12. PKG-CONFIG Configuration
# =============================================================================
set(ENV{PKG_CONFIG_SYSROOT_DIR} "${CMAKE_SYSROOT}")
set(ENV{PKG_CONFIG_LIBDIR} "${CMAKE_SYSROOT}/usr/lib/pkgconfig:${CMAKE_SYSROOT}/usr/share/pkgconfig")
set(ENV{PKG_CONFIG_PATH} "")

# =============================================================================
# 13. Additional Paths for Libraries
# =============================================================================
link_directories(
    ${CMAKE_SYSROOT}/usr/lib
    ${CMAKE_SYSROOT}/lib
)

# =============================================================================
# Toolchain Summary
# =============================================================================
message(STATUS "=== Cross-Compilation Toolchain for iMX8M Nano ===")
message(STATUS "Target: ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Sysroot: ${CMAKE_SYSROOT}")
message(STATUS "Qt Host Path: ${QT_HOST_PATH}")
message(STATUS "Qt Host Bins: ${OE_QMAKE_PATH_HOST_BINS}")
message(STATUS "===================================================")