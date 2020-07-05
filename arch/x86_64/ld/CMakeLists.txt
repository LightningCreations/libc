

add_library(ld-lcnix SHARED ld-lcnix.c crt1.S init.S resolve_one.S dso_info.h)
set_target_properties(ld-lcnix PROPERTIES PREFIX "" OUTPUT_NAME "ld-lcnix-${LCNIX_TARGET_ARCH}"
        SOVERSION "1.0")
target_link_libraries(ld-lcnix c-static)
target_link_options(ld-lcnix PRIVATE -Wl,--no-dynamic-linker -nostdlib -Wl,-e,_start
        -L${CMAKE_CURRENT_SOURCE_DIR}/scripts)