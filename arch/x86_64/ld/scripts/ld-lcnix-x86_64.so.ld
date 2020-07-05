ENTRY(_start)

SECTIONS {
    . = 0x7f00000000;
    .text : {
        *(.text);
    }
    .rodata : {
        *(.rodata);
    }

    . = . + 0x1000;
    .data : {
        *(.data);
    }
    .dynamic : {
        *(.dynamic);
    }
    .bss : {
        *(.bss);
        *(COMMON);
    }
}