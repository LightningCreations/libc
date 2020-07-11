//
// Created by chorm on 2020-07-05.
//

#include "dso_info.h"

#include <unistd.h>

void* resolve_symbol(struct DsoInfo* info,unsigned int u){
    for(int64_t begin = 0;begin<info->_cnt_needed;begin++){
        struct DsoInfo* needed_info = info->_needed_addrs[begin];
        if(needed_info == (struct DsoInfo*)-1uLL){

        }
    }
}
