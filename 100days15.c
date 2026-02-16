#include <stdio.h>
int main() 
{
    int m,n;
    printf("Enter matrix size");
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++) 
    {
        for(int j=0;j<n;j++) 
        {
            printf("Enter element");
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<m && i<n;i++) 
    {
        sum+=a[i][i];
    }
    printf("%d",sum);
}
