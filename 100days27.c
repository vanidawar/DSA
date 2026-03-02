#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int getLength(struct node *head) 
{
    int count=0;
    while (head!=NULL) 
    {
        count++;
        head=head->next;
    }
    return count;
}
struct node* findIntersection(struct node *head1, struct node *head2) 
{
    int len1=getLength(head1);
    int len2=getLength(head2);
    int diff=abs(len1-len2);
    if (len1>len2) 
    {
        while(diff--)
            head1=head1->next;
    } 
    else 
    {
        while(diff--)
            head2=head2->next;
    }
    while (head1!=NULL && head2!=NULL) {
        if (head1==head2)
            return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}
int main() 
{
    struct node *common = (struct node *)malloc(sizeof(struct node));
    common->data = 30;
    common->next = (struct node *)malloc(sizeof(struct node));
    common->next->data = 40;
    common->next->next = (struct node *)malloc(sizeof(struct node));
    common->next->next->data = 50;
    common->next->next->next = NULL;
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    head1->data = 10;
    head1->next = (struct node *)malloc(sizeof(struct node));
    head1->next->data = 20;
    head1->next->next = common;
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2->data = 15;
    head2->next = (struct node *)malloc(sizeof(struct node));
    head2->next->data = 25;
    head2->next->next = common;
    struct node *result = findIntersection(head1, head2);
    if (result != NULL)
        printf("%d", result->data);
    else
        printf("No Intersection");

}