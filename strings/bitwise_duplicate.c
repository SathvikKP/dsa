#include <stdio.h>

int main()
{
    char a[]="lots of duplicates in this string";
    long int H=0,x=0;
    for (int i=0;a[i]!='\0';i++)
    {
        //printf("%c",a[i]);
        x=1;
        //printf(" %d ",x);
        x=x<<(a[i]-97);
        //printf(" %d ",x);
        //printf(" AND with H: %d ",x&H);
        if ((x&H)>0) //important to put paranthesis  !!!!! 
        {
            printf("%c duplicate found \n",a[i]);
        }
        else
        {
            H=H|x;
            //printf(" H MOD %d ",H);
        }
        //printf("\n");
    }
    return 0;
}