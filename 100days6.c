#include <stdio.h>
int main()
{
    int n;
    printf("enter length of array");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        printf("enter element");
        scanf("%d",&a[i]);
    }
    printf("%d\t",a[0]);
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=a[i-1])
        {
            printf("%d\t",a[i]);
        }
    }
}