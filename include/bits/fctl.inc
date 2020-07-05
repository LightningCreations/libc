
#include <sys/types.h>

__syscall(open,int,const char* name,int mode,...);
__syscall(creat,int,const char* path,mode_t mode);
