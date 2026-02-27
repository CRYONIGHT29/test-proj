#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int roll;
    float cgpa;
} Student;

/* ---- Comparators ---- */

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

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    Student s[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter name: ");
        scanf("%31s", s[i].name);

        /* ---- Roll number validation ---- */
        int duplicate;
        do {
            duplicate = 0;
            printf("Enter roll number: ");
            scanf("%d", &s[i].roll);

            for (int j = 0; j < i; j++) {
                if (s[j].roll == s[i].roll) {
                    printf("Error: Roll number already exists. Enter again.\n");
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);

        /* ---- CGPA validation ---- */
        do {
            printf("Enter CGPA (0 - 10): ");
            scanf("%f", &s[i].cgpa);

            if (s[i].cgpa < 0 || s[i].cgpa > 10)
                printf("Error: CGPA must be between 0 and 10.\n");

        } while (s[i].cgpa < 0 || s[i].cgpa > 10);
    }

    printf("\nChoose sorting option:\n");
    printf("1. Sort by Roll\n");
    printf("2. Sort by Name\n");
    printf("3. Sort by CGPA\n");
    printf("Enter choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1)
        qsort(s, n, sizeof(Student), cmp_roll);
    else if (choice == 2)
        qsort(s, n, sizeof(Student), cmp_name);
    else if (choice == 3)
        qsort(s, n, sizeof(Student), cmp_cgpa);
    else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("\n--- Sorted Results ---\n");
    for (int i = 0; i < n; i++)
        printf("%s | Roll: %d | CGPA: %.2f\n",
               s[i].name, s[i].roll, s[i].cgpa);

    return 0;
}