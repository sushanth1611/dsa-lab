//5. Implementation of Post fix evalution 
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Stack
{
    struct Node* hptr;
    int size;
};

struct Node * add_node(struct Node *h,char d)
{
    struct Node* nptr;
    nptr=(struct Node*)malloc(sizeof(struct Node));
    if(h==NULL)
    {
        h=nptr;
        h->next=NULL;
        h->data=d;
        return h;
    }
    else
    {
        nptr->next=h;
        nptr->data=d;
        h=nptr;
        return h;
    }
}

void push(struct Stack* sptr,char d)
{
    if(sptr->hptr==NULL)
    {
        sptr->hptr=add_node(NULL,d);
        sptr->size=1;
    }
    else
    {
        sptr->hptr=add_node(sptr->hptr,d);
        sptr->size=sptr->size+1;
    }
}

char pop(struct Stack* sptr)
{
    if(sptr->size==0)
    {
        return -1;
    }
    else
    {
        char temp=sptr->hptr->data;
        struct Node *t=sptr->hptr;
        sptr->hptr=sptr->hptr->next;
        sptr->size-=1;
        free(t);
        return temp;
    }
}

int is_empty(struct Stack *t){
    return t->size == 0;
}

char peek(struct Stack *t){
    if(t!=NULL){
        return t->hptr->data;
    }
}

int isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int post_eval(struct Stack* sptr, char* expr){
    char* ptr = expr;
    while (*ptr!='\0'){
        char c = *ptr;
        if(!isOperator(c)){
            push(sptr,c);
        }
        else{
            int a = pop(sptr) - '0';
            int b = pop(sptr) - '0';
            if(c == '+'){
                push(sptr,(b+a)+'0');
            }
            else if(c=='-'){
                push(sptr,(b-a)+'0');
            }
            else if(c=='*'){
                push(sptr,(b*a)+'0');
            }
            else if(c=='/'){
                push(sptr,(b/a)+'0');
            }
            else if(c=='^'){
                push(sptr,(b^a)+'0');
            }
        }
        * ptr++;
    }
    return pop(sptr) - '0';
}

int main()
{
    struct Stack* sptr=(struct Stack*)malloc(sizeof(struct Stack));
    sptr->hptr=NULL;
    sptr->size=0;
    char exp[] = "12+35*4/-";
    printf("The result of given expression is: %d",post_eval(sptr,exp));
    return 0;
}

/*
Output:
The result of given expression is: 0
*/