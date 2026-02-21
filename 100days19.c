#include <stdio.h>
int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int min=arr[0]+arr[1];
    int x=arr[0],y=arr[1];
    for (int i=0;i<n;i++) 
    {
        for (int j=i+1;j<n;j++) 
        {
            int sum=arr[i]+arr[j];
            if ((sum<0?-sum:sum)<(min<0?-min:min)) 
            {
                min=sum;
                x=arr[i];
                y=arr[j];
            }
        }
    }
    printf("%d %d", x, y);
}