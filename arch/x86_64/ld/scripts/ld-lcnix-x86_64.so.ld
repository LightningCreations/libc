ENTRY(_start)

PHDRS{
    header PT_PHDR;
    text PT_LOAD;
    data PT_LOAD;
    tls PT_TLS;
    dynamic PT_DYNAMIC;
}

SECTIONS {
    .text : {
        *(.text);
    } :text
    .rodata : {
        *(.rodata);
    }
    . = .;
    .data ALIGN(1024) : {
        *(.data);
    } :data
    .dynamic :{
        _DYNAMIC = .;
        *(.dynamic);
    } :dynamic :data

    .bss : {
        *(.bss);
        *(COMMON);
    } :data

    
    .tdata : {
        *(.tdata);
    } :tls :data

    .tbss : {
        *(.tbss);
    } :tls :data

    .got : {
        *(.got);
    } :data
}