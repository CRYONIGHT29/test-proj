#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int roll;
    float cgpa;
} Student;

void clear_input()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int cmp_roll(const void *a, const void *b)
{
    const Student *s1 = a;
    const Student *s2 = b;
    return s1->roll - s2->roll;
}

int cmp_name(const void *a, const void *b)
{
    const Student *s1 = a;
    const Student *s2 = b;
    return strcmp(s1->name, s2->name);
}

int cmp_cgpa(const void *a, const void *b)
{
    const Student *s1 = a;
    const Student *s2 = b;

    if (s1->cgpa < s2->cgpa) return -1;
    if (s1->cgpa > s2->cgpa) return 1;
    return 0;
}

int main()
{
    int n;

    while (1) {
        printf("Enter number of students: ");
        if (scanf("%d", &n) == 1 && n > 0)
            break;

        printf("Invalid input. Enter a positive integer.\n");
        clear_input();
    }

    Student s[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);

        while (1) {
            printf("Enter name: ");
            if (scanf("%31s", s[i].name) == 1)
                break;

            printf("Invalid input. Enter a valid name.\n");
            clear_input();
        }

        // Roll number validation 
        while (1) {
            int duplicate = 0;

            printf("Enter roll number: ");
            if (scanf("%d", &s[i].roll) != 1) {
                printf("Invalid input. Enter integer only.\n");
                clear_input();
                continue;
            }

            if (s[i].roll <= 0) {
                printf("Roll number must be positive.\n");
                continue;
            }

            for (int j = 0; j < i; j++) {
                if (s[j].roll == s[i].roll) {
                    printf("Roll number already exists.\n");
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate)
                break;
        }

        //CGPA validation
        while (1) {
            printf("Enter CGPA (0 - 10): ");
            if (scanf("%f", &s[i].cgpa) != 1) {
                printf("Invalid input. Enter decimal number only.\n");
                clear_input();
                continue;
            }

            if (s[i].cgpa < 0 || s[i].cgpa > 10) {
                printf("CGPA must be between 0 and 10.\n");
                continue;
            }

            break;
        }
    }

    int choice;

    while (1) {
        printf("\nChoose sorting option:\n");
        printf("1. Sort by Roll\n");
        printf("2. Sort by Name\n");
        printf("3. Sort by CGPA\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 3)
            break;

        printf("Invalid choice. Enter 1, 2 or 3.\n");
        clear_input();
    }

    if (choice == 1)
        qsort(s, n, sizeof(Student), cmp_roll);
    else if (choice == 2)
        qsort(s, n, sizeof(Student), cmp_name);
    else
        qsort(s, n, sizeof(Student), cmp_cgpa);

    printf("\n--- Sorted Results ---\n");
    for (int i = 0; i < n; i++)
        printf("%s | Roll: %d | CGPA: %.2f\n",
               s[i].name, s[i].roll, s[i].cgpa);

    return 0;
}
