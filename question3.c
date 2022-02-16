//3. Implementation of circular queue
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int tail,head,size;
    int* array;
};

struct Queue* create_queue(int capacity){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue*));
    queue->head = -1;
    queue->tail = -1;
    queue->size = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

void enqueue(struct Queue *q,int data){
    if(q->head == 0 && q->tail == q->size-1){
        printf("Queue is full.\n");
        return;
    }
    else if(q->tail == q->size-1 && q->head != 0){
        q->tail = 0;
        q->array[q->tail] = data;
    }
    else if(q->head==-1){
        q->head = q->tail = 0;
        q->array[q->head] = data;
    }
    else{
        q->array[++q->tail] = data;
    }
}

int dequeue(struct Queue *q){
    if(q->head == -1){
        return -1;
    }
    else if(q->head==q->tail){
        int temp = q->array[0];
        q->tail = -1;
        q->head = -1;
        return temp;
    }
    else if(q->head >= q->size){
        q->head=0;
        dequeue(q);
    }
    else{
        return q->array[q->head++];   
    }
}

int main(){
    struct Queue *qptr = create_queue(5);
    printf("The queue of capacity %d is created.\n",qptr->size);
    enqueue(qptr,10);
    enqueue(qptr,20);
    enqueue(qptr,30);
    enqueue(qptr,40);
    enqueue(qptr,50);
    enqueue(qptr,60);
    printf("The dequeued element is : %d\n",dequeue(qptr));
    enqueue(qptr,60);
    printf("The dequeued element is : %d\n",dequeue(qptr));
    return 0;
}

/*
Output:
The queue of capacity 5 is created.
Queue is full.
The dequeued element is : 10
The dequeued element is : 20
*/