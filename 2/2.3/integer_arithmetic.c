#include <stdio.h>

const __INT64_MIN__ = 0xF0000000;
// Problem 2.27: Determine if two unsigned ints can be added without overflow
int uadd_ok(unsigned int x, unsigned int y) {
    unsigned int difference = __UINT64_MAX__ - x;
    return y <= difference;
}

// Problem 2.30: Determine if two's complement can be added without overflow
int tadd_ok(int x, int y) {
    int sum = x + y;
    if (x < 0 && y < 0)
    {
        return sum < 0 && sum >= 0xF0000000; // negative overflow if result is positive
    }

    if (x > 0 && y > 0)
        return sum > 0 && sum <= 0x0FFFFFFF; // positive overflow if result is negative
    
    return 1;
}

// Problem 2.31
/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int buggy_tadd_ok(int x, int y) {
    int sum = x + y;

    return (sum - x == y) && (sum - y == x); // always successful :(
    // if x + y overflows in either direction, sum - x still == y b/c it overflows back to == y, same w sum - y == x
}

// Problem 2.32
/* Determine whether arguments can be subtracted without overflow */
/* WARNING: This code is buggy. */
int tsub_ok(int x, int y) {
    if ((x < 0 && y < 0) || (x > 0 && y > 0)) {
        return 1;
    }
    if (y == 0xF0000000) {
        if (x == 0xF0000000) {
            return 0;
        }

        return tadd_ok(y, -x);
    }

    return tadd_ok(x, -y); // will fail if y is 0xF0000000 b/c that will positive overflow to negative 1 and throw results
}

int main()
{
    printf("can we add %u + %u? %d\n", 0xFFFFFF00, 0xFF, uadd_ok(0xFFFFFF00, 0xFF));
    printf("can we add %u + %u? %d\n", 0xFFFFFF00, 0xFFF, uadd_ok(0xFFFFFF00, 0xFFF));

    printf("can we add %d + %d? %d\n", 0x0FFFFFFF, 0x0FFFF0FF, tadd_ok(0x0FFFFFFF, 0x0FFFF0FF));
    printf("can we add %d + %d? %d\n", 0xF0000000, 0xF0000000, tadd_ok(0xF0000000, 0xF0000000));

    printf("can we add %d + %d? %d\n", 0x0FFFFFFF, 0x0FFFF0FF, buggy_tadd_ok(0x0FFFFFFF, 0x0FFFF0FF));
    printf("can we add %d + %d? %d\n", 0xF0000000, 0xF0000000, buggy_tadd_ok(0xF0000000, 0xF0000000));

    printf("can we subtract %d - %d? %d\n", 0x0FFFFFFF, 0x0FFFF0FF, tsub_ok(0x0FFFFFFF, 0x0FFFF0FF));
    printf("can we subtract %d - %d? %d\n", 0x0FFFF000, 0xF0000000, tsub_ok(0x0FFFF000, 0xF0000000));

    return 0;
}