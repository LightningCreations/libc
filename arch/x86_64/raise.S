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
    leaq __errno@tlsgd(%rip),%rdi
    callq *__tls_get_addr@plt(%rip)
    neg %rcx
    mov %rcx,(%rax)
    ret

abort:
    mov $SIGABRT,%rax
    jmp raise