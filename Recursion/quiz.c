#include <stdio.h>

int f(int n)
{
    static int i=1;
    if (n>=5) return n;
    n = n+i;
    i++;
    return f(n);
}

int fun(int n)
{
    int x=1,k;
    if (n==1) return x;
    for (k=1;k<n;++k)
    {
        x = x + fun(k) * fun(n-k);
    }
    return x;
}

void main()
{
    printf("%d \n",f(1));
    printf("%d \n",fun(5));
}