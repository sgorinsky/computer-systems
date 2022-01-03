#include <stdio.h>
#include <stdbool.h>

/* Practice 2.17: Convert between Hexadecimal, binary, B2U, B2T

Hexadecimal Binary B2U B2T

0xA         1010   10  -6
0x1         0001   1   1
0xB         1011   11  -5
0x2         0010   2   2
0x7         0111   7   7
0xC         1100   12  -4
*/

/* Practice 2.19: T2U of 4-bit integers

x  T2U

-1  15
-5  11  
-6  10
-4  12
1   1
8   8
*/

typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start, size_t len) { // pointer to array of start bytes
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]); // displays 2 digit hex representation of address of ith index of bytes array
    }
    printf(" (little endian)\n");
}

// Practice Problem 2.21: Expressions with signed and unsigned
void show_nonintuitive_expressions() {
    // Type   Evaluation (1 is true, 0 is false)
    int first = -2147483647 - 1 == 2147483648U;  // unsigned 1
    printf("-2147483647 - 1 == 2147483648U is %x\n", first);

    int second = -2147483647 - 1 < 2147483647; // signed 1
    printf("-2147483647 - 1 < 2147483647 is %x\n", second);

    int third = -2147483647 - 1U < 2147483647; // unsigned 0
    printf("-2147483647 - 1U < 2147483647 is %x\n", third);

    int fourth = -2147483647 - 1 < -2147483647; // signed 1
    printf("-2147483647-1 < -2147483647 is %x\n", fourth);

    int fifth = -2147483647 - 1U < -2147483647; // unsigned 1
    printf("-2147483647 - 1U < -2147483647 is %x\n", fifth);

    short sx = -12345; /* -12345 */
    unsigned uy = sx;  // first converted to int then unsigned due to c conventions -> (unsigned) (int) sx (instead of (unsigned) (unsigned short))
    printf("uy = %u: ", uy);
    show_bytes((byte_pointer) &uy, sizeof(typeof(uy)));
}

int main() {
    show_nonintuitive_expressions();
    return 0;
}