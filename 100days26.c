#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
int main() 
{
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL) 
        {
            head=temp=newnode;
        } 
        else 
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    temp=head;
    while (temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}