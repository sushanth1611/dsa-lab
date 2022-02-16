#include <stdio.h>
#include <stdlib.h>

//2. Implemetation of queues using arrays

struct Queue{
    int tail,head,capacity,size;
    int* array;
};

struct Queue* create_queue(int capacity){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue*));
    queue->capacity = capacity;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* q){
    return q->size == q->capacity;
}

int isEmpty(struct Queue* q){
    return q->size == 0;
}

void enqueue(struct Queue* q,int data){
    if (isFull(q)){
        return;
    }
    else{
        q->array[q->tail++] = data;
        q->size = q->size + 1;
    }
}

int dequeue(struct Queue* q){
    if (isEmpty(q) || (q->tail == q->head) || q->tail < q->head){
        return -1;
    }
    else{
        return q->array[q->head++];
    }
}

int main(){
    struct Queue *qptr = create_queue(100);
    printf("Queue of capacity %d is created.\n",qptr->capacity);\
    enqueue(qptr,20);
    enqueue(qptr,30);
    enqueue(qptr,40);
    printf("The dequeued element is: %d",dequeue(qptr));
    return 0;
}

/*
Output:
Queue of capacity 100 is created.
The dequeued element is: 20
*/