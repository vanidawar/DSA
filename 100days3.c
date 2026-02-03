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
    int k;
    printf("enter key to search");
    scanf("%d",&k);
    int index,comp;
    for (int i=0;i<n;i++)
    {
        if (a[i]==k)
        {
            index=i;
            break;
        }
        comp+=1;
    }
    printf("Found at index:%d\n",index);
    printf("comparisons=%d",comp);
}