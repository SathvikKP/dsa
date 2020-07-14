#include <stdio.h>

double e_taylor(int x, int n)
{
    static double p=1,f=1;
    double result;
    if (n==0)
    {
        return 1;
    }
    else
    {
        result=e_taylor(x,n-1);
        p=p*x;
        f=f*n;
        return result+p/f;
    }
    
}

double new_taylor(int x,int n)
{
    static double s;

    if (n==0)
    {
        return s;
    }
    s=1+(x*s)/n; //equivalent to (x/n)*s but for type conversion to double, uncommented one is correct
    return new_taylor(x,n-1);


}

double iter_taylor(int x,int n)
{
    double result=1,numerator=1,denominator=1;
    for (int i=0;i<n;i++)
    {
        numerator*=x;
        denominator*=(i+1);
        result+=numerator/denominator;
    }
    return result;
}

void main()
{
    printf("%f \n",e_taylor(1,10));
    printf("%f \n",new_taylor(1,10));
    printf("%f \n",iter_taylor(1,10));
}