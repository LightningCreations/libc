
add_subdirectory(common)
add_subdirectory(arch/${LCNIX_TARGET_ARCH})


add_library(gcc_s-static STATIC $<TARGET_OBJECTS:gcc-common>
        $<TARGET_OBJECTS:gcc-arch-${LCNIX_TARGET_ARCH}>)
set_target_properties(gcc_s-static PROPERTIES OUTPUT_NAME gcc_s)
add_library(gcc_s-shared SHARED $<TARGET_OBJECTS:gcc-common>
        $<TARGET_OBJECTS:gcc-arch-${LCNIX_TARGET_ARCH}>)
set_target_properties(gcc_s-static PROPERTIES OUTPUT_NAME gcc_s)
target_link_options(gcc_s-shared PRIVATE -nodefaultlibs)