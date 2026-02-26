#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i=0;
    int *ptr = (int*)malloc(sizeof(int)*10);
    if (ptr==NULL)
    {
        printf("malloc failed\n");
    }
    
    for ( i = 0; i < 10; i++)
    {
        ptr[i]=i+100;
    }
    
    for ( i = 0; i < 10; i++)
    {
        printf("%d element is %d\n ", i, ptr[i]);
    }
    free(ptr);
    ptr=NULL;
}
