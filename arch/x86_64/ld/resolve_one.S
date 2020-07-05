

.global _ld_sym_resolve

_ld_sym_resolve:
    xchg %rdi,(%rsp)
    xchg %rsi,8(%rsp)
    pushq %rax
    callq resolve_symbol
    mov %rax,%r11
    popq %rax
    popq %rdi
    popq %rsi
    jmpq *%r11
