#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in array");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        printf("Enter element");
        scanf("%d",&a[i]);
    }
    for (int i=n-1;i>=0;i--)
    {
        printf("%d\t",a[i]);
    }
}