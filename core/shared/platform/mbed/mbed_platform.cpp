/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "mbed.h"
#include "platform_api_vmcore.h"

/**
 *  Not needed right now as this is mandatory 
 *  if app-mgr and app-framework are needed
 */
// #include "platform_api_extension.h"

/****************************************************
 *                     Section 1                    *
 *        Interfaces required by the runtime        *
 ****************************************************/

int
bh_platform_init()
{
    return 0;
}

void
bh_platform_destroy()
{}

/**
 ******** memory allocator APIs **********
 */

/**
 * WAMR Runtime in MBed currently cannot be initialized 
 * with Alloc_With_System_Allocator.
 * Use:
 * init_args.mem_alloc_type = Alloc_With_Pool;
 */

void *
os_malloc(unsigned size)
{
    return NULL;
}

void *
os_realloc(void *ptr, unsigned size)
{
    return NULL;
}

void
os_free(void *ptr)
{}


/**
 * Time
 */
uint64
os_time_get_boot_microsecond()
{
    return Kernel::get_ms_count();
}

/**
 * Threads
 */
korp_tid
os_self_thread()
{
    return ThisThread::get_id();
}

/**
 * Needed for runtime native stack overflow check
 */
uint8 *
os_thread_get_stack_boundary()
{
    return NULL;
}

/**
 * Mutex APIs
 */

int
os_mutex_init(korp_mutex *pointer)
{
    korp_mutex mutex = (void *)new Mutex();
    *pointer = mutex;
    if (mutex != NULL) {
        return BHT_OK;
    }
    return -1;
}

int
os_mutex_destroy(korp_mutex *pointer)
{
    korp_mutex mutex = *pointer;
    delete (Mutex *)mutex;
    return 0;
}

int
os_mutex_lock(korp_mutex *pointer)
{
    Mutex *mutex = (Mutex *)(*pointer);
    mutex->lock();
    return BHT_OK;
}

int
os_mutex_unlock(korp_mutex *pointer)
{
    Mutex *mutex = (Mutex *)(*pointer);
    mutex->unlock();
    return BHT_OK;
}

/**************************************************
 *                    Section 2                   *
 *            APIs required by WAMR AOT           *
 *          Not implemented yet for MBed          *
 **************************************************/

void *
os_mmap(void *hint, size_t size, int prot, int flags)
{
    return NULL;
}
void
os_munmap(void *addr, size_t size)
{}

int
os_mprotect(void *addr, size_t size, int prot)
{
    return NULL;
}

void
os_dcache_flush()
{}