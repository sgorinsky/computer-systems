#include <stdio.h>

const __INT64__MIN__ = (__INT64_MAX__ << 1) + 1;
    // Problem 2.27: Determine if two unsigned ints can be added without overflow
int uadd_ok(unsigned int x, unsigned int y) {
    unsigned int difference = __UINT64_MAX__ - x;
    return y <= difference;
}

// Problem 2.30: Determine if two's complement can be added without overflow
int tadd_ok(int x, int y) {
    if (x < 0 && y < 0)
        return x + y < 0;

    if (x > 0 && y > 0)
        return x + y > 0;
    
    return 1;
}

int main() {
    printf("can we add %u + %u? %d\n", 0xFFFFFF00, 0xFF, uadd_ok(0xFFFFFF00, 0xFF));
    printf("can we add %u + %u? %d\n", 0xFFFFFF00, 0xFFF, uadd_ok(0xFFFFFF00, 0xFFF));

    printf("can we add %d + %d? %d\n", 0xFFFFFF00, 0xFF, tadd_ok(0xFFFFFF00, 0xFF));
    printf("can we add %d + %d? %d\n", 0xF0F00000, 0xF0000FFF, tadd_ok(0xFFFFFF00, 0xFFF));

    return 0;
}