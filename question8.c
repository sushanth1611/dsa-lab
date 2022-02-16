//8. Implementation of Stacks using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* hptr;
    int size;
};

struct Node* add_node(struct Node* h,int d){
    struct Node* nptr = (struct Node*)malloc(sizeof(struct Node*));
    nptr->data = d;
    nptr->next = NULL;
    if(h==NULL){
        return nptr;
    }
    else{
        nptr->next = h;
        return nptr;
    }
}

void push(struct Stack* s,int d){
    s->hptr = add_node(s->hptr,d);
    s->size += 1;
}

int pop(struct Stack* s){
    if(s->size == 0){
        return -1;
    }
    else{
        int t = s->hptr->data;
        struct Node* waste = s->hptr;
        s->hptr = s->hptr->next;
        s->size -= 1;
        free(waste);
        return t; 
    }
}

int peek(struct Stack* s){
    if(s->hptr!=NULL){
        return s->hptr->data;
    }
    else{
        return -1;
    }
}

void display(struct Stack* s){
    struct Node* t = s->hptr;
    while(t!=NULL){
        printf("%d\n",t->data);
        t = t->next;
    }
}

int isEmpty(struct Stack* s){
    return s->size == 0;
}

int main(){
    struct Stack *sptr = (struct Stack*)malloc(sizeof(struct Stack*));
    sptr->hptr = NULL;
    sptr->size = 0;
    push(sptr,10);
    push(sptr,20);
    push(sptr,30);
    printf("The top element of the stack is: %d\n",peek(sptr));
    printf("The stack is:\n");
    display(sptr);
    printf("The poped element of the stack is: %d\n",pop(sptr));
    printf("The stack after deletetion is:\n");
    display(sptr);
    return 0;
}

/*
Output:
The top element of the stack is: 30
The stack is:
30
20
10
The poped element of the stack is: 30
The stack after deletetion is:
20
10
*/