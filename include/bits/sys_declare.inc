
#define __syscall(name,ret,...)\
    ret name(__VA_ARGS__)
