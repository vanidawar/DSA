#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}
void bfs(Node* adj[], int n, int s) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i]=0;
    int queue[n];
    int front=0, rear=0;
    queue[rear++] = s;
    visited[s] = 1;
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }
    int s;
    scanf("%d", &s);
    printf("BFS Traversal: ");
    bfs(adj, n, s);
}