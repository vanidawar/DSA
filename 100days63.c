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
void dfs(Node* adj[], int visited[], int s) {
    visited[s] = 1;
    printf("%d ", s);
    Node* temp = adj[s];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node* adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }
    int s;
    scanf("%d", &s);
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("DFS Traversal: ");
    dfs(adj, visited, s);
}