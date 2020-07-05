//
// Created by chorm on 2020-05-02.
//

#ifndef __LCNIX_STDLIB_H
#define __LCNIX_STDLIB_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <bits/null.h>

void _Exit(int code) __attribute__((noreturn));

void exit(int code) __attribute__((noreturn));

#endif //LCNIX_STDLIB_H
