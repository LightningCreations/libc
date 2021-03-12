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
    test %rax,%rax
    js .set_errno
    ret
    .set_errno:
    mov %rax,%rcx
    movq __errno@gottpoff(%rip),%rdi
    neg %rcx
    mov %rcx,%fs:(%rdi)
    ret

abort:
    mov $SIGABRT,%rax
    jmp raise