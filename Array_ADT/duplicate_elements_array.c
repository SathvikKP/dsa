#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[10]={3,6,8,8,10,12,15,15,15,20};

    for (int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    int last=0;
    for (int i=0;i<9;i++)
    {
        if (a[i]==a[i+1])
        {
            if (a[i]!=last)
            {
                last=a[i];
                printf("Duplicate : %d\n",last);
            }
        }
    }
    for (int i=0;i<9;i++)
    {
        if (a[i]==a[i+1])
        {
            int j = i+1;
            while(a[i]==a[j]) j++;
            printf("%d appearing %d times\n",a[i],j-i);
            i=j-1;
        }
    }
    printf("\n");
    int H[30]={0};
    for (int i=0;i<10;i++)
    {
        H[a[i]]++;
    }
    for (int i=0;i<30;i++)
    {
        if (H[i]>1)
        {
            printf("%d appearing %d times\n",i,H[i]);
        }
    }

    return 0;
}