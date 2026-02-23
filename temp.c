#include <stdio.h>
#include <string.h>
#include

//calculate string length
void my_strlen(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    printf("Length (my_strlen) = %d\n", i);
}

//copy string
void my_strcpy(char dest[], char src[])
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';   // Null termination

    printf("Copied string (my_strcpy) = %s\n", dest);
}

//Function to compare two strings
int my_strcmp(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            break;
        i++;
    }

    int result = str1[i] - str2[i];
    if (result > 0)
        {
        printf("str1 is greater than str2\n");
        }
    else if (result < 0)
        {
        printf("str2 is greater than str1\n");
        }
    else
        {
        printf("Strings are same\n");
        }
    printf("Result is %d\n", result);
    return result;
}


//Function to reverse string
void my_strrev(char str[])
{
    int i = 0, len = 0;
    char temp;

    /* Find length */
    while (str[len] != '\0')
        len++;

    len--;  // Last index

    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;

        i++;
        len--;
    }

    printf("Reversed string (my_strrev) = %s\n", str);
}

int main()
{
    char str[100];
    char copy[100];
    char str2[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    my_strlen(str);
    my_strcpy(copy, str);


    printf("\nEnter another string for comparison: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    my_strcmp(str, str2);
    my_strrev(str);
    return 0;
}