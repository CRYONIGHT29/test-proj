#include <stdio.h>
struct student{
    char name[32];
    int roll_no; 
    float cgpa;
};


int main()
{
    int n = 0, int i = 0;
    printf("Enter the number of students\n");
    scanf("%d", &n);

    struct student s[n];
    

    for (i=0; i<n-1; i++)
        {
            printf("Enter the name for student %d \n", i+1);
            printf("Name: ");
            scanf("%s", s[i].name);
            printf("Roll No: ");
            scanf("%d", &s[i].roll_no);
            printf("CGPA: ");
            scanf("%f", &s[i].cgpa)
        }
    printf("The details of the students are: \n");
    for (i=0; i<n-1; i++)        {
            printf("Name: %s \n", s[i].name);
            printf("Roll No: %d \n", s[i].roll_no);
            printf("CGPA: %.2f \n", s[i].cgpa);
        }
}
