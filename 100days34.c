#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top=NULL;
void push(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=top;
    top=temp;
}
int pop() {
    struct Node* temp=top;
    int val=temp->data;
    top=top->next;
    free(temp);
    return val;
}
int main() {
    char exp[100];
    int i=0;
    printf("Enter postfix expression:");
    fgets(exp,sizeof(exp),stdin);
    while (exp[i]!='\0'){
        if (exp[i]==' '){
            i++;
            continue;
        }
        if (isdigit(exp[i])){
            int num=0;
            while (isdigit(exp[i])){
                num=num*10+(exp[i]-'0');
                i++;
            }
            push(num);
        }
        else{
            int b=pop();
            int a=pop();
            if(exp[i]=='+')push(a+b);
            else if (exp[i]=='-')push(a-b);
            else if (exp[i]=='*')push(a*b);
            else if (exp[i]=='/')push(a/b);
            i++;
        }
    }
    printf("Result: %d\n",pop());
}