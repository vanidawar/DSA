#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
void addEdge(Node* adj[], int u, int v) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=v;
    newNode->next=adj[u];
    adj[u]=newNode;
}
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    Node* adj[n];
    for (int i=0; i<n;i++) {
        adj[i]=NULL;
    }
    for (int i=0;i<m;i++) {
        int u, v;
        scanf("%d %d",&u,&v);
        addEdge(adj,u,v);
        addEdge(adj,v,u);
    }
    for (int i=0;i<n;i++) {
        printf("%d: ",i);
        Node* temp=adj[i];
        while (temp) {
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
