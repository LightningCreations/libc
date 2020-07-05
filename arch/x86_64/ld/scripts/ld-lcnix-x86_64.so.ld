ENTRY(_start)

PHDRS{
    header PT_PHDR;
    text PT_LOAD;
    data PT_LOAD;
    tls PT_TLS;
    dynamic PT_DYNAMIC;
}

SECTIONS {
    .text : AT(.){
        *(.text);
    } :text
    .rodata : AT(ADDR(.text) + SIZEOF(.text)){
        *(.rodata);
    }
    . = . + 0x1000;
    .data : {
        *(.data);
    } :data
    .dynamic : AT(ADDR(.data)+SIZEOF(.data)){
        _DYNAMIC = .;
        *(.dynamic);
    } :dynamic :data

    .bss : {
        *(.bss);
        *(COMMON);
    } :NONE

    .tbss : {
        *(.tbss);
    } :tls
    .tdata : {
        *(.tdata);
    } :tls :data

    .got : {
        *(.got);
    } :data
}