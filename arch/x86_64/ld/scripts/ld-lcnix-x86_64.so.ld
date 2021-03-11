ENTRY(_start)

PHDRS{
    headers PT_PHDR PHDRS ;
    text PT_LOAD;
    data PT_LOAD;
    tls PT_TLS;
    dynamic PT_DYNAMIC;
}

SECTIONS {
    . = SIZEOF_HEADERS;
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