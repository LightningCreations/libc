//
// Created by chorm on 2020-07-03.
//

#include <asm/unistd.h>

extern int __errno;

#define __stringify0(v) #v
#define __stringify1(v) __stringify0(v)
#define __stringify(v) __stringify1(__eval(v))

#define __eval0(v) v
#define __eval(v) __eval0(v)

#define __syscall_no(n) __stringify(__NR_##n)

#define __syscall(n,ret_t,...)\
    ret_t n(__VA_ARGS__){\
        long v;\
        __asm__("mov $" __syscall_no(n) ",%%rax\n\t"\
        "syscall\n\t"\
        "mov %%rax,%0":"=r"(v)::);\
        if(v<0){\
            __errno = -v;\
            return -1;\
        }\
        return (ret_t)v;\
    }

__syscall(read,int,int fd,void* mem,unsigned long sz)
__syscall(write,int,int fd,const void* mem,unsigned long sz)
