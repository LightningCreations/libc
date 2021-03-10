
set(CMAKE_ASM_FLAGS ${CMAKE_ASM_FLAGS})

add_library(ld-lcnix SHARED ld-lcnix.c crt1.S init.S resolve_one.S dso_info.h
        scripts/ld-lcnix-x86_64.so.ld resolve.c)
set_target_properties(ld-lcnix PROPERTIES PREFIX "" OUTPUT_NAME "ld-lcnix-${LCNIX_TARGET_ARCH}"
        SOVERSION "1.0"
        POSITION_INDEPENDENT_CODE ON
        LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/ld-lcnix-x86_64.so.ld)
target_link_libraries(ld-lcnix c-static)
target_link_options(ld-lcnix PRIVATE -nostdlib -Wl,-e,_start
        -L${CMAKE_CURRENT_SOURCE_DIR}/scripts
        -Wl,-T,ld-lcnix-x86_64.so.ld)