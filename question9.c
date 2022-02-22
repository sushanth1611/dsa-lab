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

void display(struct Queue* q){
    if(q->head == q->tail){
        printf("%d\n",q->head->data);
    }
    else{
        struct Node *h = q->head;
        while(h!=q->tail){
            printf("%d ",h->data);
            h = h->next;
        } 
        printf("%d\n",q->tail->data);
    }
}

int main(){
    struct Queue *qptr = (struct Queue*)malloc(sizeof(struct Queue *));
    qptr->head = NULL;
    qptr->tail = NULL;
    enqueue(qptr,10);
    enqueue(qptr,20);
    enqueue(qptr,30);
    printf("The queue is: \n");
    display(qptr);
    printf("The dequeued element is: %d\n",dequeue(qptr));
    printf("The queue after dequeue is: \n");
    display(qptr);
}

/*
Output:
The queue is: 
10 20 30
The dequeued element is: 10
The queue after dequeue is: 
20 30
*/