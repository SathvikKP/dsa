#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
    //int A[10];
    int* A;
    int n;
};

void Set(struct Matrix* m,int i,int j,int x)
{
    if (i==j)
    {
        m->A[i-1]=x;
    }
}

int Get(struct Matrix m,int i,int j)
{
    if (i==j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }    
}

void Display(struct Matrix m)
{
    int i,j;
    for (i=0;i<m.n;i++)
    {
        for (j=0;j<m.n;j++)
        {
            if (i==j)
            {
                printf("%d ",m.A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void SetLower(struct Matrix* m,int i,int j,int x)
{
    if (i>=j)
    {
        m->A[i*(i-1)/2+j-1]=x;
    }
}

int GetLower(struct Matrix m, int i, int j)
{
    if (i>=j)
    {
        return m.A[i*(i-1)/2+j-1];
    }
    else
    {
        return 0;
    }
}

void DisplayLower(struct Matrix m)
{
    for (int i=1;i<=m.n;i++)
    {
        for (int j=1;j<=m.n;j++)
        {
            printf("%d ",GetLower(m,i,j));
        }
        printf("\n");
    }
}

int main()
{
    /*
    struct Matrix m;
    m.n=4;

    Set(&m,1,1,5);Set(&m,2,2,8);Set(&m,3,3,9);Set(&m,4,4,12);
    Display(m);
    return 0;
    */
    struct Matrix m;
    printf("Enter dimension : ");scanf("%d",&m.n);
    m.A = (int* )malloc(m.n*(m.n+1)/2*sizeof(int));

    printf("Enter all elements : \n");
    for (int i=1;i<=m.n;i++)
    {
        for (int j=1;j<=m.n;j++)
        {
            int x;
            scanf("%d",&x);
            SetLower(&m,i,j,x);
        }
        printf("\n");
    }
    printf("\n");
    DisplayLower(m);

}