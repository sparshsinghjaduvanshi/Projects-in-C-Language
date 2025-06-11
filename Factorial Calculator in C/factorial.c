#include <stdio.h>

long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{

    int n;
    long long result;
    printf("Enter the value of n : ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("\nERROR invalid input.\n");
    }
    else
    {
        result = factorial(n);
        printf("The factorial of %d! is : %lld", n, result);
    }

    return 0;
}