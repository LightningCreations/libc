//
// Created by chorm on 2020-07-03.
//

char** __environ;

__thread long __errno;

struct _ExceptBlock{
    _Bool _has_except;
    void* _exception_info_ptr;
    struct _ExceptBlock* _next;
    char _sbo_block[64];
};


_Noreturn void abort(void);

extern void(__attribute__((noreturn))*__terminate_fn)(void)__attribute__((weak));
__thread struct _ExceptBlock __base_exception_block = {._has_except = 0};

void __cxa_at_exit(void(*__finalize)(void*),void* obj,void* dso_base);

_Noreturn void exit(int code);

_Noreturn void __libc_start_main(int(*main)(int,char**,char**),int argc,char** argv,
        void(*_init)(void),void(*_fini)(void),void(*_rtld_fini)(void),
        void* stack_end){
    char** envp = &argv[argc+1];
    __environ = envp;
    if(_init)
        _init();
    __cxa_at_exit((void(*)(void*))_fini,0,0);
    // For now, we don't need to deal with _rtld_fini
    // FIXME when called from a dso how the heck do we get the dso base address to pass to __cxa_at_exit
    // __dso_handle
    __cxa_at_exit((void(*)(void*))_rtld_fini,0,0);
    int code = main(argc,argv,envp);
    // if(__base_exception_block._has_except) {
    //     if(!&__terminate_fn||!__terminate_fn)
    //         abort();
    //     else
    //         __terminate_fn();
    // }
    exit(code);
}
