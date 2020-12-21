/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BH_PLATFORM_MBED
#define BH_PLATFORM_MBED
#endif

#define BH_APPLET_PRESERVED_STACK_SIZE (2 * BH_KB)

/* Default thread priority */
/* MBed's osPriorityNormal is 24 */
#define BH_THREAD_DEFAULT_PRIORITY 24

#define os_printf  printf
#define os_vprintf vprintf

typedef void *korp_tid;
typedef void *korp_mutex;
typedef void *korp_cond;
typedef void *korp_thread;

#endif