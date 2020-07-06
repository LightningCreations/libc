//
// Created by chorm on 2020-07-05.
//

#ifndef LCNIX_DSO_INFO_H
#define LCNIX_DSO_INFO_H

#include <stdint.h>

#include <elf.h>



struct DsoInfo{
    void **global_offset_table;
    Elf64_Dyn *_dynamic;
    uint64_t _cnt_needed;
    struct DsoInfo* _needed_addrs[];
};


#endif //LCNIX_DSO_INFO_H
