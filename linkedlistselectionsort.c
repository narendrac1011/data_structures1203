#include<stdio.h>
#include<stdlib.h>


//Creating node with 2 variables - Val and Next
struct node{
    int val;
    struct node *next;
};

typedef struct node *NodeAddress;


//Printing the Linked List
void printLinkedList(NodeAddress temp){
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

        if(temp == NULL){
        printf("NULL");
    }
}


//Selection Sort
void LLSelectionSort(NodeAddress head){

    NodeAddress temp, current, minimum;

    temp = head;

    while(temp->next != NULL){
        minimum = temp;
        current = temp->next;


        //This loops helps us find the minimum value in the linked list
        while(current != NULL){
            if (current->val < minimum->val){
                minimum = current;
            }

            current = current->next;
        }


        //Swap Data of minimum value in the linked list with the temp node value
        int x = temp->val;
        temp->val = minimum->val;
        minimum->val = x;

        //Increase the temp by 1
        //This makes us go through the whole linked list
        temp = temp->next;
    }

}

int main(){

    //Initially, the Values of all the Elements in the Linked List is set to NULL.
    NodeAddress head = NULL;
    NodeAddress second = NULL;
    NodeAddress third = NULL;
    NodeAddress fourth = NULL;
    NodeAddress fifth = NULL;
    NodeAddress sixth = NULL;

    //We allocate memory to the every Element in the Linked List.
    head = (NodeAddress)malloc(sizeof(NodeAddress));
    second = (NodeAddress)malloc(sizeof(NodeAddress));
    third = (NodeAddress)malloc(sizeof(NodeAddress));
    fourth = (NodeAddress)malloc(sizeof(NodeAddress));
    fifth = (NodeAddress)malloc(sizeof(NodeAddress));
    sixth = (NodeAddress)malloc(sizeof(NodeAddress));

    //We enter the values from each address and we go to the next address one after the other
    //Values of different nodes and the sequence of linked list:
    head->val = 19;
    head->next = second;

    second->val = 101;
    second->next = third;

    third->val = 22;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 48;
    fifth->next = sixth;

    sixth->val = 59;
    sixth->next = NULL;


    printLinkedList(head);
    printf("\n");

    LLSelectionSort(head);
    printLinkedList(head);

    free(head);

    return 0;
}


//My Scanf command doesn't work. So, I have inputted the values myself.