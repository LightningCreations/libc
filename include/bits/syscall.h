//
// Created by chorm on 2020-07-04.
//

#ifndef LCNIX_SYSCALL_H
#define LCNIX_SYSCALL_H

#include <asm/unistd.h>

#ifdef __NR_read
#define SYS_read __NR_read
#endif


#ifdef __NR_write
#define SYS_write __NR_write
#endif


#ifdef __NR_open
#define SYS_open __NR_open
#endif

#endif //LCNIX_SYSCALL_H
