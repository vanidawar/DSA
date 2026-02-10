#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    printf("Enter a lowercase string to check");
    scanf("%s",str);
    int len;
    len=strlen(str);
    for(int i=0,j=len-1;i<j;i++,j--) 
    {
        if (str[i]!=str[j]) 
        {
            printf("NO");
            break;
        }
        else
        {
            printf("YES");
            break;
        }
    }
}