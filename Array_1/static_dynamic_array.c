#include <stdio.h>
#include <stdlib.h>

void main()
{
    int* p;
    int n;
    scanf("%d",&n);
    p = (int*)malloc(n*sizeof(int));
    printf("\nEnter elements : ");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n");
      for (int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    free(p);
}

