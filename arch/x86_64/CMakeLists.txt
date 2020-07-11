enable_language(ASM)

add_library(c-arch-x86_64 OBJECT syscall.S raise.S syscalls.c)
set_target_properties(c-arch-x86_64 PROPERTIES POSITION_INDEPENDENT_CODE ${LCNIX_LIBC_ENABLE_SHARED})

if(NOT LCNIX_LIBC_NOSHARED)
add_subdirectory(ld)
endif()

add_subdirectory(crt)