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


//Insertion Sort of Linked List
NodeAddress LLInsertionSort(NodeAddress head){
    //Base Cases
    //If the Linked List is empty, we return NULL!
    if (head == NULL){
        return 0;
    }

    //If the Linked List has only one Element, then There is no need to sort!
    else if(head->next == NULL){
        return head;
    }
    
    else{
        NodeAddress curr, temp;
        curr = head;

        //For each element in Linked List, we take that element to its sorted place
        while(curr->next != NULL){
            temp = curr->next;

            while(temp != NULL){

                //If Current value is greater than the Current->next value, then we swap the values!
                if(curr->val > temp->val){
                    int swap = curr->val;
                    curr->val = temp->val;
                    temp->val = swap;
                }

                temp = temp->next;
            }

            //Move on to the next element in the Linked List
            curr = curr->next;

        }//Repeat this for all the elements in the Linked List!

    }//We would have the sorted Linked List.
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

    //Print the Linked List before Sorting
    printf("The Linked List without Sorting: ");
    printLinkedList(head);
    printf("\n");

    //Sort the Linked List using sorting and Print it!
    LLInsertionSort(head);
    printf("The Linked List after Insertion Sort: ");
    printLinkedList(head);

    free(head);

    return 0;
}


//My Scanf command doesn't work. So, I have inputted the values myself.