#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int heap[MAX];
int size = 0;
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
int parent(int i) {
    return (i-1)/2;
}
int left(int i) {
    return 2*i+1;
}
int right(int i) {
    return 2*i+2;
}
void bubbleUp(int i) {
    while (i!=0 && heap[parent(i)]>heap[i]) 
    {
        swap(&heap[i],&heap[parent(i)]);
        i=parent(i);
    }
}
void insert(int key) {
    heap[size]=key;
    bubbleUp(size);
    size++;
}
void minHeapify(int i) {
    int l=left(i);
    int r=right(i);
    int smallest=i;

    if (l<size && heap[l]<heap[smallest])
        smallest=l;
    if (r<size && heap[r]<heap[smallest])
        smallest=r;

    if (smallest!=i) {
        swap(&heap[i],&heap[smallest]);
        minHeapify(smallest);
    }
}
int extractMin() {
    if (size==0)
        return -1;
    if (size==1) {
        size--;
        return heap[0];
    }

    int root=heap[0];
    heap[0]=heap[size-1];
    size--;
    minHeapify(0);
    return root;
}
int peek() {
    if (size==0)
        return -1;
    return heap[0];
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        char command[20];
        int val;
        scanf("%s",command);

        if (command[0]=='i') { 
            scanf("%d",&val);
            insert(val);
        } else if (command[0]=='p') { 
            printf("%d\n", peek());
        } else if (command[0]=='e') { 
            printf("%d\n", extractMin());
        }
    }

}