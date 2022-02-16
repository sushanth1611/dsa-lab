// 7.Implementation of doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* add_node(struct Node* n,int data){
    struct Node* nptr = (struct Node*)malloc(sizeof(struct Node*));
    nptr->data = data;
    nptr->next = NULL;
    nptr->prev = NULL;
    if(n==NULL){
        n = nptr;
        return n;
    }
    else{
        nptr->next = n;
        n->prev = nptr;
        return nptr;
    }
}

void print_list(struct Node* n){
    struct Node* hptr = n;
    while(hptr->next!=NULL){
        printf("%d->",hptr->data);
        hptr = hptr->next;
    }
    printf("%d\n",hptr->data);
    printf("Reverse Order is:\n");
    while(hptr!=NULL){
        if(hptr->prev == NULL){
            printf("%d",hptr->data);
        }
        else{
            printf("%d->",hptr->data);
        }
        hptr = hptr->prev;
    }
}

int main(){
    struct Node *hptr = NULL;
    hptr = add_node(hptr,10);
    hptr = add_node(hptr,20);
    hptr = add_node(hptr,30);
    printf("The linked list is:\n");
    print_list(hptr);
}

/*
Output:
The linked list is:
30->20->10
Reverse Order is:
10->20->30
*/