#include <stdio.h>
#include <stdlib.h>

void main()
{
    int* p;
    p = (int*) malloc (5*sizeof(int));
    p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5;

    for (int i=0;i<5;i++)
    {
        printf("%d ",p[i]);
    }

    int* q;
    q = (int*) malloc (10*sizeof(int));

    for (int i=0;i<5;i++)
    {
        q[i]=p[i]+1;
    }
    printf("\n");
    for (int i=0;i<10;i++)
    {
        printf("%d ",q[i]);
    }
    free(p);
    p=q;
    q=NULL;
    printf("\n");
    for (int i=0;i<5;i++)
    {
        printf("%d ",p[i]);
    }
    


}