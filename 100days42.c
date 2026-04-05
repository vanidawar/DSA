#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int queue[MAX];
int front = 0, rear = -1;
int stack[MAX];
int top = -1;
void enqueue(int x) {
    queue[++rear] = x;
}
int dequeue() {
    return queue[front++];
}
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }
    for (int i = 0; i < N; i++) {
        push(dequeue());
    }
    for (int i = 0; i < N; i++) {
        enqueue(pop());
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}