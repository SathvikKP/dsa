#include <stdio.h>

int main()
{
    char a[]="medical";
    char b[]="decimal";
    int i=0;int H[26]={0};

    for (int i=0;a[i]!='\0';i++)
    {
        H[a[i]-'a']+=1;
    }
    for (int i=0;b[i]!='\0';i++)
    {
        H[b[i]-'a']-=1;
        if (H[b[i]-'a']<0)
        {
            printf("not anagram\n"); //scan after full for duplicates!!!
            break;
        }
    }
    if (b[i]!='\0')
    {
        printf("anagram\n");
    }
    return 0;
}