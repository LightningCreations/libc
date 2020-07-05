//
// Created by chorm on 2020-07-03.
//

#include <asm/unistd.h>

extern long __errno;

#define __stringify0(v) #v
#define __stringify1(v) __stringify0(v)
#define __stringify(v) __stringify1(__eval(v))

#define __eval0(v) v
#define __eval(v) __eval0(v)

#define __syscall_no(n) __NR_##n

/// Defines the syscall function
#define __syscall(n,ret_t,...)\
    ret_t n(__VA_ARGS__){\
        static unsigned long __test __attribute__((unused)) = __syscall_no(n);\
        register long v __asm__("rax");\
        __asm__("mov $" __stringify(__syscall_no(n)) ",%%rax\n\t"\
        "syscall\n\t"\
        :"=r"(v)::"memory");\
        if(v<0){\
            __errno = -v;\
            return (ret_t)-1;\
        }\
        return (ret_t)v;\
    }

#define __LCNIX_WANT_EXTENDED_SYSCALLS
#define _GNU_SOURCE
#include <bits/unistd.inc>
#include <bits/fctl.inc>
#include <bits/mman.inc>


char* getcwd(char* buf,size_t size){ // NOLINT no, not it cannot clang-tidy
    static unsigned long __test __attribute__((unused)) = __syscall_no(getcwd);
    register long v __asm__("rax");
    __asm__("mov $"__stringify(__syscall_no(getcwd))",%%rax\n\t"
            "syscall\n\t"
            :"=r"(v)::"memory");
    if(v<0){
        __errno = -v;
        return 0;
    }
    return buf;
}

static void* __brk_val;

int brk(void* brk){
    static unsigned long __test __attribute__((unused)) = __syscall_no(brk);
    register long v __asm__("rax");
    __asm__("mov $"__stringify(__syscall_no(brk))",%%rax\n\t"
            "syscall\n\t"
    :"=r"(v):"r"(brk):"memory");
    if(v<0){
        __errno = -v;
        return 0;
    }
    __brk_val = brk;
    return v;
}

void* sbrk(intptr_t offset){
    if(offset!=0)
        brk(__brk_val+offset);
    return __brk_val;
}