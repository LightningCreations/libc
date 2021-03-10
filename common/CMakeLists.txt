

add_library(c-common OBJECT malloc.c exit.c ../include/stdlib.h ../include/stdint.h __cxa_exit.c ../include/unistd.h init.c ../include/signal.h ../include/bits/syscall.h ../include/sys/mman.h ../include/fcntl.h ../include/elf.h)
set_target_properties(c-common PROPERTIES POSITION_INDEPENDENT_CODE ON)
