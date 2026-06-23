#pragma once
#define _itoa n64_itoa
#define log n64_log
#include "compat.h"
#include "n64_types.h"
#include <stdint.h>
#include <stdlib.h>
#include "recomp.h"

#ifdef log
#undef log
#endif

#include <math.h>

// --- basic runtime stubs ---
void __recomp_assert_fail(const char* msg);
#define recomp_assert(x) if (!(x)) __recomp_assert_fail(#x)

// --- memory helpers (stubbed for now) ---
extern uint8_t* g_memory_base;