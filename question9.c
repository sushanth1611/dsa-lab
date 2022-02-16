// 9. Implementation of Queues using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue{
    struct Node *head;
    struct Node *tail;
};

void enqueue(struct Queue *q,int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node *));
    new_node->data = data;
    new_node->next = NULL;
    if(q->tail==NULL){
        q->head = new_node;
        q->tail = q->head;
    }
    else{
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(struct Queue *q){
    if(q->head==NULL){
        return -1;
    }
    else{
        struct Node* waste = q->head;
        q->head = q->head->next;
        int t = waste->data;
        free(waste);
        if(q->head==NULL){
            q->tail = NULL;
        }
        return t;
    }
}

int main(){
    struct Queue *qptr = (struct Queue*)malloc(sizeof(struct Queue *));
    qptr->head = NULL;
    qptr->tail = NULL;
    enqueue(qptr,10);
    enqueue(qptr,20);
    enqueue(qptr,30);
    printf("The dequeued element is: %d",dequeue(qptr));
}

/*
Output:
The dequeued element is: 10
*/