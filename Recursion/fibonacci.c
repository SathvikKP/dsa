#include <stdio.h>

int fib(int n)
{
    if (n<=1) return n;
    int t0=0,t1=1,s;
    for (int i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

int rfib(int n)
{
    if (n<=1)
    {
        return n;
    }
    else
    {
        return rfib(n-1)+rfib(n-2);
    }
}

int F[11];

int mfib(int n)
{
    if (n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if (F[n-2]==-1)
        {
            F[n-2]=mfib(n-2);
        }
        if (F[n-1]==-1)
        {
            F[n-1]=mfib(n-1);
        }
        F[n]= F[n-2]+F[n-1];
        return F[n];
    }
}


int main()
{
    for (int i=0;i<10;i++)
    {
        F[i]=-1;
    }
    printf("%d %d \n",fib(5),fib(10));
    printf("%d %d \n",rfib(5),rfib(10));
    printf("%d %d \n",mfib(5),mfib(10));
    return 0;
}