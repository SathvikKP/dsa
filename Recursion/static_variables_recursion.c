#include <stdio.h>

int sum(int n)
{
    static int x=0;
    if (n>0)
    {
        x++;
        return sum(n-1)+x;
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