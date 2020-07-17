#include <stdio.h>

int main()
{
    char* name = "welcome"; //int i;
    //scanf("%s",name);
    int l=0;
    for (int i=0;name[i]!='\0';i++)
    {
        l++;
    }
    printf("\nLength is : %d\n",l);

    //char s[]="welcome";
    char *s="welcome";
    
    //printf("2 pos is %c\n",s[2]);
    
    for (int i=0;s[i]!='\0';i++)
    {
        if (s[i]>='a' && s[i]<='z')
        {
            s[i]-=32;
        }
        else if (s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]+32;
        }
    }
    
    printf("\n%s\n",s);

    return 0;
}