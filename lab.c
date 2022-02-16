#include <stdio.h>
#include <stdlib.h>

// 1. Implementation of stacks using arrays
/*
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
*/
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

//2. Implemetation of queues using arrays
/*
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
/*
Output:
Queue of capacity 100 is created.
The dequeued element is: 20
*/

//3. Implementation of circular queue
/*
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
*/
/*
Output:
The queue of capacity 5 is created.
Queue is full.
The dequeued element is : 10
The dequeued element is : 20
*/

// 4.Implementation of Infix to Postfix
/*
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

int getPred(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    else{
        return -1;
    }
}

void in_to_post(struct Stack *sptr, char* expr){
    char* ptr = expr;
    while(*ptr!='\0'){
        char c = *ptr;
        if(!isOperator(c)){
            printf("%c",c);
        }
        else{
            if(is_empty(sptr)){
                push(sptr,c);
            }
            else{
                while(!is_empty(sptr) && getPred(c) <= getPred(peek(sptr))){
                    printf("%c",pop(sptr));
                }
                push(sptr,c);
            }
        }
        * ptr++;
    }
    while(!is_empty(sptr)){
        printf("%c",pop(sptr));
    }
}

int main()
{
    struct Stack* sptr=(struct Stack*)malloc(sizeof(struct Stack));
    sptr->hptr=NULL;
    sptr->size=0;
    char exp[] = "1+2-3*5/4";
    printf("The postfix form of the given infix %s is : ",exp);
    in_to_post(sptr,exp);
    return 0;
}
*/
/*
Output:
The postfix form of the given infix 1+2-3*5/4 is : 12+35*4/-
*/

//5. Implementation of Post fix evalution 
/*
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
*/
/*
Output:
The result of given expression is: 0
*/

// 6. Implementation of Singly Linked List
/*
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
*/
/*
Output:
The linked list is: 
30->20->10
*/

// 7.Implementation of doubly Linked List
/*
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
*/
/*
Output:
The linked list is:
30->20->10
Reverse Order is:
10->20->30
*/

//8. Implementation of Stacks using Linked List
/*
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
*/
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

// 9. Implementation of Queues using Linked List
/*
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
*/
/*
Output:
The dequeued element is: 10
*/

//10. Implementation of binary search
/*
int binary_search(int* array,int x,int start,int end){
    if(start<=end){
        int mid = (start+end)/2;
        if(array[mid]==x){
            return mid;
        }
        else if(array[mid] > x){
            return binary_search(array,x,start,mid-1);
        }
        else{
            return binary_search(array,x,mid+1,end);
        }
    }
    else{
        return -1;
    }
}

void print_result(int res){
    if(res==-1){
        printf("Not Found.");
    }
    else{
        printf("The element is present at the index: %d",res);
    }
}

int main(){
    int n,x,res;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*(n-1));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    } 
    printf("Enter the element you want to search: ");
    scanf("%d",&x);
    print_result(binary_search(a,x,0,n));
    return 0;
}
*/
/*
Output:
Enter the no of elements: 5
10
20
30
40
50
Enter the element you want to search: 40
The element is present at the index: 3
*/

// 11.Implementation of tree transversals in binary trees
/*
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* new_node(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node* ));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inOrder(struct Node* n){
    if(n == NULL){
        return;
    }
    inOrder(n->left);
    printf("%d ",n->data);
    inOrder(n->right);
}

void preOrder(struct Node* n){
    if(n == NULL){
        return;
    }
    printf("%d ",n->data);
    preOrder(n->left);
    preOrder(n->right);
}

void postOrder(struct Node* n){
    if(n==NULL){
        return;
    }
    postOrder(n->left);
    postOrder(n->right);
    printf("%d ",n->data);
}

int main(){
    struct Node* root = new_node(10);
    root->left = new_node(20);
    root->right = new_node(30);
    root->left->left = new_node(40);
    root->left->right = new_node(50);
    printf("The in-order transversal of the given tree is: \n");
    inOrder(root);
    printf("\n");
    printf("The pre-order transversal of the given tree is: \n");
    preOrder(root);
    printf("\n");
    printf("The post-order transversal of the given tree is: \n");
    postOrder(root);
    return 0;
}
*/
/*
Output:
The in-order transversal of the given tree is: 
40 20 50 10 30
The pre-order transversal of the given tree is:
10 20 40 50 30
The post-order transversal of the given tree is:
40 50 20 30 10
*/

