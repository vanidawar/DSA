#include <stdio.h>
int sqr(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    return a*sqr(a,b-1);
}

int main() 
{
    int a,b;
    printf("Enter a and b");
    scanf("%d %d",&a,&b);
    printf("%d", sqr(a, b));
}
