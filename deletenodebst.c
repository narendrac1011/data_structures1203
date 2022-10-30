#include<stdio.h>
#include<stdlib.h>


//The Structure of the Node. 
//Any node of this struct would have 3 variables - val, left and right
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


//Get Minimum Node value in a Sub-Tree
int getMinimum(NodeAddress root){
    while(root->left != NULL){
        root = root->left;
    }

    return root->val;
}


//Inserting a Root in a BST
NodeAddress Insert(NodeAddress root, int val){
	if(root == NULL){
        return CreateNode(val);
    }

	if( val < root->val ){
        root->left  = Insert(root->left , val);
    }

	else if( val > root->val ){
        root->right = Insert(root->right, val);
    }

	return root;
}


//Delete a Node in a BST
NodeAddress Delete(NodeAddress root, int val){
    if(root == NULL){
        return NULL;
    }


	if( val < root->val ){
        root->left = Delete(root->left , val);
    }

	else if( val > root->val ){
        root->right = Delete(root->right, val);
    }

    else{

        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        else if(root->left == NULL){
            free(root);
            return root->right;
        }

        else if(root->right == NULL){
            free(root);
            return root->left;
        }

        else{
            int RightMinimum = getMinimum(root->right);
            root->val = RightMinimum;
            root->right = Delete(root->right, RightMinimum);
        }

        return root;
    }
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


//Main Function
int main(){

    int array[] = {3, 5, 7, 9, 11};
    int size = sizeof(array)/sizeof(array[0]);

    NodeAddress root;

    root = ArrayToBST(array, size, 0);

    printf("The BST in Inorder Order:\n");
    InorderPrint(root);

    printf("\n");

    Insert(root, 22);
    Insert(root, 1);
    Insert(root, 46);
    Delete(root, 3);
    Delete(root, 7);

    printf("After Insertion and Deletion:\n");
    printf("The BST in Inorder Order:\n");
    InorderPrint(root);
}