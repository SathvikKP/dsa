#include <stdio.h>
#include <stdlib.h>

int main()
{
    int** A; int m,n;
    printf("Enter array size (m,n) : ");scanf("%d%d",&m,&n);printf("\n");
    A = (int** ) malloc (m*sizeof(int*));
    for (int i=0;i<m;i++)
    {  
        A[i] = (int*) malloc (n*sizeof(int));
        //*(A+i)
    }

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    return 0;
}