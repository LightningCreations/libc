
#include <sys/types.h>

__syscall(mlock,int,const void* mem, size_t size);
__syscall(mlockall,int,int flags);
__syscall(mmap,void*,void* region,size_t size,int prot,int flags,int fd,off_t offset);
__syscall(mprotect,int, void* region,size_t size,int prot);
__syscall(msync,int,void* region,size_t sz,int flags);
__syscall(munlock,int,const void* mem,size_t size);
__syscall(munlockall,int,void);

#if defined(_GNU_SOURCE)
__syscall(pkey_mprotect,int,void* addr,size_t sz,int prot,int pkey);
__syscall(pkey_alloc,int,int flags,int rights);
__syscall(pkey_free,void,int pkey);
#endif