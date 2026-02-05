#include <stdio.h>
#include <stdlib.h>
int main()
{
    int p,q;
    printf("Enter number of elements in server 1");
    scanf("%d",&p);
    int *A=(int *)malloc(p*sizeof(int));
    for(int i=0;i<p;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter number of elements in server 2");
    scanf("%d",&q);
    int *B=(int *)malloc(q*sizeof(int));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&B[i]);
    }
    int *C=(int *)malloc((p + q)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<p && j<q)
    {
        if(A[i]<=B[j])
        {
            C[k++]=A[i++];
        }
        else
        {
            C[k++]=B[j++];
        }
    }
    while (i < p)
    {
        C[k++] = A[i++];
    }
    while (j < q)
    {
        C[k++] = B[j++];
    }
    for (int i=0;i<p+q;i++)
    {
        printf("%d ", C[i]);
    }
}
