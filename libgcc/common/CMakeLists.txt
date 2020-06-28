
add_library(gcc-common OBJECT memcpy.c)
target_compile_options(gcc-common PRIVATE -ffreestanding)