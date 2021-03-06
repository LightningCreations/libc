cmake_minimum_required(VERSION 3.17)
project(lclibc C)

enable_testing()
add_subdirectory(test)

set(LCNIX_TARGET_ARCH ${CMAKE_SYSTEM_PROCESSOR} CACHE STRING "Sets the architecture to target with the lcnix build. This is an advanced operation. When cross-compiling you should use a Cross-compilation script that sets CMAKE_SYSTEM_PROCESSOR")

include_directories(SYSTEM include arch/${LCNIX_TARGET_ARCH}/include)

option(LCNIX_LIBC_NOSHARED "Disable Shared Libraries for libc/libm. This also prevents the building of the dynamic (runtime) linker" OFF)

if(LCNIX_LIBC_NOSHARED)
    message(STATUS "Shared Libraries Disabled")
    set(LCNIX_LIBC_ENABLE_SHARED_INIT OFF)
else()
    message(STATUS "Shared Libraries Enabled")
    set(LCNIX_LIBC_ENABLE_SHARED_INIT ON)
endif()

option(LCNIX_LIBC_ENABLE_SHARED "Enables or disables shared libraries for libc. Note that setting this option to OFF does not disable the dynamic (runtime) linker" ${LCNIX_LIBC_ENABLE_SHARED_INIT})

add_subdirectory(arch/${LCNIX_TARGET_ARCH})
add_subdirectory(common)
if(NOT LCNIX_LIBC_NOSHARED)
add_subdirectory(ld)
endif()

add_subdirectory(libm)
add_subdirectory(libgcc)

set(LCNIX_LIBC_VER "0.1")

add_library(c-static STATIC $<TARGET_OBJECTS:c-arch-${LCNIX_TARGET_ARCH}> $<TARGET_OBJECTS:c-common>)
add_library(c ALIAS c-static)

if(LCNIX_LIBC_ENABLE_SHARED)
    add_library(c-shared SHARED $<TARGET_OBJECTS:c-arch-${LCNIX_TARGET_ARCH}> $<TARGET_OBJECTS:c-common>)
    set_target_properties(c-shared PROPERTIES OUTPUT_NAME c SOVERSION ${LCNIX_LIBC_VER})
    target_link_options(c-shared PRIVATE "-nodefaultlibs" "-Wl,-e,_start")
    target_link_libraries(c-shared PRIVATE crt)
    install(TARGETS c-shared)
endif()

install(TARGETS c-static)
install(DIRECTORY include/ TYPE INCLUDE FILES_MATCHING PATTERN "*.h")
