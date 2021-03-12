//
// Created by chorm on 2020-05-02.
//

#include <signal.h>

extern _Noreturn void _Exit(int code);
extern void __cxa_finalize(void* dso_base);

_Noreturn void exit(int code){
    __cxa_finalize(0);
    _Exit(code);
}


_Noreturn void abort(){
    for(;;){
        raise(SIGABRT);
    }
}