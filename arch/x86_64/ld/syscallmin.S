#include <asm/unistd.h>

.global read
.global open
.global mmap

read:
    mov $__NR_read,%rax
    syscall
    ret ; No need to deal with __errno

open:
    mov $__NR_open,%rax
    syscall
    ret

mmap:
    mov $__NR_mmap,%rax
    syscall
    ret
