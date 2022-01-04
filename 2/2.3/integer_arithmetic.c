#include <stdio.h>

// Problem 2.27: Determine if two unsigned ints can be added without overflow
int uadd_ok(unsigned int x, unsigned int y) {
    unsigned int difference = __UINT64_MAX__ - x;
    return y <= difference;
}

int main() {
    unsigned int x = 0xFF000000;
    printf("can we add %u + %u? %d\n", 0xFFFFFF00, 0xFF, uadd_ok(0xFFFFFF00, 0xFF));
    printf("can we add %u + %u? %d\n", 0xFFFFFF00, 0xFFF, uadd_ok(0xFFFFFF00, 0xFFF));

    return 0;
}