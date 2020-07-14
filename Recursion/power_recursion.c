#include <stdio.h>

int power1(int m,int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return power1(m,n-1)*m;
    }
    
}

int power2(int m,int n)
{
    if (n==0)
    {
        return 1;
    }
    else if (n%2==0)
    {
        return power2(m*m,n/2);
    }
    else
    {
        return power2(m*m,(n-1)/2)*m;
    }
}

void main()
{
    int m=4,n=4;
    printf("%d\n",power1(m,n));
    printf("%d\n",power2(m,n));
}