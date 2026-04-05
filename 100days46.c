#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* newNode(int data) {
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}
Node* buildTree(int arr[], int n) {
    if (n==0 || arr[0]==-1) return NULL;
    Node* root=newNode(arr[0]);
    Node* q[n];
    int f=0,r=0;
    q[r++]=root;
    int i=1;
    while (i<n) {
        Node* curr=q[f++];
        if (arr[i]!=-1) {
            curr->left=newNode(arr[i]);
            q[r++]=curr->left;
        }
        i++;
        if (i<n && arr[i]!=-1) {
            curr->right=newNode(arr[i]);
            q[r++]=curr->right;
        }
        i++;
    }
    return root;
}
void levelOrder(Node* root){
    if (!root) return;
    Node* q[1000];
    int f=0,r=0;
    q[r++]=root;
    while (f<r) {
        Node* curr=q[f++];
        printf("%d ",curr->data);
        if (curr->left) q[r++]=curr->left;
        if (curr->right) q[r++]=curr->right;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0; i<n;i++)
        scanf("%d",&arr[i]);
    Node* root=buildTree(arr, n);
    levelOrder(root);
}