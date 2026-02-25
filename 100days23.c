#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, x;
    struct node *head=NULL,*temp=NULL,*new=NULL;
    struct node *merged=NULL,*tail=NULL;
    printf("Enter length of linked list 1: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
    {
        printf("Enter element");
        scanf("%d",&x);
        new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=NULL;

        if (head==NULL) 
        {
            head=temp=new;
        } 
        else 
        {
            temp->next=new;
            temp=new;
        }
    }

    int n2,x2;
    struct node *head2=NULL,*temp2=NULL,*new2=NULL;

    printf("Enter length of linked list 2: ");
    scanf("%d",&n2);

    for (int i=0;i<n2;i++) 
    {
        printf("Enter element");
        scanf("%d",&x2);
        new2=(struct node*)malloc(sizeof(struct node));
        new2->data=x2;
        new2->next=NULL;

        if (head2==NULL) 
        {
            head2=temp2=new2;
        } 
        else 
        {
            temp2->next=new2;
            temp2=new2;
        }
    }
    while (head!=NULL && head2!=NULL) {
        struct node *picked;
        if (head->data<head2->data) {
            picked=head;
            head=head->next;
        } 
        else 
        {
            picked=head2;
            head2=head2->next;
        }

        if (merged==NULL) 
        {
            merged=tail=picked;
        } 
        else 
        {
            tail->next=picked;
            tail=picked;
        }
    }

    if (merged==NULL) 
    {
        merged=(head!=NULL)?head:head2;
    } 
    else 
    {
        tail->next=(head!=NULL)?head:head2;
    }
    temp=merged;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}