#include <stdio.h>

// Problem 2.27: Determine if two unsigned ints can be added without overflow
int uadd_ok(unsigned int x, unsigned int y) {
    unsigned int difference = __UINT32_MAX__ - x;
    return y <= difference;
}

int main() {
    unsigned int x = 0xFF000000;
    printf("can add %d\n", uadd_ok(0xFFFFFF00, 0xFF));
    
    return 0;
}