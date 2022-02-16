// 12.Implementation of Binary Search Trees
#include <stdio.h>
#include <stdlib.h>

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