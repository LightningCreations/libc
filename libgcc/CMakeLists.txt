
add_subdirectory(common)
add_subdirectory(arch/${LCNIX_TARGET_ARCH})

add_library(gcc-objects OBJECT $<TARGET_OBJECTS:gcc-common>
        $<TARGET_OBJECTS:gcc-arch-${LCNIX_TARGET_ARCH}>)

add_library(gcc_s-static STATIC $<TARGET_OBJECTS:gcc-objects>)
add_library(gcc_s-shared SHARED $<TARGET_OBJECTS:gcc-objects>)
target_link_options(gcc_s-shared PRIVATE -nodefaultlibs)