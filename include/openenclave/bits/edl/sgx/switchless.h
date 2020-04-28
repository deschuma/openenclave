// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#ifndef _OE_EDL_SWITCHLESS_H
#define _OE_EDL_SWITCHLESS_H

#include <openenclave/bits/defs.h>
#include <openenclave/bits/types.h>

// This function cannot be defined in EDL because it uses volatile
// members
typedef struct _host_worker_context
{
    volatile void* call_arg;
    oe_enclave_t* enclave;
    volatile bool is_stopping;

    volatile int32_t event;

    // Number of times the worker spun without seeing a message.
    uint64_t spin_count;

    // Statistics.
    uint64_t total_spin_count;
} oe_host_worker_context_t;

typedef struct _enclave_worker_context
{
    volatile void* call_arg;
    oe_enclave_t* enclave;
    volatile bool is_stopping;

    volatile int32_t event;

    // Number of times the worker spun without seeing a message.
    uint64_t spin_count;

    // The limit at which to stop spinning and return to host to sleep.
    uint64_t spin_count_threshold;

    // Statistics.
    uint64_t total_spin_count;
} oe_enclave_worker_context_t;

#endif
