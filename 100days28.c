#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* createCircularList(int n) 
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    if (temp != NULL)
        temp->next = head;
    return head;
}
void traverseCircularList(struct node *head) {
    struct node *temp = head;

    if (head == NULL)
        return;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);
    struct node *head = createCircularList(n);
    traverseCircularList(head);
}