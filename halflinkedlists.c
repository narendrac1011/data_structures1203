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


void PrintHalfLinkedList(NodeAddress head){

    //To Print Half Linked List, we use the Hare and Tortoise Pointer Algorithm/Method.
    //We Initialize 2 pointers (Tortoise and Hare), both pointing to the head of Linked List
    //We set tortoise pointer to move only one step at a time, i.e. only yo next node
    //We set hare pointer to move 2 steps at a time, i.e. next->next node
    //We will Loop until the Hare reaches the end of the Linked List

    //When the Hare would be at the End of the Linked List, the tortoise would still be at the Middle
    //Thus, we would get the Half Linked List


    NodeAddress temp, Tortoise, Hare;
    
    temp = head;
    Tortoise = head;
    Hare = head;

    //This Loopn will run until we reach the end of the Linked List
    while(Hare != NULL && Hare->next != NULL){
        Tortoise = Tortoise->next;
        Hare = Hare->next->next;
    }

    int i = 0;

    //We print the Linked List till where the Tortoise is.
    while(temp != Tortoise){
        printf(i?" -> %d":"%d", temp->val);
        temp = temp->next;
        i++;
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

    PrintHalfLinkedList(head);

    free(head);

    return 0;

}