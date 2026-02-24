#include <stdio.h>
#include <stdlib.h>

void destroy(int **ptr)
{
    free(*ptr);
    *ptr = NULL;
}

int main ()
{
    int n = 0;
    int capacity = 10;

    int *ptr = (int*)malloc(sizeof(int) * capacity);
    if (ptr == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (i >= capacity)
        {
            int new_capacity = capacity * 2;

            int *temp = (int*)realloc(ptr, sizeof(int) * new_capacity);
            if (temp == NULL)
            {
                printf("realloc failed\n");
                destroy(&ptr);
                return 1;
            }

            ptr = temp;
            capacity = new_capacity;
        }

        ptr[i] = i + 100;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d element is %d\n", i, ptr[i]);
    }

    destroy(&ptr);
    destroy(&ptr);

    return 0;
}