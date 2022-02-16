// 11.Implementation of tree transversals in binary trees
#include <stdio.h>
#include <stdlib.h>

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

/*
Output:
The in-order transversal of the given tree is: 
40 20 50 10 30
The pre-order transversal of the given tree is:
10 20 40 50 30
The post-order transversal of the given tree is:
40 50 20 30 10
*/
