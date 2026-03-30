#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int dq[MAX];
int f=-1,r=-1;
int empty() {
    return (f==-1);
}
int full() {
    return ((f==0 && r==MAX-1) || (f==r+1));
}
void push_front(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        f=r=0;
    }
    else if (f==0) {
        f=MAX-1;
    }
    else {
        f--;
    }
    dq[f]=x;
}
void push_back(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        f=r=0;
    }
    else if (r==MAX-1) {
        r=0;
    }
    else {
        r++;
    }
    dq[r]=x;
}
void pop_front() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }
    if (f==r) {
        f=r=-1;
    }
    else if (f==MAX-1) {
        f=0;
    }
    else {
        f++;
    }
}
void pop_back() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }
    if (f==r) {
        f=r=-1;
    }
    else if (r==0) {
        r=MAX-1;
    }
    else {
        r--;
    }
}
int front() {
    if (empty()) return -1;
    return dq[f];
}
int back() {
    if (empty()) return -1;
    return dq[r];
}
int size() {
    if (empty()) return 0;
    if (r>=f) return r-f+1;
    return MAX-f+r+1;
}
void display() {
    if (empty()) {
        printf("Empty\n");
        return;
    }
    int i=f;
    while (1) {
        printf("%d ",dq[i]);
        if (i==r) break;
        i=(i+1)%MAX;
    }
    printf("\n");
}
void clear() {
    f=r=-1;
}