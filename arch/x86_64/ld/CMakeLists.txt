

add_library(ld-lcnix SHARED ld-lcnix.c crt1.S init.S resolve_one.S dso_info.h
        scripts/ld-lcnix-x86_64.so.ld)
set_target_properties(ld-lcnix PROPERTIES PREFIX "" OUTPUT_NAME "ld-lcnix-${LCNIX_TARGET_ARCH}"
        SOVERSION "1.0")
add_dependencies(ld)
target_link_libraries(ld-lcnix c-shared)
target_link_options(ld-lcnix PRIVATE -Wl,--no-dynamic-linker -nostdlib -Wl,-e,_start
        -L${CMAKE_CURRENT_SOURCE_DIR}/scripts
        -Wl,-T,ld-lcnix-x86_64.so.ld
        -Wl,-z,notext
        -Wl,-z,relro)