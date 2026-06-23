#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "recomp.h"
#include "n64_types.h"

// N64 has 8MB of RAM
#define N64_RAM_SIZE (8 * 1024 * 1024)

// The global memory base - all recompiled functions read/write through this
uint8_t* g_memory_base = NULL;

// Recomp context holds the emulated CPU registers
recomp_context g_ctx = { 0 };

// Forward declarations of recompiled game functions
void thread3_main(uint8_t* rdram, recomp_context* ctx);

// Stub implementations for OS functions the game expects
// These will need proper implementations later

void osInitialize(void) {
    printf("[STUB] osInitialize\n");
}

void osCreateThread(void* thread, uint32_t id, void* entry, void* arg,
    void* stack, uint8_t pri) {
    printf("[STUB] osCreateThread id=%u\n", id);
}

void osStartThread(void* thread) {
    printf("[STUB] osStartThread\n");
}

int main(int argc, char** argv) {
    printf("BananaRacer (DKR Recomp) starting...\n");

    // Allocate emulated N64 RAM
    g_memory_base = (uint8_t*)calloc(1, N64_RAM_SIZE);
    if (!g_memory_base) {
        fprintf(stderr, "Failed to allocate N64 RAM!\n");
        return 1;
    }

    printf("N64 RAM allocated: %d MB at %p\n", N64_RAM_SIZE / (1024 * 1024),
        (void*)g_memory_base);

    // Zero out the context
    memset(&g_ctx, 0, sizeof(g_ctx));

    printf("Calling thread3_main...\n");

    // Call the game's main thread
    // This will crash or hang until we stub out the OS/hardware calls it makes
    thread3_main(g_memory_base, &g_ctx);

    printf("thread3_main returned.\n");

    free(g_memory_base);
    return 0;
}