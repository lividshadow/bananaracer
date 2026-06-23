#include <stdio.h>
#include <stdlib.h>

void __recomp_assert_fail(const char* msg) {
    printf("Recomp assertion failed: %s\n", msg);
    abort();
}