#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    printf("Enter a lowercase string to mirror");
    scanf("%s",str);
    int len;
    len=strlen(str);
    for (int i=len-1;i>=0;i--)
    {
        printf("%c",str[i]);
    }

}