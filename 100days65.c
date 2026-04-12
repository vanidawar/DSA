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
int dfs(Node* adj[], int visited[], int node, int parent) {
    visited[node] = 1;
    Node* temp = adj[node];
    while (temp) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            if (dfs(adj, visited, neighbor, node))
                return 1;
        }
        else if (neighbor != parent) {
            return 1;  // cycle found
        }
        temp = temp->next;
    }
}
int hasCycle(Node* adj[], int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, i, -1))
                return 1;
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
    if (hasCycle(adj, n))
        printf("YES\n");
    else
        printf("NO\n");
}