//
// Created by chorm on 2020-05-12.
//

#ifndef LCNIX_UNISTD_H
#define LCNIX_UNISTD_H

long syscall(long syscallno,...);

void _exit(int code);


#include <bits/sys_declare.inc>

#include <bits/unistd.inc>

#endif //LCNIX_UNISTD_H
