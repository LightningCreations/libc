
#include <sys/types.h>

#include <stdint.h>

__syscall(read,ssize_t,int fd,void* mem,size_t sz);
__syscall(write,ssize_t,int fd,const void* mem,size_t sz);
__syscall(close,long,int fd);

__syscall(access,int,const char* fname,int mode);
__syscall(alarm,unsigned int,unsigned int seconds);
__syscall(chdir,int,const char* dir);
__syscall(chroot,int,const char* dir);
__syscall(chown,int,const char* file,uid_t uid,gid_t gid);

__syscall(dup,int,int fd);
__syscall(dup2,int,int fd1,int fd2);

__syscall(fchown,int,int fd,uid_t uid,gid_t gid);
__syscall(fchdir,int,int fd);
__syscall(fdatasync,int,int fd);
__syscall(fsync,int,int fd);
__syscall(ftruncate,int,int fd);

__syscall(fork,pid_t,void);

__syscall(geteuid,uid_t,void);
__syscall(getegid,gid_t,void);
__syscall(getuid,uid_t,void);
__syscall(getgid,gid_t,void);
__syscall(getgroups,int,int sizesize,gid_t grouplist[]);
__syscall(getpgid,gid_t,pid_t pid);
__syscall(getpgrp,pid_t,void);
__syscall(getpid,pid_t,void);
__syscall(getppid,pid_t,void);
__syscall(getsid,pid_t,pid_t pid);


__syscall(lchown,int,const char* name,uid_t uid,gid_t gid);
__syscall(link,int,const char* path1,const char* path2);
__syscall(lseek,off_t,int fd,off_t off,int whence);
__syscall(pipe,int,int fd[2]);

__syscall(pause,int,void);

__syscall(readlink,int,const char* path, char* buf, size_t sz);
__syscall(rmdir,int,const char* path);

__syscall(setgid,int,gid_t gid);
__syscall(setpgid,int,pid_t pid,pid_t pgrp);
__syscall(setreuid,int,uid_t ruid,uid_t euid);
__syscall(setregid,int,gid_t rgid,gid_t egid);
__syscall(setsid,pid_t,void);
__syscall(symlink,int,const char* path1,const char* path2);
__syscall(sync,void,void);
__syscall(unlink,int,const char* path);

__syscall(vfork,pid_t,void);

int brk(void* addr);
void *sbrk(intptr_t ptr);
char* getcwd(char* buf,size_t size);