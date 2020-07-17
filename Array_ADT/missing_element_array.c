#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a;
    a = (int*)malloc(11*sizeof(int));
    a[0]=6;a[1]=7;a[2]=8;a[3]=9;a[4]=11;a[5]=12;a[6]=15;a[7]=16;a[8]=17;a[9]=18;a[10]=20;
    for (int i=0;i<11;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    int diff = a[0]-0;
    for (int i=0;i<11;i++)
    {
        if ((a[i]-i)!=diff)
        {
            while (diff<(a[i]-i))
            {
                printf("%d missing\n",i+diff);
                diff++;
            }
        }
    }
    printf("\n");
    int b[10] = {3,7,4,9,12,6,1,11,2,10};
    int l=1,h=12,n=10;
    for (int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    int H[20]={0};
    for (int i=0;i<n;i++)
    {
        H[b[i]]++;
    }
    for (int i=l;i<=h;i++)
    {
        if (H[i]==0)
        {
            printf("%d missing\n",i);
        }
    }
    
    return 0;
}