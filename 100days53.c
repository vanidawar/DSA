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
typedef struct {
    Node* node;
    int hd;
} Pair;
void verticalOrder(Node* root) {
    if (!root) return;
    Pair queue[1000];
    int front = 0, rear = 0;
    int map[2000][100]; 
    int count[2000] = {0};
    int offset = 1000; 
    queue[rear++] = (Pair){root, 0};
    int minHD = 0, maxHD = 0;
    while (front < rear) {
        Pair p = queue[front++];
        Node* curr = p.node;
        int hd = p.hd;
        map[hd + offset][count[hd + offset]++] = curr->data;
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
        if (curr->left)
            queue[rear++] = (Pair){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (Pair){curr->right, hd + 1};
    }
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    Node* root = buildTree(arr, n);
    verticalOrder(root);
}