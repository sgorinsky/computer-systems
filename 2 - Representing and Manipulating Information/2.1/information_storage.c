#include <stdio.h>

typedef unsigned char* byte_pointer; // creates a new type that is a pointer to a variable

void show_bytes(byte_pointer start, size_t len) { // pointer to array of start bytes
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]); // displays 2 digit hex representation of address of ith index of bytes array
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((unsigned char*) &x, sizeof(int));
}
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x) {
    show_bytes((unsigned char*) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void show_binary(int val) {
    int ival = val;
    const int int_length = sizeof(int) * 8; // sizeof yields answer in bytes
    int bits[int_length] = { 0 };
    int idx = int_length - 1;
    while (ival > 0) {
        bits[idx--] = ival & 1;
        ival >>= 1;
    }

    for (int i = 0; i < int_length; i += 2) {
        printf("%.1x%.1x", bits[i], bits[i+1]);
    }
    printf("\n");
}

// Problem 2.10
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; // Step 1: x = x; y = x ^ y
    *x = *x ^ *y; // Step 2: x = x ^ x ^ y; y = x ^ y
    *y = *x ^ *y; // Step 3: x = x ^ x ^ y -> y; y = x ^ x ^ y ^ x ^ y -> x
}

/* Problem 2.11

a. In final iteration of array, first and last both reference middle element of odd-length array
b. inplace_swap sets middle element to 0 because xor-ing an element with itself is 0, so y becomes 0 on the first step
   and x becomes y on the last step
c. If we set the break condition to first < last instead of first <= last, this will work for all arrays
*/
void reverse_array(int a[], int cnt) {
    for (int first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

void print_array(int a[], int cnt) {
    for (int i = 0; i < cnt; ++i) {
        printf(" %x ", a[i]);
    }
    printf("\n");
}

// Problem 2.12
void show_least_significant_bytes(int n, int w) {
    int least_significant_byte = 0x0;
    for (int i = 0; i < w; ++i) {
        least_significant_byte <<= 4;
        least_significant_byte |= 0xFF;
    }

    int res = n & least_significant_byte;
    printf("%x\n", res);
}

void show_complement_bytes_except_last_two(int n) {
    int complement = n ^ 0xFFFFFF00;
    printf("%x\n", complement);
}

void show_least_significant_byte_as_ones(int n) {
    int res = n | 0x000000FF; // left of last two bytes remains unchanged
    printf("%x\n", res);
}

// Problem 2.13
/* Declarations of functions implementing operations bis and bic */
// int bis(int x, int m); // setting z to 1 at each place m is 1 -> x | m
// int bic(int x, int m); // setting z to 0 at each place m is 1 -> x & ~m

// /* Compute x|y using only calls to functions bis and bic */
// int bool_or(int x, int y) {
//     int result = bis(x, y);
//     return result;
// }

// /* Compute x^y using only calls to functions bis and bic */
// int bool_xor(int x, int y) {
//     int result = bis(bic(x, y), bic(y, x));
//     return result;
// }

void main() {
    /* Problem 2.5

    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a; 
    show_bytes(ap, 1); // A
    show_bytes(ap, 2); // B
    show_bytes(ap, 3); // C

    Little Endian; Big Endian
    A: 78; 12
    B: 78 56; 12 34
    C: 78 56 34; 12 34 56
    */
    test_show_bytes(0x12345678);

    /* Problem 2.6 

    a.
    Base-10, Hex, Binary
    2607352, 0x0027C8F8, 1001111100100011111000
    3510593.0, 0x4A1F23E0, 01001010000111110010001111100000

    b. 29 matching bits

    c. beginning and end don't match
    */

    show_binary(0x4A1F23E0);

    /* Problem 2.7

    Result of:
    const char *m = "mnopqr";
    show_bytes((byte_pointer)m, strlen(m));

    strings are more platform independent:
    --> 6d 6e 6f 70 71 72 00
    -->  m   n   o   p   q   r   (terminating byte)
    --> 109 110 111 112 113 114 000
    */
    const char *m = "mnopqr";
    const m_length = 7;
    show_bytes((byte_pointer) m, m_length);


    // Problem 2.11 Cont.
    int nums[5] = { 1, 2, 3, 4, 5 };
    print_array(nums, 5);
    reverse_array(nums, 5);
    print_array(nums, 5);

    // Problem 2.12: Masking Operations
    show_least_significant_bytes(0x87654321, 1); // Least significant byte
    show_complement_bytes_except_last_two(0x87654321); // Complement of n except last two bytes
    show_least_significant_byte_as_ones(0x87654321); // Least significant byte set to all ones and all other bytes left unchanged
}


