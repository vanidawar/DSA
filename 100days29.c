#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
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
    return head;
}
struct node* rotateRight(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    struct node *temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    temp->next=head;
    k = k % length;
    int steps = length - k;
    temp=head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
void traverse(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
    struct node *head = createList(n);
    scanf("%d", &k);
    head = rotateRight(head, k);
    traverse(head);
}