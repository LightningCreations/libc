
.weak __init_begin
.weak __init_end

.weak __fini_begin
.weak __fini_end

.global __libc_csu_init
.global __libc_csu_fini

__libc_csu_init:
    movq __init_begin@GOTPCREL(%rip),%rsi
    movq __init_end@GOTPCREL(%rip),%rdi
    .init_loop:
    cmp %rsi,%rdi
    jae .init_exit
    movq (%rsi),%rdx
    lea 8(%rsi),%rsi
    call *%rdx
    jmp .init_loop
    .init_exit:
    ret

__libc_csu_fini:
    movq __fini_begin@GOTPCREL(%rip),%rsi
    movq __fini_end@GOTPCREL(%rip),%rdi
    .fini_loop:
    cmp %rsi,%rdi
    jae .fini_exit
    movq (%rsi),%rdx
    lea 8(%rsi),%rsi
    call *%rdx
    jmp .fini_loop
    .fini_exit:
    ret