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
    int pos;
    printf("enter 1-based position to delete element:");
    scanf("%d",&pos);
    for (int i=pos-1;i<n-1;i++) 
    {
        a[i]=a[i+1];
    }
    for (int i=0;i<n-1;i++) 
    {
        printf("%d\t",a[i]);
    }
}