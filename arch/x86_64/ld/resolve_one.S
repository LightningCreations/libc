

.global _ld_sym_resolve

_ld_sym_resolve:
    xchg %rdi,(%rsp) ; Identifier, stored at _GLOBAL_OFFSET_TABLE_[1], this is a pointer to the DSO structure
    xchg %rsi,8(%rsp) ; Index
    pushq %rax
    callq resolve_symbol
    mov %rax,%r11
    popq %rax
    popq %rdi
    popq %rsi
    jmpq *%r11
