#include<stdio.h>
#include<stdlib.h>


//The Structure of the Node. Any node of this struct would have 3 variables - val, left and right
struct node{
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node *NodeAddress;


//Creating Nodes for each root
NodeAddress CreateNode(int x){

    NodeAddress temp = malloc(sizeof(struct node));

    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


//Convert an Array to a Binary Search Tree
NodeAddress ArrayToBST(int *a, int n, int i){

    NodeAddress root = NULL;
    if (i < n){

        root = CreateNode(a[i]);
        root->left = ArrayToBST(a, n, 2*i + 1);
        root->right = ArrayToBST(a, n, 2*i + 2);
    }

    return root;
}


//Inorder Print Function
//We print the BST in the Inorder Format, i.e. Left, Root, Right
void InorderPrint(NodeAddress root){

    if (!root){
        return;
    }

    InorderPrint(root->left);
    printf("%d \n", root->val);
    InorderPrint(root->right);
}

//Prefix Print Function
//We print the BST in the prefix format - i.e. Root, Left, Right
void prefixPrint(NodeAddress root){

    if (!root){
        return;
    }

    printf("%d \n", root->val);
    prefixPrint(root->left);
    prefixPrint(root->right);
}


//PostOrder Print Function
//We print the BST in the Post Order format - i.e. Left, Right, Root
void PostOrderPrint(NodeAddress root){

    if (!root){
        return;
    }

    PostOrderPrint(root->left);
    PostOrderPrint(root->right);
    printf("%d \n", root->val);
}


int main(){

    int array[] = {17, 16, 34, 23, 3, 5, 7};
    int size = sizeof(array)/sizeof(array[0]);

    NodeAddress root;

    root = ArrayToBST(array, size, 0);

    printf("The BST in Inorder Order:\n");
    InorderPrint(root);

    printf("\n");

    printf("The BST in Prefix Order:\n");
    prefixPrint(root);

    printf("\n");

    printf("The BST in Post Order:\n");
    PostOrderPrint(root);
}