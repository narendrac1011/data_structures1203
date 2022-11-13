/*Most of the Parts of the Code have been inferred from the AVL Tree Code on the programiz.com website.*/

#include<stdio.h>
#include<stdlib.h>


struct node{
    int val;
    struct node *left;
    struct node *right;
    int height;
};


typedef struct node *NodeAddress;


//Creating Nodes for each root
NodeAddress CreateNode(int x){

    NodeAddress root = malloc(sizeof(struct node));

    root->val = x;
    root->left = NULL;
    root->right = NULL;
    root->height = 0;

    return root;
}


//Max Function
int max(int a, int b){
    int maximum;

    //If a < b then a is small
    if (a > b){
        maximum = a;
    }
    //If b < a, then b is small
    else{
        maximum = b;
    }

    return maximum;
}


//Left Rotation
NodeAddress LeftRotate(NodeAddress root){

    NodeAddress x = root->right;
    root->right = x->left;
    x->left = root;
    return x;
}


//Right Rotation
NodeAddress RightRotate(NodeAddress root){
    NodeAddress x = root->left;
    root->left = x->right;
    x->right = root;
    return x;
}


//Insertion in a AVL Tree
NodeAddress Insert(NodeAddress node, int value){

    if (node == NULL){
        CreateNode(value);
    }

    //If the Value to be inserted is greater than the root node value, we insert it in the Right side of the root node.
    else if(value > node->val){
        node->right = Insert(node->right, value);
    

        if(node->right->height - node->left->height < -1){
        
            if (value > node->right->val){
                return LeftRotate(node);
            }

            else{
                node->right = RightRotate(node->right);
                return LeftRotate(node);
            }
        }
    }

    //If the Value of be inserted is smaller than the root node value, we insert it in the Left side of the root node.
    else if(value < node->val){
        node->left = Insert(node->left, value);

        
        if(node->left->height - node->right->height > 1){

            if (value < node->left->val){
                return RightRotate(node);
            }

            else{
                node->left = LeftRotate(node->left);
                return RightRotate(node);
            }
        }
    }

    node->height = 1 + max(node->left->height, node->right->height);
    return node;
}


//Inorder Print Function
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

    //Array
    int array[] = {17, 16, 34, 23, 3, 5, 7};
    int size = sizeof(array)/sizeof(array[0]);

    NodeAddress root;

    //Insert each element in the array to the AVL Tree
    for(int i = 0; i < size; i++){
        root = Insert(root, array[i]);
    }

    //Print the AVL Tree in Inorder Format
    printf("The AVL Tree: ");
    InorderPrint(root);
}