// 12.Implementation of Binary Search Trees
/*
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int d){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void in_order(struct Node* r){
    if(r==NULL){
        return;
    }
    in_order(r->left);
    printf("%d ",r->data);
    in_order(r->right);
}

struct Node* insert_node(struct Node* root,int d){
    if(root==NULL){
        return create_node(d);
    }
    else if(d<root->data){
        root->left  = insert_node(root->left,d);
    }
    else if(d > root->data){
        root->right = insert_node(root->right,d);
    }
    return root;
}

int get_min(struct Node* r){
    if(r->left == NULL){
        return r->data;
    }
    else{
        return get_min(r->left);
    }
}

struct Node* del_node(struct Node* r,int d){
    if(r==NULL){
        return NULL;
    }
    else if(d < r->data){
        r->left = del_node(r->left,d);
    }
    else if(d > r->data){
        r->right = del_node(r->right,d);
    }
    else{
        //case 1: Node to be deleted is a leaf node
        if(r->left == NULL && r->right == NULL){
            free(r);
            return NULL;
        }
        //case 2: Node to be deleted has a child node
        else if(r->right == NULL){
            struct Node* temp = r->left;
            free(r);
            return temp;
        }
        else if(r->left == NULL){
            struct Node* temp = r->right;
            free(r);
            return temp;
        }
        //case 3 : If the Node to be deleted has two child nodes
        else{
            int least = get_min(r->right);
            r->data = least;
            r->right = del_node(r->right,least);
            return r;
        }
    }
    return r;
}

int main(){
    struct Node* root = NULL;
    int n,m,x,a;
    printf("Enter the number of nodes in your tree: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data in tree: ");
        scanf("%d",&m);
        root = insert_node(root,m);
    }
    printf("The given tree is: \n");
    in_order(root);
    printf("\nEnter the element that you want to delete: ");
    scanf("%d",&a);
    root = del_node(root,a);
    printf("The tree after deletation is: \n");
    in_order(root);
}
*/
/*
Output:
Enter the number of nodes in your tree: 5
Enter the data in tree: 30
Enter the data in tree: 20
Enter the data in tree: 40
Enter the data in tree: 10
Enter the data in tree: 25
The given tree is: 
10 20 25 30 40 
Enter the element that you want to delete: 20
The tree after deletation is: 
10 25 30 40
*/

// 13.Implementation of Selection Sort
/*
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int n,i;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*(n-1));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array befor sorting is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    selection_sort(a,n);
    printf("\nThe array after the sort is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
*/
/*
Output:
Enter the no of elements: 5
30
10
40
20
50
The array befor sorting is:
30 10 40 20 50 
The array after the sort is:
10 20 30 40 50 
*/

//14.Implementation of Insertion Sort
/*
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n,i;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*(n-1));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array befor sorting is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    insertion_sort(a,n);
    printf("\nThe array after the sort is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
*/
/*
Output:
Enter the no of elements: 5
30
10
40
20
50
The array befor sorting is:
30 10 40 20 50 
The array after the sort is:
10 20 30 40 50 
*/

// 15. Implementation of Heap Sort
/*
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;  
    if (left < n && arr[left] > arr[largest])
      largest = left;  
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}

int main(){
    int n,i;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*(n-1));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array befor sorting is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    heap_sort(a,n);
    printf("\nThe array after the sort is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
*/
/*
Output:
Enter the no of elements: 5
30
10
40
20
50
The array befor sorting is:
30 10 40 20 50 
The array after the sort is:
10 20 30 40 50 
*/
//----------------------------------- THE END-------------------------------//