#include <stdio.h>
#include <math.h>
//SEED01-260220-44548
// function for prime num
void prime(int num)
{
    int i, count = 0;

    if (num <= 1)
    {
        printf("%d is not a prime number\n", num);
        return;
    }

    for (i = 1; i <= num/2; i++)
    {
        if (num % i == 0)
            count++;
    }

    if (count == 2)
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);
}
// prime endshere

//function for perfect num
void perfect(int num)
{
    int i, sum = 0;

    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum = sum + i;
    }

    if (sum == num && num != 0)
        printf("%d is a perfect number\n", num);
    else
        printf("%d is not a perfect number\n", num);
}
//perfect num ends here

//function for armstrong num
void armstrong(int num)
{
    int digit, count = 0, sum = 0, temp;

    if (num <= 0)
    {
        printf("%d is not an Armstrong number\n", num);
        return;
    }

    temp = num;
    while (temp != 0)
    {
        temp = temp / 10;
        count++;
    }

    temp = num;
    while (temp != 0)
    {
        digit = temp % 10;
        sum = sum + pow(digit, count);
        temp = temp / 10;
    }

    if (sum == num)
        printf("%d is an Armstrong number\n", num);
    else
        printf("%d is not an Armstrong number\n", num);
}

int main()
{
    int i=0, num=0, n=0, temp=0;
    printf("Enter the number\n");
    scanf("%d", &num);
    prime(num);
    perfect(num);
    armstrong(num);
}