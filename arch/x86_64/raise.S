#define __ASSEMBLY__
#include <asm/unistd.h>
#include <asm/signal.h>


.global raise
.global abort

raise:
    mov %rdi,%rsi
    mov $__NR_gettid,%rax
    syscall
    mov %rax,%rdi
    mov $__NR_tkill,%rax
    syscall
    mov %rax,%rdi
    js .set_errno
    ret
    .set_errno:
    mov __errno@GOTPCREL(%rip), %rsi
    neg %rdi
    mov %rdi,(%rsi)
    ret

abort:
    mov $SIGABRT,%rax
    jmp raise