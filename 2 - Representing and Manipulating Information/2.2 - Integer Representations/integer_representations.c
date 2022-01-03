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

void show_nonintuitive_expressions() {
    // Practice Problem 2.21: Expressions with signed and unsigned
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

/* Practice Problem 2.22: Sign extension for B2T
Formula for sign extension if everything from the left is ones is to take the rightmost from the contiguous ones and use that as the most significant bit
100 = 4
1100 = 4
11100 = 4
111100 = 4
*/

/* Practice Problem 2.23: bit shifts and extensions on 32-bit machine
int fun1(unsigned word) {
    return (int)((word << 24) >> 24);
}
int fun2(unsigned word) {
    return ((int)word << 24) >> 24;
}

a. 

Hex             fun1            fun2

0x00000076      0x00000076      0x00000076 // 7 = 0111 --> when shifted, significant bits aren't extended
0x87654321      0x00000021      0x00000021 // 2 = 0010
0x000000C9      0x000000C9      0xFFFFFFC9 // C = 1100 --> significant bits are extended since sign is 1
0xEDCBA987      0x00000087      0xFFFFFF87 // 8 = 1000

b. fun1 keeps everything unsigned until the end so sign extension isn't used since it only works for B2T while fun2 casts word as an int before it's shifted
which is why the significant bits are extended

*/

/* Practice Problem 2.24: Truncation of 4 bits to 3 bits

Hex                         Unsigned                    Two's Complement

Original    Truncated       Original    Truncated       Original    Truncated
1           1               1           1               1           1
3           3               3           3               3           3
5 (0101)    5 (5 mod 8)     5           5               5           -3
C (1100)    4 (12 mod 8)    12          4               -4          -4
E (1110)    6 (14 mod 8)    14          6               -2          -2

When truncating unsigned integers, we simply find the number mod 2^3. 
For signed integers, we convert the number to an unsigned integer mod 2^k then we convert it to two's complement
*/

int main()
{
    show_nonintuitive_expressions();
    return 0;
}