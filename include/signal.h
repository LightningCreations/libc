//
// Created by chorm on 2020-07-04.
//

#ifndef LCNIX_SIGNAL_H
#define LCNIX_SIGNAL_H

#include <stddef.h>

#include <asm/signal.h>

#include <bits/sys_declare.inc>

#include <bits/signal.inc>

__signalfn_t* (signal)(int sig,__signalfn_t*);

#define signal(...) __rt_signal(__VA_ARG__)

int raise(int sig);

#ifdef _POSIX_C_SOURCE
int sigaction(int sig,const struct sigaction* sa,struct sigaction* prev_sa);
#define sigaction(...) __rt_sigaction

#endif

#endif //LCNIX_SIGNAL_H
