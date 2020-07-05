#ifndef __LCLIBC_SYS_TYPE_H
#define __LCLIBC_SYS_TYPE_H

#include <asm/types.h>

#if __has_include_next(<sys/types.h>)
#include_next <sys/types.h>
#else

typedef __s64 id_t;
typedef id_t uid_t;
typedef id_t pid_t;

typedef long ssize_t;
typedef unsigned long size_t;

#endif

#endif