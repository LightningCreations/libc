

.section .data
.global _DSO_ROOT
_DSO_ROOT:
    .quad _GLOBAL_OFFSET_TABLE_
    .quad _DYNAMIC
    .quad 1
    .quad 0


.section .got
.quad _DYNAMIC
.quad _DSO_ROOT
.quad _ld_sym_resolve
