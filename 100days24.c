#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node* createList(int n){
    struct node *head=NULL,*temp=NULL,*newNode;
    int val;
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&val);
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=val;
        newNode->next=NULL;
        if (head==NULL) 
        {
            head=newNode;
            temp=head;
        } 
        else 
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
    return head;
}
struct node* deleteFirst(struct node *head,int key) 
{
    struct node *temp=head,*prev=NULL;
    if (head!=NULL && head->data==key) 
    {
        head=head->next;
        free(temp);
        return head;
    }
    while (temp!=NULL && temp->data!=key) 
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp!=NULL) 
    {
        prev->next=temp->next;
        free(temp);
    }
    return head;
}
void display(struct node *head) 
{
    while (head!=NULL) 
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
int main() 
{
    int n,key;
    scanf("%d",&n);
    struct node *head=createList(n);
    scanf("%d",&key);
    head=deleteFirst(head, key);
    display(head);
}