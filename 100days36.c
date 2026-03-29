#include <stdio.h>
#define MAX 100
int q[MAX];
int front=-1,rear=-1;
void enqueue(int x) {
    if ((rear+1)%MAX==front) {
        return;
    }
    if (front==-1) front=0;
    rear=(rear+1)%MAX;
    q[rear]=x;
}
void dequeue() {
    if (front==-1) return;
    if (front==rear) {
        front=rear=-1;
    } else {
        front=(front+1)%MAX;
    }
}
void display() {
    if (front==-1) return;
    int i=front;
    while (1) {
        printf("%d ",q[i]);
        if (i==rear) break;
        i=(i+1)%MAX;
    }
}
int main() {
    int n,x,m;
    scanf("%d",&n);
    for (int i=0; i<n;i++) {
        scanf("%d",&x);
        enqueue(x);
    }
    scanf("%d", &m);
    for (int i=0; i<m;i++) {
        dequeue();
    }
    display();
}