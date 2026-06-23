#include <stdint.h>

void switch_error(const char* func, uint32_t pc, uint32_t info)
{
    (void)func;
    (void)pc;
    (void)info;

#ifdef DEBUG
    // crash intentionally so you catch bad switch cases
    volatile int* bad = (int*)0;
    *bad = 0;
#endif

    // release builds just halt safely (optional)
    for (;;);
}