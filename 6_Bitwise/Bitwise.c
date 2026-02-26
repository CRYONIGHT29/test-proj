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

int main() {
    uint32_t x;
    int choice;
    unsigned bit;

    printf("Enter an unsigned integer: ");
    if (scanf("%u", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nChoose operation:\n");
    printf("1. Set bit\n");
    printf("2. Clear bit\n");
    printf("3. Toggle bit\n");
    printf("4. Test bit\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nEnter bit position (0-31): ");
    if (scanf("%u", &bit) != 1 || bit >= 32) {
        printf("Invalid bit position. Must be 0-31.\n");
        return 1;
    }

    printf("\n      BEFORE\n");
    display(x);

    uint32_t before = x;

    switch (choice) {

        case 1:  // Set
            x |= (1u << bit);
            printf("\nOperation: Set bit %u\n", bit);
            break;

        case 2:  // Clear
            x &= ~(1u << bit);
            printf("\nOperation: Clear bit %u\n", bit);
            break;

        case 3:  // Toggle
            x ^= (1u << bit);
            printf("\nOperation: Toggle bit %u\n", bit);
            break;

        case 4: { // Test
            unsigned result = (x >> bit) & 1u;
            printf("\nOperation: Test bit %u\n", bit);
            printf("Bit value: %u\n", result);
            printf("\n      AFTER (unchanged)\n");
            display(x);
            return 0;
        }

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("\n      AFTER\n");
    display(x);

    return 0;
}