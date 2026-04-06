#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    Node* root = createNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}
void zigzag(Node* root) {
    if (!root) return;
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int leftToRight = 1;
    while (front < rear) {
        int size = rear - front;
        int level[size];
        for (int i = 0; i < size; i++) {
            Node* curr = queue[front++];
            level[i] = curr->data;
            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
        }
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    Node* root = buildTree(arr, n);
    zigzag(root);
}