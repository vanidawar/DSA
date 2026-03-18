#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coef;
    int exp;
    struct Node* next;
};
struct Node* create(int n)
{
    struct Node *head=NULL,*temp=NULL,*new;
    int c,e;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&c,&e);
        new=(struct Node*)malloc(sizeof(struct Node));
        new->coef=c;
        new->exp=e;
        new->next=NULL;
        if(head==NULL) 
        {
            head=new;
            temp=new;
        } 
        else 
        {
            temp->next=new;
            temp=new;
        }
    }
    return head;
}
void display(struct Node* head) 
{
    struct Node* temp=head;
    while(temp!=NULL) 
    {
        if(temp->exp==0)
            printf("%d",temp->coef);
        else if(temp->exp==1)
            printf("%dx",temp->coef);
        else
            printf("%dx^%d",temp->coef,temp->exp);
        if(temp->next != NULL)
            printf(" + ");
        temp=temp->next;
    }
}
int main() 
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    struct Node* head=create(n);
    printf("Polynomial:\n");
    display(head);
}