#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;
Node* newNode(int val) {
    Node* node=(Node*)malloc(sizeof(Node));
    node->val=val;
    node->left=node->right=NULL;
    return node;
}
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i<=end; i++) {
        if (inorder[i]==val)
            return i;
    }
    return -1;
}
Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start>end) return NULL;
    Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;
    if (start==end) return root;
    int inIndex=search(inorder, start, end, root->val);
    root->left=buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right=buildTree(preorder, inorder, inIndex + 1, end, preIndex);
    return root;
}
void postorder(Node* root) {
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}
int main() {
    int n;
    scanf("%d",&n);
    int preorder[n], inorder[n];
    for (int i=0; i<n; i++)
        scanf("%d", &preorder[i]);
    for (int i=0; i<n; i++)
        scanf("%d", &inorder[i]);
    int preIndex=0;
    Node* root=buildTree(preorder, inorder, 0, n - 1, &preIndex);
    postorder(root);
}