//
// Created by chorm on 2020-05-03.
//

struct __cxa_at_exit_handler{
    void(*finalizer)(void*);
    void* obj;
    void* dso_base;
};


static struct __cxa_at_exit_handler at_exits[1024];
static unsigned at_exitc;

void __cxa_at_exit(void(*finalizer)(void*),void* obj,void* dso_base){
    at_exits[at_exitc].finalizer = finalizer;
    at_exits[at_exitc].obj = obj;
    at_exits[at_exitc].dso_base = dso_base;
    at_exitc++;
}

void __cxa_finalize(void* dso_base){
    for(unsigned i = at_exitc;i>0;i--)
        if(at_exits[i-1].finalizer&&((!dso_base)||at_exits[i-1].dso_base==dso_base)){
            at_exits[i-1].finalizer(at_exits[i].obj);
            at_exits[i-1].finalizer = 0;
        }

}

void atexit(void(*at_exit)(void)){
    __cxa_at_exit((void(*)(void*))at_exit,0,0);
}
