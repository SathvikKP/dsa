#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[10] = {6,3,8,10,16,7,5,2,9,14};

    for (int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    int k=10;
    int H[30]={0};
    for (int i=0;i<10;i++)
    {
        if ((k-a[i])>=0 && H[k-a[i]]!=0)
        {
            printf("%d and %d \n",a[i],k-a[i]);
        }
        H[a[i]]++;
    }

    int b[10] = {1,3,4,5,6,8,9,10,12,14};
    printf("\n");
    for (int i=0;i<10;i++)
    {
        printf("%d ",b[i]);
    }
    int i=0,j=9;printf("\n");
    while(i<j)
    {
        if (b[i]+b[j]==k)
        {
            printf("%d and %d\n",b[i],b[j]);
            i++;j--;
        }
        else if (b[i]+b[j]<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }


    return 0;
}