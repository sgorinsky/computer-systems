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
}


