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

uint32_t rotl(uint32_t x, unsigned k) {
    k &= 31;  // ensure 0–31
    return (x << k) | (x >> ((32 - k) & 31));
}

uint32_t rotr(uint32_t x, unsigned k) {
    k &= 31;  // ensure 0–31
    return (x >> k) | (x << ((32 - k) & 31));
}

int main() {
    uint32_t x;
    int choice;
    unsigned k;

    printf("Enter an unsigned integer: ");
    if (scanf("%u", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nChoose operation:\n");
    printf("1. Rotate Left\n");
    printf("2. Rotate Right\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nEnter rotate amount: ");
    if (scanf("%u", &k) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\n      BEFORE\n");
    display(x);

    uint32_t result;

    switch (choice) {

        case 1:
            printf("\nOperation: Rotate Left by %u\n", k);
            result = rotl(x, k);
            break;

        case 2:
            printf("\nOperation: Rotate Right by %u\n", k);
            result = rotr(x, k);
            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("\n      AFTER\n");
    display(result);

    return 0;
}