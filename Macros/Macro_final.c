#include <stdio.h>

#define SWAP(a, b, type)          \
do {                              \
    type temp = (a);              \
    (a) = (b);                    \
    (b) = temp;                   \
} while(0)

int main()
{
    int choice;

    printf("Select data type:\n");
    printf("1. int\n");
    printf("2. double\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            int x, y;

            printf("Enter two integer values: ");
            scanf("%d %d", &x, &y);

            printf("Before swap: x = %d, y = %d\n", x, y);
            SWAP(x, y, int);
            printf("After swap:  x = %d, y = %d\n", x, y);

            break;
        }

        case 2:
        {
            double p, q;

            printf("Enter two double values: ");
            scanf("%lf %lf", &p, &q);

            printf("Before swap: p = %.2lf, q = %.2lf\n", p, q);
            SWAP(p, q, double);
            printf("After swap:  p = %.2lf, q = %.2lf\n", p, q);

            break;
        }

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}