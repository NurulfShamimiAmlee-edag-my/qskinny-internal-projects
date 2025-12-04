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
        "  source /opt/fsl-imx-wayland/6.12-walnascar/environment-setup-armv8a-poky-linux"
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

message(STATUS "Target Sysroot: ${CMAKE_SYSROOT}")
message(STATUS "Native Sysroot: $ENV{OECORE_NATIVE_SYSROOT}")

# =============================================================================
# 4. Cross-Compilation Search Rules
# =============================================================================
set(CMAKE_FIND_ROOT_PATH 
    $ENV{OECORE_TARGET_SYSROOT}
    $ENV{OECORE_NATIVE_SYSROOT}
)

# Programs (compilers, tools): Only on host, never in sysroot
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Libraries and headers: Only in sysroot
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Packages: Search both sysroot AND host (needed for Qt *Tools packages)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

# =============================================================================
# 5. Compiler Configuration
# =============================================================================
set(CMAKE_C_COMPILER aarch64-poky-linux-gcc)
set(CMAKE_CXX_COMPILER aarch64-poky-linux-g++)

# Skip compiler tests (already validated by SDK)
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
set(OPENGL_gles3_LIBRARY "${CMAKE_SYSROOT}/usr/lib/libGLESv2.so" CACHE FILEPATH "GLES3 library" FORCE)

# Some CMake modules look for GLX (X11 OpenGL), but iMX8M uses EGL (Wayland)
# We set this to avoid the "missing glx" error
set(OPENGL_glx_LIBRARY "" CACHE FILEPATH "GLX library (not used on Wayland)" FORCE)

# Tell CMake we have OpenGL (via GLES)
set(OpenGL_FOUND TRUE CACHE BOOL "OpenGL found" FORCE)
set(OPENGL_FOUND TRUE CACHE BOOL "OpenGL found" FORCE)

# =============================================================================
# 8. Qt6 Configuration for Cross-Compilation
# =============================================================================

# Tell CMake where to find Qt6 packages in the target sysroot
set(CMAKE_PREFIX_PATH 
    ${CMAKE_SYSROOT}/usr/lib/cmake
    ${CMAKE_SYSROOT}/usr/lib
)

# Qt Host Tools Configuration
set(QT_HOST_PATH "/usr" CACHE PATH "Path to host Qt installation" FORCE)
set(QT_HOST_PATH_CMAKE_DIR "/usr/lib/x86_64-linux-gnu/cmake" CACHE PATH "Path to host Qt CMake directory" FORCE)

# Allow CMake to find Qt host tools from Debian system
list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

# Explicitly point to host Qt tool packages
if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6CoreTools")
    set(Qt6CoreTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6CoreTools" 
        CACHE PATH "Host Qt6CoreTools" FORCE)
endif()

if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6GuiTools")
    set(Qt6GuiTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6GuiTools" 
        CACHE PATH "Host Qt6GuiTools" FORCE)
endif()

if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6QmlTools")
    set(Qt6QmlTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6QmlTools" 
        CACHE PATH "Host Qt6QmlTools" FORCE)
endif()

if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6QuickTools")
    set(Qt6QuickTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6QuickTools" 
        CACHE PATH "Host Qt6QuickTools" FORCE)
endif()

if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6DBusTools")
    set(Qt6DBusTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6DBusTools" 
        CACHE PATH "Host Qt6DBusTools" FORCE)
endif()

if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6WidgetsTools")
    set(Qt6WidgetsTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6WidgetsTools" 
        CACHE PATH "Host Qt6WidgetsTools" FORCE)
endif()

if(EXISTS "/usr/lib/x86_64-linux-gnu/cmake/Qt6ShaderToolsTools")
    set(Qt6ShaderToolsTools_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt6ShaderToolsTools" 
        CACHE PATH "Host Qt6ShaderToolsTools" FORCE)
endif()

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
message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Sysroot: ${CMAKE_SYSROOT}")
message(STATUS "Qt Host Path: ${QT_HOST_PATH}")
message(STATUS "OpenGL ES Support: YES (via Vivante)")
message(STATUS "===================================================")