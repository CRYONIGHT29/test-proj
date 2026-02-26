#include <stdio.h>
#include <stdint.h>


void print_binary(uint32_t x) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (x >> i) & 1u);
        if (i % 4 == 0) printf(" ");
    }
}

void display(uint32_t x) {
    printf("Decimal : %u\n", x);
    printf("Binary  : ");
    print_binary(x);
    printf("\n");
}

unsigned count_ones(uint32_t x) {
    unsigned count = 0;

    while (x) {
        x &= (x - 1);
        count++;
    }

    return count;
}

int main() {
    uint32_t x;

    printf("Enter a 32-bit unsigned integer: ");
    if (scanf("%u", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\n      INPUT \n");
    display(x);

    unsigned ones = count_ones(x);

    printf("\nNumber of 1 bits: %u\n", ones);

    return 0;
}