// 6. Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* add_node(struct Node* n,int d){
    struct Node* nptr = (struct Node*)malloc(sizeof(struct Node*));
    nptr->data = d;
    nptr->next = NULL;
    if(n==NULL){
        n = nptr;
        return n;
    }
    else{
        nptr->next = n;
        return nptr;
    }
}

void print_list(struct Node* n){
    struct Node* hptr = n;
    while(hptr!=NULL){
        if(hptr->next == NULL){
            printf("%d\n",hptr->data);
        }
        else{
            printf("%d->",hptr->data);
        }
        hptr = hptr->next;
    }
}

int main(){
    struct Node* hptr = NULL;
    hptr = add_node(hptr,10);
    hptr = add_node(hptr,20);
    hptr = add_node(hptr,30);
    printf("The linked list is: \n");
    print_list(hptr);
    return 0;
}

/*
Output:
The linked list is: 
30->20->10
*/