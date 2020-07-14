#include <stdio.h>

int sum(int n)
{
    if (n>0)
    {
        return sum(n-1)+n;
    }
    return 0;
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d \n",sum(x));
    return 0;
}