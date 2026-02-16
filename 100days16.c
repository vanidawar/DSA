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
    for (int i=0;i<n;i++) 
    {
        int count=1;
        if (a[i]==-1)
        {
            continue;
        }
        for (int j=i+1;j<n;j++) 
        {
            if (a[i]==a[j]) 
            {
                count++;
                a[j]=-1;
            }
        }
        printf("%d:%d ",a[i], count);
    }

}