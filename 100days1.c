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
    int pos,x;
    printf("Enter position to insert");
    scanf("%d",&pos);
    printf("Enter element to insert");
    scanf("%d",&x);
    for (int i=n;i>=pos;i--)
    {
        a[i]=a[i-1];
    }
    a[pos-1]=x;
    printf("Updated array:\n");
    for (int i=0;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}
