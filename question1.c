// 1. Implementation of stacks using arrays
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int capacity;
    int* array;
};

struct Stack* create_stack(int capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int is_full(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

int is_empty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack,int item){
    if (is_full(stack)){
        return;
    }
    else{
        stack->array[++stack->top] = item;
    }
}

int pop(struct Stack* stack){
    if (is_empty(stack)){
        return -1;
    }
    else{
        return stack->array[stack->top--];
    }
}

int peek(struct Stack* stack){
    if (is_empty(stack)){
        return -1;
    }
    else{
        return stack->array[stack->top];
    }  
}

void print_stack(struct Stack* stack){
    for(int i=stack->top;i>=0;i--){
        printf("%d\n",stack->array[i]);
    }
}

int main(){
    struct Stack *sptr = create_stack(100);
    printf("The stack is created with capacity %d\n",sptr->capacity);
    push(sptr,10);
    push(sptr,20);
    push(sptr,30);
    printf("The element at the top is: %d",peek(sptr));
    printf("\nThe poped element from the stack is: %d\n",pop(sptr));
    push(sptr,40);
    printf("Currently the stack is: \n");
    print_stack(sptr);
    return 0;
}

/*
Output:
The stack is created with capacity 100
The element at the top is: 30
The poped element from the stack is: 30
Currently the stack is: 
40
20
10
*/