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

//Searching a Value in a BST
NodeAddress Search(NodeAddress root, int val){
	if(root == NULL){
        return NULL;
    }


	if( val < root->val ){
        return Search(root->left , val);
    }

	else if( val > root->val ){
        return Search(root->right, val);
    }

	else {
        return root;
    }
}


//Second Code for Search
NodeAddress Search2(NodeAddress root, int val){
    return root?((val==root->val)? root: ((val < root->val)? Search2(root->left , val): Search2(root->right, val))): NULL;
}


//Inserting a Root in a BST
NodeAddress Insert(NodeAddress root, int val){
	if(root==NULL){
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


//Second Code for Insert
NodeAddress Insert2(NodeAddress root, int val) {
	if(root == NULL){
        return CreateNode(val);
    }

	if(val < root->val){ 

		if(root->left){
            return Insert2(root->left, val);
        }

		else{
            root->left = CreateNode(val);
        }

		return root->left;
	}

	else if(val > root->val){

		if(root->right){
            return Insert2(root->right, val);
        }

		else{
            root->right = CreateNode(val);
        }

		return root->right;
	}
	
	return root;
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

    int array[] = {17, 16, 34, 23, 3, 5, 7};
    int size = sizeof(array)/sizeof(array[0]);

    NodeAddress root;

    root = ArrayToBST(array, size, 0);

    printf("The BST in Inorder Order:\n");
    InorderPrint(root);

    printf("\n");

    Insert(root, 23);
    Insert(root, 1);
    Insert2(root, 46);

    printf("After Insertion:\n");
    printf("The BST in Inorder Order:\n");
    InorderPrint(root);
}