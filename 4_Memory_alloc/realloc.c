#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i = 0;
    int n = 0;

    int capacity = 10;      // initial capacity
    int size = 0;

    int *ptr = (int*)malloc(sizeof(int) * capacity);
    if (ptr == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        /* Check if resize needed */
        if (n >= capacity)
        {
            int new_capacity = capacity * 2;

            int *temp = (int*)realloc(ptr, sizeof(int) * new_capacity);
            if (temp == NULL)
            {
                printf("realloc failed\n");
                free(ptr);
                ptr = NULL;
                return 1;
            }

            ptr = temp;
            capacity = new_capacity;
        }

        ptr[i] = i + 100;
        size++;
    }

    for (i = 0; i < size; i++)
    {
        printf("%d element is %d\n", i, ptr[i]);
    }

    free(ptr);
    ptr = NULL;

    return 0;
}