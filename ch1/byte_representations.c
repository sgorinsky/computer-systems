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

int main() {
    test_show_bytes(12345);
    return 0;
}
