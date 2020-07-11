enable_language(C)

set(CMAKE_C_DIALECT 11)

include_directories(SYSTEM include)

add_subdirectory(arch/${LCNIX_TARGET_ARCH})
add_subdirectory(common)

if(LCNIX_LIBC_ENABLE_SHARED)
    add_library(m-shared SHARED $<TARGET_OBJECTS:m-common> $<TARGET_OBJECTS:m-arch-${LCNIX_TARGET_ARCH}>)
    set_target_properties(m-shared PROPERTIES OUTPUT_NAME m SOVERSION ${LCNIX_LIBC_VERSION})
    target_link_options(m-shared PRIVATE "-nostdlib")
    install(TARGETS m-shared)
endif()
add_library(m-static STATIC $<TARGET_OBJECTS:m-common> $<TARGET_OBJECTS:m-arch-${LCNIX_TARGET_ARCH}>)
set_target_properties(m-static PROPERTIES OUTPUT_NAME m)

# add_library(m ALIAS m-static)

install(TARGETS m-static)
install(DIRECTORY include/ TYPE INCLUDE FILES_MATCHING PATTERN "*.h")