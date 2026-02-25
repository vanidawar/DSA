#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

int main(){
    int n,x,count=0;
    struct node *head=NULL, *temp=NULL, *new=NULL;
    printf("enter length of linked list");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element");
        scanf("%d", &x);
        new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=NULL;
        if (head == NULL) 
        {
            head=new;
            temp=head;
        } 
        else 
        {
            temp->next=new;
            temp=new;
        }
    }
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        count++;
        temp=temp->next;
    }
    printf("\n");
    printf("count:%d",count);
}